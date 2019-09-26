# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ayundina <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/03 15:07:08 by ayundina      #+#    #+#                  #
#    Updated: 2019/08/03 15:07:11 by ayundina      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc

FLAGS = -g -Wall -Wextra -Werror

INCLUDES = -I ./includes -I ./libft

SRCS = $(addprefix ./srcs/, main.c \
		ft_read_ants.c \
		ft_read_rooms.c \
		ft_rooms_into_array.c \
		ft_read_connections.c \
		ft_hash.c \
		ft_delete_dead_ends.c \
		ft_bfs_level.c \
		ft_push_to_q.c \
		ft_is_in_q.c \
		ft_set_level_for_visited.c \
		ft_assign_room_level_n_q.c \
		ft_initialize_q.c \
		ft_visited_n_is_in_q.c \
		ft_start_n_free_q.c \
		ft_sort_connections.c \
		ft_start_connections_paths.c \
		ft_shortest_path.c \
		ft_valid_connection.c \
		ft_is_in_path.c \
		ft_delete_current_room_from_path.c \
		ft_count_connections.c \
		ft_malloc_paths.c \
		ft_malloc_arr_of_rooms.c \
		ft_malloc_pointer_to_arr_of_rooms.c \
		ft_malloc_room.c \
		ft_free_arr_of_rooms.c \
		ft_free_pointer_to_arr_of_rooms.c \
		ft_free_room.c \
		ft_delete_path.c \
		ft_count_steps_per_path.c \
		ft_paths_better_eval.c \
		ft_make_moves.c \
		ft_assign_ant_nums.c \
		ft_move_ants.c \
		ft_free_lem.c)

LIB = ./libft/libftprintf.a

all: $(LIB) $(NAME)

$(LIB):
		@make -C ./libft

$(NAME):
		@$(CC) $(FLAGS) $(SRCS) $(LIB) $(INCLUDES) -o $(NAME)
	    @echo "--> Compiled $(NAME)."

clean:
		@make clean -C ./libft

fclean: clean
		@make fclean -C ./libft
		@/bin/rm -f $(NAME)
		@echo "--> Deleted $(NAME)."

re: fclean all
