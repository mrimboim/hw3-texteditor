# ***HW3 Notes ECS36c***<!-- omit in toc --> 
- [Questions](#questions)
  - [2/10](#210)
- [Notes](#notes)
  - [2/10](#210-1)
  - [2/11](#211)
- [To-do](#to-do)
  - [Now](#now)
  - [Soon](#soon)
  - [Later](#later)
- [Brainstorms](#brainstorms)

# Questions

## [2/10](#210-1)

- big question of the day, how to do undo and redo ? 

- does trailing whitespace matter ????

# Notes

## [2/10](#210)

-  Use smart pointers instead of regular pointers -> test with valgrind at the end

- g++	-g -Wall -Werror -std=c++14 editor.cpp -o editor

- for openFile 
  - 0 is good 
  - 1 couldnt open file
  - 2 too manny lines
  - 3 too many charcters for a line
    - 1 2 3 print msg in main and terminate 


## [2/11](#211)
- heap and stack grow towards each other 
1 grows to 2000  stack 4000 and grows 2000 for stack and heap for allocated mem
-stack can hold pointer to a space in stack that store dynamic mem alloc from malloc ->which is in heap
-stack stores the locally scoped var
-global vars are stored in data section 
  


# To-do

## Now  

- [ ] 

## Soon 

- [ ]  test display function 

## Later 

- [ ] find a way to make the window tops and bottoms automatically created from max width 

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
g++ -g -Wall -Werror -std=c++14 editor.cpp -o editor


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
    - you can use the size of main vector to see where the delimiter | should be 
    - use setw and look at ecs50 project for refrence 


  - need a open file and validate function 
    - opens file, reads lines into data structre, validates data, closes file
    -  
  - need a main function with args and validation and a loop
  - 
  - need an input function that can check if there is a previous command, and also do some validation on input data
    - calls other commands based on input and calls display buffer after command is called
    -   
  - save file function (checks if file exists and overwrites it or creates new one)
  - 
  - quit function (with some understanding of save file and **stack size** for keeping track of changes)
  - 
  - undo redo funcs (with ability to interact with buffer and both stacks)
  - 
  - move functions
    - can update row and coulmns and look at input to check if number is there so they know by how much to do something
    - **idea** *to move down add to row, if row already at nine add to topLine until it equals buffer.size, then for every addtional move down add one to topLine and subtract one from row until buffer.size == topLine in which case youve reached the end of possible down movment*
    - 
  - insert function (looks at coulmns and row and then starts changing things in the vector until it needs to move to another vector each vector it uses it pushes it to a data structre that holds x number of vectors before a change) - need to see how getline works to see if i need a data structre to properly have | charcter pop up 
  - 

-variables 
  - vector of string vectors function (need to see how getline works first huh) 
  - undo and redo stack and previous undo stack size var (if no time you can just push the etire vec of vecs instead of specififc vecs)
  - row and coulmn vars
  - topLine so that you can use it to move the display based on top line and row, also useful so you can set topline to size of vector and then after print empty things
  - previous command var you can use string.empty for prev command thing


1 [1 2 3]
2 [4 5 6]
3 [7 8 9]

1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 

$rdi -> input 1 index 0 -> find a way to increment to find correct index based on rows and colms

1 4 7 2 5 8 3 6 9

$rcx -> index 0 -> first element of output matrix -> increment by 1 each time

output row ++

3 row 
2 col

0 0 

1 [1 3 5]
2 [2 4 6]

1 3 5 2 4 6


stack 
bla blabla
call scanf
mov (%rsp), whatever 


i r 
backtrace 
continue 
n 


input function 
 - w 10 
 - r 
 - ribbion 
 - ribion_
 - save
 - w_
 - w__
 - w 10_
 - w 10__
 - i
 - i_asdkf asdf asdf asdf sadf asdf asdf_

insert
save 
q 
u 
r 

w number 

if first letter is recognized (q, s, w, a, s, d, i, r, u) 
->if size is 1 pass it to correct funtion, if extra params needed pass error 
->if size greater then 1 
    -if find " " is greater then size of string(if not save then say string is not valid input)
    -if 