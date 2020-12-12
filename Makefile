ME	= libft.a
HEAD :	= -I../printf\
	-I../printf/
CFLAGS	= -Wall -Wextra -Werror
SRC :	= ../printf/.c\
	../printf//*.
all :    $(NAME)

$(NAME) :
	@gcc -c ${CFLAGS} ${HEAD} ${SRC}
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@gcc libft.a test.c
	@rm -f *.o
	@rm libft.a
	@mv a.out result
	@echo "\033[0;32mCompiled\033[0m"

clean : @rm -f *.o

fclean : clean
	@rm -f $(NAME)
	@rm -f result
	@echo "\033[1;31mDelete all\033[0m"

re :	fclean all
