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
Here is an example of a valid input file: <br />
9.ox <br />
.......... <br />
.......... <br />
..oooo.... <br />
..oooo.... <br />
..oooo.... <br />
..oooo.... <br />
..oooo.... <br />
..oooo.... <br />
.......... <br />
<br />
To run the program with the input file, use the following command:
```
./bsq input_file
```
The program will output the map with the biggest square found, represented by the defined char in the file.

## Algorithm
The algorithm used to find the biggest square is based on dynamic programming. It works as follows:

We create a matrix with the same dimensions as the input map, initialized to 0.
For each cell in the input map, we check if it is an obstacle or not.
If it is an obstacle, we set the corresponding cell in the matrix to 0.
If it is not an obstacle, we set the corresponding cell in the matrix to the minimum of the three cells above, to the left, and diagonally above and to the left, plus 1.
We keep track of the biggest square found so far, and its position in the map.
Once we have processed all the cells, we mark the biggest square found by setting its cells to x's in the output map.

## Credits
This program was written by sacorder and abimassap as part of the 42 Piscine. If you have any questions or suggestions, feel free to contact me at sacorder@student.42madrid.com


