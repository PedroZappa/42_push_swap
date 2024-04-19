# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 20:18:57 by passunca          #+#    #+#              #
#    Updated: 2024/04/19 15:43:22 by passunca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  MAKE CONFIG                                 #
#==============================================================================#

SHELL := bash

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

USER			= passunca
NAME			= push_swap
UNAME 			= $(shell uname)

### Message Vars
_SUCCESS 		= [$(GRN)SUCCESS$(D)]
_INFO 			= [$(BLU)INFO$(D)]
_NORM 			= [$(MAG)Norminette$(D)]
_NORM_SUCCESS 	= $(GRN)=== OK:$(D)
_NORM_INFO 		= $(BLU)File no:$(D)
_NORM_ERR 		= $(RED)=== KO:$(D)

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_PATH	= src
LIBS_PATH	= lib
BUILD_PATH	= .build

SRC			= $(addprefix $(SRC_PATH)/, main.c ft_errors.c ft_stack.c ft_ops.c \
			  ft_create_stack.c ft_sort_three.c ft_sort_stack.c ft_median.c \
			  ft_order.c ft_rotate.c)

OBJS		= $(SRC:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)
DEPS		= $(OBJS:.o=.d)

LIBFT_PATH	= $(LIBS_PATH)/libft
LIBFT_ARC	= $(LIBFT_PATH)/libft.a

VISUALIZER_PATH	= $(LIBS_PATH)/visualizer

RANDGEN_PATH	= ./test/
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

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	@echo -n "$(MAG)█$(D)"
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH):
	$(MKDIR_P) $(BUILD_PATH)
	@echo "* $(YEL)Creating $(BUILD_PATH) folder:$(D) $(_SUCCESS)"

$(NAME): $(BUILD_PATH) $(LIBFT_ARC) $(OBJS)
	@echo "[$(YEL)Compiling push_swap$(D)]"
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJS) $(LIBFT_ARC) -o $(NAME)
	@echo "[$(_SUCCESS) compiling $(MAG)push_swap!$(D) $(YEL)🖔$(D)]"

$(LIBFT_ARC):
	$(MAKE) $(LIBFT_PATH) extra

bonus:			## Compile push_swap with bonus features
	@echo "[$(YEL)Compiling push_swap with bonus features$(D)]"
	make all
	@echo "[$(_SUCCESS) compiling $(MAG)push_swap w/ bonus!$(D) $(YEL)🖔$(D)]"

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

##@ Test, Debug & Leak Check Rules 

norm: 		## Run norminette test
	@printf "${_NORM}\n"
	@ls $(SRC_PATH) | wc -l > norm_ls.txt
	@printf "$(_NORM_INFO) $$(cat norm_ls.txt)\n"
	@printf "$(_NORM_SUCCESS) "
	@norminette $(SRC_PATH) | grep -wc "OK" > norm.txt; \
	if [ $$? -eq 1 ]; then \
		echo "0" > norm.txt; \
	fi
	@printf "$$(cat norm.txt)\n"
	@if ! diff -q norm_ls.txt norm.txt > /dev/null; then \
		printf "$(_NORM_ERR) "; \
		norminette $(SRC_PATH) | grep -v "OK"> norm_err.txt; \
		cat norm_err.txt | grep -wc "Error:" > norm_errn.txt; \
		printf "$$(cat norm_errn.txt)\n"; \
		printf "$$(cat norm_err.txt)\n"; \
	else \
		printf "[$(YEL)Everything is OK$(D)]\n"; \
	fi

valgrind: all			## Run push_swap w/ Valgrind
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

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

build_randgen:	## Get & Build Random Number Generator
	@if test ! -d "$(PCG_C_PATH)"; then make get_pcgc; \
	else echo "[$(CYA)pcg-c$(D)] folder found $(YEL)🖔$(D)"; \
	fi
	@echo "[$(YEL)Compiling $(MAG)pcg-c$(D) Random Number Generator$(D)]"
	$(MAKE) $(RANDGEN_PATH)
	@echo "[$(_SUCCESS) compiling $(MAG)randgen!$(D) $(YEL)🖔$(D)]"

get_pcgc:
	@echo "[Downloading $(CYA)Random Number Generator$(D) $(MAG)pcg-c$(D)]"
	git clone git@github.com:imneme/pcg-c.git $(PCG_C_PATH)
	@echo "* $(MAG)pcg-c$(D) download: $(_SUCCESS)"
	@echo "[$(YEL)Building $(MAG)pcg-c$(D) Random Number Generator$(D)]"
	$(MAKE) $(PCG_C_PATH)
	@echo "[$(_SUCCESS) building $(MAG)pcg-c$(D) $(CYA)Random Number Generator!$(D) $(YEL)🖔$(D)]"

randgen: build_randgen	## Generate list of random values
	@echo "* [$(YEL)Generating list of random values$(D)]"
	./test/randgen $(n) $(seed)
	@echo "* [$(YEL)List of random values generated with$(D): $(_SUCCESS)]"

test_three:			## Test with 3 element stack
	@ARG="2 1 3"; ./$(NAME) $$ARG | ./checker_linux $$ARG

##@ Clean-up Rules 󰃢

clean: 				## Remove object files
	$(MAKE) $(LIBFT_PATH) clean
	@echo "* $(YEL)Cleaning Libft objects 󰃢:$(D) $(_SUCCESS)"
	@echo "* $(MAG)Removing push_swap$(D)"
	$(RM) $(BUILD_PATH)
	@echo "* $(YEL)Removing $(BUILD_PATH) folder & files$(D): $(_SUCCESS)"
	$(RM) norm.txt norm_ls.txt norm_err.txt norm_errn.txt
	@echo "* $(YEL)Removing Norminette temp files:$(D) $(_SUCCESS)"

fclean: clean	## Remove archives & executables
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@echo "* $(YEL)Cleaning executable$(D): $(_SUCCESS)"
	$(MAKE) $(LIBFT_PATH) fclean
	@echo "* $(YEL)Removing libft archive$(D): $(_SUCCESS)"

libclean: fclean	## Remove libft
	$(RM) $(LIBS_PATH)
	@echo "* $(YEL)Removing libft folder & files!$(D) : $(_SUCCESS)"

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
