LIBFT = ./libft/libft.a

NAME = pipex

NAME_B = bonus/pipex

SRCS = srcs/pipex.c srcs/utils.c

SRCS_B = bonus/pipex_bonus.c srcs/utils.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

INCLUDES = $(wildcard ./includes/*.h)

CC = gcc -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) all -C ./libft
	@$(CC) -o $(NAME) $(LIBFT) $(OBJS)

bonus: $(OBJS_B)
	@$(MAKE) all -C ./libft
	@$(CC) -o $(NAME_B) $(LIBFT) $(OBJS_B)

clean :
	@rm -rf $(wildcard ./*.o)
	@rm -rf $(wildcard ./*/*.o)
	@rm -rf $(wildcard ./*/*/*.o)

fclean : clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re

norm:
	@norminette -R CheckForbiddenSourceHeader