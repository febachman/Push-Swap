*This project has been created as part of the 42 curriculum by <fbachman> & <made-luc>*

# push_swap

## Description
This project centers on sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. At its core, this assignment serves as a practical deep dive into **algorithmic complexity**, data structures (specifically doubly linked lists), and optimization strategies under strict operation constraints.

## Overview
The primary objective of **push_swap** is to code an executable that calculates and displays on the standard output the minimum instruction set required to sort an array of integers. 

The program works with two stacks: **Stack A** (which begins with a random amount of negative and/or positive integers without duplicates) and **Stack B** (which starts empty).

This project introduces foundational computer science concepts:
* **Algorithmic Selection:** Matching stack configurations with specific sorting behaviors (e.g., Bubble Sort, Three-element math, or Chunk-based Sorting).
* **Dynamic Complexity Analysis:** Optimizing loops and minimizing rotation choices to stay well below the 42 project thresholds.
* **Architecture Integrity:** Safely interacting with abstract memory concepts without modifying core header structures or corrupting team parsing code.

### Adaptive Strategy & Performance Thresholds
This repository features an intelligent **Adaptive Strategy** that profiles the layout of the integers before running. It computes an operational disorder metric and routes execution automatically:
* **Small Stacks ($\leq 5$ elements):** Handled via optimized hardcoded logic (`sort_three`, `sort_five`).
* **Low Disorder ($< 20\%$ mistakes):** Handled via an ultra-lightweight list traversal (`ft_bubble_sort`).
* **High Disorder / Large Stacks (100 to 500+ elements):** Managed by our custom mathematical **Chunk Sort** algorithm.

---

## Algorithm & Data Structure Justification

The core challenge of large stacks is avoiding $O(n^2)$ rotation costs. Instead of searching for absolute minimums one by one, our **Chunk Sort** algorithm splits the numbers into distinct ranges based on their size and moves them via controlled entropy.

* **The Doubly Linked List Structure:** Stack modifications (`pa`, `pb`, `ra`, `rra`) require $O(1)$ constant pointer swapping. This ensures that memory management never bogs down the operating speed of the execution lifecycle.
* **On-the-Fly Indexing:** To avoid modifying the core `t_node` struct and risking dependency errors with team parsing files, this algorithm calculates **global ranks on the fly**. It queries both stacks dynamically to establish absolute sizing metadata without saving temporary markers to headers.

### The Hourglass/Butterfly Effect Mechanics (Phase 1)
When pushing from Stack A to Stack B, the algorithm calculates a sliding window size driven by a custom mathematical scaling formula:

$$\text{chunk\_size} = \sqrt{n} \times 1.5 + (n \times 0.01)$$

* **Lower Window Segment:** If an item fits the lower half of the sliding boundary, it is pushed to Stack B and immediately rotated (`ft_rb`).
* **Upper Window Segment:** If an item fits the upper half of the boundary, it is simply pushed (`ft_pb`).

This structural distribution forces smaller values to the bottom of Stack B and larger values to the top, forming an organized **hourglass shape**. This controlled distribution guarantees that returning items to Stack A later remains extremely cheap.

### Step-by-Step Logic

1. **Analysis (`ft_compute_disorder`):** The program scans the initial input array to assess the percentage of inversion pairs and assigns an appropriate execution strategy.
2. **Phase One (`ft_phase_one`):** Large datasets are streamed from Stack A into Stack B using the dynamic square-root chunk multiplier, forming a dual-layered hourglass shape.
3. **Phase Two (`ft_phase_two`):** The program scans Stack B to find the absolute maximum global rank position, calculates the shortest rotation path (`rb` vs `rrb`), brings it to the top, and pushes it perfectly sorted back to Stack A.

---

## Instructions

### Compilation & Installation

The project includes a robust, automated dependency tracking Makefile that compiles an executable binary alongside your `libft` library.

To compile the program, clone the repository and run:
```bash
make
Repository Structure
The project architecture keeps sorting algorithms cleanly separated from node manipulation routines:

op_pop_node.c / op_push.c / op_rotate.c / op_swap.c (Stack Manipulations)

parse_main.c / parse_args.c / parse_flags.c (Input Validation)

sort_disorder_metric.c (Strategy Orchestrator)

sort_medium.c (The Hyrbid Chunk Sorting Codebase)

Usage & Examples
To execute the program, pass a random list of unique integers as arguments:

Bash
ARG="45 0 -3 12 100 5" && ./push_swap $ARG
Expected Output
The program outputs the list of standard instructions. You can pipe the result straight into a line counter to verify performance metrics:

Bash
./push_swap 3 2 1 4 5 | wc -l
Resources
References

AI Usage
Mathematical Tuning: Assisted in developing the integer-safe scaling formula to eliminate float dependency overhead inside the chunk allocation blocks.

Refactoring Safeguards: Assisted in configuring the on-the-fly index engine to protect shared codebase boundaries between collaborators.

Documentation & Technical Writing: Assisted in structuring, formatting, and refining this README.md file, ensuring clear technical prose and professional presentation.