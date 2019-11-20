# Lem-in
Finds the shortest path or combination of paths to get ants across a graph.

Quickest way means the solution with the least number of lines, respecting the output format requested below.

There are some basic constraints. To be the first to arrive, ants will need to take the shortest path. They will also need to avoid traffic jams as well as walking all over their fellow ants. Each room can only contain one ant at a time.

At the beginning of the game, all the ants are in the room ##start. The goal is to bring them to the room ##end with as few turns as possible.

# Objectives
The program receives a file or data from the standard output in the format:
1. Number_of_ants
2. Room_with_x_and_y_coordinates
3. Links_between_rooms

**Input example of a map:**<br>
```
6
##start
S 0 4
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
T 9 4
6-5
6-T
6-4
6-3
#another comment
5-T
5-3
4-3
4-S
3-S
#another comment
```
**Output example:**<br>
```
lem-in will print input map and the moves after a line break

L1-4 L2-3
L1-6 L3-4 L2-5 L4-3
L1-T L3-6 L5-4 L2-T L4-5 L6-3
L3-T L5-6 L4-T L6-5
L5-T L6-T
```

Where L1, L2, L... refers to an ant name

# Building
```
$ make && ./lem-in < file.map
```

#### To run the test
```
$ cd test;sh test.sh -all
```
