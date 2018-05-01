# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 17:33:46 by vkuksa            #+#    #+#              #
#    Updated: 2018/03/18 18:12:54 by vkuksa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvec.a
CFILES = \
	vec_new.c\
	vec_scale.c\
	vec_add.c\
	vec_sub.c\
	vec_magn.c\
	vec_norm.c\
	vec_dot.c\
	vec_cross.c\
	vec_rot_x.c\
	vec_rot_y.c\
	vec_rot_z.c\
	vec_cpy.c\
	vec_rot_xyz.c\
	vec_rot_zyx.c

HFILES = libvec.h

D_SRC = ./src/
D_OBJ = ./obj/
D_INC = ./includes/

SRC = $(addprefix $(D_SRC), $(CFILES))
OBJ = $(addprefix $(D_OBJ), $(CFILES:.c=.o))
INC = $(addprefix $(D_INC), $(HFILES))

CC = gcc
CFLAGS = -Wall -Werror -Wextra

C_RED = \033[31m
C_GREEN = \033[32m
C_NONE = \033[0m

all: $(NAME)

$(NAME): $(INC) $(D_OBJ) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "Libvec: %-24s$(C_GREEN)[done]$(C_NONE)\n" $@

$(D_OBJ):
	@mkdir $(D_OBJ)
	@printf "Libvec: %-24s$(C_GREEN)[done]$(C_NONE)\n" $@

$(D_OBJ)%.o:$(D_SRC)%.c $(INC)
	@$(CC) $(CFLAGS) -c -I $(D_INC) $< -o $@
	@printf "Libvec: %-24s$(C_GREEN)[done]$(C_NONE)\n" $@

clean:
	@rm -rf $(D_OBJ)
	@printf "Libvec: %-24s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean
	@rm -rf $(NAME)
	@printf "Libvec: %-24s$(C_RED)[done]$(C_NONE)\n" $@

re: fclean all

norm:
	@norminette $(D_INC) $(D_SRC)
