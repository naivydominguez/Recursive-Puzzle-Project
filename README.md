# Cryptarithmetic Puzzle Solver

A C++ program that solves cryptarithmetic puzzles using recursive backtracking.
Cryptarithmetic puzzles replace digits with letters in arithmetic equations. 
The goal is to determine which digit each letter represents so that the equation is mathematically correct.

Example puzzle:
SEND + MORE = MONEY
Each letter represents a unique digit (0–9).

## Features

- Solves addition-based cryptarithmetic puzzles
- Uses recursive backtracking to explore possible digit assignments
- Ensures each letter maps to a unique digit
- Prevents leading characters from being assigned zero
- Supports puzzles with up to 10 unique characters

## Example Input

Enter word 1: SEND  
Enter word 2: MORE  
Enter result: MONEY

## Example Output

°❀⋆.ೃ࿔*:･ Solution Found! ◝(ᵔᗜᵔ)◜ °❀⋆.ೃ࿔*:･"
SEND + MORE = MONEY  
9567 + 1085 = 10652

## Algorithm Overview

The program uses a recursive backtracking approach:

1. Extract all unique characters from the input words.
2. Assign digits (0–9) to characters.
3. Ensure no leading letter is assigned zero.
4. Recursively test all valid digit combinations.
5. Evaluate whether the equation is satisfied.

If a valid mapping is found, the program prints the solution.

## Technologies Used

- C++
- Recursion
- Backtracking algorithms
- STL containers:
  - unordered_map
  - unordered_set
  - vector

## How to Run

Compile the program:
g++ puzzle_solver.cpp -o solver
Run the executable:
./solver
Then enter the words for the puzzle.

## Example Puzzles to Try

SEND + MORE = MONEY  
BASE + BALL = GAMES  
TWO + TWO = FOUR
