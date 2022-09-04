CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRCS = mandatory/client/client_main.c	\
			  mandatory/client/client_utils.c

SEVER_SRCS = mandatory/server/server_main.c

PRINTF_SRCS = mandatory/ft_printf/ft_flag_set.c	\
			 mandatory/ft_printf/ft_itoa.c					\
			 mandatory/ft_printf/ft_printf_memory_utils.c	\
			 mandatory/ft_printf/ft_printf_type.c			\
			 mandatory/ft_printf/ft_printf_type2.c			\
			 mandatory/ft_printf/ft_printf_utils.c			\
			 mandatory/ft_printf/ft_printf_utils2.c			\
			 mandatory/ft_printf/ft_printf.c				\
			 mandatory/ft_printf/ft_type_check.c			\
			 mandatory/ft_printf/ft_write.c					\

NAME = client
S_NAME = sever
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SEVER_OBJS = $(SEVER_SRCS:.c=.o)

RM = rm -f

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : $(CLIENT_OBJS) $(SEVER_OBJS) $(PRINTF_OBJS) 
	$(CC) $(CLIENT_OBJS) $(PRINTF_OBJS) -o $(NAME)
	$(CC) $(SEVER_OBJS) $(PRINTF_OBJS) -o $(S_NAME)
 
%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	$(RM) $(CLIENT_OBJS) $(SEVER_OBJS) $(PRINTF_OBJS)

fclean : clean
	$(RM) $(NAME) $(S_NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re bonus