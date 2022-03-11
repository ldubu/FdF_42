#MAKEFLAGS = --silent

CC = 		gcc

CFLAGS = -g -Wall  -Wextra $(FSAN)
#FSAN = -fsanitize=address

IFLAGS = 	-I includes -I libft_42/includes -I minilibx-linux

NAME = 		fdf

RM =		rm -rf

HEADER = 	includes/fdf.h

OBJS_PATH = objs/

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m
_END= 	$'\033[37m
SRC =	main.c \
		srcs/draw_a_line.c \
		graphical.c

OBJ = $(addprefix $(OBJS_PATH), $(SRC:.c=.o))

$(OBJS_PATH)%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"			

$(NAME): 	$(OBJ) $(HEADER) libft
	@printf "%-15s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) libft.a minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -o ${NAME}
	@printf "\n${_GREEN}${_BOLD}[Fdf OK]${_END}\n"
	
all: $(NAME)

libft:
	@make -C libft_42/
	@cp ./libft_42/libft.a ./

clean:
	@$(RM) $(OBJ)

fclean:		clean
	@$(RM) $(NAME) $(OBJS_PATH) libf.a

re: 	fclean all

.PHONY: 	clean fclean re all libft