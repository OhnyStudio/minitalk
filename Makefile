Server 		=	server
Client		= 	client
CC 			=	gcc
CFLAGS 		=	-Wall -Wextra -Werror -g
LIBFT_PATH	=	libft/
LIBFT_LIB	=	$(LIBFT_PATH)libft.a
CFILES		=	src/server.c \
				src/client.c
Y			=	"\033[33m"
R			=	"\033[31m"
G			=	"\033[32m"
B			=	"\033[34m"
X			=	"\033[0m"
UP			=	"\033[A"
CUT			=	"\033[K"
OBJECTS		=	$(CFILES:.c=.o)

all: subsystems $(Server)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -Imlx -c -o $@ $<
	@printf $(UP)$(CUT)

subsystems:
	@echo $(B)
	make -C $(LIBFT_PATH) all

$(Server): $(OBJECTS)
	@echo $(Y)Compiling [$(CFILES)]...$(X)
	@echo $(G)Finished [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(Server)]...$(X)
	@$(CC) $(CFLAGS) src/server.o $(LIBFT_LIB) -o $(Server)
	@echo $(G)Finished [$(Server)]$(X)
	@echo $(Y)Compiling [$(Client)]...$(X)
	@$(CC) $(CFLAGS) src/client.o $(LIBFT_LIB) -o $(Client)
	@echo $(G)Finished [$(Client)]$(X)

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(Server)
	@echo $(R)Removed [$(Server)]$(X)
	@rm -f $(Client)
	@echo $(R)Removed [$(Client)]$(X)

re: fclean all

.PHONY: all bonus libft clean fclean re