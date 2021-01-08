C = clang

NAME = ft_printf.a
LIBFT = libft
LIBFT_LTB = libft.a 

SRCS = 
	 ./ft_printf.c \
			  ./parse_all.c \
			  ./process_all.c \
			  ./prepare_sign.c\
			  ./print_int.c \
			  ./manage_box.c 
			  

OBJS	= $(SRCS:.c=.o)
INCS	= .
RM		= rm -f
LIBC	= ar rc
CC		= gcc
CFLAGS	= -Wall -Wextra - Werror	

.c.o :
	$(CC) $(CFLAGS) -c $< $(<:.c=.o) -I$(INCS)

$(NAME)	: $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)
#ex) # ar crv lib.a prog1.o prog2.o
#=> lib.a라는 이름의 라이브러리 파일을 생성하고 prog1.o, prog2.o


all : $(NAME)

fclean : clean
	$(RM) $(NAME) $(ALL)
	make clean -C $(LIBFT)

re : fclean all

ALL : all

.PHONY : all clean fclean re ALL .c.o