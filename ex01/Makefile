# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: steh <steh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 17:07:14 by steh              #+#    #+#              #
#    Updated: 2022/08/22 21:01:54 by steh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=	$(wildcard $(SRCS_DIR)/*.cpp)
SRCS_DIR		=	src
OBJ_DIR			=	obj
HEAD_DIR		=	header
NAME			=	program
# OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
OBJS			=	$(patsubst $(SRCS_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
CFLAGS			=	-Wall -Wextra -Werror -std=c++98 -pedantic -g -fsanitize=address
CC				=	c++	

all				: 	$(NAME)
					./$(NAME)

$(NAME)			:	$(OBJS)
					$(CC) $(CFLAGS) -I $(HEAD_DIR) $(OBJS) -o $@

$(OBJ_DIR)/%.o	:	$(SRCS_DIR)/%.cpp $(HEAD_DIR)
					mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -I $(HEAD_DIR) -c $< -o $@

clean			:
					@rm -rf $(OBJ_DIR)

fclean			:	clean
					@rm -f $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re