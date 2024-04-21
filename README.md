42 Project : push_swap
<a name="readme-top"></a>
<div align="center">

# push_swap

> Data on stack; a limited set of instructions; the lowest possible number of operations. Fun with data sorting algorithms!

<p>
    <img src="https://img.shields.io/badge/score-%20%2F%20100-success?style=for-the-badge" />
    <img src="https://img.shields.io/github/repo-size/PedroZappa/42_push_swap?style=for-the-badge&logo=github">
    <img src="https://img.shields.io/github/languages/count/PedroZappa/42_push_swap?style=for-the-badge&logo=" />
    <img src="https://img.shields.io/github/languages/top/PedroZappa/42_push_swap?style=for-the-badge" />
    <img src="https://img.shields.io/github/last-commit/PedroZappa/42_push_swap?style=for-the-badge" />
</p>

___

<h3>Table o'Contents</h3>

<!-- mtoc-start -->

* [About 📌](#about-)
* [Implementation 📜](#implementation-)
* [QuickSort Algorithm (push_swap Variation)](#quicksort-algorithm-push_swap-variation)
  * [If the stack is empty:](#if-the-stack-is-empty)
  * [If the stack is invalid:](#if-the-stack-is-invalid)
  * [If the stack has 2 values:](#if-the-stack-has-2-values)
  * [If the stack has 3 values:](#if-the-stack-has-3-values)
  * [If the stack has more than 3 values:](#if-the-stack-has-more-than-3-values)
* [Calculating the Best Move](#calculating-the-best-move)
* [Usage 🏁](#usage-)
* [Tests 🧪](#tests-)
* [References 📚](#references-)
* [License 📖](#license-)

<!-- mtoc-end -->

</div>

# About 📌

# Implementation 📜

The algorithm used to sort a stack of random integer values (`stack_a`) is a variation of the `QuickSort Algorithm` adapted to sort stacks. The algorithm sorts `stack_a` by repeatedly partitioning it around a `median` (pivot) value, pushing elements to `stack_b` programmatically after calculating which element is less costly to sort at each iteration. At the end of execution `stack_a` contains all values stacked in ascending order.

___

## QuickSort Algorithm (push_swap Variation)

Here's a general description of the logic implemented in this project:

### If the stack is empty:

* The program simply returns the prompt to the user.

___

### If the stack is invalid:

* The program prints "Error\n" to `stdout` and returns the prompt to the user.

___

### If the stack has 2 values:

* If the elements are already in order:
	* No operations is necessary.
* If the elements are not in order:
	* A single **swap** operation is performed to sort `stack_a`.

___

### If the stack has 3 values:

* It starts by getting the `start` and `end` indices of `stack_a`.

* It checks if `stack_a` is already sorted: If the **minimum value** is at the `start` of `stack_a` and the **maximum value** is at the `end`, the function returns without making any changes.

* If the **minimum value** is at the `start` and the **maximum value** is in the middle (second position), it **swaps** the first two elements and then **rotates** `stack_a`. This effectively moves the **maximum value** to the end of `stack_a`.

* If the **maximum value** is at the `start` of `stack_a`, it rotates the stack. This moves the **maximum value** to the `end`.

* If the first element is greater than the second element, it **swaps** the first two elements.

* If the **minimum value** is at the `end` of `stack_a`, a **reverse rotation** is performed. This moves the **minimum value** to the `start` of `stack_a`.

> [!Note]
>
> See the [ft_sort_three.c](https://github.com/PedroZappa/42_push_swap/blob/main/src/ft_sort_three.c) for a direct look into the implementation of this part of the algorithm.

___

### If the stack has more than 3 values:

* The algorithm starts by partitioning `stack_a` around a **median value**. 
	* `i` is initialized to the start of `stack_a`, and `median` to its median value.
	* It then loops through `stack_a`, pushing elements to `stack_b` until there are only three elements left in `stack_a`. 
		* If the current element in `stack_b` is greater than the `median` and the number of elements in `stack_a` is greater than 3, it rotates `stack_b`.

* The three remaining elements in `stack_a` are sorted.
* The algorithm then resets `i` to the start of `stack_b`;
* Then iterates through `stack_b`, calculating the best move for each element in `stack_b`.

* It rotates `stack_a` until the smallest number greater than the value at the top of `stack_b` is at the top of `stack_a`.

* The top of `stack_b` is then pushed to `stack_a`.

* Finally, it **rotates** `stack_a` until its smallest element is at the top.

This process is repeated until all the values in `stack_a` are sorted.

___

## Calculating the Best Move

...

___

# Usage 🏁

# Tests 🧪

# References 📚

# License 📖
