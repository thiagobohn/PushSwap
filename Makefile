# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srmeneses <srmeneses@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 09:51:57 by tbohn-co          #+#    #+#              #
#    Updated: 2024/04/08 18:51:00 by srmeneses        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                                COMPILATION                                   #
#******************************************************************************#

CFLAGS	:= -g -Wextra -Wall -Werror

#******************************************************************************#
#                                   PATH                                       #
#******************************************************************************#

HEADER_PATH	:=./include/

#******************************************************************************#
#                                   FILES                                      #
#******************************************************************************#

HEADER			:=	$(HEADER_PATH)push_swap.h
MANDATORY_NAME	:=	push_swap
MANDATORY_SRCS	:=	push_swap.c \
					error_handler.c \
					lists_handler.c \
					utils.c \
					movements1.c \
					movements2.c
MANDATORY_OBJS	:=	$(MANDATORY_SRCS:.c=.o)

BONUS_NAME		:=	server_bonus
BONUS_SRCS		:=	server_bonus.c
BONUS_OBJS		:=	$(BONUS_SRCS:.c=.o)


#******************************************************************************#
#                                   TARGETS                                    #
#******************************************************************************#

all: $(MANDATORY_NAME)

$(MANDATORY_NAME): $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) -o $(MANDATORY_NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -rf $(MANDATORY_OBJS)
	rm -rf $(BONUS_OBJS)

fclean: clean
	rm -rf $(MANDATORY_NAME)
	rm -rf $(BONUS_NAME)

re: fclean all

.PHONY: all, clean, fclean, re