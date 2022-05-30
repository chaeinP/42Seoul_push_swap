# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/29 14:27:05 by chaepark          #+#    #+#              #
#    Updated: 2022/05/31 00:08:56 by chaepark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c ft_atoi.c ft_create.c ft_initialize_stack.c ft_split.c \
	 ft_utils.c ft_strlcpy.c ft_actions.c


OBJS= $(SRCS:.c=.o)


.c.o :
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -g $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
