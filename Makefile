NAME	=	fillit
CC		=	cc
CFLAGS	=	-Wextra -Werror -Wall -Wno-unused-parameter
CDEBUG	=	-g

L_PATH	=	libft
LIB		=	$(L_PATH)/libft.a
LIB_INC	=	-I$(L_PATH)

OBJS	=	objs/parser.o \
			objs/tetriminos.o \
			objs/board.o \
			objs/solver.o \
			objs/main.o

INC		=	-I.

ifeq ($(DEBUG), 1)
	CFLAGS	+=	$(CDEBUG)
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) Makefile
	@$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME)

objs/%.o: %.c
	@[[ -d objs ]] || mkdir -p objs/parser
	@$(CC) -c $< -o $@ $(CFLAGS) $(INC)

fclean: clean
	@rm -rf $(NAME)

clean:
	@rm -rf objs

re: fclean all
