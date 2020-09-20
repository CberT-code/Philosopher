NAME = 			philo_one

SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
INCS_PATH = ./includes/

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))
OBJS = $(addprefix $(OBJS_PATH),$(OBJS_NAME))
INCS = $(addprefix -I,$(INCS_PATH)) -lpthread

OBJS_NAME = $(SRCS_NAME:.c=.o)

SRCS_NAME= 		ft_lib.c ft_lib2.c main.c start.c utils.c monitoring.c free.c

CC = gcc

FLAGS =	-Wall -Werror -Wextra

LOGFILE	=		$(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`

all: 			$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(INCS) 
		@echo "\033[0;34mExecutable Philo \033[0m \033[0;32m [OK] \033[0m"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c includes/philo.h
		@mkdir -p $(OBJS_PATH)
		@gcc $(FLAGS) $(INCS) -o $@ -c $<

run : 
		make re
		./$(NAME)

git:			fclean
				git add -A
				git add *
				git commit -u -m "$(LOGFILE) $(MSG)"
				git push

clean:
		@rm -rf $(OBJS_PATH)
		@echo "deleted ./obj/"

fclean: clean
		@rm -rf $(NAME)
		@echo "deleted ./minishell"

re: fclean all

.PHONY:			all clean fclean re git
