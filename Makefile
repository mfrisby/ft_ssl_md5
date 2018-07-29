NAME =		ft_ssl

SRCS = 		srcs/ft_ssl.c srcs/init.c srcs/ft_md5.c srcs/ft_md5_static.c \
			srcs/ft_md5_aux.c srcs/ft_md5_abcd_words.c

INCS = 	-I ./incs

OBJS = $(patsubst srcs/%.c, objs/%.o, $(SRCS))

FLAGS =	-Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): 	objs $(OBJS)
			@make -C libft/
			@gcc $(FLAGS) -o $(NAME) $(OBJS) ./libft/libft.a
			@echo "\033[32mCompilation OK\033[m"

objs/%.o: 	srcs/%.c
			@gcc $(FLAGS) $(INCS) -o $@ -c $<

objs:
			@mkdir -p objs

clean:
	@rm -rf objs
	@echo "\033[33mclean done\033[m"

fclean: 		clean
	@/bin/rm -f $(NAME)
	@echo "\033[33mfclean done\033[m"

libfc:
	@make -C libft/ fclean

re: 			fclean all

.PHONY = 		all clean fclean re