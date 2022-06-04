
SRCS_C = client.c

SRCS_S = server.c

LIBFT = libft/libft.a

OBJS_C = $(patsubst %.c, objs/%.o,$(SRCS_C))

OBJS_S = $(patsubst %.c, objs/%.o,$(SRCS_S))

NAME_C = client

NAME_S = server

FLAGS = -Wall -Wextra -Werror

CC = cc

objs/%.o: %.c $(LIBFT)
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME_C) $(NAME_S)

$(LIBFT) :
	make -C $(dir $(LIBFT))

$(NAME_C) : $(OBJS_C)
	$(CC) $(FLAGS) $(OBJS_C) libft/libft.a -o $(NAME_C)

$(NAME_S) : $(OBJS_S)
	$(CC) $(FLAGS) $(OBJS_S) libft/libft.a -o $(NAME_S)

clean :
	make fclean -C $(dir $(LIBFT))
	rm -f $(OBJS_C) $(OBJS_S)

fclean :
	make clean
	rm -f $(NAME_C) $(NAME_S) 

re :
	make fclean
	make all

.PHONY : re clean fclean all