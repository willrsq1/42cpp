### COMPILATION ###

CC      = c++
FLAGS   = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

### EXECUTABLE ###

NAME    = ex02

### SOURCE FILES ###

SOURCES =	main.cpp \
			
OBJS    = $(SOURCES:.cpp=.o)

### RULES ###

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.cpp *.hpp *.tpp
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
