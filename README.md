# Quiz 2 DAA Water Jug Problem

## Problem :
Water jug problems are a class of puzzle involving a finite collection of water jugs of known integer capacities (in terms of a liquid measure such as liters or gallons). Initially each jug contains a known integer volume of liquid, not necessarily equal to its capacity. Puzzles of this type ask how many steps of pouring water from one jug to another (until either one jug becomes empty or the other becomes full) are needed to reach a goal state, specified in terms of the volume of liquid that must be present in some jug or jugs.
Initial State : (0,0)
For example :
Volume of jug A : jugA
Volume of jug B : jugB
The water in jug A : wtrA
The water in jug B : wtrB

### Rules :
Fill the jug A from the faucet (wtrA = jugA)
Fill the jug B from the faucet (wtrB = jugB)
Empty the jug A (wtrA = 0)
Empty the jug B (wtrB = 0)
Pour water from jug A to the jug B until its empty
if wtrA + wtrB <= jugB then wtrB = wtrA + wtrB , wtrA = 0
if wtrA + wtrB > jugB then wtrB = jugB , wtrA = wtrA - (jugB - wtrB)
Pour water from  jug B to the jug A until its empty
if wtrA + wtrB <= jugA then wtrA = wtrA + wtrB , wtrB = 0
if wtrA + wtrB > jugA then wtrA = jugA , wtrB = wtrB - (jugA - wtrA)





### Term :
Fill the jug A from the faucet (wtrA < jugA), wtrA cannot exceed the jugA
Fill the jug B from the faucet (wtrB < jugB), wtrB cannot exceed the jugB
Empty the water from jug A (wtrA > 0), wtrA must be greater than 0 (not empty)
Empty the water from jug B (wtrB > 0), wtrB must be greater than 0 (not empty)
Fill the jug B with the jug A until its empty (wtrA > 0 and wtrB < jugB), wtrA must be greater than 0 (not empty) and wtrB must be lower than jugB (not full)
 Fill the jug A with the jug B until its empty (wtrB > 0 and wtrA < jugA), wtrB must be greater than 0 (not empty) and wtrA must be lower than jugA (not full)

## Illustrations

![alt text](https://i.postimg.cc/0N5mx4nX/guci.png)


## Anggota Kelompok
### Abdun Nafi 05111940000066
### Rizqi Rifaldi 05111940000068
### Naufaliando Yudo Kusumo 05111940000169
