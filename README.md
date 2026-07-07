*This project has been created as part of the 42 curriculum by <fbachman> & <made-luc>*

# push_swap

## Description
This project centers on sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. At its core, this assignment serves as a practical deep dive into **algorithmic complexity**, data structures (specifically doubly linked lists), and optimization strategies under strict operation constraints.

## Overview
The primary objective of **push_swap** is to code an executable that calculates and displays on the standard output the minimum instruction set required to sort an array of integers. 

The program works with two stacks: **Stack A** (which begins with a random amount of negative and/or positive integers without duplicates) and **Stack B** (which starts empty).

This project introduces foundational computer science concepts:
* **Algorithmic Selection:** Matching stack configurations with specific sorting behaviors (e.g., Bubble Sort, Three-element math, or Chunk-based Sorting).
* **Dynamic Complexity Analysis:** Optimizing loops and minimizing rotation choices to stay well below the thresholds.
* **Architecture Integrity:** Safely interacting with abstract memory concepts without modifying core header structures or corrupting team parsing code.

### Disorder metric
**Disorder** is a number between 0 and 1 that tells how far the initial *Stack A* is from being sorted. 
* If the numbers are already in the *right order*, the disorder is **0**. 
* If they are in the *worst possible order*, the disorder is **1**.
* Anything in between means the stack is partly sorted, but still messy.

### Adaptive Strategy & Performance Thresholds
This repository features an intelligent **Adaptive Strategy** that profiles the layout of the integers before running. It computes an operational disorder metric and routes execution automatically:
* **Small Stacks ($\leq 5$ elements):** Handled via optimized hardcoded logic (`ft_sort_three`, `ft_sort_four`, `ft_sort_five`).
* **Low Disorder ($< 20\%$ disorder):** Handled via a so-called *simple algorithm* in a $O(n^2)$ time (`ft_bubble_sort`).
* **Medium Disorder ($<= 20\%$ disorder $< 50\%$):** Handled via a so-called *medium algorithm* in a $O(n√n)$ time (`ft_chunk_sort`).
* **High Disorder (disorder $>= 50\%$):** Managed by (`ft_chunklog_sort`), an algorithm adaptation with stack partitioning run in  $O(n log n)$ time.

---

## Algorithm & Data Structure Justification

The core challenge of large stacks is avoiding $O(n^2)$ rotation costs. Instead of searching for absolute minimums one by one, our architecture dynamically shifts strategies based on stack size and data topology. 

* **The Doubly Linked List Structure:** Stack modifications (`pa`, `pb`, `ra`, `rra`) require $O(1)$ constant pointer swapping. This ensures that memory management never bogs down the operating speed of the execution lifecycle.
* **On-the-Fly Indexing:** To avoid modifying the core `t_node` struct and risking dependency errors with team parsing files, this algorithm calculates **global ranks on the fly**. It queries both stacks dynamically to establish absolute sizing metadata without saving temporary markers to headers.

---

### Small Stacks Logic ($\leq 5$ elements)
At ultra-small sizes, the overhead of structural profiling or partitioning algorithms completely outweighs their benefit. 

* **3 Elements (`ft_sort_three`):** Uses deterministic mathematical mapping. With only 3 elements, there are 6 possible permutations. By checking the positions of the minimum and maximum values, the algorithm hardcodes the exact decision tree, requiring a maximum of **2 operations**.
* **4–5 Elements (`ft_sort_four` / `ft_sort_five`):** Finds the absolute smallest element(s) in Stack A, uses the shortest rotation path (`ra` vs `rra`) to bring them to the top, and pushes them to Stack B. The remaining 3 elements are sorted using the 3-element logic, and the values are pushed back. This guarantees sorting in $\leq 12$ moves.

---

### Simple Algorithm
When the initial profiling step detects that the stack is already highly organized, running a global sorting algorithm generates wasteful structural overhead.

* **Optimized Bubble Sort (`ft_bubble_sort`):** This routine performs localized adjustments directly within Stack A whenever possible. By leveraging the `sa` (swap) command paired with short, targeted look-ahead rotations, it "bubbles" misplaced values into their correct positions
* **Adaptation for push-swap:**

	* Compare top 2 elements of stack A if they are out of order, swap them (sa)
	* Move to the next pair by rotating the stack A (ra)
	* Repeat this $(n - 1 - i)$ times to complete a full pass
	* Perform one final rotate (ra) at the end of the pass to bring the stack to its original orientation. At this point, the largest element will have successully 'bubbled' to the absolute bottom of the stack
	* Repeat the entire outer loop $(n - 1)$ times
* **Complexity:** It runs exactly $(n - 1) * n$ times rotations plus conditional swaps, so it adheres to the $O(n^2)$ strategy
* **Independence:** It leaves Stack B entirely untouched
* **The Benefit:** Because the data is already close to its sorted state, elements do not undergo the expensive "round-trip" process of being pushed entirely to Stack B and back, saving a massive number of instructions on nearly-sorted large sets

---
### Medium Algorithm
For moderately chaotic sets, the program deploys a customized **Chunk Sort** that balances dynamic cost evaluation with organized entropy.

#### Theoretical Deepening
* **Normalization (indexing)**: transforming data into a predictable format.
	Without indexing, there is no way of kniwing if a number is small or huge unless you can the entire stack to find the min and max.
	By replacing every number with its sorted rank (index), the stack is turned into a mathematical map
	* *value = rank* -> if a node holds the value `0`, it is definitely the absolute minimum, if it holds `n - 1`, it is the absolute maximum
	* *proximity math* -> by using simple arithmetic bounds, the numbers can be set in chunks, not demanding complex comparison logic
* **Controled Entropy (A->B)**: in this phase, it is not imporant if a chunk of n numbers is perfectly sorted inside Stack B, it is only relevant that those numbers are isolated from the rest of the database
	* *lower window segment:* If an item fits the lower half of the sliding boundary, it is pushed to Stack B and immediately rotated (`ft_rb`)
	* *upper window segment:* If an item fits the upper half of the boundary, it is simply pushed (`ft_pb`)
	* *the hourglass/butterfly effect mechanics* -> This structural distribution forces smaller values to the bottom of Stack B and larger values to the top, forming an organized **hourglass shape**. This controlled distribution guarantees that returning items to Stack A later remains extremely cheap. when pushing from Stack A to Stack B, the algorithm calculates a sliding window size driven by a custom mathematical scaling formula
* **Soft Landing (B->A)**: due to controlled entropy part, Stack B is now a structured pile. When looking for the max element to push back to Stack A, the max element will almost always be very close to either the top or the bottom of Stack B. Instead of searching through n elements, the search space for the next largest element is reduced because the chunks act as a filter to bring the max element to the top of Stack B. To calculate the shortest path:
	* if it's closer to the top: rb
	* if it's closer to the bottom: rrb
	
	Once it hits the top, `pa` places it onto Stack A. Because the max are being pulled one by one, Stack A naturally fills up from highest to lowest - meaning the largest number ends up at the bottom of A while the smallest ends up at the top.
* **Efficiency**: it depends entirely on the chunk size
	* If chunks are too large (example, 1 chunk of size $n$), the first part takes almost 0 rotations because everything fits the chunk, but the second part is $O(n^2)$ and it will spend thousands of rotations searching for the max element
	* If chunks are too small (example, $n$ chunks of size 1), the second phase is incredibly cheap because Stack B is perfectly sorted, however phase 1 will have to rotate Stack A thousand times just searching for that specific number that fits the current tiny window
	* By choosing a chunk size relative to $√n$, it mathematically balances the rotation cost of both phases, achieving efficient total moves that beats the required limit
$$\text{Total Cost} = Cost_of_A->B + Cost_of_B->A$$

#### Step-by-Step Logic

1. **Analysis (`ft_compute_disorder`):** The program scans the initial input array to assess the percentage of inversion pairs and assigns an appropriate execution strategy.
2. **Phase One (`ft_phase_one`):** Large datasets are streamed from Stack A into Stack B using the dynamic square-root chunk multiplier, forming a dual-layered hourglass shape.
3. **Phase Two (`ft_phase_two`):** The program scans Stack B to find the absolute maximum global rank position, calculates the shortest rotation path (`rb` vs `rrb`), brings it to the top, and pushes it perfectly sorted back to Stack A.

---

### Complex Algorithm
For massive chaotic sets (e.g., 500+ elements), hardcoded chunk limits break down. To counteract this, the program deploys a Logarithmically Scaled Chunk Sort that dynamically calculates an optimized sliding window to minimize rotations.

#### Theoretical Deepening
* **Logarithmic Scaling Math:** Hardcoding a static chunk size (like 45) causes the operation count to scale exponentially on very large lists. To find the sweet spot between Phase 1 filtering and Phase 2 retrieval, the algorithm uses a base-2 logarithm scaling formula. This dynamically adjusts the window size relative to the size of the dataset, keeping total operations well below the strict evaluation benchmarks.
$$\text{Chunk Size} = \left(\frac{N}{\log_2(N)}\right) \times \frac{6}{10}$$
* **Controlled Entropy & The Hourglass Structure (A $\rightarrow$ B):** Rather than enforcing strict order early on, Phase 1 splits values into isolated numeric windows.
	* *lower window segment:* If an element fits into the lower half of the active sliding boundary, it is pushed to Stack B and immediately rotated (`ft_rb`), sending it to the bottom of the stack.
	* *upper window segment:* If it fits the upper half of the boundary, it is simply pushed (`ft_pb`) to the top of Stack B.This split forces smaller values to the bottom and larger values to the top of Stack B, generating an organized hourglass shape
* **Soft Landing (B $\rightarrow$ A):** Because Stack B has been shaped into an hourglass, the global maximum elements naturally gravitate toward the extreme ends (the very top or very bottom of Stack B). The search space is radically reduced. The algorithm calculates the shortest path to bring the maximum element to the top:
	* If it is closer to the top: rotate (rb).
	* If it is closer to the bottom: reverse rotate (rrb)Once it reaches the top, it is pushed back (pa), cleanly rebuilding a sorted Stack A from highest to lowest
	
### Step-by-Step Logic
[Stack A] ---> (Dynamic Log Window Check) ---> [Stack B (Hourglass Shape)] ---> (Shortest Path rb/rrb) ---> [Stack A (Sorted)]
* **Dynamic Scaling Calculation (ft_chunklog_sort):** The program checks the current size of Stack A and processes it through the ft_log2 function to determine an optimized, mathematically balanced chunk_size.
* **Phase One Streaming (ft_phase_one_complex):** Elements are evaluated from Stack A. If they fall inside the current dynamically shifting index range ($i$ to $i + \text{chunk\_size}$), they are pushed into Stack B's dual-layered hourglass structure. Elements outside the window are rotated to the back of Stack A via ft_ra.
* **Phase Two Reconstruction (ft_phase_two):** The program recursively scans Stack B for the maximum global rank, rotates via the absolute shortest path (rb vs rrb), and restores elements onto Stack A in perfect ascending order.

---

## Instructions

### Compilation & Installation

The project includes a robust, automated dependency tracking Makefile that compiles an executable binary alongside a `libft` library.

To install and compile the codebase, clone the repository and run the following command in your terminal:

```bash
make
```

Makefile Command Reference:
* make / make all: Compiles the push_swap executable using strict compiler flags (-Wall -Wextra -Werror).
* make clean: Removes all intermediate object (.o) files from both the main project and libft.
* make fclean: Executes clean and completely deletes the compiled binaries and library archives (.a).
* make re: Performs a clean re-compilation of the entire project from scratch.

### Repository Structure
The project architecture keeps sorting algorithms cleanly separated from node manipulation routines and parsing workflows:

* **Stack Manipulations:** op_populate_stack / op_pop_node / op_push_back / op_push_front
* **Stack Operations:** op_push / op_rotate / op_rrotate / op_swap
* **Input Validation:** parse_args / parse_bench / parse_flags / parse_nbr
* **Strategy Orchestrator:** sort_disorder_metric
* **Sorting Algorithms:** sort_small / sort_simple / sort_medium / sort_complex

### Usage & Examples
To execute the program, pass a random list of unique integers as arguments:

```bash
# Define a mixed set of integers and pass it to push_swap
ARG="45 0 -3 12 100 5"
./push_swap $ARG
```
*Expected Output:* The program outputs the amount of standard instructions.

## Resources

### References
* [Medium] - (https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
* [Medium] - (https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0)
* [Medium] - (https://medium.com/@twof/on-the-optimization-of-bubble-sort-e1096d93d478)
* [Medium] - (https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
* [GeeksForGeeks] - (https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/) 

### AI Usage
Mathematical Tuning: Assisted in developing the integer-safe scaling formula to eliminate float dependency overhead inside the chunk allocation blocks.

Refactoring Safeguards: Assisted in configuring the on-the-fly index engine to protect shared codebase boundaries between collaborators.

Documentation & Technical Writing: Assisted in structuring, formatting, and refining this README.md file, ensuring clear technical prose and professional presentation.