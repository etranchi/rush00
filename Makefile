# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 15:34:13 by fmuller           #+#    #+#              #
#    Updated: 2019/01/13 03:19:17 by fmuller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#~~~~~~~~| COMPILATION |~~~~~~~~#
CXX					= clang++
CXXFLAGS			= -Wall -Werror -Wextra
CPPFLAGS			= -I $(HEADERS_DIR)
LDFLAGS				= 
LDLIBS				= -lncurses

#~~~~~~~~~~| SOURCES |~~~~~~~~~~#
SRC_NAME 			= main.cpp Game.cpp AEntity.cpp Player.cpp AEnemy.cpp BasicShip.cpp
SRC_DIR				= src
SRC					= $(addprefix $(SRC_DIR)/,$(SRC_NAME))

OBJ_NAME			= $(SRC_NAME:.cpp=.o)
OBJ_DIR				= build
OBJ					= $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

HEADERS_NAME		= 
HEADERS_DIR			= include
HEADERS				= $(addprefix $(HEADERS_DIR)/,$(HEADERS_NAME))

#~~~~~~~~~~~| COLOR |~~~~~~~~~~~#
EOC					= \033[0m
BOLD				= \033[1m
RED					= \033[31m
GREEN				= \033[32m

#~~~~~~~~~~~| OTHER |~~~~~~~~~~~#
NAME				= ft_retro
DEBUG				= 0

.PHONY: all clean fclean re

all: $(NAME)


$(NAME): $(OBJ)
	@$(CXX) $(LDFLAGS) $(LDLIBS) -o $@ $(OBJ)
	@echo "✅  $(BOLD)$(NAME)$(EOC)	$(GREEN)created$(EOC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
ifeq ($(DEBUG),0)
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<
else
	@$(CXX) -g $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<
endif

clean:
	@rm -rf $(OBJ_DIR)
	@echo "⚠️  $(BOLD)object file$(EOC)	$(RED)removed$(EOC)"

fclean: clean
	@rm -f $(NAME)
	@echo "❌  $(BOLD)$(NAME)$(EOC)	$(RED)removed$(EOC)"

re: fclean all
