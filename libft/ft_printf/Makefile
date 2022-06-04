NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

INC = .

LIBFT = libft/libft.a

SRCS = 	ft_printf.c \
		ft_printf_utils.c \
		ft_printf_utils2.c \
		ft_printf_components.c \
		conversions_files/ft_putstr_printf.c \
		conversions_files/ft_putnbr_printf.c \
		conversions_files/ft_putchar_printf.c \
		conversions_files/ft_puthexa_min_printf.c \
		conversions_files/ft_putpointeur_printf.c \
		conversions_files/ft_putpointeur2_printf.c \
		conversions_files/ft_puthexa_maj_printf.c \
		conversions_files/ft_putnbr_unsigned_printf.c

OBJS = ${SRCS:.c=.o}

%.o:%.c
	$(CC) $(FLAGS) -I$(INC) -c -o  $@ $<

all : $(NAME)

$(LIBFT):
	make -C $(dir $(LIBFT))

$(NAME) : $(LIBFT) ${OBJS}
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

bonus : all

clean :
	make -C $(dir $(LIBFT)) fclean
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : 
	make fclean
	make all

.PHONY : all re clean fclean bonus
