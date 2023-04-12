# Big Square Problem Solver in C

This program is a solution to the big square problem, which consists of finding the biggest square possible in a given map filled with obstacles.

The program is written in C and was developed as part of the 42 Piscine, a coding bootcamp focused on teaching the basics of programming in a short amount of time.

## Installation
To use this program, you first need to download the source code. You can do this by cloning the repository:

```
git clone https://github.com/yourusername/big-square-problem-solver.git
```
Once you have the source code, you can compile the program by running make

## Usage
The program takes a file as input, which contains the map with obstacles. The file should have the following format:

The first line should contain one integer (number of lines) and the codification (eg: 9.ox would be 9 lines, '.' would be a free space, 'o' and obstable and 'x' the square representation). The remaining lines should contain the map itself.
Here is an example of a valid input file: 
```
9.ox
.........
......o..
.........
.........
.........
.........
.........
o........
.........
```
To run the program with the input file (here shown as map), use the following command:
```
./bsq map
```
The program will output the map with the biggest square found, represented by the defined char in the file.
```
 . . . . . . . . .
 . . . . . . o . .
 . x x x x x x x .
 . x x x x x x x .
 . x x x x x x x .
 . x x x x x x x .
 . x x x x x x x .
 o x x x x x x x .
 . x x x x x x x .
```
_(Note that a space is printed between chars to make the square clearer)_

To run the perl map generator, use the next command (where 9 9 means x and y and 1 is the obstacle density):
```
perl perlMapGenerator 9 9 1
```

Or redirect the output to a file with the name of your choice:
```
perl perlMapGenerator 9 9 1 > map
```
## Algorithm
The algorithm used to find the biggest square is based on brute force. It works as follows:

We create a matrix with the same dimensions as the input map, and copy each char on it.
For each cell in the input map, we check if it is an obstacle or not.
If it is an obstacle, we skip the cell.
If it is not an obstacle, we assume that cell as the bottom right corner fo our square. Then we keep substracting 1 to both x and y, getting a top left cell for the square each time. We check that the upper left border doesnt contain an obstacle (the inner and bootom right cells would have been checked in previous iterations), and we keep moving the top left corner until an obstacle or the map border is hit. Once we hit something, we check if the side of the square is bigger than the previous biggest side. If so, we save the 'x, y' values of the new biggest square's bottom right corner, and the side size. After we check the last cell, we draw a side size square from 'x, y' bottom right corner and print the result.

## Credits
This program was written by sacorder and abimassap as part of the 42 Piscine. If you have any questions or suggestions, feel free to contact me at sacorder@student.42madrid.com


