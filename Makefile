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
n		?= 100
arg		?= "2 7 5 3 4 9 6 8 1"
SIZES	:= 3 6 9 25 50 100
SIZES	+= 200 300 400 500
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

RANDGEN_PATH	= ./randgen/
PCG_C_PATH		= $(LIBS_PATH)/pcg-c
PCG_C_SRC		= $(PCG_C_PATH)/src
PCG_C_OBJS		= $(PCG_C_SRC:$(PCG_C_PATH)/%.c=$(BUILD_PATH)/%.o)
PCG_ARC			= $(PCG_C_PATH)/libpcg-c.a

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

get_libft:
	@echo "* $(CYA)Getting Libft submodule$(D)]"
	git clone git@github.com:PedroZappa/42_libft.git $(LIBFT_PATH)
	@echo "* $(GRN)Libft submodule download$(D): $(_SUCCESS)"

update_modules:
	@echo "* $(CYA)Updating submodules$(D)]"
	git submodule init
	git submodule update --recursive --remote
	@echo "* $(GRN)Submodules update$(D): $(_SUCCESS)"

randgen: all build_randgen	## Generate list of n random values w/ given seed
	@echo "* [$(YEL)Generating list of random values$(D)]"
	./randgen/randgen $(n) $(seed) | tee $(TEMP_PATH)/rand.txt
	@echo "* [$(YEL)List of random values generated with$(D): $(_SUCCESS)]"

build_randgen:
	@if test ! -d "$(PCG_C_PATH)"; then make get_pcgc; \
	else echo "[$(CYA)pcg-c$(D)] folder found $(YEL)🖔$(D)"; \
	echo "[$(_SUCCESS) compiling $(MAG)randgen!$(D) $(YEL)🖔$(D)]"; \
	fi
	@echo "[$(YEL)Compiling $(MAG)pcg-c$(D) Random Number Generator$(D)]"
	$(MAKE) $(RANDGEN_PATH)

get_pcgc:
	@echo "[Downloading $(CYA)Random Number Generator$(D) $(MAG)pcg-c$(D)]"
	git clone git@github.com:imneme/pcg-c.git $(PCG_C_PATH)
	@echo "* $(MAG)pcg-c$(D) download: $(_SUCCESS)"
	@echo "[$(YEL)Building $(MAG)pcg-c$(D) Random Number Generator$(D)]"
	$(MAKE) $(PCG_C_PATH)
	@echo "[$(_SUCCESS) building $(MAG)pcg-c$(D) $(CYA)Random Number Generator!$(D) $(YEL)🖔$(D)]"

visual: 	## Run push_swap Visualizer 
	@if test ! -d "$(VISUALIZER_PATH)"; then make get_visual; \
	else echo "$(YEL)[push_swap Visualizer]$(D) folder found 🖔"; \
	./$(VISUALIZER_PATH)/build/bin/visualizer; fi

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
	make randgen n=500
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "$$ARG" | tee $(TEMP_PATH)/push_swap_out.txt

gdb:				## Run with GDB w/ custom arg=""
	gdb --tui --args ./$(NAME) $(arg)

##@ Test Rules 🧪

print_test:
	@echo "$(YEL)$(_SEP)$(D)";
	@N_OPS=$$(wc -l < $(TEMP_PATH)/push_swap_out.txt); \
	echo "Sorted in: $(GRN)$$N_OPS$(D) ops"; \
	echo "$(YEL)$(_SEP)$(D)"; \

test_subject: all	## Test push_swap with examples from subject
	@echo "[$(YEL)Running push_swap tests from subject$(D)]"
	@echo "[$(RED)1/3$(D) :$(CYA)Success test$(D) (correct args)]"
	./push_swap 2 1 3 6 5 8
	@echo "$(YEL)$(_SEP)$(D)"
	@echo "[$(RED)2/3$(D) :$(CYA)Failure test$(D) (wrong args)]"
	./push_swap 0 one 2 3
	@echo "$(YEL)$(_SEP)$(D)"
	@echo "[$(RED)3/3$(D) :$(CYA)Failure test$(D) (wrong args)]"
	./push_swap 0 "" 2 3
	@echo "$(YEL)$(_SEP)$(D)"

test_n:	all build_randgen $(TEMP_PATH)			## Test with n elements
	make --no-print-directory randgen n=$(n)
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	./$(NAME) "$$ARG" | tee $(TEMP_PATH)/push_swap_out.txt | ./checker_linux "$$ARG"; \
	make --no-print-directory print_test

test_three:	all build_randgen			## Test with 3 element stack
	make --no-print-directory randgen n=3
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	./$(NAME) "$$ARG" | tee $(TEMP_PATH)/push_swap_out.txt | ./checker_linux "$$ARG"; \
	make --no-print-directory print_test

test_six:	all build_randgen			## Test with 6 element stack
	make --no-print-directory randgen n=6
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	./$(NAME) "$$ARG" | tee $(TEMP_PATH)/push_swap_out.txt | ./checker_linux "$$ARG"; \
	make --no-print-directory print_test

test_rand100:	all build_randgen		## Test with 100 random elements
	make --no-print-directory randgen n=100
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	./$(NAME) "$$ARG" | tee $(TEMP_PATH)/push_swap_out.txt | ./checker_linux "$$ARG"; \
	make --no-print-directory print_test

test_rand500:	all build_randgen	## Test with 500 random elements
	make --no-print-directory randgen n=500
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	./$(NAME) "$$ARG" | tee $(TEMP_PATH)/push_swap_out.txt | ./checker_linux "$$ARG"; \
	make --no-print-directory print_test

test_50rand500:	all build_randgen	## Test with 50 sets of 500 random elements
	@echo "[$(CYA)Running tests with 50 sets of 500 random elements$(D)]"
	@echo "[$(YEL)Generating and sorting lists...$(D)]"
	@rm -f $(TEMP_PATH)/ops.txt 2>/dev/null
	@for i in {1..50}; do \
		echo "Test set $(RED)$$i$(D)"; \
		./randgen/randgen 500 > $(TEMP_PATH)/rand.txt; \
		ARG=$$(cat $(TEMP_PATH)/rand.txt); \
		./$(NAME) "$$ARG" | tee $(TEMP_PATH)/push_swap_out.txt | ./checker_linux "$$ARG"; \
		N_OPS=$$(wc -l < $(TEMP_PATH)/push_swap_out.txt); \
		echo "Sorted in: $(GRN)$$N_OPS$(D) ops"; \
		echo "$(YEL)$(_SEP)$(D)"; \
		echo $$N_OPS >> $(TEMP_PATH)/ops.txt; \
	done
	@echo "[$(CYA)Calculating statistics...$(D)]"
	@echo "Minimum: $$(sort -n $(TEMP_PATH)/ops.txt | head -n 1)"
	@echo "Maximum: $$(sort -n $(TEMP_PATH)/ops.txt | tail -n 1)"
	@echo "Median: $$(awk '{sum += $$1} END {print sum / NR}' $(TEMP_PATH)/ops.txt)"
	@echo "$(YEL)$(_SEP)$(D)"

test_checker: all bonus		## Test checker with examples from subject
	@echo "[$(YEL)Running checker tests from subject$(D)]"
	@echo "[$(RED)1/4$(D) :$(CYA)Success test$(D) (correct operations)]"
	echo -e "rra\npb\nsa\nrra\npa" > $(TEMP_PATH)/input.txt
	./checker 3 2 1 0 < $(TEMP_PATH)/input.txt
	@echo "[$(RED)2/4$(D) :$(CYA)Failure test$(D) (wrong operations)]"
	echo -e "sa\nrra\npb" > $(TEMP_PATH)/input.txt
	./checker 3 2 1 0 < $(TEMP_PATH)/input.txt
	@echo "[$(RED)3/4$(D) :$(CYA)Failure test$(D) (receiving chars)]"
	./checker 3 2 one 0
	@echo "[$(RED)4/4$(D) :$(CYA)Failure test$(D) (receiving empty string)]"
	./checker "" 1

test_checker_n: all bonus	## Test bonus checker with n elements
	./randgen/randgen $(n) > $(TEMP_PATH)/rand.txt
	@echo "[$(YEL)Running push_swap checker_linux$(D)]"
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	./$(NAME) "$$ARG" | tee $(TEMP_PATH)/push_swap_out.txt | ./checker_linux "$$ARG"
	@echo "[$(YEL)Running push_swap passunca's checker$(D)]"
	@ARG=$$(cat $(TEMP_PATH)/rand.txt); \
	./$(NAME) "$$ARG" | tee $(TEMP_PATH)/push_swap_out.txt | ./checker_linux "$$ARG"; \
	make --no-print-directory print_test

gen_rand: $(TEMP_PATH)
	@for size in $(SIZES); do \
		echo "[$(YEL)Generating list of size $(GRN)$$size$(D)]"; \
		./randgen/randgen $$size > $(TEMP_PATH)/rand_$$size.txt; \
		echo "[$(_SUCCESS)]"; \
	done

run_rand: $(TEMP_PATH)
	@for size in $(SIZES); do \
		echo "$(YEL)Running $(MAG)push_swap $(YEL)with size $(GRN)$$size$(D)"; \
		ARG=$$(cat $(TEMP_PATH)/rand_$$size.txt); \
		./$(NAME) "$$ARG" | tee $(TEMP_PATH)/out_$$size.txt >/dev/null 2>&1; \
	done

test_complexity: gen_rand run_rand 	## Analyse Complexity
	@for size in $(SIZES); do \
		echo "$(YEL)Analyzing output for size $(GRN)$$size$(D)"; \
		wc -l $(TEMP_PATH)/out_$$size.txt; \
	done

##@ Clean-up Rules 󰃢

clean: 				## Remove object files
	$(MAKE) $(LIBFT_PATH) clean
	@echo "* $(YEL)Cleaning Libft objects 󰃢:$(D) $(_SUCCESS)"
	@echo "* $(MAG)Removing push_swap$(D)"
	$(RM) $(BUILD_PATH)
	@echo "* $(YEL)Removing $(CYA)$(BUILD_PATH)$(D) folder & files$(D): $(_SUCCESS)"
	$(RM) $(TEMP_PATH)
	@echo "* $(YEL)Removing $(CYA)$(TEMP_PATH)$(D) folder & files:$(D) $(_SUCCESS)"

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
