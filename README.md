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

**Example input:**<br>
6<br>
##start<br>
S 0 4<br>
#comment<br>
3 16 3<br>
4 16 5<br>
5 9 3<br>
6 1 5<br>
7 4 8<br>
##end<br>
T 9 4<br>
6-5<br>
6-T<br>
6-4<br>
6-3<br>
#another comment<br>
5-T<br>
5-3<br>
4-3<br>
4-S<br>
3-S<br>
#another comment

**Example output:**<br>
lem-in will print input map and the moves after the line break<br>

L1-4 L2-3<br>
L1-6 L3-4 L2-5 L4-3<br>
L1-T L3-6 L5-4 L2-T L4-5 L6-3<br>
L3-T L5-6 L4-T L6-5<br>
L5-T L6-T<br>

Where L1, L2, L... refers to an ant name

# Building
`make && ./lem-in < file.map`

#### To run the test
`cd test;sh test.sh -all`
