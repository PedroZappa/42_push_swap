set trace-commands on
set logging on

define rfr
	refresh
end

define main
	display *input_list
	display *stack_a
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
	display start
	display end
end

# set print pretty on

# Start debugging from main.c
# fs cmd
# break main:42
# info break
# run "1 2 3 -4"
# main
# rfr

# Start at ft_sort()
# fs cmd
# break main.c:118
# run "1 2 3 -4"
# info break
# ft_sort
# rfr

# Start at ft_sort_three()
fs cmd
break ft_sort_three
# run "1 3 2"
run "3 2 1"
# run "1 2 3"
info break
ft_sort_three
rfr
