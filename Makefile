# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelkabia <eelkabia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/25 20:32:50 by eelkabia          #+#    #+#              #
#    Updated: 2025/01/08 22:32:15 by eelkabia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAME_BONUS = checker
SRC = check_input.c push_swap_utils.c push_swap.c \
		sort/array_utils.c sort/large_sort.c sort/push_element_to_a.c \
		sort/push_element_to_b.c sort/small_sort.c sort/sort_utils.c \
		operations/push_operation.c operations/reverse_rotate_operation.c \
		operations/rotate_operation.c operations/swap_operation.c \
		libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
		libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
		libft/ft_itoa.c libft/ft_lstadd_back_bonus.c libft/ft_lstadd_front_bonus.c \
		libft/ft_lstclear_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstiter_bonus.c \
		libft/ft_lstlast_bonus.c libft/ft_lstmap_bonus.c libft/ft_lstnew_bonus.c \
		libft/ft_lstsize_bonus.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_putstr.c \
		libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
		libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c \
		libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c \
		libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c \
		libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c \
		libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c
SRC_BONUS = bonus/checker_bonus.c bonus/check_input_bonus.c \
			bonus/push_swap_utils_bonus.c \
			bonus/operations_bonus/push_operation_bonus.c \
			bonus/operations_bonus/reverse_rotate_operation_bonus.c \
			bonus/operations_bonus/rotate_operation_bonus.c \
			bonus/operations_bonus/swap_operation_bonus.c \
			get_next_line/get_next_line.c \
			libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
			libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
			libft/ft_itoa.c libft/ft_lstadd_back_bonus.c libft/ft_lstadd_front_bonus.c \
			libft/ft_lstclear_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstiter_bonus.c \
			libft/ft_lstlast_bonus.c libft/ft_lstmap_bonus.c libft/ft_lstnew_bonus.c \
			libft/ft_lstsize_bonus.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_putstr.c \
			libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
			libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c \
			libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c \
			libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c \
			libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c \
			libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(SRC_BONUS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re

