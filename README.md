# Maze-Solver
This project is a Maze Solver application developed in C++, which utilizes the Breadth-First Search (BFS) algorithm to find the shortest path from a user-defined start point to an end point in a maze represented by a 2D grid. The application features interactive input for maze dimensions and allows users to construct their own mazes with dynamic start and end points.

**Features**
Efficient Path Finding: Implements the Breadth-First Search (BFS) algorithm to ensure the shortest path is found.
User-Defined Points: Users can specify their own start and end points within the maze.
Interactive Input: Users can input the dimensions of the maze interactively.
Custom Maze Construction: Users can build their own maze by defining each cell as either a path (0) or a wall (1).
Robust Input Validation: Ensures that start and end points are within bounds and not walls, prompting users to re-enter invalid inputs.

**Input Instructions:**

Enter the number of rows and columns for the maze.
Input the maze row by row, using 0 for paths and 1 for walls.
Specify the start point (row and column).
Specify the end point (row and column).

**Example**

Enter the number of rows in the maze: 5
Enter the number of columns in the maze: 5
Enter the maze row by row (0 for path, 1 for wall):
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0
0 1 1 1 0
0 0 0 0 0
Enter the start point (row and column): 0 0
Enter the end point (row and column): 4 4

**Output**
The application will print the maze with the path marked from the start (S) to the end (E), using * to denote the path:

S # . . .
. # . # .
. . . # .
. # # # .
. . . . E










