# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 20:18:57 by passunca          #+#    #+#              #
#    Updated: 2024/04/26 12:51:48 by passunca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  MAKE CONFIG                                 #
#==============================================================================#

SHELL	:= bash

# Default test values
set		?= 10
n		?= 100
arg		?= "2 7 5 3 9 4 6 8 1"
SIZES	:= 3 6 9
# SIZES	+= 25 50 100
# SIZES	+= 200 250 500
# SIZES	+= 1000 2000

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

USER			= passunca
NAME			= push_swap
NAME_BONUS		= checker
UNAME 			= $(shell uname)

### Message Vars
_SUCCESS 		= [$(GRN)SUCCESS$(D)]
_INFO 			= [$(BLU)INFO$(D)]
_NORM 			= [$(MAG)Norminette$(D)]
_NORM_SUCCESS 	= $(GRN)=== OK:$(D)
_NORM_INFO 		= $(BLU)File no:$(D)
_NORM_ERR 		= $(RED)=== KO:$(D)
_SEP 			= =====================

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_PATH	= src
BONUS_PATH	= bonus
LIBS_PATH	= lib
BUILD_PATH	= .build
TEMP_PATH	= .temp

SRC			= $(addprefix $(SRC_PATH)/, main.c ft_errors.c ft_assert_stack.c \
			  ft_ops.c ft_create_stack.c ft_sort_three.c ft_sort_stack.c \
			  ft_median.c ft_order.c ft_rotate.c)
BONUS		= $(addprefix $(BONUS_PATH)/, main_checker.c ft_assert_stack.c \
			  ft_create_stack.c ft_checker_errors.c ft_ops_checker.c \
			  ft_ops_mult.c ft_check_stack.c)


OBJS		= $(SRC:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)
BONUS_OBJS	= $(BONUS:$(BONUS_PATH)/%.c=$(BUILD_PATH)/%.o)

LIBFT_PATH	= $(LIBS_PATH)/libft
LIBFT_ARC	= $(LIBFT_PATH)/libft.a

VISUALIZER_PATH	= $(LIBS_PATH)/visualizer

RANDGEN_PATH	= $(LIBS_PATH)/randgen/

#==============================================================================#
#                              COMPILER & FLAGS                                #
#==============================================================================#

CC		= cc

CFLAGS		= -Wall -Werror -Wextra
DFLAGS		= -g

INC			= -I

#==============================================================================#
#                                COMMANDS                                      #
#==============================================================================#

AR			= ar rcs
RM			= rm -rf
MKDIR_P		= mkdir -p

MAKE		= make -C

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#

##@ push_swap Compilation Rules 🏗

all: deps $(NAME)		## Compile push_swap

bonus: all $(NAME_BONUS)	## Compile push_swap checker

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	@echo -n "$(MAG)█$(D)"
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

$(BUILD_PATH)/%.o: $(BONUS_PATH)/%.c
	@echo -n "$(MAG)█$(D)"
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

$(BUILD_PATH):
	$(MKDIR_P) $(BUILD_PATH)
	@echo "* $(YEL)Creating $(BUILD_PATH) folder:$(D) $(_SUCCESS)"

$(TEMP_PATH):
	$(MKDIR_P) $(TEMP_PATH)
	@echo "* $(YEL)Creating $(TEMP_PATH) folder:$(D) $(_SUCCESS)"

$(NAME): $(BUILD_PATH) $(LIBFT_ARC) $(OBJS)
	@echo "[$(YEL)Compiling push_swap$(D)]"
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJS) $(LIBFT_ARC) -o $(NAME)
	@echo "[$(_SUCCESS) compiling $(MAG)push_swap!$(D) $(YEL)🖔$(D)]"

$(NAME_BONUS): $(BUILD_PATH) $(LIBFT_ARC) $(BONUS_OBJS)
	@echo "[$(YEL)Compiling push_swap checker$(D)]"
	$(CC) $(CFLAGS) $(DFLAGS) $(BONUS_OBJS) $(LIBFT_ARC) -o $(NAME_BONUS)
	@echo "[$(_SUCCESS) compiling $(MAG)push_swap checker!$(D) $(YEL)🖔$(D)]"

$(LIBFT_ARC):
	$(MAKE) $(LIBFT_PATH) extra

deps: 			## Download/Update libft
	@if test ! -d "$(LIBFT_PATH)"; then make get_libft; \
		else echo "$(YEL)[libft]$(D) folder found 🖔"; fi
	@echo " $(RED)$(D) [$(GRN)Nothing to be done!$(D)]"

-include $(DEPS)

update_modules:
	@echo "* $(CYA)Updating submodules$(D)]"
	git submodule init
	git submodule update --recursive --remote
	@echo "* $(GRN)Submodules update$(D): $(_SUCCESS)"

get_libft:
	@echo "* $(CYA)Getting Libft submodule$(D)]"
	git clone git@github.com:PedroZappa/42_libft.git $(LIBFT_PATH)
	@echo "* $(GRN)Libft submodule download$(D): $(_SUCCESS)"

get_randgen:
	@echo "* $(CYA)Getting Randgen submodule$(D)]"
	git clone git@github.com:PedroZappa/randgen.git $(RANDGEN_PATH)
	@echo "* $(GRN)Randgen submodule download$(D): $(_SUCCESS)"

build_randgen: all $(TEMP_PATH)
	@if test ! -d "$(RANDGEN_PATH)"; then \
	git clone git@github.com:PedroZappa/randgen.git $(RANDGEN_PATH); fi
	$(MAKE) $(RANDGEN_PATH)

randgen: build_randgen		## Generate list of n random values w/ given seed
	@echo "* [$(YEL)Generating list of random values$(D)]"
	./lib/randgen/randgen $(n) $(seed) | tee $(TEMP_PATH)/rand.txt
	@echo "* [$(YEL)List of random values generated with$(D): $(_SUCCESS)]"

visual: bonus 	## Run push_swap Visualizer 
	@if test ! -d "$(VISUALIZER_PATH)"; then make get_visual; \
	else echo "$(YEL)[push_swap Visualizer]$(D) folder found 🖔"; \
	./$(VISUALIZER_PATH)/build/bin/visualizer; fi
	make visual

get_visual:
	@echo "* [$(CYA)Getting push_swap Visualizer$(D)]"
	git clone https://github.com/o-reo/push_swap_visualizer.git $(VISUALIZER_PATH)
	@echo "* $(GRN)Visualizer download$(D): $(_SUCCESS)"
	@echo "[$(YEL)Building push_swap Visualizer$(D)]"
	cd $(VISUALIZER_PATH) && mkdir build && cd build && cmake .. && make
	@echo "[$(_SUCCESS) building $(MAG)push_swap Visualizer!$(D) $(YEL)🖔$(D)]"

##@ Norm, Debug & Leak Check Rules 

norm: $(TEMP_PATH)		## Run norminette test on push_swap files
	@printf "${_NORM}: $(YEL)$(SRC_PATH)$(D)\n"
	@ls $(SRC_PATH) | wc -l > $(TEMP_PATH)/norm_ls.txt
	@printf "$(_NORM_INFO) $$(cat $(TEMP_PATH)/norm_ls.txt)\n"
	@printf "$(_NORM_SUCCESS) "
	@norminette $(SRC_PATH) | grep -wc "OK" > $(TEMP_PATH)/norm.txt; \
	if [ $$? -eq 1 ]; then \
		echo "0" > $(TEMP_PATH)/norm.txt; \
	fi
	@printf "$$(cat $(TEMP_PATH)/norm.txt)\n"
	@if ! diff -q $(TEMP_PATH)/norm_ls.txt $(TEMP_PATH)/norm.txt > /dev/null; then \
		printf "$(_NORM_ERR) "; \
		norminette $(SRC_PATH) | grep -v "OK"> $(TEMP_PATH)/norm_err.txt; \
		cat $(TEMP_PATH)/norm_err.txt | grep -wc "Error:" > $(TEMP_PATH)/norm_errn.txt; \
		printf "$$(cat $(TEMP_PATH)/norm_errn.txt)\n"; \
		printf "$$(cat $(TEMP_PATH)/norm_err.txt)\n"; \
	else \
		printf "[$(YEL)Everything is OK$(D)]\n"; \
	fi
	@echo "$(CYA)$(_SEP)$(D)"
	@make --no-print-directory norm_bonus

norm_bonus: 		## Run norminette test on chcker files
	@printf "${_NORM}: $(YEL)$(BONUS_PATH)$(D)\n"
	@ls $(BONUS_PATH) | wc -l > $(TEMP_PATH)/norm_ls.txt
	@printf "$(_NORM_INFO) $$(cat $(TEMP_PATH)/norm_ls.txt)\n"
	@printf "$(_NORM_SUCCESS) "
	@norminette $(BONUS_PATH) | grep -wc "OK" > $(TEMP_PATH)/norm.txt; \
	if [ $$? -eq 1 ]; then \
		echo "0" > $(TEMP_PATH)/norm.txt; \
	fi
	@printf "$$(cat $(TEMP_PATH)/norm.txt)\n"
	@if ! diff -q $(TEMP_PATH)/norm_ls.txt $(TEMP_PATH)/norm.txt > /dev/null; then \
		printf "$(_NORM_ERR) "; \
		norminette $(BONUS_PATH) | grep -v "OK"> $(TEMP_PATH)/norm_err.txt; \
		cat $(TEMP_PATH)/norm_err.txt | grep -wc "Error:" > $(TEMP_PATH)/norm_errn.txt; \
		printf "$$(cat $(TEMP_PATH)/norm_errn.txt)\n"; \
		printf "$$(cat $(TEMP_PATH)/norm_err.txt)\n"; \
	else \
		printf "[$(YEL)Everything is OK$(D)]\n"; \
	fi

check_ext_func: bonus		## Check for external functions
	@echo "[$(YEL)Checking for external functions$(D)]"
	@echo "$(YEL)$(_SEP)$(D)"
	@echo "$(CYA)Reading binary$(D): $(MAG)push_swap$(D)"
	nm ./push_swap | grep "U" | tee $(TEMP_PATH)/ext_func.txt
	@echo "$(YEL)$(_SEP)$(D)"
	@echo "$(CYA)Reading binary$(D): $(MAG)checker$(D)"
	nm ./checker | grep "U" | tee $(TEMP_PATH)/ext_func.txt
	@echo "$(YEL)$(_SEP)$(D)"

valgrind: all build_randgen		## Run push_swap w/ Valgrind
	make randgen n=$(n)
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "$$ARG" | tee $(TEMP_PATH)/out.txt; \
	# N_ARGS=$$(cat $(TEMP_PATH)/rand.txt | wc -w); \
	# echo "N_ARGS: $(GRN)$$N_ARGS$(D)";
	@make --no-print-directory print_test

gdb:				## Run with GDB w/ custom arg=""
	gdb --tui --args ./$(NAME) $(arg)

##@ Test Rules 🧪

print_test:
	@echo "$(YEL)$(_SEP)$(D)"
	@N_ARGS=$$(wc -w $(TEMP_PATH)/rand.txt | awk '{print $$1}'); \
	N_OPS=$$(wc -l < $(TEMP_PATH)/out.txt); \
	echo "*** $(MAG)$$N_ARGS$(D) elements sorted in: $(GRN)$$N_OPS$(D) ops"; \
	echo "$(YEL)$(_SEP)$(D)"; \

test_subject: all	## Test push_swap with examples from subject
	@echo "[$(YEL)Running push_swap tests from subject$(D)]"
	@echo "$(BGRN)*** Error Handling Tests ***$(D)"
	@echo "[$(RED)1/5$(D) :$(CYA)Success test$(D) (correct args)]"
	./push_swap 2 1 3 6 5 8
	@echo "[$(RED)2/5$(D) :$(CYA)Failure test$(D) (wrong args)]"
	./push_swap 0 one 2 3
	@echo "[$(RED)3/5$(D) :$(CYA)Failure test$(D) (wrong args)]"
	./push_swap 0 "" 2 3
	@echo "[$(RED)4/5$(D) :$(CYA)Error handling$(D) (for n > INT_MAX test)]"
	./push_swap 2147483648 1 2
	./push_swap 0 21474836848 1 2
	./push_swap "0 1 2147483648 2"
	@echo "[$(RED)5/5$(D) :$(CYA)Error handling$(D) (No args)]"
	./push_swap
	@echo "$(BGRN)*** Identity Tests ***$(D)"
	@echo "[$(RED)1/1$(D) :$(CYA)no output expected$(D) (Sorted stacks)]"
	./push_swap 42
	./push_swap 2 3 
	./push_swap 0 1 2 3
	./push_swap 0 1 2 3 4 5 6 7 8 9
	./push_swap 1 3 5 6 8 9
	@echo "$(BGRN)*** $ARG Tests ***$(D)"
	@echo "[$(RED)1/4$(D) :$(CYA)Simple test$(D) (sort 3 elements)]"
	ARG="2 1 0"; ./push_swap $$ARG | ./checker_linux $$ARG
	@echo "[$(RED)2/4$(D) :$(CYA)Simple test$(D) (sort 4 elements)]"
	ARG="2 1 0 3"; ./push_swap $$ARG | ./checker_linux $$ARG
	@echo "[$(RED)3/4$(D) :$(CYA)Simple test$(D) (sort 5 elements)]"
	ARG="1 5 2 4 3"; ./push_swap $$ARG | ./checker_linux $$ARG
	@echo "[$(RED)4/4$(D) :$(CYA)Simple test$(D) (sort 5 elements)]"
	ARG="7 3 9 11 0"; ./push_swap $$ARG | ./checker_linux $$ARG

test_n:	all build_randgen $(TEMP_PATH)			## Test with n elements
	make --no-print-directory randgen n=$(n)
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	./$(NAME) "$$ARG" | tee $(TEMP_PATH)/out.txt | ./checker_linux "$$ARG"; \
	make --no-print-directory print_test

test_three:	all build_randgen $(TEMP_PATH)			## Test with 3 element stack
	make --no-print-directory randgen n=3
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	./$(NAME) "$$ARG" | tee $(TEMP_PATH)/out.txt | ./checker_linux "$$ARG"; \
	make --no-print-directory print_test

test_six:	all build_randgen $(TEMP_PATH)			## Test with 6 element stack
	make --no-print-directory randgen n=6
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	./$(NAME) "$$ARG" | tee $(TEMP_PATH)/out.txt | ./checker_linux "$$ARG"; \
	make --no-print-directory print_test

test_rand100:	all build_randgen $(TEMP_PATH)		## Test with 100 random elements
	make --no-print-directory randgen n=100
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	./$(NAME) "$$ARG" | tee $(TEMP_PATH)/out.txt | ./checker_linux "$$ARG"; \
	make --no-print-directory print_test

test_rand500:	all build_randgen $(TEMP_PATH)	## Test with 500 random elements
	make --no-print-directory randgen n=500
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	./$(NAME) "$$ARG" | tee $(TEMP_PATH)/out.txt | ./checker_linux "$$ARG"; \
	make --no-print-directory print_test

test_nrand:	all build_randgen $(TEMP_PATH)	## Test with 20 sets of 500 random elements
	@echo "[$(CYA)Running tests with $(RED)$(set) $(CYA)sets of $(YEL)$(n) $(CYA)random elements$(D)]"
	@echo "[$(BGRN)Generating and sorting lists...$(D)]"
	@rm -f $(TEMP_PATH)/ops.txt 2>/dev/null
	@for i in {1..$(set)}; do \
		printf "Test set $(CYA)$$i$(D): "; \
		./lib/randgen/randgen $(n) > $(TEMP_PATH)/rand.txt; \
		ARG=$$(cat $(TEMP_PATH)/rand.txt); \
		./$(NAME) "$$ARG" | tee $(TEMP_PATH)/out.txt | ./checker_linux "$$ARG"; \
		make --no-print-directory print_test; \
		N_OPS=$$(wc -l < $(TEMP_PATH)/out.txt); \
		echo $$N_OPS >> $(TEMP_PATH)/ops.txt; \
		sleep 1s; \
	done
	make --no-print-directory get_stats

get_stats:
	@echo "[$(CYA)Calculating statistics...$(D)]"
	@MAX_OPS=$$(sort -n $(TEMP_PATH)/ops.txt | tail -n 1); \
	echo "Max for $(CYA)$$SIZE$(D) elements: $(RED)$$MAX_OPS$(D) ops" >> $(TEMP_PATH)/max.txt; \
	echo "Maximum: $(RED)$$MAX_OPS$(D)"
	@echo "Median: $(YEL)$$(awk '{sum += $$1} END {print sum / NR}' $(TEMP_PATH)/ops.txt)$(D)"
	@echo "Minimum: $(GRN)$$(sort -n $(TEMP_PATH)/ops.txt | head -n 1)$(D)"
	@echo "$(YEL)$(_SEP)$(D)"

test_checker: all bonus $(TEMP_PATH)		## Test checker with examples from subject
	@echo "[$(YEL)Running checker tests from subject$(D)]"
	@echo "$(BGRN)*** Error Handling Tests ***$(D)"
	@echo "[$(RED)1/5$(D) :$(CYA)Failure test$(D) (receiving chars)]"
	./checker 3 2 one 0
	@echo "[$(RED)2/5$(D) :$(CYA)Failure test$(D) (receiving empty string)]"
	./checker "" 1
	@echo "[$(RED)3/5$(D) :$(CYA)Error handling$(D) (no args)]"
	./checker
	@echo "[$(RED)4/6$(D) :$(CYA)Error handling$(D) (for n > INT_MAX test)]"
	./checker 2147483648 1 2
	./checker 0 21474836848 1 2
	./checker "0 1 2147483648 2"
	@echo "[$(RED)5/5$(D) :$(CYA)Error handling$(D) (No args)]"
	./checker
	@echo "$(BGRN)*** False Tests ***$(D)"
	@echo "[$(RED)1/2$(D) :$(CYA)Error handling$(D) (wrong operations)]"
	echo -e "sa\npb\nrrr" > $(TEMP_PATH)/input.txt
	./checker 0 9 1 8 2 7 3 6 4 5 < $(TEMP_PATH)/input.txt
	@echo "[$(RED)2/2$(D) :$(CYA)Failure test$(D) (wrong operations)]"
	echo -e "sa\nrra\npb" > $(TEMP_PATH)/input.txt
	./checker 3 2 1 0 < $(TEMP_PATH)/input.txt
	@echo "$(BGRN)*** Right Tests ***$(D)"
	@echo "[$(RED)1/2$(D) :$(CYA)Success test$(D) (sorted stacks)]"
	./checker 0 1 2 << EOF
	@echo "[$(RED)2/2$(D) :$(CYA)Success test$(D) (sorted stacks)]"
	echo -e "pb\nra\npb\nra\nsa\nra\npa\npa" > $(TEMP_PATH)/input.txt
	./checker 0 9 1 8 2 < $(TEMP_PATH)/input.txt
	@echo "[$(RED)3/3$(D) :$(CYA)Success test$(D) (correct operations)]"
	echo -e "rra\npb\nsa\nrra\npa" > $(TEMP_PATH)/input.txt
	./checker 3 2 1 0 < $(TEMP_PATH)/input.txt

test_complexity: all build_randgen $(TEMP_PATH)  	## Analyse Complexity
	@echo "[$(YEL)Running complexity tests$(D)]"
	@echo "[$(CYA)$(set)$(D) sets of $(MAG)$(SIZES)$(D) elements each$(D)]"
	rm -f $(TEMP_PATH)/max.txt 2>/dev/null
	@for size in $(SIZES); do \
		rm -f $(TEMP_PATH)/ops.txt 2>/dev/null; \
		echo "[$(YEL)Generating $(CYA)$(set) $(YEL)lists of size $(MAG)$$size$(D)]"; \
		for i in {1..$(set)}; do \
			./lib/randgen/randgen $$size > $(TEMP_PATH)/rand.txt; \
			ARG=$$(cat $(TEMP_PATH)/rand.txt); \
			./$(NAME) "$$ARG" | tee $(TEMP_PATH)/out.txt >/dev/null 2>&1; \
			N_OPS=$$(wc -l < $(TEMP_PATH)/out.txt); \
			echo "Sorted in: $(GRN)$$N_OPS$(D) ops"; \
			echo $$N_OPS >> $(TEMP_PATH)/ops.txt; \
			sleep 1s; \
		done; \
		sleep 1s; \
		echo "[$(YEL)$(_SEP)$(D)]"; \
		SIZE=$$size make --no-print-directory get_stats; \
	done
	@echo "[$(YEL)Displaying maximum values for each size$(D)]"
	@cat $(TEMP_PATH)/max.txt

test_checker_n: all bonus $(TEMP_PATH)	## Test bonus checker with n elements
	./lib/randgen/randgen $(n) > $(TEMP_PATH)/rand.txt
	@echo "[$(YEL)Running push_swap checker_linux$(D)]"
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	./$(NAME) "$$ARG" | tee $(TEMP_PATH)/out.txt | ./checker_linux "$$ARG"
	@echo "[$(YEL)Running push_swap passunca's checker$(D)]"
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	./$(NAME) "$$ARG" | tee $(TEMP_PATH)/out.txt | ./checker_linux "$$ARG"; \
	make --no-print-directory print_test

##@ Clean-up Rules 󰃢

clean: 				## Remove object files
	@echo "* $(MAG)Removing push_swap$(D)"
	@if [ -d "$(LIBS_PATH)" ]; then \
		$(MAKE) $(LIBFT_PATH) clean; \
		echo "* $(YEL)Removing $(CYA)$(LIBS_PATH)$(D) folder & files$(D): $(_SUCCESS)"; \
	fi
	@if [ -d "$(BUILD_PATH)" ]; then \
		$(RM) $(BUILD_PATH); \
		echo "* $(YEL)Removing $(CYA)$(BUILD_PATH)$(D) folder & files$(D): $(_SUCCESS)"; \
	fi
	@if [ -d "$(TEMP_PATH)" ]; then \
		$(RM) $(TEMP_PATH); \
		echo "* $(YEL)Removing $(CYA)$(TEMP_PATH)$(D) folder & files:$(D) $(_SUCCESS)"; \
	fi

fclean: clean	## Remove archives & executables
	$(RM) $(NAME) $(NAME_BONUS)
	@echo "* $(YEL)Cleaning executable$(D): $(_SUCCESS)"
	$(MAKE) $(LIBFT_PATH) fclean
	@echo "* $(YEL)Removing libft archive$(D): $(_SUCCESS)"

libclean: fclean	## Remove libft
	$(RM) $(LIBS_PATH)
	@echo "* $(YEL)Removing lib folder & files!$(D) : $(_SUCCESS)"

re: fclean all	## Purge and Recompile

##@ Help 󰛵

.PHONY: help
help: 			## Display this help page
	@awk 'BEGIN {FS = ":.*##"; \
			printf "\n=> Usage:\n\tmake $(GRN)<target>$(D)\n"} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
			printf "\t$(GRN)%-15s$(D) %s\n", $$1, $$2 } \
		/^##@/ { \
			printf "\n=> %s\n", substr($$0, 5) } ' Makefile
## Tweaked from source:
### https://www.padok.fr/en/blog/beautiful-makefile-awk

.PHONY: bonus deps get_libft update_modules clean fclean libclean re \
		norm valgrind
	

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
#
B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)
