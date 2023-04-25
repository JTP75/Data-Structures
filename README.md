# Data-Structures
University of Pittsburgh ECE 0302

## Brief
Formulating and structuring data using OOP in C++/CMake on Ubuntu (Virtual Machine and Linux Partition). 

## Semester
Summer 2022

# Projects
## Project 1 - Bit Set
Implementing a simple bitset data structure in C++.
* Header: bitset.hpp
* Implementation: bitset.tpp
* Testbench: bitset_test.cpp
## Project 2 - Finding Palindromes
Object oriented approach to palindrome detection algorithms.
* Header: FindPalindrome.hpp
* Implementation: FindPalindrome.cpp
* Testbench: FindPalindrome_test.cpp
## Project 3 - Parsing XML
Using OOP to tokenize and parse XML. Also implemented a stack and a bag using a common node class.
* Node: Node.hpp, Node.tpp
* Bag: Bag.hpp, Bag.tpp
* Stack: Stack.hpp, Stack.tpp, mainStack.cpp
* XMLParser: XMLParser.hpp, XMLParser.cpp, mainXMLParser.cpp
* Testbench: XMLParser_test.cpp
## Project 4 - Pathfinder
Find optimal solutions to large mazes. My solver employs a breadth-first search algorithm.
* Abstract type conformities: abstract_list.hpp, abstract_queue.hpp
* Queue: queue.hpp, queue.tpp, queue_test.cpp
* List: DynamicArrayList.hpp, DynamicArrayList.tpp
* Maze: Maze.hpp, Maze.cpp (container for maze data)
* Problem: Problem.hpp, Problem.cpp (state-based container for maze class)
* Main: pathfinder.cpp
* Results: tests directory
## Project 5 - Puzzle Solver
Write a program to optimally solve a 3x3 sliding tile puzzle. Implemented by evaluating path, heuristic, and goal costs in a frontier queue.
* Frontier Queue: frontier_queue.hpp, frontier_queue.tpp
* Puzzle Solver: puzzle_solver.hpp, puzzle_solver.cpp
* Testbenches: test_frontier_queue.cpp, test_solver.cpp
## Bonus Project - Database
Implement a fully functional database using trees and lists.
* Binary Search Tree: binary_search_tree.hpp, binary_search_tree.tpp
* List (inherits from abstract list): list.hpp, list.tpp
* Database: Database.hpp, Database.tpp
* Testbench: test_database.cpp
