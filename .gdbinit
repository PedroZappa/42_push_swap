set trace-commands on
set logging enabled on

define rfr
	refresh
end

define main
	display *input_list
	display *stack_a
	display *(stack_a+1)
	display *(stack_a+2)
	display *(stack_a+3)
	display *(stack_a+4)
	display *stack_b
	display must_free
	display error
end

define ft_sort
	display stack_a
	display stack_b
	display argc
end

define ft_sort_three
	display *stack
	display *(stack+1)
	display *(stack+2)
	display *(stack+3)
	display start
	display end
end

define ft_create_stack
	display argc
	display argv
	display select
	display *stack
	display *(stack+1)
	display *(stack+2)
	display *(stack+3)
	display *(stack+4)
	display i
	next
end

define ft_sort_stack
	display *stack_a@stack_len
	display *stack_b@stack_len
	display stack_len
	display i
	display median
end

# set print pretty on
# set print elements 2
set print array on

# Start debugging from main.c
#fs cmd
# break main:42
# info break
# run "1 2 3 -4"
# main
# rfr
# next

# Start at ft_sort()
# fs cmd
# break main.c:118
# run "1 2 3 -4"
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
# run "1 2 3 -4"
# main
# step
# ft_create_stack
# rfr
# next

# Start at ft_sort_stack()
fs cmd
break ft_sort_stack
run "1 2 3 0 6 8 5 7"
ft_sort_stack
rfr

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
