globals [
  C_A              ; anterior discrete diffusion parameter
  C_P              ; posterior discrete diffusion parameter
  C_alpha          ; segmentation discrete diffusion parameter
  C                ; axial segmentation clock
  dC               ; clock derivative
;  G                ; growth signal
  C_BAM            ; anterior border discrete diffusion parameter
  C_BPM            ; posterior border discrete diffusion parmeter
  recip-e          ; 1 / e
  recording-movie? ; set if recording a movie
]

patches-own [
  A Ap         ; anterior morphogen
  P Pp         ; posterior morphogen
  M Mp         ; cell mass
  S Sp         ; somite concentration
  T Tp         ; tail cell concentration
  G Gp         ; growth signal
  K            ; axial clock signal
  dK           ; derivative of axial clock signal
  L            ; peripheral clock signal
  dL           ; derivative of peripheral clock signal
  phi          ; firing signal
  alpha alphap ; segmentation signal
  rho rhop     ; recovery variable
  Vx Vy        ; velocity
  BA BAp       ; anterior border marker
  BP BPp       ; posterior border marker
  AB           ; anterior morphogen block
  BAM BAMp     ; anterior border morphogen
  BPM BPMp     ; posterior border morphogen
  ID           ; imaginal disk for limb (called K in user interface)
  dID          ; derivative of ID density
  local-density; local S (somite) density
  edge         ; edge signal
  LM           ; limb marker concentration
]

to setup
  clear-patches
  compute-diffusion-parameters
  initialize-head
  initialize-tailbud
  ; initialize clock
  ask patches [ set K 1 set dK 0 set L 1 set dL 1 set G 1 ]
;  set G 1
  set recip-e 1 / 2.718281828
  set recording-movie? false
  reset-ticks
end

to default-parameters
  set delta-s 0.04
  set delta-t 0.04
  set tail-length 1
  set growth-rate 0.3
  set T_G 30
  ;
  set D_A 0.005
  set T_A 1
  set K_A 10
  set A_upb 0.1
  ;
  set D_P 0.005
  set T_P 1
  set K_P 10
  set P_upb 0.1
  ;
  set D_alpha 0.005
  set T_alpha 0.6
  set alpha_lwb 0.1
  set theta_alpha 0.2
  ;
  set omega 1
  set theta_C 0.9
  set theta_rho 0.01
  set T_rho 1
  set K_S 5
  ;
  set theta_BA 0.5
  set T_BA 1
  set K_BA 10
  ;
  set theta_BP 0.5
  set T_BP 5
  set K_BP 10
  ;
  set D_BAM 0.005
  set T_BAM 1
  set K_BAM 10
  set BAM_lwb 0.004
  set BAM_upb 0.03
  ;
  set D_BPM 0.005
  set T_BPM 3
  set K_BPM 10
  set BPM_lwb 0.02
  set BPM_upb 0.09
  ;
  set K_ID 1
  set K_TLM 0.1
  set theta_LM 0.01
  ;
  set T_AB 3
  set S_upb 0.8
  set K_phi 1
  set psi 1
end

to compute-diffusion-parameters
  set C_A disc-from-cont-diff D_A
  set C_P disc-from-cont-diff D_P
  set C_alpha disc-from-cont-diff D_alpha
  set C_BAM disc-from-cont-diff D_BAM
  set C_BPM disc-from-cont-diff D_BPM
end

to-report disc-from-cont-diff [D]
  report D * 8 * delta-t / (delta-s * delta-s)
end

to initialize-head
  ask patches with [ pxcor <= 25 and abs pycor <= 25 ] [
    set A 1
    set M 1
    set S 1
  ]
end

to initialize-tailbud
  ask patches with [ 25 < pxcor and pxcor <= 50 and abs pycor <= tail-length / delta-s ] [
    set P 1
    set M 1
    set T 1
  ]
end

to step
;  set G G - delta-t * G / T_G ; update growth timer
  ;
  ; morphogens diffuse
  ;
  diffuse A min list 1 C_A
  diffuse P min list 1 C_P
  diffuse alpha min list 1 C_alpha
  diffuse BAM min list 1 C_BAM
  diffuse BPM min list 1 C_BPM
  ;
  ask patches [ prepare-variables ]
  ask-concurrent patches with [pxcor > min-pxcor and pxcor < max-pxcor and pycor > min-pycor and pycor < max-pycor ] [ grow ]
  ask patches [
    set G G - delta-t * G / T_G ; update growth timer
    ;
    ; update sinusoidal clocks
    ;
    set dK dK - delta-t * omega * K
    set K K + delta-t * omega * dK
    set dL dL - delta-t * psi * L
    set L L + delta-t * psi * dL
    ;
    ; update Anterior and Posterior morphogens
    ;
    set Ap A + delta-t * (K_A * S * (1 - A) * unitstep (recip-e - AB) - A / T_A) ; blocked by AB > 1/e
    set Pp P + delta-t * (K_P * T * (1 - P) - P / T_P)
    ;
    ; update cell mass [NEEDS TO BE MODIFIED FOR LIMB GROWTH]
    ;
    set Mp min list 1 M + delta-t * (T * growth-rate / tail-length)
    ;
    ; density of cell mass that will fire
    ;
    set phi M * unitstep (alpha - theta_alpha) * unitstep (theta_rho - rho) * K_phi / delta-t
    ;
    ; update refractory period
    ;
    set rhop min list 1 (rho + delta-t * (phi - rho / T_rho))
    ;
    ; update wavefront excitation [NEEDS TO BE MODIFIED FOR LIMB GROWTH]
    ;
    set alphap min list 1 (alpha + delta-t * (phi + T * unitstep (K - theta_C) * unitstep (G - recip-e) - alpha / T_alpha))
    ;
    ; update Segmentation signal
    ;
    let S-trigger unitstep (alpha - alpha_lwb) * unitstep (A_upb - A) * unitstep (P_upb - P)
    set Sp S + delta-t * (K_S * S * (1 - S) + S-trigger)
    ;
    set AB min list 1 (AB + S-trigger - delta-t * (AB / T_AB)) ; Anterior morphogen Block
    ;
    ; Anterior and Posterior Border tussues differentiate
    ;
    set BPp BP + delta-t * (K_BP * S * BP * (1 - BP) +
       unitstep (0.95 * P_upb - P) * unitstep (P - 0.8 * P_upb) * unitstep (alpha - alpha_lwb) - BP / T_BP)
    set BAp BA + delta-t * (K_BA * S * BA * (1 - BA) +
       unitstep(0.5 * A_upb - A) * unitstep (A - 0.25 * A_upb) * unitstep (alpha - alpha_lwb) - BA / T_BA)
    ;
    ; update Anterior and Posterior Border morphogens
    ;
    set BAMp BAM + delta-t * (K_BAM * S * unitstep (BA - theta_BA) * (1 - BAM) - BAM / T_BAM)
    set BPMp BPM + delta-t * (K_BPM * S * unitstep (BP - theta_BP) * (1 - BPM) - BPM / T_BPM)
    ;
    ; Imaginal Disk regions differentiate
    ;
    set local-density mean [S] of neighbors
    set edge unitstep (S_upb - local-density) * K_ID / delta-t
    set dID unitstep(BAM - BAM_lwb) * unitstep(BAM_upb - BAM) * 
      unitstep(BPM - BPM_lwb) * unitstep(BPM_upb - BPM) * edge * S * (1 - ID)
    set ID ID + delta-t * dID
    set LM LM + delta-t * K_LM * unitstep(dID - theta_dID)
  ]
  ask patches [ update-variables ]
  update-display
  tick-advance delta-t
  if recording-movie? [movie-grab-view]
end

to grow ; of terminal cells (T = 1)
  ; velocity is fixed (to right) for all tail cells
  let mLM mean [LM] of neighbors4
  let mT mean [T] of neighbors4
  ifelse mLM = 0 and mT > 0
    [ set Vx 1 
      set Vy 0 
      set G [G] of patch-at -1 0
    ]
  ; velocity away from axis for foot cells
  [ if mLM > 0 and mT > 0
      [ set Vx 0
        ifelse pycor > 0
        [set Vy 1]
        [set Vy -1]
      ]]
  ; LM cells differentiate into T cells when sufficient density
  let LM-trigger delta-t * K_TLM * unitstep (LM - theta_LM)
  ; flux = tail material per unit area per unit time = growth-rate * T * velocity
  ; change in tail concentration = - divergence of flux
  ;   = - growth-rate / delta-s (Delta Tx Vx + T Delta Vx + Delta Ty Vy + T Delta Vy)
  ; double negative divergence estimate:
  let neg-div ([T * Vx] of patch-at -1 0) + ([T * Vy] of patch-at 0 -1)
            - ([T * Vx] of patch-at 1 0) - ([T * Vy] of patch-at 0 1) 
  ;let Delta-Tx T - [T] of patch-at -1 0
  ;let Delta-Ty T - [T] of patch-at 0 -1
  ;let Delta-Vx Vx - [Vx] of patch-at -1 0
  ;let Delta-Vy Vy - [Vy] of patch-at 0 -1
  ; change in conc. in one time step = - delta-t / delta-s * growth-rate * divergence (if still growing)
  ;set Tp min list 1 (Tp - delta-t * growth-rate / delta-s *
  ; (Delta-Tx * Vx + T * Delta-Vx + Delta-Ty * Vy + T * Delta-Vy) * unitstep (G - 1 / 2.712828))
  set Tp max list 0 (min list 1 (T + delta-t / delta-s * growth-rate * neg-div / 2 * unitstep (G - recip-e) + LM-trigger))
  ;
  ; need to update LM like T
  ;
  let neg-div-LM ([LM * Vx] of patch-at -1 0) + ([LM * Vy] of patch-at 0 -1)
               - ([LM * Vx] of patch-at 1 0) - ([LM * Vy] of patch-at 0 1) 
  set LM max list 0 (min list 1 LM + delta-t / delta-s * growth-rate * neg-div-LM / 2 * unitstep (G - recip-e))
end

to prepare-variables
  set Ap A
  set Pp P
  set Mp M
  set Sp S
  set Tp T
  set Gp G
;  set Kp K
  set alphap alpha
  set rhop rho
  set BAp BA
  set BPp BP
  set BAMp BAM
  set BPMp BPM
end

to update-variables
  set A Ap
  set P Pp
  set M Mp
  set S Sp
  set T Tp
;  set G Gp ; Gp is not used
;  set K Kp
  set alpha alphap
  set rho rhop
  set BA BAp
  set BP BPp
  set BAM BAMp
  set BPM BPMp
end

to-report unitstep [x]
  report ifelse-value (x > 0) [1] [0]
end

to update-display
  ask patches [
    let variable 1
    let hue grey
    ifelse field-display = "composite" [ 
      let variables (list alpha T (1.1 * BP) (1.15 * BA) S A P (0.9 * M))
      let variable-colors (list red violet cyan lime brown green blue yellow)
      let dominant argmax variables
      set variable item dominant variables
      set hue item dominant variable-colors
      ] [
    ifelse field-display = "BAM+BPM+K+L" [
      let variables (list LM ID BAM BPM)
      let variable-colors (list magenta grey orange turquoise)
      let dominant argmax variables
      set variable item dominant variables
      set hue item dominant variable-colors      
    ] [
    ifelse field-display = "BAM+BPM+K+L+alpha" [
      let variables (list alpha LM ID BAM BPM)
      let variable-colors (list red magenta grey orange turquoise)
      let dominant argmax variables
      set variable item dominant variables
      set hue item dominant variable-colors      
    ] [
    ifelse field-display = "A & P" [
      let variables (list A P)
      let variable-colors (list green blue)
      let dominant argmax variables
      set variable item dominant variables
      set hue item dominant variable-colors
    ] [
    ifelse field-display = "S+A+P+alpha" [
      let variables (list alpha S A P)
      let variable-colors (list red brown green blue)
      let dominant argmax variables
      set variable item dominant variables
      set hue item dominant variable-colors
    ] [
    ifelse field-display = "alpha" [ set variable alpha set hue orange ] [
    ifelse field-display = "A" [ set variable A set hue green ] [
    ifelse field-display = "C" [ set variable (K + 1) / 2 set hue red ] [
    ifelse field-display = "M" [ set variable M set hue yellow ] [
    ifelse field-display = "P" [ set variable P set hue blue ] [
    ifelse field-display = "S" [ set variable S set hue brown ] [
    ifelse field-display = "T" [ set variable T set hue violet ] [
    ifelse field-display = "BA" [ set variable BA set hue lime ] [ 
    ifelse field-display = "BP" [ set variable BP set hue cyan ] [ 
    ifelse field-display = "BAM" [ set variable BAM set hue orange ] [ 
    ifelse field-display = "BPM" [ set variable BPM set hue turquoise ] [ 
      set variable 1 ]]]]]]]]]]]]]]]]
    set pcolor scale-color hue (variable / 1.5) 0 1
  ]
end

to-report argmax [val]
  let Mx -100000 ; "negative infinity"
  let i 0
  let j 0
  foreach val [
    if ? > Mx [
      set j i
      set Mx ?
    ]
    set i i + 1
  ]
  report j
end

to start-movie
  movie-start user-input "Movie file name (with .mov)?"
  set recording-movie? true
end

to finish-movie
  set recording-movie? false
  movie-close
end
@#$#@#$#@
GRAPHICS-WINDOW
10
10
272
643
-1
150
2.0
1
10
1
1
1
0
0
0
1
0
125
-150
150
0
0
1
ticks
30.0

BUTTON
525
10
587
43
NIL
setup
NIL
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

BUTTON
590
10
700
43
default parameters
default-parameters
NIL
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

CHOOSER
875
10
1062
55
field-display
field-display
"composite" "alpha" "A & P" "S+A+P+alpha" "C" "M" "P" "S" "T" "BA" "BP" "BAM+BPM+K+L" "BAM+BPM+K+L+alpha"
0

BUTTON
705
10
870
43
update display
update-display
NIL
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

SLIDER
535
250
707
283
delta-s
delta-s
0
1
0.04
0.01
1
NIL
HORIZONTAL

SLIDER
710
250
882
283
delta-t
delta-t
0
1
0.04
0.01
1
NIL
HORIZONTAL

BUTTON
525
45
588
78
NIL
step
NIL
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

BUTTON
590
45
700
78
cycle
step
T
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

SLIDER
525
80
697
113
D_A
D_A
0
0.01
0.0050
0.0001
1
NIL
HORIZONTAL

SLIDER
700
80
872
113
T_A
T_A
0
10
1
0.1
1
NIL
HORIZONTAL

SLIDER
875
80
1047
113
K_A
K_A
0
10
10
0.1
1
NIL
HORIZONTAL

MONITOR
1010
250
1067
295
C_A
C_A
3
1
11

SLIDER
525
115
697
148
D_P
D_P
0
0.01
0.0050
0.0001
1
NIL
HORIZONTAL

SLIDER
525
150
697
183
D_alpha
D_alpha
0
0.02
0.0050
0.0001
1
NIL
HORIZONTAL

SLIDER
700
115
872
148
T_P
T_P
0
10
1
0.1
1
NIL
HORIZONTAL

SLIDER
875
115
1047
148
K_P
K_P
0
10
10
0.1
1
NIL
HORIZONTAL

MONITOR
1010
300
1067
345
NIL
C_P
3
1
11

SLIDER
700
150
872
183
T_alpha
T_alpha
0
10
0.6
.1
1
NIL
HORIZONTAL

SLIDER
535
320
707
353
A_upb
A_upb
0
1
0.1
0.01
1
NIL
HORIZONTAL

SLIDER
535
355
707
388
P_upb
P_upb
0
1
0.1
0.01
1
NIL
HORIZONTAL

SLIDER
875
150
1047
183
alpha_lwb
alpha_lwb
0
1
0.1
.01
1
NIL
HORIZONTAL

SLIDER
535
425
707
458
T_rho
T_rho
0
10
1
.01
1
NIL
HORIZONTAL

SLIDER
535
285
707
318
tail-length
tail-length
0
10
1
0.1
1
NIL
HORIZONTAL

SLIDER
710
285
882
318
growth-rate
growth-rate
0
1
0.3
0.1
1
NIL
HORIZONTAL

MONITOR
890
250
1005
295
display growth rate
growth-rate * delta-t / delta-s
3
1
11

SLIDER
350
10
522
43
omega
omega
0
10
1
0.1
1
NIL
HORIZONTAL

SLIDER
350
185
522
218
theta_C
theta_C
0
1
0.9
.01
1
NIL
HORIZONTAL

SLIDER
535
390
707
423
theta_alpha
theta_alpha
0
1
0.2
.01
1
NIL
HORIZONTAL

SLIDER
360
425
532
458
theta_rho
theta_rho
0
1
0.01
.01
1
NIL
HORIZONTAL

SLIDER
710
355
882
388
K_S
K_S
0
10
5
.1
1
NIL
HORIZONTAL

MONITOR
1010
350
1065
395
C_alpha
C_alpha
3
1
11

SLIDER
710
320
882
353
T_G
T_G
0
30
30
1
1
NIL
HORIZONTAL

MONITOR
950
300
1007
345
G[0,0]
[G] of patch 0 0
3
1
11

MONITOR
890
300
947
345
clock
[K] of patch 0 0
3
1
11

BUTTON
890
350
1005
383
NIL
start-movie
NIL
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

BUTTON
890
455
1005
488
NIL
finish-movie
NIL
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

SLIDER
350
115
520
148
D_BAM
D_BAM
0
0.01
0.0050
.0001
1
NIL
HORIZONTAL

SLIDER
350
150
520
183
D_BPM
D_BPM
0
.01
0.0050
.0001
1
NIL
HORIZONTAL

SLIDER
350
220
522
253
T_BA
T_BA
0
10
1
.1
1
NIL
HORIZONTAL

SLIDER
350
255
522
288
T_BP
T_BP
0
10
5
.1
1
NIL
HORIZONTAL

SLIDER
360
460
532
493
K_BA
K_BA
0
10
10
.1
1
NIL
HORIZONTAL

SLIDER
360
495
532
528
K_BP
K_BP
0
10
10
.1
1
NIL
HORIZONTAL

MONITOR
1010
395
1067
440
NIL
C_BPM
3
1
11

SLIDER
535
460
707
493
T_AB
T_AB
0
10
3
.1
1
NIL
HORIZONTAL

MONITOR
1010
445
1067
490
time
ticks
3
1
11

SLIDER
350
290
522
323
T_BAM
T_BAM
0
10
1
.1
1
NIL
HORIZONTAL

SLIDER
350
325
522
358
T_BPM
T_BPM
0
10
3
.1
1
NIL
HORIZONTAL

SLIDER
360
530
532
563
K_BAM
K_BAM
0
10
10
.1
1
NIL
HORIZONTAL

SLIDER
360
565
532
598
K_BPM
K_BPM
0
10
10
.1
1
NIL
HORIZONTAL

SLIDER
350
45
522
78
theta_BA
theta_BA
0
1
0.5
0.1
1
NIL
HORIZONTAL

SLIDER
350
80
522
113
theta_BP
theta_BP
0
1
0.5
.1
1
NIL
HORIZONTAL

SLIDER
535
530
707
563
BAM_lwb
BAM_lwb
0
.1
0.0040
.001
1
NIL
HORIZONTAL

SLIDER
535
565
707
598
BPM_lwb
BPM_lwb
0
.1
0.02
.001
1
NIL
HORIZONTAL

SLIDER
710
530
882
563
BAM_upb
BAM_upb
0
.1
0.03
.001
1
NIL
HORIZONTAL

SLIDER
710
565
882
598
BPM_upb
BPM_upb
0
.1
0.09
.001
1
NIL
HORIZONTAL

SLIDER
535
495
707
528
S_upb
S_upb
0
1
0.8
.01
1
NIL
HORIZONTAL

SLIDER
710
495
882
528
K_phi
K_phi
0
1
1
.01
1
NIL
HORIZONTAL

SLIDER
710
390
882
423
K_ID
K_ID
0
1
1
0.01
1
NIL
HORIZONTAL

SLIDER
885
530
1057
563
psi
psi
0
10
1
0.1
1
NIL
HORIZONTAL

BUTTON
705
45
870
78
go for ...
repeat (read-from-string user-input \"How long?\") / delta-t\n[ step ]
NIL
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

BUTTON
890
385
1005
418
suspend movie
set recording-movie? false
NIL
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

BUTTON
890
420
1005
453
resume movie
set recording-movie? true
NIL
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

SLIDER
710
460
882
493
theta_LM
theta_LM
0
1
0.01
0.01
1
NIL
HORIZONTAL

SLIDER
710
425
882
458
K_TLM
K_TLM
0
10
5
0.1
1
NIL
HORIZONTAL

SLIDER
885
565
1057
598
theta_dID
theta_dID
0
100
20
1
1
NIL
HORIZONTAL

SLIDER
885
495
1057
528
K_LM
K_LM
0
100
100
1
1
NIL
HORIZONTAL

@#$#@#$#@
## WHAT IS IT?

To see how it works, select Setup then Cycle. You can change the display using the selector in the upper right.

(1) Original version.  
(2) Higher spatial resolution, restored padding on edges. Modified formula for S to ensure saturation. Default parameters defined.  
(3-4) Clock distributed to cells. Tail cells migrate according to a fixed vector, established at initialization. But putting this velocity just where T>0 means that the leading edge of the tailbud doesn't move, so we also have to do one patch to the left (a finite mesh problem).   
(6) Includes composite display option. Corrected initialization so first segment is a full cycle rather a half cycle.   
(7) Movie making added.  
(8) Adds marking of anterior and posterior borders of segments. This has to be separate from the diffusion of the anterior- and posterior-border morphogens. Marking the anterior border is not working, because cells generate A when they differentiate.  
(9) The premature generation of a A is blocked by a timer BA that starts when the differentiation signal passes. This results in correct marking of anterior and posterior borders of segments. Also added tick counter to show simulation time.  
(10) Added diffusion of BAM and BPM from anterior and posterion borders, but only in differentiated tissue. Further, if BAM and BPM are in specified bounds, then this leads to differentiation of imaginal regions in the middle of the segments. Space shortened to 350 to speed up simulations.  
(11) Imaginal region is created only on exterior surface of segment.  
(11 short) This has a shorter axis to allow quicker computation and more convenient generation of art of 5 segments for Turku presentation.  
(13) Impulses properly scaled. More comments added.  
(14) Separate clock (global) for segmentation of extremities. Display modified to preset A and P together.  
(15) Additional display options to aid movie production.  
(16) Mean computations on neighbors used in grow to avoid off-by-one/grid problems on IDs. Runs much slower!  
(17) Corrected divergence estimate uses double differences. Leads to "morphogenetic defects," perhaps because with the new divergence formula, the tail region breaks up into multiple bands. As a result, get segments with two posterior regions.  Doing growth with ask-concurrent eliminates banding, but the tail cells never fired! However, increasing theta_rho to 0.01 (from 0?) allowed phi to become non-zero. This seems to work correctly (as per 15). The default is theta_rho = 0.05, but this leads to banding, so I am using 0.01. Decreased theta_ID to 0.01. ID has to move along with the growing T cells. The limbs grow too rapidly. The spurious ID region immediately posterior to the anterior part of the segment tries to grow a leg. The BPM morphogen generated at the root of the leg seems to detach the leg by suppressing ID in the leg. I get banding in the legs, apparently from boundary effects when the leg reached the upper or lower limits of the space.  
(18) Wider and shorter space for making video.  
(19) Corrected and updated default-parameters to include default values actually in use. Individual cells have growth signals. Doesn't use Gp; need to make sure this is correct. Am getting doubled leg growth, anterior with alpha only at end, posterior (correct) with alpha along length. Part of the problem is that I am using ID for two purposes: to mark the imaginal disks on the surface of the trunk and to mark the growing limbs (as opposed to axis); in the latter case, ID moves down the limbs.  
(20) Separated functions of ID into ID, which just marks imaginal disks, and LM, the limb marker (which supplements T signal). Initial secretion on LM is triggered by a sufficiently rapid increase of ID, which marks initial differentiation of ID. LM propagates like T. This generates segmented limbs! The first pair is well-formed, the second is not, due to their growth from excessivley wide IDs. (Fast ID increase will also trigger initialization of growth timer for limb in a latr version.)  
(20w) Wider, to allow longer legs.

## HOW IT WORKS

A discrete-time discrete-space simulation of PDEs. The discretization is set by delta-t and delta-s parameters.

## HOW TO USE IT

This section could explain how to use the model, including a description of each of the items in the interface tab.

## THINGS TO NOTICE

This section could give some ideas of things for the user to notice while running the model.

## THINGS TO TRY

This section could give some ideas of things for the user to try to do (move sliders, switches, etc.) with the model.

## EXTENDING THE MODEL

This section could give some ideas of things to add or change in the procedures tab to make the model more complicated, detailed, accurate, etc.

## NETLOGO FEATURES

This section could point out any especially interesting or unusual features of NetLogo that the model makes use of, particularly in the Procedures tab.  It might also point out places where workarounds were needed because of missing features.

## RELATED MODELS

This section could give the names of models in the NetLogo Models Library or elsewhere which are of related interest.

## CREDITS AND REFERENCES

This section could contain a reference to the model's URL on the web if it has one, as well as any other necessary credits or references.
@#$#@#$#@
default
true
0
Polygon -7500403 true true 150 5 40 250 150 205 260 250

airplane
true
0
Polygon -7500403 true true 150 0 135 15 120 60 120 105 15 165 15 195 120 180 135 240 105 270 120 285 150 270 180 285 210 270 165 240 180 180 285 195 285 165 180 105 180 60 165 15

arrow
true
0
Polygon -7500403 true true 150 0 0 150 105 150 105 293 195 293 195 150 300 150

box
false
0
Polygon -7500403 true true 150 285 285 225 285 75 150 135
Polygon -7500403 true true 150 135 15 75 150 15 285 75
Polygon -7500403 true true 15 75 15 225 150 285 150 135
Line -16777216 false 150 285 150 135
Line -16777216 false 150 135 15 75
Line -16777216 false 150 135 285 75

bug
true
0
Circle -7500403 true true 96 182 108
Circle -7500403 true true 110 127 80
Circle -7500403 true true 110 75 80
Line -7500403 true 150 100 80 30
Line -7500403 true 150 100 220 30

butterfly
true
0
Polygon -7500403 true true 150 165 209 199 225 225 225 255 195 270 165 255 150 240
Polygon -7500403 true true 150 165 89 198 75 225 75 255 105 270 135 255 150 240
Polygon -7500403 true true 139 148 100 105 55 90 25 90 10 105 10 135 25 180 40 195 85 194 139 163
Polygon -7500403 true true 162 150 200 105 245 90 275 90 290 105 290 135 275 180 260 195 215 195 162 165
Polygon -16777216 true false 150 255 135 225 120 150 135 120 150 105 165 120 180 150 165 225
Circle -16777216 true false 135 90 30
Line -16777216 false 150 105 195 60
Line -16777216 false 150 105 105 60

car
false
0
Polygon -7500403 true true 300 180 279 164 261 144 240 135 226 132 213 106 203 84 185 63 159 50 135 50 75 60 0 150 0 165 0 225 300 225 300 180
Circle -16777216 true false 180 180 90
Circle -16777216 true false 30 180 90
Polygon -16777216 true false 162 80 132 78 134 135 209 135 194 105 189 96 180 89
Circle -7500403 true true 47 195 58
Circle -7500403 true true 195 195 58

circle
false
0
Circle -7500403 true true 0 0 300

circle 2
false
0
Circle -7500403 true true 0 0 300
Circle -16777216 true false 30 30 240

cow
false
0
Polygon -7500403 true true 200 193 197 249 179 249 177 196 166 187 140 189 93 191 78 179 72 211 49 209 48 181 37 149 25 120 25 89 45 72 103 84 179 75 198 76 252 64 272 81 293 103 285 121 255 121 242 118 224 167
Polygon -7500403 true true 73 210 86 251 62 249 48 208
Polygon -7500403 true true 25 114 16 195 9 204 23 213 25 200 39 123

cylinder
false
0
Circle -7500403 true true 0 0 300

dot
false
0
Circle -7500403 true true 90 90 120

face happy
false
0
Circle -7500403 true true 8 8 285
Circle -16777216 true false 60 75 60
Circle -16777216 true false 180 75 60
Polygon -16777216 true false 150 255 90 239 62 213 47 191 67 179 90 203 109 218 150 225 192 218 210 203 227 181 251 194 236 217 212 240

face neutral
false
0
Circle -7500403 true true 8 7 285
Circle -16777216 true false 60 75 60
Circle -16777216 true false 180 75 60
Rectangle -16777216 true false 60 195 240 225

face sad
false
0
Circle -7500403 true true 8 8 285
Circle -16777216 true false 60 75 60
Circle -16777216 true false 180 75 60
Polygon -16777216 true false 150 168 90 184 62 210 47 232 67 244 90 220 109 205 150 198 192 205 210 220 227 242 251 229 236 206 212 183

fish
false
0
Polygon -1 true false 44 131 21 87 15 86 0 120 15 150 0 180 13 214 20 212 45 166
Polygon -1 true false 135 195 119 235 95 218 76 210 46 204 60 165
Polygon -1 true false 75 45 83 77 71 103 86 114 166 78 135 60
Polygon -7500403 true true 30 136 151 77 226 81 280 119 292 146 292 160 287 170 270 195 195 210 151 212 30 166
Circle -16777216 true false 215 106 30

flag
false
0
Rectangle -7500403 true true 60 15 75 300
Polygon -7500403 true true 90 150 270 90 90 30
Line -7500403 true 75 135 90 135
Line -7500403 true 75 45 90 45

flower
false
0
Polygon -10899396 true false 135 120 165 165 180 210 180 240 150 300 165 300 195 240 195 195 165 135
Circle -7500403 true true 85 132 38
Circle -7500403 true true 130 147 38
Circle -7500403 true true 192 85 38
Circle -7500403 true true 85 40 38
Circle -7500403 true true 177 40 38
Circle -7500403 true true 177 132 38
Circle -7500403 true true 70 85 38
Circle -7500403 true true 130 25 38
Circle -7500403 true true 96 51 108
Circle -16777216 true false 113 68 74
Polygon -10899396 true false 189 233 219 188 249 173 279 188 234 218
Polygon -10899396 true false 180 255 150 210 105 210 75 240 135 240

house
false
0
Rectangle -7500403 true true 45 120 255 285
Rectangle -16777216 true false 120 210 180 285
Polygon -7500403 true true 15 120 150 15 285 120
Line -16777216 false 30 120 270 120

leaf
false
0
Polygon -7500403 true true 150 210 135 195 120 210 60 210 30 195 60 180 60 165 15 135 30 120 15 105 40 104 45 90 60 90 90 105 105 120 120 120 105 60 120 60 135 30 150 15 165 30 180 60 195 60 180 120 195 120 210 105 240 90 255 90 263 104 285 105 270 120 285 135 240 165 240 180 270 195 240 210 180 210 165 195
Polygon -7500403 true true 135 195 135 240 120 255 105 255 105 285 135 285 165 240 165 195

line
true
0
Line -7500403 true 150 0 150 300

line half
true
0
Line -7500403 true 150 0 150 150

pentagon
false
0
Polygon -7500403 true true 150 15 15 120 60 285 240 285 285 120

person
false
0
Circle -7500403 true true 110 5 80
Polygon -7500403 true true 105 90 120 195 90 285 105 300 135 300 150 225 165 300 195 300 210 285 180 195 195 90
Rectangle -7500403 true true 127 79 172 94
Polygon -7500403 true true 195 90 240 150 225 180 165 105
Polygon -7500403 true true 105 90 60 150 75 180 135 105

plant
false
0
Rectangle -7500403 true true 135 90 165 300
Polygon -7500403 true true 135 255 90 210 45 195 75 255 135 285
Polygon -7500403 true true 165 255 210 210 255 195 225 255 165 285
Polygon -7500403 true true 135 180 90 135 45 120 75 180 135 210
Polygon -7500403 true true 165 180 165 210 225 180 255 120 210 135
Polygon -7500403 true true 135 105 90 60 45 45 75 105 135 135
Polygon -7500403 true true 165 105 165 135 225 105 255 45 210 60
Polygon -7500403 true true 135 90 120 45 150 15 180 45 165 90

sheep
false
0
Rectangle -7500403 true true 151 225 180 285
Rectangle -7500403 true true 47 225 75 285
Rectangle -7500403 true true 15 75 210 225
Circle -7500403 true true 135 75 150
Circle -16777216 true false 165 76 116

square
false
0
Rectangle -7500403 true true 30 30 270 270

square 2
false
0
Rectangle -7500403 true true 30 30 270 270
Rectangle -16777216 true false 60 60 240 240

star
false
0
Polygon -7500403 true true 151 1 185 108 298 108 207 175 242 282 151 216 59 282 94 175 3 108 116 108

target
false
0
Circle -7500403 true true 0 0 300
Circle -16777216 true false 30 30 240
Circle -7500403 true true 60 60 180
Circle -16777216 true false 90 90 120
Circle -7500403 true true 120 120 60

tree
false
0
Circle -7500403 true true 118 3 94
Rectangle -6459832 true false 120 195 180 300
Circle -7500403 true true 65 21 108
Circle -7500403 true true 116 41 127
Circle -7500403 true true 45 90 120
Circle -7500403 true true 104 74 152

triangle
false
0
Polygon -7500403 true true 150 30 15 255 285 255

triangle 2
false
0
Polygon -7500403 true true 150 30 15 255 285 255
Polygon -16777216 true false 151 99 225 223 75 224

truck
false
0
Rectangle -7500403 true true 4 45 195 187
Polygon -7500403 true true 296 193 296 150 259 134 244 104 208 104 207 194
Rectangle -1 true false 195 60 195 105
Polygon -16777216 true false 238 112 252 141 219 141 218 112
Circle -16777216 true false 234 174 42
Rectangle -7500403 true true 181 185 214 194
Circle -16777216 true false 144 174 42
Circle -16777216 true false 24 174 42
Circle -7500403 false true 24 174 42
Circle -7500403 false true 144 174 42
Circle -7500403 false true 234 174 42

turtle
true
0
Polygon -10899396 true false 215 204 240 233 246 254 228 266 215 252 193 210
Polygon -10899396 true false 195 90 225 75 245 75 260 89 269 108 261 124 240 105 225 105 210 105
Polygon -10899396 true false 105 90 75 75 55 75 40 89 31 108 39 124 60 105 75 105 90 105
Polygon -10899396 true false 132 85 134 64 107 51 108 17 150 2 192 18 192 52 169 65 172 87
Polygon -10899396 true false 85 204 60 233 54 254 72 266 85 252 107 210
Polygon -7500403 true true 119 75 179 75 209 101 224 135 220 225 175 261 128 261 81 224 74 135 88 99

wheel
false
0
Circle -7500403 true true 3 3 294
Circle -16777216 true false 30 30 240
Line -7500403 true 150 285 150 15
Line -7500403 true 15 150 285 150
Circle -7500403 true true 120 120 60
Line -7500403 true 216 40 79 269
Line -7500403 true 40 84 269 221
Line -7500403 true 40 216 269 79
Line -7500403 true 84 40 221 269

x
false
0
Polygon -7500403 true true 270 75 225 30 30 225 75 270
Polygon -7500403 true true 30 75 75 30 270 225 225 270

@#$#@#$#@
NetLogo 5.0.5
@#$#@#$#@
@#$#@#$#@
@#$#@#$#@
@#$#@#$#@
@#$#@#$#@
default
0.0
-0.2 0 0.0 1.0
0.0 1 1.0 0.0
0.2 0 0.0 1.0
link direction
true
0
Line -7500403 true 150 150 90 180
Line -7500403 true 150 150 210 180

@#$#@#$#@
1
@#$#@#$#@
