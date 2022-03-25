#MAKEFLAGS = --silent

CC = 		gcc

CFLAGS = -Wall  -Wextra 
FSAN = -g -fsanitize=address

IFLAGS = 	-I includes -I includes_bonus -I libft/includes -I mlx

NAME = 		fdf

RM =		rm -rf

HEADER = 	includes/fdf.h includes/struct.h 
#HEADER_BONUS = includes_bonus/fdf_bonus.h includes_bonus/struct_bonus.h
OBJS_PATH = objs/
OBJS_PATH_BONUS = objs_bonus/

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
		srcs/color.c \
		srcs/draw_a_line_utils.c \
		srcs/init.c \
		srcs/write_img.c \
		srcs/graphical.c \
		srcs/read_map.c \
		srcs/free.c \
		srcs/scale.c \
		srcs/bonus.c
#SRC_BONUS = srcs_bonus/main_bonus.c \
		srcs_bonus/draw_a_line_bonus.c \
		srcs_bonus/color_bonus.c \
		srcs_bonus/draw_a_line_utils_bonus.c \
		srcs_bonus/init_bonus.c \
		srcs_bonus/bonus.c \
		srcs_bonus/write_img_bonus.c \
		srcs_bonus/graphical_bonus.c \
		srcs_bonus/read_map_bonus.c

OBJ = $(addprefix $(OBJS_PATH), $(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(OBJS_PATH_BONUS), $(SRC:.c=.o))

$(OBJS_PATH)%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS)  $(IFLAGS) -c $< -o $@
	@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"	

$(OBJS_PATH_BONUS)%.o: %.c $(HEADER_BONUS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -D BONUS=1 $(IFLAGS) -c $< -o $@
	@printf "%-15s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"		

$(NAME): 	$(OBJ) $(HEADER) libft
	@printf "%-15s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) libft.a mlx/libmlx_Linux.a -lXext -lX11 -lm -o ${NAME}
	@printf "\n${_GREEN}${_BOLD}[Fdf OK]${_END}\n"
	
all: $(NAME)

test:		$(OBJ) $(HEADER) libft
	@printf "%-15s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
	@$(CC) $(CFLAGS) $(FSAN) $(IFLAGS) $(OBJ) libft.a mlx/libmlx_Linux.a -lXext -lX11 -lm -o ${NAME}
	@printf "\n${_GREEN}${_BOLD}[Fdf OK]${_END}\n"

bonus:		$(OBJ_BONUS) $(HEADER) libft 
	@printf "%-15s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
	@$(CC) $(CFLAGS) -D BONUS=1 $(IFLAGS) $(OBJ_BONUS)  libft.a mlx/libmlx_Linux.a -lXext -lX11 -lm -o ${NAME}
	@printf "\n${_GREEN}${_BOLD}[Fdf OK]${_END}\n"


libft:
	@make -C libft/
	@cp ./libft/libft.a ./

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean:		clean
	@$(RM) $(NAME) $(OBJS_PATH) libf.a

re: 	fclean all

.PHONY: 	clean fclean re all libft