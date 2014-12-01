## Variables  - variable name declarations (type name initial_value)
scalar box1 0
scalar box2 0
vector vect 1

## Constants - (dt=timestep[seconds]) need ranges for sliders, cannot use x,y,z
t 0
dt .01
k 2.0
tau .01

## Ranges - for x y and z
x 0 10 dim
y 0 10 dim
z 0 10 dim
box1 0 110 show
box2 0 110 show
dt .001 1 show
k 0.1 5.0 show
tau 0.1 5.0 show

## Equation definitions (available operators: lapacian, etc)
vect = vect + .01
t=t+dt

## files with initial values listed belowS
initial_test.txt
