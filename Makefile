NAME = so_long
NAME_BNS = so_long_bonus

FLAGS = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra

CC = cc

SRCS = mandatory/game/init_game.c mandatory/game/init_map.c mandatory/game/handle_events.c mandatory/helper_functions/ft_strchr.c mandatory/helper_functions/ft_strcmp.c\
		mandatory/helper_functions/ft_strdup.c mandatory/helper_functions/ft_split.c  mandatory/helper_functions/ft_strjoin.c mandatory/helper_functions/ft_putnbr_fd.c mandatory/helper_functions/ft_strjoin_free.c mandatory/helper_functions/ft_strlen.c \
		mandatory/helper_functions/ft_substr.c mandatory/helper_functions/get_next_line.c mandatory/parsing/create_map.c mandatory/parsing/validate_arguments.c mandatory/parsing/validate_path.c mandatory/so_long.c

SRCS_BNS = bonus/game/init_game_bonus.c bonus/game/move_ennemie_bonus.c bonus/game/init_map_bonus.c bonus/game/handle_events_bonus.c bonus/helper_functions/ft_strchr_bonus.c bonus/helper_functions/ft_strcmp_bonus.c\
		bonus/helper_functions/ft_strdup_bonus.c bonus/helper_functions/ft_split_bonus.c bonus/helper_functions/ft_itoa_bonus.c bonus/helper_functions/ft_strjoin_bonus.c bonus/helper_functions/ft_strjoin_free_bonus.c bonus/helper_functions/ft_strlen_bonus.c \
		bonus/helper_functions/ft_substr_bonus.c bonus/helper_functions/get_next_line_bonus.c bonus/parsing/create_map_bonus.c bonus/parsing/validate_arguments_bonus.c bonus/parsing/validate_path_bonus.c bonus/so_long_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BNS = $(SRCS_BNS:.c=.o)

all: $(NAME)

bonus: $(NAME_BNS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(FLAGS) $(OBJS) -o $(NAME)

$(NAME_BNS): $(OBJS_BNS)
	$(CC) $(CFLAGS) $(FLAGS) $(OBJS_BNS) -o $(NAME_BNS)

mandatory/%.o : mandatory/%.c mandatory/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o : bonus/%.c bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_BNS)

fclean : clean
	$(RM) $(NAME) $(NAME_BNS)

re : fclean all
