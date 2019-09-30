# Lem-in
Guides an ant colony through a graph.

# Objectives
The program receives a file or data from the standard output in the format:
1. Number_of_ants
2. Room_with_x_and_y_coordinates
3. Links_between_rooms

##### Example input:<br>
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

##### Example output:<br>
First it will print input map and the moves after the line break<br>

L1-4 L2-3<br>
L1-6 L3-4 L2-5 L4-3<br>
L1-T L3-6 L5-4 L2-T L4-5 L6-3<br>
L3-T L5-6 L4-T L6-5<br>
L5-T L6-T<br>
