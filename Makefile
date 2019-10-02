FLAGS = -Wall -Werror -Wextra
NAME = ifarahi.filler
OBJECTS = functions_00.o functions_01.o functions_02.o main.o
LIBFT = libft/libft.a
all : $(NAME)
$(NAME) : $(OBJECTS) $(LIBFT)
	@gcc $(FLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
%.o : %.c
	@gcc $(FLAGS) -g -c $< -o $@
$(LIBFT):
	@make -C libft/
clean :
	@make clean -C libft/
	@rm -f $(OBJECTS)
fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft/
re : fclean all
