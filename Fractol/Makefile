NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

PRINTFDIR = Printf
LIBFTDIR = $(PRINTFDIR)/libft
MLXDIR = minilibx

SRCS =  utils.c main.c pixels.c render.c fractal.c
OBJS = $(SRCS:.c=.o)

PRINTF = $(PRINTFDIR)/libftprintf.a

INCLUDES = -I$(PRINTFDIR) -I$(LIBFTDIR) -I$(MLXDIR)
LIBS = -L$(PRINTFDIR) -lftprintf -L$(MLXDIR) -lmlx -lXext -lX11 -lm

all: $(PRINTF) $(OBJS) $(NAME)

$(PRINTF):
	@make -C $(PRINTFDIR)

$(NAME): $(OBJS) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

.c.o:
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(PRINTFDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTFDIR) fclean

re: fclean all

.PHONY: all clean fclean re
