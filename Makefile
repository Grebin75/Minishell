# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 10:52:52 by gabriel           #+#    #+#              #
#    Updated: 2023/03/08 13:31:28 by hcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(SRCS_DIR)/main.c \
			$(SRCS_DIR)/env/env.c \
			$(SRCS_DIR)/env/path.c \
			$(SRCS_DIR)/executor/executor.c \
			$(SRCS_DIR)/utils/strings.c \
			$(SRCS_DIR)/utils/strings1.c \
			$(SRCS_DIR)/utils/allocation.c \
			$(SRCS_DIR)/utils/struct.c \
			$(SRCS_DIR)/builtins/builtins.c \
			$(SRCS_DIR)/builtins/builtins1.c \
			$(SRCS_DIR)/lists/listutils_01.c \
			$(SRCS_DIR)/lists/listutils_02.c \

SRCS_DIR	= srcs

OBJS		= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR	= objs

NAME		= minishell

CC			= cc

CFLAGS 		= -Wall -Wextra -Werror -pthread -I includes  #-g -fsanitize=address

RM 			= rm -rf

all: $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -L/opt/homebrew/opt/readline/lib -lreadline $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
			mkdir -p $(@D)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(OBJS)

re: fclean all
