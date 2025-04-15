
CC = cc #definition of the compiler  #varivel


C = -Wall -Wextra -Werror #definition of the flags


NAME = libft.a 	#name of library


FUNCTIONS = ft_isascii.c ft_strmapi.c ft_itoa.c ft_strdup.c ft_memcmp.c ft_putnbr_fd.c ft_toupper.c ft_isalpha.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strnstr.c ft_strlcat.c ft_strrchr.c ft_atoi.c ft_isdigit.c ft_memcpy.c ft_putstr_fd.c ft_strlcpy.c ft_strtrim.c ft_bzero.c ft_isprint.c ft_memmove.c ft_split.c ft_strlen.c ft_substr.c ft_calloc.c ft_itoa.c ft_memset.c ft_strchr.c ft_strmapi.c ft_tolower.c ft_isalnum.c ft_strjoin.c ft_putchar_fd.c ft_strdup.c ft_strncmp.c ft_toupper.c ft_isalpha.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strnstr.c


OBJECTS = $(FUNCTIONS:.c=.o)


all: $(NAME) #regra


$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)


#Suffix replacement
.c.o:
	$(CC) $(C) -c $< -o ${<:.c=.o}


clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY:  all clean fclean re
