set trace-commands on
set logging on

define rfr
	refresh
end

define main
	display input_list
	display stack_a
	display stack_b
	display must_free
	display error
end

define ft_sort
	display stack_a
	display stack_b
	display argc
end

# Start debugging from main.c
# fs cmd
# break main:41
# run "1 2 3 -5"
# main
# rfr

# Start at ft_sort()
fs cmd
break ft_sort
run "1 2 3 -5"
# ft_sort
rfr
