# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kskender <kskender@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 11:34:30 by kskender          #+#    #+#              #
#    Updated: 2025/08/05 11:35:03 by kskender         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

CC := cc
CFLAGS := -Wall -Wextra -Werror -O3 -ffast-math -march=native

# Include paths
INCLUDES := -I include -I MLX42/include -I include/libft -I include/Printf

# Libraries and library paths
MLX_DIR := MLX42
MLX_BUILD := $(MLX_DIR)/build
MLX_LIB := -L $(MLX_BUILD) -lmlx42 -lglfw

LIBFT_DIR := include/libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

PRINTF_DIR := include/ft_printf
PRINTF_LIB := $(PRINTF_DIR)/libftprintf.a

# Source files
SRCS := src/main.c \
        src/initializing.c \
        src/handle_errors.c \
        src/julia.c \
        src/mandelbrot.c \
        src/burning_ship.c \
        src/color.c \
        src/hooks.c \
        src/utils.c

# Object files
OBJS := src/main.o \
        src/initializing.o \
        src/handle_errors.o \
        src/julia.o \
        src/mandelbrot.o \
        src/burning_ship.o \
        src/color.o \
        src/hooks.o \
        src/utils.o

all: $(LIBFT_LIB) $(PRINTF_LIB) $(MLX_LIB) $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB) $(MLX_LIB) \
		-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo \
		-o $(NAME)

# Compile each object file explicitly (NO pattern rules)
src/main.o: src/main.c include/fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

src/initializing.o: src/initializing.c include/fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

src/handle_errors.o: src/handle_errors.c include/fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

src/julia.o: src/julia.c include/fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

src/mandelbrot.o: src/mandelbrot.c include/fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

src/burning_ship.o: src/burning_ship.c include/fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

src/color.o: src/color.c include/fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

src/hooks.o: src/hooks.c include/fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

src/utils.o: src/utils.c include/fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build MLX42 library if needed
$(MLX_LIB):
	if [ ! -d "$(MLX_DIR)" ]; then \
		git clone --recursive https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
	fi
	cd $(MLX_DIR) && git submodule update --init --recursive
	mkdir -p $(MLX_BUILD)
	cd $(MLX_BUILD) && cmake .. && make

# Build Libft and Printf
$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean || true
	make -C $(PRINTF_DIR) clean || true

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_DIR)
	make -C $(LIBFT_DIR) fclean || true
	make -C $(PRINTF_DIR) fclean || true

re: fclean all

.PHONY: all clean fclean re $(LIBFT_LIB) $(PRINTF_LIB) $(MLX_LIB)