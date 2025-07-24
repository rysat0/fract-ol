NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

RM = rm -f

SRCS = fill_frac.c hook.c main.c set_calc.c \
		utils1.c

OBJS = $(SRCS:.c=.o)

MLX_LINUX := -lmlx -lXext -lX11 -lm -lbsd

all : $(NAME)

$(NAME) : $(OBJS) libmlx.a
	cc $(OBJS) -L. $(MLX_LINUX) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
