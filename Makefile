CC		=	gcc

CFLAGS		+=	-g -Wall -Wextra 

CPPFLAGS	+=	-I./include

NAME		=	mybsq

UT_NAME		=	unit_tests

OBJ		=	$(SRC:.c=.o)

SRC		=	src/main.c	\
			src/error_handling.c	\
			src/file_to_array.c	\
			src/array_utils.c	\
			src/display_usage.c	\
			src/count_fct.c	\
			src/algorithm.c

UT_SRC		=	./tests/test.c  \

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(UT_NAME)
	$(RM) *.c~
	$(RM) vgcore*
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.html
	$(RM) *.css
	$(RM) *~

re: fclean all

tests_run:
	$(CC) -o $(UT_NAME) $(CPPFLAGS) $(CFLAGS) --coverage $(UT_SRC) -lcriterion
	./$(UT_NAME)
	gcovr --html-details coverage.html
	cd build; gcovr -r.

debug: CFLAGS += -g
debug: $(NAME)

.PHONY: all clean fclean re debug
