NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/error_handle.c mandatory/utils.c mandatory/ft_split.c \
mandatory/pipex.c mandatory/libft_func.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all