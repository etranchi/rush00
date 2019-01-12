NAME = ft_retro

SRC_FILES = main.cpp\
			Game.cpp\
			Player.cpp

PP = g++

PP_FLAGS = -Wall -Werror -Wextra
LIB_FLAGS = -lncurses
O_FILES = $(SRC_FILES:.cpp=.o)

$(NAME): $(O_FILES)
	@$(PP) $(LIB_FLAGS) $(PP_FLAGS) $^ -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(O_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re
