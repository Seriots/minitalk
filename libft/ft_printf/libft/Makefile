SRCS = 	ft_atoi.c \
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
		ft_strjoin.c

BONUS = ft_lstadd_front.c \
		ft_lstadd_back.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS:.c=.o}

CC = cc

HEADERS = libft.h

INC = .

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

all : bonus

$(NAME) : ${OBJS}
	 ar rlcs $(NAME) $(OBJS)

%.o:%.c
		$(CC) -c $(FLAGS) -I$(INC) $< -o $@

bonus : ${OBJS} ${BONUS_OBJS}
	ar rlcs ${NAME} $(OBJS) $(BONUS_OBJS)

clean :
	rm -rf ${OBJS} $(BONUS_OBJS)

fclean : clean
	rm -rf ${NAME}

re : fclean all