#
##
### GDB Settings 
##
#
set trace-commands on
set logging enabled on

# set print pretty on
# set print elements 2
set print array on

set unwindonsignal on
#
##
### Custom Commands
##
#
define rfr
	refresh
end

define nr
	next
	refresh
end

# main.c
define main
	display *input_list
	display *stack_a@argc
	display *stack_b@argc
	display must_free
	display error
end

define ft_get_elem
	display *argc
	display *argv
	display *must_free
	display *split_list@*argc
end

define ft_sort
	display *stack_a@argc
	display *stack_b@argc
	display argc
end

# ft_errors.c
define ft_errors
	display argc
	display *input_list@argc
end

define ft_are_args_nbr
	display i
	display j
	display argc
	display *argv@argc
end

# ft_sort_three.c
define ft_sort_three
	display *stack@(end+2)
	display ft_stack_min(stack)
	display ft_stack_max(stack, -1)
	display start
	display end
end

# ft_create_stack.c
define ft_create_stack
	display argc
	display argv
	display select
	display *stack@argc
	display i
	next
end

# ft_assert_stack.c
define ft_is_sorted
	display *stack@ft_stack_end(stack-2)
	display stack[i]
	display stack[i+1]
	display i
end

define ft_stack_start
	display *stack
	display *stack@start
	display start
end

define ft_stack_end
	display *stack
	display *stack@end
	display end
end

define ft_stack_min
	display *stack
	display *stack@start
	display start
	display end
	display min_idx
end

define ft_stack_max
	display *stack
	display *stack@start
	display start
	display end
	display max_idx
end

# ft_median.c
define ft_is_median
	display *stack
	display num
	display start
	display end
end

define ft_median
	display *stack
	display num
	display start
	display end
	display min
	display max
	display diff
end

define ft_min_above_thresh
	display *stack
	display stack[start].num
	display threshold
	display start
	display end
	display ft_stack_min(stack)
	display min_idx
	display stack[min_idx]
end	

# ft_order.c
define ft_check_order
	display *stack_a
	display *stack_b
	display idx
	display n_op_a
	display n_op_b
	display n_ops
	display min
	display ft_stack_min(stack_b).num
	display ft_stack_max(stack_b, -1).num

end

define ft_order
	display *stack_a
	display *stack_b
	display idx
	display n_ops

end

define ft_getontop_ops
	display *stack@(end+2)
	display sign
	display start
	display end
	display idx
	display median
	display n_ops
end

# ft_rotate.c
define ft_rotate
	
end

define ft_rev_rotate

end

define ft_rotate_top
	display *stack@ft_stack_end(stack-2)
	display stack[idx]
	display idx
	display op
	display n_ops
	display sign
end

# ft_sort_stack.c
define ft_sort_stack
	display *stack_a@stack_len
	display *stack_b@stack_len
	display stack_len
	display i
	display median
	display ft_stack_start(stack_b)
	display ft_stack_end(stack_b)
	display ft_best_op_idx(stack_b, stack_a, stack_len)
	display stack_a[i].num
	display ft_min_above_thresh(stack_a, stack_b[i].num).index
end

define ft_exec_move
	display *stack_a@stack_len
	display *stack_b@stack_len
	display stack_len
	display idx
	display start
	display ordered
	display ft_stack_min(stack_a).num
	display ft_stack_max(stack_a, -1).num
	display stack_b[idx].num
	display ft_min_above_thresh(stack_a, stack_b[idx].num).index
end

define ft_best_op_idx
	display *stack_a@stack_len
	display *stack_b@stack_len
	display stack_len
	display idx
	display cost
	display start
	display min_ops
	display stack_a[idx]
	display stack_b[idx]
end

define ft_get_align_ops
	display *stack_a@(ft_stack_end(stack_a)+2)
	display *stack_b@(ft_stack_end(stack_b)+2)
	display idx
	display n_ops
	display order
	display min_n_behind
	display ft_stack_min(stack_b).num
	display ft_stack_max(stack_b, -1).num
	display stack_a[idx].num
	display stack_b[min_n_behind.index]
end

# Start debugging from main.c
fs cmd
break main.c:52
break ft_exec_move
info break
run
main
rfr
next

# Start at ft_sort()
# fs cmd
# break main.c:118
# run
# info break
# ft_sort
# rfr

# Start at ft_sort_three()
# fs cmd
# break ft_sort_three
# run "1 3 2"
# # run "3 2 1"
# # sorted example
# # run "1 2 3"
# ft_sort_three
# rfr

# Start at ft_create_stack()
# fs cmd
# break main.c:52
# run
# main
# step
# ft_create_stack
# rfr
# next

# Start at ft_sort_stack() : test with 9 elements
# fs cmd
# break ft_sort_stack.c:56
# break ft_calc_move
# run
# # target record-full
# ft_sort_stack
# rfr

###
### Checker DBG
###

# define main
# 	display argc
# 	display *argv
# 	display *(argv+1)
# 	display *(argv+2)
# 	display *input_list
# 	display *stack_a
# 	display *stack_b
# 	display must_free
# 	display error
# end
#
# define ft_errors
# 	display argc
# 	display **input_list
# 	display **(input_list+1)
# end
#
# define ft_are_args_nbr
# 	display i
# 	display j
# 	display argc
# 	display **argv
# 	display **(argv+1)
# end

# Start debugging from checker.c
# fs cmd
# break main
# run "" 1
# main
# rfr
# next

# Start at ft_errors()
# fs cmd
# break ft_errors
# run "" 1
# ft_errors
# rfr
# next

# Start at ft_are_args_nbr()
# fs cmd
# break ft_are_args_nbr
# run "" 1
# ft_are_args_nbr
# rfr
# next
