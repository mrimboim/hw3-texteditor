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