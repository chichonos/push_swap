NAME = push_swap

SRC = $(MAIN_SRC) $(SRC_PARSING) $(SRC_ALGO) $(SRC_OP)

MAIN_SRC = main.c

LIBFT_A = libft.a
LIBF_DIR = libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

PARSING = check.c error.c linkedlist.c
SRC_PARSING = $(addprefix srcs/parsing/, $(PARSING))

OPERATIONS = utils.c utils_2.c utils_3.c utils_4.c utils_5.c manip.c manip_2.c manip_3.c 
SRC_OP = $(addprefix srcs/operations/, $(OPERATIONS))

ALGO = sort.c bigsort.c radix.c bigsort_utils.c bubblesort.c
SRC_ALGO = $(addprefix srcs/algo/, $(ALGO))

OBJ = *.o

FLAGS = -Wextra -Wall -Werror -g -fsanitize=address
INCLUDE = includes

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

.c.o:
	@gcc $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBF_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) -I$(INCLUDE) $(LIBFT) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC)

debug: fclean
	@make FLAGS="$(FLAGS) -g"

exe: re
	@make -C ./ clean
	@echo $(YELLOW)"     - Executing $(NAME)... \n"$(NONE)
	@./$(NAME) $(m)
	@echo $(YELLOW)"\n     - Done -"$(NONE)

libftnorm:
	@echo $(GRAY) ""
	@make -C $(LIBF_DIR) norm
	@echo $(NONE) ""

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)
	@make -C $(LIBF_DIR) clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -C $(LIBF_DIR) fclean

re: fclean all