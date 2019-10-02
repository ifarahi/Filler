# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 15:54:16 by ifarahi           #+#    #+#              #
#    Updated: 2019/10/02 16:00:02 by ifarahi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = gcc -Wall -Wextra  -Werror
OBJECTS =   ft_isdigit.o ft_lstmap.o ft_memdel.o ft_putnbr.o ft_strcmp.o ft_strjoin.o ft_strncpy.o ft_strstr.o \
	ft_isprint.o ft_lstnew.o ft_memmove.o ft_putnbr_fd.o ft_strcpy.o ft_strlcat.o ft_strndup.o ft_strsub.o \
	ft_atoi.o ft_itoa.o ft_memalloc.o ft_memset.o ft_putstr.o ft_strdel.o ft_strlen.o ft_strnequ.o ft_strtrim.o \
	ft_bzero.o ft_lstadd.o ft_memccpy.o ft_putchar.o ft_putstr_fd.o ft_strdup.o ft_strmap.o ft_strnew.o ft_tolower.o \
	ft_isalnum.o ft_lstdel.o ft_memchr.o ft_putchar_fd.o ft_strcat.o ft_strequ.o ft_strmapi.o ft_strnstr.o ft_toupper.o \
	ft_isalpha.o ft_lstdelone.o ft_memcmp.o ft_putendl.o ft_strchr.o ft_striter.o ft_strncat.o ft_strrchr.o get_next_line.o \
	ft_isascii.o ft_lstiter.o ft_memcpy.o ft_putendl_fd.o ft_strclr.o ft_striteri.o ft_strncmp.o ft_strsplit.o
all: $(NAME)
$(NAME): $(OBJECTS) ./libft.h
	@ar rc $(NAME) $(OBJECTS)
%.o : %.c
	@$(CC) -g -c $< -o $@
clean:
	@rm -rf $(OBJECTS)
fclean: clean
	@rm -rf $(NAME)
re: fclean all
