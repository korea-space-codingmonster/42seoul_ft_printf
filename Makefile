# C = clang
# NAME = ft_printf.a
# LIBFT = libft
# LIBFT_LTB = libft.a
# SRCS = ./ft_printf.c \
# 		./parse_all.c \
# 		./process_all.c \
# 		./print_int.c \
# 		./print_char.c \
# 		./print_string.c \
# 		./print_pointer.c \
# 		./print_percent.c \
# 		./print_hexa.c \
# 		./store_nbyte.c \
# 		./manage_box.c \
# 		./prepare_sign.c

# OBJS = $(SRCS:.c=.o)
# INCS = .
# RM = rm -f
# LIBC = ar rc
# CC = gcc
# CFLAGS = -Wall -Wextra - Werror
# all : $(NAME)

# fclean : clean
# 	$(RM) $(NAME) $(ALL)
# 	make clean -C $(LIBFT)

# re : fclean all

# .c.o :
# 	$(CC) $(CFLAGS) -c $< $(<:.c=.o) -I$(INCS)

# $(NAME)	: $(OBJS)
# 	make all -C $(LIBFT)/
# 	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
# 	$(LIBC) $(NAME) $(OBJS)
# #ex) # ar crv lib.a prog1.o prog2.o
# #=> lib.a라는 이름의 라이브러리 파일을 생성하고 prog1.o, prog2.o


# .PHONY : all clean fclean re ALL .c.o



C = clang

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= ./ft_printf.c \
			  ./parse_all.c \
			  ./process_all.c \
			  ./print_char.c \
			  ./print_string.c \
			  ./print_int.c \
			  ./print_hexa.c \
			  ./print_pointer.c \
			  ./print_percent.c \
			  ./store_nbyte.c \
			  ./manage_box.c \
			  ./prepare_sign.c

OBJS		= $(SRCS:.c=.o)
INCS		= .
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME) $(bonus)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all

bonus : all

.PHONY: all clean fclean re bonus .c.o