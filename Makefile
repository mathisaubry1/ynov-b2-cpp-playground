SRC	=	src/main.cpp\
		src/human.cpp\
		src/print.cpp\
		src/game.cpp\
		src/fight.cpp	

OBJS		=	$(SRC:.cpp=.o)

CFLAGS	=	-Wall -Werror

CC	=	g++

INCL	=	-I include/

NAME	=	humain_game

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(INCL) $(OBJS) -lncurses

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
