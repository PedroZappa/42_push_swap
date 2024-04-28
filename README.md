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

<img alt="minitalk demo" src="./video/push_swap-demo.gif" width="100%" />

___

<h3>Table o'Contents</h3>

</div>

<!-- mtoc-start -->

* [About 📌](#about-)
* [`push_swap` Requirements Overview ✅](#push_swap-requirements-overview-)
* [`push_swap` Operations](#push_swap-operations)
* [Operations Example](#operations-example)
* [Complexity](#complexity)
  * [Table of Common Time Complexities](#table-of-common-time-complexities)
* [Implementation 📜](#implementation-)
* [Data Structures](#data-structures)
* [Processing Input Arguments](#processing-input-arguments)
* [Error / Invalid Input Handling](#error--invalid-input-handling)
* [Creating the Stacks](#creating-the-stacks)
* [Sorting the Stacks](#sorting-the-stacks)
* [Freeing the Stacks](#freeing-the-stacks)
* [QuickSort Algorithm (push_swap Variation)](#quicksort-algorithm-push_swap-variation)
  * [If the stack has 2 values:](#if-the-stack-has-2-values)
  * [If the stack has 3 values:](#if-the-stack-has-3-values)
  * [If the stack has more than 3 values:](#if-the-stack-has-more-than-3-values)
  * [Calculating the Best Move](#calculating-the-best-move)
    * [`ft_best_op_idx()`](#ft_best_op_idx)
    * [`ft_calc_move()`](#ft_calc_move)
* [Bonus: Checker Requirements Overview ✅](#bonus-checker-requirements-overview-)
* [Checker Implementation 📜](#checker-implementation-)
  * [`ft_parse_stack()` ](#ft_parse_stack-)
  * [`ft_check_op()` ](#ft_check_op-)
  * [`ft_parse_op()` ](#ft_parse_op-)
* [Usage 🏁](#usage-)
* [Build `push_swap`](#build-push_swap)
* [Build `checker`](#build-checker)
* [Tests 🧪](#tests-)
* [License 📖](#license-)

<!-- mtoc-end -->

# About 📌

## `push_swap` Requirements Overview ✅

* It takes a stack as an argument, formatted as a list of positive and/or negative integers.
* The first element should be at the top of the stack.

* The program prints to `stdout` the instructions to sort `stack_a` separated by a `\n`.

* The goal is to sort the stack with the lowest possible number of operations.

* If no argument is given, the program gives the prompt back and does nothing.

* In case of an error, it displays "Error" followed by a `\n` to `stderr`. 

Errors include:
* Some arguments are not integers.
* Some arguments are bigger than an integer.
* Some arguments are duplicates.

> [!Important]
>
> The objective of `push_swap` is to sort the values in `stack_a` in **ascending order** using a set of `push_swap` operations.

## `push_swap` Operations

To get the stack sorted, we have the following operations at our disposal:

| Code  | Operation                         | Description                                            |
| ----- | --------------------------------- | -------------------------------------------------------|
| `sa`  | swap a                              | swaps the 2 top elements of `stack_a`                    |
| `sb`  | swap b                              | swaps the 2 top elements of `stack_b`                    |
| `ss`  | swap a & swap b                     | performs both `sa` and `sb`                          |
| `pa`  | push a                              | moves the top element of stack b at the top of `stack_a` |
| `pb`  | push b                              | moves the top element of stack a at the top of `stack_b` |
| `ra`  | rotate a                            | shifts all elements of `stack_a` from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of `stack_b` from bottom to top      |
| `rr`  | rotate a & rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of `stack_a` from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of `stack_b` from top to bottom      |
| `rrr` | reverse rotate a & reverse rotate b | performs both `rra` and `rrb`                                   |

## Operations Example

To show these instructions in action, let’s sort a random list of integers.
In this example, we’ll consider that both stacks grow from the right.

|Init a and b |`sa` |`pb` |`pb` |`pb` |`ra` |`rb` |`rra`|`rrb`|`sa` |`pa` |`pa` |`pa` |
|-------------|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
| 2          | `1`   |     |     |     |     |     |     |     |     |     |     | `1`   |
| 1          | `2`   | 2   |     |     |     |     |     |     |     |     | `2`   | 2   |
| 3          | 3   | 3   | 3   |     |     |     |     |     |     | `3`   | 3   | 3   |
| 6          | 6   | 6   | 6   | 6 `3` | 5 3 | 5 2 | `6` 2 | 6 `3` | `5` 3 | 5   | 5   | 5   |
| 5          | 5   | 5   | 5 `2` | 5 2 | 8 2 | 8 1 | 5 1 | 5 2 | `6` 2 | 6 2 | 6   | 6   |
| 8          | 8   | 8 `1` | 8 1 | 8 1 | `6` 1 | 6 `3` | 8 3 | 8 1 | 8 1 | 8 1 | 8 1 | 8   |
| a b        | a b | a b | a b | a b | a b | a b | a b | a b | a b | a b | a b | a b |

___

## Complexity

Also known as `Time Complexity`, is the **computational complexity** that describes the amount of computer time it takes to run an algorithm (usually measured by the **number of needed elementary operations**, assuming each operation takes a fixed amount of time to be performed).

> [!Note]
>
> The computational complexity of an algorithm is the amount of resources required to run it. Particular focus is given to **computation time** and **memory storage** requirements**.

Since an algorithm's running time usually varies between different inputs of the same size, it is common to consider the **worst-case time complexity**, the maximum length of time required to run a given algorithm.

Less common, but more often explicitly specified, the **average-case time complexity** is the average length of time required to run a given algorithm.

In either case, the **Time Complexity** is generally expressed as a function of the input size. Such a function is most often very difficult to define, and since its running time is usually inconsequential, it is customary to focus on the **asymptotic behaviour** of the complexity

> [!Note]
>
> The asymptotic behaviour of a function is the behaviour of the function as the input size increases.

Taking this into consideration, the **Time Complexity** is commonly expressed using **Big O Notation**, expressed as $O(n)$ , $O(n\log n)$, $O(2^n)$, etc., where $n$ is the size in units of bits needed to represent the input.  

### Table of Common Time Complexities

| Complexity     | Time Complexity | Example |
|----------------|-----------------|---------|
| $O(1)$           | Constant        | Finding the median value in a sorted array of numbers. |
| $O(log$ n)       | Logarithmic     | Binary Search       |
| $O(n)$           | Linear          | Finding the smallest/largest element in an array.      |
| $O(n^2)$         | Quadratic       | 4       |
| $O(n^3)$         | Cubic           | 5       |


___
# Implementation 📜

The sorting algorithm used in this implementation is a variation of the `QuickSort Algorithm` adapted to sort stacks using only the aforementioned operations.

> Before we get into the nitty and gritty details of the algorithm, let's take a look at how the program handles input arguments and sets up the stacks.
___

## Data Structures

* `stack_a` and `stack_b`, are arrays of `t_elem` structs:
```c
typedef struct s_elem {
	int	num;
	int	index;
	int	set;
}	t_elem;
```

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
* Initializes `must_free` flag to 0 (This flag is used to indicate that the memory was allocated and therefore needs to be freed later);
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
> - If no errors are detected, the function returns 1.
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
>	- If the memory allocation fails, it returns NULL.
> - Initializes `i` to 0.
> - Then it enters a loop initializing each element of the stack, with `i` as the index.
>	- If `select` is 1, it initializes `stack_a`:
>		- Sets the `stack[i].num` field of the current element to the integer value of the corresponding argument (converted using [ft_atoi()](https://github.com/PedroZappa/42_libft/blob/master/libft/ft_atoi.c)).
>		- Sets the `stack[i].set` field to 1 (used for some conditional checks later in the program).
>	- If `select` is 0, it initializes `stack_b`:
>		- Sets the `stack[i].num` field of the current element to 0. 
>		- Sets `stack[i].set` fields of the current element to 0.
>	- At the end of each iteration, sets the `stack[i].index` field of the current element to `i` (representing the position of the element in the stack).
> - After the loop is done, the `stack[i].index` field is set to -1, signaling the end of the stack (sentinel value).
> - It returns the stack.
___

## Sorting the Stacks
```c
int	main(int argc, char **argv)
{
	(...)
	if (ft_is_sorted(stack_a) == -1)
		ft_sort(stack_a, stack_b, argc);
	(...)
}
```

If `stack_a` is not already sorted (indicated by `ft_is_sorted()` returning -1), it is sorted using `ft_sort()`.
```c
static void	ft_sort(t_elem *stack_a, t_elem *stack_b, int argc)
{
	if (argc == 3)
	{
		if (ft_is_sorted(stack_a) == -1)
			ft_swap_elem(stack_a, "sa\n");
	}
	else if (argc == 4)
		ft_sort_three(stack_a);
	else
		ft_sort_stack(stack_a, stack_b, argc);
}
```

> - If `argc` is 3, it means there are two elements in `stack_a` (plus the program's name). 
>	- In this case, it checks if `stack_a` is already sorted. If it is NOT sorted (indicated by `ft_is_sorted()` returning -1): 
>		- Swaps the two elements using `ft_swap_elem()`.
> - If `argc` is 4, it means there are three elements in `stack_a`. 
>	- In this case, it sorts the three elements using `ft_sort_three()`.
> - If `argc` is greater than 4, meaning there are more than three elements in `stack_a`: 
>	- The stack is sorted using `ft_sort_stack()`.

> [!Note]
>
> We'll get into more detail about how these subroutines work in the algorithm description section.
___

## Freeing the Stacks
```c
int	main(int argc, char **argv)
{
	(...)
	ft_free(stack_a, stack_b, input_list, must_free);
	return (0);
}
```
* Finally, it frees any allocated memory before exiting the program using [ft_free()](https://github.com/PedroZappa/42_push_swap/blob/main/src/main.c).

___

## QuickSort Algorithm (push_swap Variation)

This modified version of the `QuickSort Algorithm` sorts a stack (`stack_a`) by leveraging a second "temporary" stack (`stack_b`), repeatedly partitioning its elements around a `median` (pivot) value (the key concept of the traditional `QuickSort Algorithm`), while keeping track of the optimal operations needed to merge the partitions back together into `stack_a`. At the end `stack_a` is sorted in ascending order. 

> Following is a description of each case handled by the algorithm implemented in this project.
___

### If the stack has 2 values:

* If the elements are already in order:
	* No operations are necessary.
* If the elements are NOT in order:
	* A single **swap** operation is performed to sort `stack_a`.
___

### If the stack has 3 values:

The logic in [ft_sort_three.c](https://github.com/PedroZappa/42_push_swap/blob/main/src/ft_sort_three.c) is triggered. This subroutine works as follows:

* It starts by getting the `start` and `end` indices of `stack_a`.

* It checks if `stack_a` is already sorted, if the **minimum value** is at the `start` of `stack_a` and the **maximum value** is at the `end`,
	* Returns without executing any operations.

* If the **minimum value** is at the `start` and the **maximum value** is in the middle (second position):
	* It **swaps** the top two elements.
	* Then **rotates** `stack_a`. 
> This effectively moves the **maximum value** to the top (`end`) of `stack_a`.

* If the **maximum value** is at the `start` of `stack_a`:
	* it **rotates** the `stack_a`. 
> This moves the **maximum value** to the `end`.

* If the element at the bottom (`start`) is greater than the middle element: 
	* It **swaps** the first two elements.

* If the **minimum value** is at the `end` of `stack_a`: 
	* A **reverse rotation** is performed. 
> This effectively moves the **minimum value** to the bottom (`start`) of `stack_a`.

> [!Note]
>
> See the [ft_sort_three.c](https://github.com/PedroZappa/42_push_swap/blob/main/src/ft_sort_three.c) for a direct look into the implementation of this part of the algorithm.

___

### If the stack has more than 3 values:

The logic in [ft_sort_stack.c](https://github.com/PedroZappa/42_push_swap/blob/main/src/ft_sort_stack.c) is triggered. This is where we get into the meat of the algorithm:

* It starts by setting `i` to the start of `stack_a`;
* It then calculates the median value of `stack_a` using [ft_median()](https://github.com/PedroZappa/42_push_swap/blob/main/src/ft_median.c).
* Loops through `stack_a`:
	* Pushing elements to `stack_b` until there are only three elements left in `stack_a`.
	* If the current top element in `stack_b` is greater than the `median` and the number of elements in `stack_a` is greater than 3, it **rotates** `stack_b`.
* The three remaining elements in `stack_a` are sorted with [ft_sort_three.c](https://github.com/PedroZappa/42_push_swap/blob/main/src/ft_sort_three.c).

* `i` is reset to the start of `stack_b`;
* It then loops through `stack_b`:
	* For each element, it calculates the index in `stack_a` that requires the minimum number of operations to move that element into the correct sorted position.
* It **rotates** `stack_a` until the **value right above the median** is at the top.
* It **pushes** the top element of `stack_b` to `stack_a`.
* It **rotates** `stack_a` to move its new **smallest element** to the top.

This process is repeated until all the values in `stack_a` are sorted.
___

### Calculating the Best Move

[ft_calc_move()](https://github.com/PedroZappa/42_push_swap/blob/main/src/ft_sort_stack.c) executes **rotation** and **push** operations according to the return of `ft_best_op_idx()` which calculates the optimal move to make when transferring elements from `stack_b` back to `stack_a` during the sorting process.

#### `ft_best_op_idx()`

* `ft_best_op_idx()` loops through all the elements in `stack_a` calling `ft_get_align_ops()` to calculate the cost (number of operations) of moving that element to the top and aligning it with the corresponding element in `stack_b`.
	* `ft_get_align_ops()` subroutine calculates the total number of operations needed to move an element at a given index in `stack_a` to the top, and to align a corresponding element in `stack_b` with it.
		* First it calculates the cost to move the element at index `idx` in `stack_a` to the top.
		* Afterwards calculates the cost to move the corresponding element in `stack_b` to the top.
		* It returns the total cost of aligning the element in `stack_b` with the element in `stack_a`.

> In short, `ft_best_op_idx()` calculates the index that has the minimum cost.

#### `ft_calc_move()`

* Once the optimal index is found, `ft_calc_move()` is called (with the calculated index as an argument) to actually execute the moves:
	* Gets the start index of `stack_a` storing it in `start`.
	* Calls `ft_check_order()` to check if any elements in `stack_b` are already in order with `stack_a`. It saves the number of elements found to already be in order into `ordered`.
	* Then calls `ft_order()` to move elements from `stack_b` to `stack_a` that are already in the correct order relative to each other.
	* If necessary, handles the adjustment of the index `idx` after `ordered` elements have been moved from `stack_b` to `stack_a`.
	* If `idx` is past the end of `stack_a`:
		* It is recalculated and **looped back to the start** of the stack.
	* Else, if `idx` is past the start of `stack_a`:
		* It is recalculated and **looped back to the end** of the stack.

	* **Rotates** `stack_a` to move the element at `idx` to the top.
	* Again, check if `idx` is past the end of `stack_a`:
		* If so, it is recalculated and **looped back to the start** of the stack.

	* Checks if the min or max value of `stack_b` is less/greater than the element now at the top of `stack_a`:
		* If so, it ***rotates** `stack_b` to move its min to the top.
	* Else, 
		* It **rotates** `stack_b` to move the smallest element greater than `stack_a`'s top to the top of `stack_b`.
	* **Pushes** the top element of `stack_b` to `stack_a`.

___

## Bonus: Checker Requirements Overview ✅

The `checker` program checks whether the list of instructions generated by the `push_swap` program actually sorts the stack correctly.

* Takes `stack_a` as an argument.
* If no argument is given, it stops displaying nothing.
* Waits until instructions are read from `stdin`, each instruction separated by a `\n`.
* Once all instructions have been read, it executes them on the stack received as an argument.
* If after executing the instructions, the stack is sorted:
	* Displays "OK" followed by a `\n`. 
* Else:
	* Displays "KO" followed by a `\n`.
* In case of an error, it displays "Error" followed by a `\n` to `stderr`. 

Errors include:
* Some arguments are not integers.
* Some arguments are bigger than an integer.
* Some arguments are duplicates.
* An instruction doesn't exist or is incorrectly formatted.

___

## Checker Implementation 📜

```c
/* push_swap checker (main_checker.c) */
int	main(int argc, char **argv)
{
	char	**input_list;
	t_elem	*stack_a;
	t_elem	*stack_b;
	int		must_free;
	int		error;

	++argv;
	input_list = argv;
	must_free = 0;
	if (argc == 2)
		input_list = ft_get_elems(&argc, argv, &must_free);
	error = ft_errors(argc, input_list);
	if (error <= 0)
	{
		ft_free(input_list, must_free);
		return (0);
	}
	stack_a = ft_create_stack(argc, input_list, 1);
	stack_b = ft_create_stack(argc, input_list, 0);
	ft_free(input_list, must_free);
	ft_check_stack(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
```
The `checker` program reads a set of instructions from `stdin` and executes them on the stack received as an argument. It has a very similar structure and uses many of the same subroutines as this project's `push_swap` implementation.

> [!Important]
>
> The main difference between the `checker` program and the `push_swap` program is that other than sorting `stack_a` it also checks if the instructions produced by `push_swap` are valid.

___
### `ft_parse_stack()` 

```c
void	ft_check_stack(t_elem *stack_a, t_elem *stack_b)
{
	int		result;
	int		start;
	char	*line;

	result = 1;
	while (result)
	{
		line = get_next_line(0);
		if (!line)
			result = 0;
		else
			ft_check_op(stack_a, stack_b, line);
	}
	start = 0;
	while ((stack_b[start].index != -1) && (stack_b[start].set != 1))
		++start;
	if ((ft_is_sorted(stack_a) == 1) && (stack_b[start].index == -1))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
```
* It takes in two stacks - `stack_a` and `stack_b`.

* It reads input commands line by line using [get_next_line()](https://github.com/PedroZappa/42_get_next_line).
	* For each line, it calls `ft_check_op()` which will process and check if the line contains a valid instruction.

* After reading all the input, it checks if the stacks are in the expected sorted state:
	* `stack_b` should be empty, so it loops through to find the first element with index = -1 (the sentinel value signifying the end of the stack).
	* `stack_a` should be sorted, so it calls `ft_is_sorted()` to check.

	* If both conditions are met:
		* It prints "OK\n" to `stdout`, meaning the instructions are valid.
		* else prints "KO\n" to `stdout`, meaning the instructions are invalid.
___
### `ft_check_op()` 

```c
static void	ft_check_op(t_elem *stack_a, t_elem *stack_b, char *op)
{
	int		result;

	if ((op == NULL) || (ft_strlen(op) == 1))
		result = -1;
	else
		result = ft_parse_op(op, stack_a, stack_b);
	if (op != NULL)
		free(op);
	if (result == -1)
	{
		free(stack_a);
		free(stack_b);
		get_next_line(0);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}
```
* It takes in `stack_a` and `stack_b`, and the operation string `op`.

* It first checks if the `op` string is valid:
	* If it's NULL or only 1 character, set result = -1 to indicate invalid operation.
	* Else it calls `ft_parse_op()` to execute the operation on the appropriate stack.

* It frees the `op` string.

* It checks the return value of `ft_parse_op()` stored in `result`. If -1, it means an invalid operation was parsed. 
	* It frees the stacks.
	* It reads and discards the rest of input.
	* It prints "Error\n" to `stderr` and exits.

___
### `ft_parse_op()` 
```c
static int	ft_parse_op(char *op, t_elem *stack_a, t_elem *stack_b)
{
	if (ft_strncmp_checker(op, "pa\n", 3) == 0)
		ft_push_elem(stack_b, stack_a);
	else if (ft_strncmp_checker(op, "pb\n", 3) == 0)
		ft_push_elem(stack_a, stack_b);
	else if (ft_strncmp_checker(op, "sa\n", 3) == 0)
		ft_swap_elem(stack_a);
	else if (ft_strncmp_checker(op, "sb\n", 3) == 0)
		ft_swap_elem(stack_b);
	else if (ft_strncmp_checker(op, "ss\n", 3) == 0)
		ft_swap_both(stack_a, stack_b);
	else if (ft_strncmp_checker(op, "ra\n", 3) == 0)
		ft_rotate(stack_a);
	else if (ft_strncmp_checker(op, "rb\n", 3) == 0)
		ft_rotate(stack_b);
	else if (ft_strncmp_checker(op, "rr\n", 3) == 0)
		ft_rotate_both(stack_a, stack_b, 0);
	else if (ft_strncmp_checker(op, "rra\n", 4) == 0)
		ft_rev_rotate(stack_a);
	else if (ft_strncmp_checker(op, "rrb\n", 4) == 0)
		ft_rev_rotate(stack_b);
	else if (ft_strncmp_checker(op, "rrr\n", 4) == 0)
		ft_rotate_both(stack_a, stack_b, 1);
	else
		return (-1);
	return (1);
}
```
Parses an `op` string and executes the corresponding operation on `stack_a` or `stack_b`.

* It compares the input string `op` to each possible operation. Based on the matching operation, it calls the corresponding stack operation function.
	* If there is no match, it returns -1 to indicate invalid operation.
	* Otherwise it executes the operation and returns 1.
___

# Usage 🏁

First, clone the repository, and `cd` into the project folder:
```sh
git clone git@github.com:PedroZappa/42_push_swap.git 42_push_swap_passunca
cd 42_push_swap_passunca
```
## Build `push_swap`

To build `push_swap` run: 
```sh
make
```
> This command will fetch the dependencies and build the project.

Here are a couple different ways to run the program:
```sh
./push_swap 2 1 3 6 5 8
# or
./push_swap "2 1 3 6 5 8"
# or
ARG="2 1 3 6 5 8"; ./push_swap $ARG
# and to run it with the checker provided by 42:
ARG="2 1 3 6 5 8"; ./push_swap $ARG | ./checker_linux $ARG
```
___

## Build `checker`

To build `checker`, run:
```sh
make bonus
```

To manually test `checker`, run:
```sh
echo -e "rra\npb\nsa\nrra\npa" > input.txt
./checker 3 2 1 0 < input.txt
```
___

# Tests 🧪

I've prepared several make rules to test the `push_swap` program and the `checker` in a systematic and automated way.

To run the tests present on the subject run:
```sh
make test_subject	# for push_swap
make test_checker	# for checker
```

To test `push_swap` with a custom number of input elements run:
```sh
make test_n n=42
```
To test `push_swap` together `checker` with a custom number of input elements run:
```sh
make test_checker n=42
```
> `n` is the number of input elements, in these examples, 42.

To check all available commands including tests run:
```sh
make help
```
> [!Important]
>
> Check the [Makefile](https://github.com/PedroZappa/42_push_swap/blob/master/Makefile) for more details about what's going on with each command. there is a lot of juicy juice gathered in it for your Make'ing enjoyment 🤓

# License 📖

This work is published under the terms of <a href="https://github.com/PedroZappa/42_minitalk/blob/main/LICENSE">42 Unlicense</a>.

<p align="right">(<a href="#readme-top">get to top</a>)</p>
