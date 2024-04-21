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
* [Calculating the Best Move](#calculating-the-best-move)
* [Usage 🏁](#usage-)
* [Tests 🧪](#tests-)
* [References 📚](#references-)
* [License 📖](#license-)

<!-- mtoc-end -->

</div>

# About 📌

# Implementation 📜

The algorithm used to sort a stack of random integer values is a variation of the `QuickSort Algorithm`, adapted specifically for stacks. The algorithm uses two stacks to sort the elements, pushing and swapping elements between the stacks as necessary.

___

Here's a general description of the logic implemented in this project:

If the input stack is empty:

...

If the input stack has 2 values:

...

If the input stack has 3 values:

...

If the input stack has more than 3 values:

* The algorithm starts by partitioning `stack_a` around a **median value**. 
	* `i` is initialized to the start of `stack_a`, and `median` to its median value.
	* It then loops through `stack_a`, pushing elements to `stack_b` until there are only three elements left in `stack_a`. 
		* If the current element in `stack_b` is greater than the `median` and the number of elements in `stack_a` is greater than 3, it rotates `stack_b`.

* The three remaining elements in `stack_a` are sorted.
* The algorithm then resets `i` to the start of `stack_b`;
* Then iterates through `stack_b`, calculating the best move for each element in `stack_b`.

* It rotates `stack_a` until the smallest number greater than the value at the top of `stack_b` is at the top of `stack_a`.

* The top of `stack_b` is then pushed to `stack_a`.

* Finally, it rotates `stack_a` until its smallest element is at the top.

This process is repeated until the entire stack is sorted.

## Calculating the Best Move

...

___

# Usage 🏁

# Tests 🧪

# References 📚

# License 📖
