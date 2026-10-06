# Drunken bishop algorithm
It is a data visualization algorithm used mainly by OpenSSH to visualize key fingerprints.  
Even though it is very easy, I find it extremely cool and satisfying.  

## Algorithm

The algorithm is:
* Created a board (in my example - 17x17)
* Every board cell is set a value of 0 and starting point marked as S
* The bishop is placed in the middle of a board of any size (i chose 17x17)
* Input data is read two bits at a time from least significant to most significant
* The moves of the bishop are determined by the bit combinations: 00 - Up Left, 01 - Up Right, 10 - Down Left, 11 - Down Right
* Bishop moves only one cell at a time and when it lands on the cell - value of the cell increments by 1
* When data is finished processing, end position is marked with E
* Board is displayed by reading each cell's value on the board and assigning a symbol from the array to the screen.  
  Display symbols are taken from this array:  
   ` [ ' ', '.', 'o', '+', '=', '*', 'B', 'O', 'X', '@', '%', '&', '#', '/', '^' ]`

> If bishop can't move in a certain direction, it doesn't move. For example if it is located in \[0,0\],
> but the command is 01, it doesn't move up, but moves to the right, allowing it to slide.

> If the value in the cell is larger than last index of the symbols array,
> the last element of the array is displayed anyways because it is the "strongest"

## Building

To build this thing you will need just a C++ compiler

```bash
clang++ -o drunken-bishop main.cpp
```

Run it with input as the first argument, or pass it through stdin
