NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

HEADERS = $(wildcard $(INC_DIR)/*.h)

SRCS = $(wildcard $(SRC_DIR)/*.c)

vpath %.c $(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

RM = rm

RMFLAGS = -rf

all : $(NAME)

clean :
		@$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean : clean
		@$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(OBJ_DIR) :
		@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c $(OBJ_DIR)
		@$(CC) $(CFLAGS) -I $(INC_DIR) -c  $< -o $@

$(NAME) : $(HEADERS) $(OBJS)
		@$(CC) -lpthread $(CFLAGS) -I $(INC_DIR) $(OBJS) -o $@
		