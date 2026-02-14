[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/rwwm5TnE)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=22683225&assignment_repo_type=AssignmentRepo)
# Week 4 Wed Lab

## Directions

You will be finishing the implementation of the DoublyList ADT as a linked list. The `DoublyList` abstract class is already given to you, along with the header file for the `DoublyList` class, and a skeleton of its implementation file. Many of the operations are already done for you. Your task is to complete the remaining three methods marked TO DO.

## Do not edit the driver.cpp file

You are also in charge of writing your own driver program to test your `DoublyList` class more extensively and submit the output to canvas. Be thorough with your testing by checking all the operations in different scenarios and with various data types. You can call your driver file any name (except don't use driver.cpp)

## Notes

- If you notice you are writing the same code (for example, get a node at a particular position in several methods then create a new method getNode to use everywhere. You need to edit the .hpp file  to include prototype and .tpp file for implementation. 
  
```C++
// return the node at the given position (argument)
Node* getNode(int) const;
```
- The `<<` stream insertion operator has been overloaded for the `DoublyList` class, meaning you can use `cout` on your `DoublyList` object to print out the nodes inside
