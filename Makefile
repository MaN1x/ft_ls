# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wanton <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/23 13:15:24 by wanton            #+#    #+#              #
#    Updated: 2019/12/24 11:27:48 by wanton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

DIR_PATH = dir_utilities/
FILE_PATH = dir_utilities/file_utilities/
LIB_PATH = lib/

SRC1 = print_st_size.c print_pw_size.c check_args.c main.c print_dir.c scan.c scan_utilities.c print_assist.c
SRC_DIR = dir_add.c dir_getend.c dir_list_size.c dir_list_swap.c dir_new.c free_dir_list.c sort_dir_list.c
FILE_SRC = file_add.c file_list_size.c file_list_swap.c file_new.c free_files.c sort_file_list.c file_size.c 

INC = -I . -I ./$(DIR_PATH) -I ./$(FILE_PATH)

SRC2 = $(addprefix $(DIR_PATH), $(SRC_DIR))
SRC3 = $(addprefix $(FILE_PATH), $(FILE_SRC))

FLAGS = -Wall -Wextra -Werror

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)

all: $(NAME)

$(NAME): $(OBJ1) $(OBJ2) $(OBJ3)
		@make -C $(LIB_PATH)
		@gcc $(FLAGS) $(OBJ2) $(OBJ3) $(OBJ1) $(INC) -L $(LIB_PATH) -lft -o $(NAME)

./%.o: %.c
		@gcc $(FLAGS) -c $< -o $@ 

clean:
		@make -C $(LIB_PATH)/ clean
		@/bin/rm -f $(OBJ1) $(OBJ2) $(OBJ3)

fclean: clean
		@make -C $(LIB_PATH)/ fclean
		@/bin/rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re
