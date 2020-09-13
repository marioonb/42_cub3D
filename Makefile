# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 13:40:03 by mbelorge          #+#    #+#              #
#    Updated: 2020/02/10 14:36:21 by mbelorge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	cub3d.c\
			parsing/build_map.c\
			raycasting/keyboard_control.c\
			parsing/check_map.c\
			raycasting/screenshot.c\
			raycasting/sprite_init.c\
			raycasting/sprite_draw.c\
			parsing/check_error.c\
			parsing/error.c\
			parsing/check_fd.c\
			raycasting/initialisation.c\
			parsing/parse.c\
			parsing/free.c\
			raycasting/raycasting.c\
			raycasting/get_texture_color.c\
			raycasting/moove.c\
			raycasting/draw.c\
			tools/color_tools.c\
			tools/pixel_tools.c\
			tools/map_tools.c\

NAME	= Cub3D

OBJS	= ${SRCS:.c=.o}

LIBFT	= libft/libft.a

MINILIBX= minilibX/libmlx.a

CFLAGS	=	-Wall -Werror -Wextra -g

LOGFILE = $(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`
MSG = auto save

%.o: %.c	$(INCS)
		gcc $(CFLAGS) -o $@ -c $<

$(NAME):	${OBJS}
			make -C minilibX
			make -C libft
			gcc -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX)

all:		${NAME}

clean:
			rm -f ${OBJS}
			make clean -C libft

fclean:		clean
			rm -f ${NAME} cub.bmp
			make clean -C minilibX
			make fclean -C libft

git : fclean
	@(make fclean -C libft)
	@(git add *)
	@(git commit -m "$(LOGFILE) : $(MSG)")
	@(git push)

re:			fclean all

.PHONY:		all clean fclean
