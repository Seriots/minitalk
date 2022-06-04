SRCS = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
 		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_striteri.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strlcat.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_lstadd_front.c \
		ft_lstadd_back.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_power.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		
FT_PRINTF = ft_printf.c \
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

FT_PRINTF_SRCS = $(addprefix ft_printf/, $(FT_PRINTF))

OBJS = $(SRCS:.c=.o)

FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)

CC = cc

INC = -I. \
	-Iget_next_line \
	-Ift_printf \
	-Ift_printf/conversions_files

HEADERS = libft.h

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

%.o:%.c
		gcc -c $(FLAGS) $(INC) $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(FT_PRINTF_OBJS)
	 ar rlcs $(NAME) $(OBJS) $(FT_PRINTF_OBJS)

clean :
	rm -rf $(OBJS) $(FT_PRINTF_OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : re fclean clean all
