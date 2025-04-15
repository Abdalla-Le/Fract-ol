
CC = cc


C = -Wall -Wextra -Werror


NAME = libftprintf.a

LIBFTNAME = libft.a


FUNCTIONS = is_hexa.c is_char.c is_int.c is_ptr.c ft_printf.c is_unsig.c

OBJECTS = $(FUNCTIONS:.c=.o)


all: $(NAME)

entry:
	make -C ./libft
	cp ./libft/$(LIBFTNAME) .
	mv $(LIBFTNAME) $(NAME)


$(NAME): $(OBJECTS) entry
	ar rcs $(NAME) $(OBJECTS)


.c.o:
	$(CC) $(C) -c $< -o ${<:.c=.o}


clean:
	rm -f $(OBJECTS)
	cd ./libft && make clean

fclean: clean
	rm -f $(NAME)
	cd ./libft && make clean

re: fclean all


.PHONY:  all clean fclean re
