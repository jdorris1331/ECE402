## Variables  - variable name declarations (type name initial_value)
vector var1 0
scalar var2 1
scalar var3 0

## Constants - (dt=timestep[seconds]) need ranges for sliders, cannot use x,y,z
t = 0
dt .01
k 2.0

## Ranges - for x y and z
x 0 10 dim
y 0 10 dim
z 0 10 dim
var1 20 30 warn
var1 25 27 show
var2 3.3 3.5 warn
var2 3 4 show
dt .001 1 show


## Equation definitions (available operators: lapacian, etc)
dvar1 = grad(var1)+y
var1 = var1 + dvar1


## files with initial values listed belowS
initial.txt
