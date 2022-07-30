SRCS = srcs/u_conversion.c \
	   srcs/ft_parsing.c \
	   srcs/ft_utils.c \
	   srcs/di_conversion.c \
	   srcs/ft_printf.c \
	   srcs/c_conversion.c \
	   srcs/s_conversion.c  \
	   srcs/p_conversion.c \
	   srcs/x_conversion.c \
	   srcs/perc_conversion.c \
	   srcs/ft_help_parsing.c \
	   srcs/ft_special_putnbr.c \
	   srcs/di_noprc_conversion.c \
	   srcs/di_prc_under0.c \
	   srcs/ft_special_putnbr.c \
	   srcs/ft_under_loadint.c \
	   srcs/ft_width.c \
	   srcs/s_interuptor1.c \
	   srcs/s_interuptor0.c \
	   srcs/u_prc_0.c \
	   srcs/u_prc_1.c \
	   srcs/ft_utils_1.c \
	   srcs/x_dispatch.c \
	   srcs/x_prc.c \
	   srcs/x_help.c \
	   srcs/p_help_load.c \
	   srcs/p_dispatch.c \
	   srcs/p_special_case.c \
	   srcs/p_special_case1.c

OBJS = ${SRCS:.c=.o}

HEADER=includes

NAME = libftprintf.a

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: ${NAME}

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(HEADER)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
