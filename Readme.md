# ***HW3 Notes ECS36c***<!-- omit in toc --> 
- [Questions](#questions)
  - [2/10](#210)
- [Notes](#notes)
  - [2/10](#210-1)
- [To-do](#to-do)
  - [Now](#now)
  - [Soon](#soon)
  - [Later](#later)
- [Brainstorms](#brainstorms)

# Questions

## [2/10](#210-1)

- big question of the day, how to do undo and redo ? 

# Notes

## [2/10](#210)

-  Use smart pointers instead of regular pointers -> test with valgrind at the end


# To-do

## Now  

- [ ] 

## Soon 

- [ ] 

## Later 

- [ ] 

# Brainstorms 


- need an input function that takes in the input and sets the var last input that way if an empty thing is entereted the last command is repeated  A


- **Opening the file** 
  - file is a command line arg with input validation for num args
  - Following constraints
    - file cant be opened -> error msg
    - file has more than 30 lines (31 or greater inclusive)
    - one line has more then 20 charcters not counting newline (21 or greater inclusive not counting new line)
    - 


- **Moving around the file** 
 - vector of vectors, we can use size of vector for several things,
 - size of each vector plus each other can be useful to see if its possible to insert stuff
 - vector of main thing gives number of lines 
 - size of other vectors or string vectors gives the number of charcters 

  -for moving around we can think of it like a matrix where the a d left right is the coulmn number 
  - the line number is the row number 

  - if the size of the line is zero or 1 based on new line then we dont put a | 



- **insertions** 


- **undo redo** 
 - rough ideas: use two stacks, when a undo is done, the top of undo stack is pusshed onto redo stack, this can continue until undo stack is empty or until a new operation is done in which case redo stack is erased
 - maybe keep a counter of the stack size

- **saving the file before closing/closing the file** 
  - get stack size at save, if save is tried again see if the stack size is diffrent prompt to save before quitting 



- WHICH libraries do i need
  - #include <iostream>
  - #include <iomanip>
  - #include <ostream>
  - #include <stdio.h>=
  - #include <stdlib.h>
  - #include <string.h>
  - #include <fstream>
  - #include <stack>
  - #include <vector>

- FUNCTIONS
  - need a display buffer function
    - (use the coulmn and row to update things every time enter is pressed) 
    - For the actual display you could maybe do like a cout where you do strings like `if(currentrow == row(i)) "*" + i + 
  - need a open file and validate function 
  - need a main function with args and validation and a loop
  - need an input function that can check if there is a previous command, and also do some validation on input data
    - calls other commands based on input and calls display buffer after command is called  
  - save file function (checks if file exists and overwrites it or creates new one)
  - quit function (with some understanding of save file and stack size for keeping track of changes)
  - undo redo funcs (with ability to interact with buffer and both stacks)
  - move functions
    - can update row and coulmns and look at input to check if number is there so they know by how much to do something
    - 
  - insert function (looks at coulmns and row and then starts changing things in the vector until it needs to move to another vector each vector it uses it pushes it to a data structre that holds x number of vectors before a change) - need to see how getline works to see if i need a data structre to properly have | charcter pop up 
  - 

-variables 
  - vector of string vectors function (need to see how getline works first huh) 
  - undo and redo stack and previous undo stack size var (if no time you can just push the etire vec of vecs instead of specififc vecs)
  - row and coulmn vars
  - previous command var 