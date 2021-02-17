# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 08:45:26 by jecaudal          #+#    #+#              #
#    Updated: 2021/02/17 09:28:03 by jecaudal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	tester

SRCS		=	test_menu.cpp				\
				srcs/vector/main_vector.cpp	\
				srcs/list/main_list.cpp		\
				srcs/queue/main_queue.cpp	\
				srcs/stack/main_stack.cpp	\
				srcs/map/main_map.cpp		\
				srcs/test_tools/menu.cpp	\
				srcs/test_tools/print_functions.cpp

CC			=	g++

OBJS		=	$(SRCS:.cpp=.o)

CFLAGS		+=	-Wall -Werror -Wextra

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

san			:	$(OBJS)
				$(CC) -o $(NAME) -fsanitize=address $(CFLAGS) $(OBJS)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all
