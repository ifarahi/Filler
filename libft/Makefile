NAME  = libft.a
all : $(NAME)
$(NAME) :
	gcc -c *.c -Wall -Werror -Wextra
	ar rc $(NAME) *.o 
clean :
	rm -f *.o
fclean : clean
	rm -rf $(NAME)
re : fclean all
