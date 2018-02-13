SRC	=	src/test.cpp\
		src/human.cpp\
		src/print.cpp\
		src/game.cpp	

OBJS		=	$(SRC:.cpp=.o)

CFLAGS	=	-Wall -Werror

CC	=	g++

INCL	=	-I include/

NAME	=	test

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(INCL) $(OBJS) -lncurses

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
