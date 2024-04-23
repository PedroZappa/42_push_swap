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
* [Processing Input Arguments](#processing-input-arguments)
* [Error / Invalid Input Handling](#error--invalid-input-handling)
* [Creating the Stacks](#creating-the-stacks)
* [Sorting the Stacks](#sorting-the-stacks)
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

The algorithm used in this implementation to sort a stack of random integer values (`stack_a`) is a variation of the `QuickSort Algorithm` adapted to sort stacks.

The algorithm sorts `stack_a` by repeatedly partitioning it around a `median` (pivot) value, pushing elements to `stack_b` programmatically after calculating which element is less costly to sort at each iteration. At the end of execution `stack_a` contains all values stacked in ascending order.

> But before we get into the nitty and gritty details of the algorithm, let's take a look at how the program handles input arguments and sets up the stacks.
___

## Processing Input Arguments
```c
int	main(int argc, char **argv)
{
	(...)
	++argv;
	input_list = argv;
	must_free = 0;
	if (argc == 2)
		input_list = ft_get_elems(&argc, argv, &must_free);
	(...)
}
```
* First, it increments `argv` so to skip the program's name;
* It then assigns `argv` to `input_list`.
* Initializes `must_free` flag to 0 (This flag is used to indicate that the memory was allocated and needs to be freed later);
* If `argc` is 2 (meaning a single command line argument was provided) `ft_get_elems()` is called:
```c
static char	**ft_get_elems(int *argc, char **argv, int *must_free)
{
	char	**split_list;

	split_list = ft_split(argv[0], ' ');
	*argc = ft_argv_count(split_list) + 1;
	*must_free = 1;
	return (split_list);
}
```
> * Splits the single argument into multiple elements based on the specified separator (' ') storing the result in `split_list`. This is accomplished using the [ft_split](https://github.com/PedroZappa/42_libft/blob/master/libft/ft_split.c) function defined in my custom [libft](https://github.com/PedroZappa/42_libft) helper library;
> * It counts the number of elements in the `split_list` using the `ft_argv_count()` and adds 1 to the count (to account for the program name skipped at the start of execution). This updated count is assigned to `argc`.
> * It sets the `must_free` flag to 1 (indicating `split_list` must be freed).
> * It returns `split_list` containing the list of input elements.
___

## Error / Invalid Input Handling
```c
int	main(int argc, char **argv)
{
	(...)
	error = ft_errors(argc, input_list);
	if (error <= 0)
	{
		ft_free(NULL, NULL, input_list, must_free);
		return (0);
	}
	(...)
}
```
* Next, the program checks for invalid input in the `input_list` using the `ft_errors()` function:
	* If an error is found (indicated by a return value less than or equal to 0), it frees any previously allocated memory and exits the cleanly.
```c
int	ft_errors(int argc, char **input_list)
{
	if (argc == 1)
		return (0);
	if (ft_are_args_nbr(argc, input_list) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (ft_is_duplicate(argc, input_list) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (1);
}
```
> - In case `argc` is 1, meaning no arguments were provided, the function simply returns 0.
> - If the values in `input_list` are NOT numbers, the call to `ft_are_args_nbr()` returns -1. In this case, the function prints "Error\n" to the `stderr` and returns -1.
> - Lastly if there are duplicate numbers in the `input_list`, the call to `ft_is_duplicate()` returns -1, in which case the function prints "Error\n" to the `stderr` and returns -1.
> - If no errors were detected, the function returns 1.
___

## Creating the Stacks
```c
int	main(int argc, char **argv)
{
	(...)
	stack_a = ft_create_stack(argc, input_list, 1);
	stack_b = ft_create_stack(argc, input_list, 0);
	(...)
}
```

* If no errors were detected, the program creates two stacks (`stack_a` and `stack_b`) from the input arguments using the `ft_create_stack()` function (the third argument indicates whether the stack should be filled with the input elements (`stack_a`) or left empty (`stack_b`).
```c
t_elem	*ft_create_stack(int argc, char **argv, int select)
{
	t_elem	*stack;
	int		i;

	stack = malloc(sizeof(t_elem) * (argc + 1));
	if (stack == NULL)
		return (NULL);
	i = 0;
	while (i < (argc - 1))
	{
		if (select == 1)
		{
			stack[i].num = ft_atoi(argv[i]);
			stack[i].set = 1;
		}
		else
		{
			stack[i].num = 0;
			stack[i].set = 0;
		}
		stack[i].index = i;
		++i;
	}
	stack[i].index = -1;
	return (stack);
}
```

> - It allocates memory for the stack using `malloc()`. The size of the allocated memory is the size of `t_elem` multiplied by (`argc` + 1) (the extra element is used as a sentinel value signaling the end of the stack.
>	- If the memory allocation fails, the function returns NULL.
> - Initializes `i` to 0.
> - Then it enters a loop initializing each element of the stack, with `i` as the index.
>	- If `select` is 1:
>		- Sets the `stack[i].num` field of the current element to the integer value of the corresponding argument (converted using `ft_atoi()`);
		- Sets the `stack[i].set` field to 1 (used for some conditional checks later in the program).
>	- If `select` is 0:
>		- Sets the `stack[i].num` field of the current element to 0. 
>		- Sets `stack[i].set` fields of the current element to 0.
>	- At the end of each iteration, sets the `stack[i].index` field of the current element to `i` (representing the position of the element in the stack).
> - After the loop is done, it sets the index field of the sentinel element to -1.
> - It returns the stack.
___

## Sorting the Stacks

If stack_a is not already sorted (indicated by `ft_is_sorted()` returning -1), it sorts `stack_a` using the `ft_sort()` function.

Finally, it frees any allocated memory before exiting the program.

___

## QuickSort Algorithm (push_swap Variation)

Here's a general description of the logic implemented in this project:

### If the stack is empty:

* The program simply returns the prompt to the user.

___

### If the stack is invalid:

* The program prints "Error\n" to `stderr` and returns the prompt to the user.

> [!Note]
>
> See the [ft_errors.c](https://github.com/PedroZappa/42_push_swap/blob/main/src/ft_errors.c) to learn more about this implementation's error handling functions.
___

### If the stack has 2 values:

* If the elements are already in order:
	* No operations is necessary.
* If the elements are NOT in order:
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
