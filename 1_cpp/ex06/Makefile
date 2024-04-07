### COMPILATION ###

CC      = c++
FLAGS   = -Wall -Wextra -Werror

### EXECUTABLE ###

NAME    = harlFilter

### SOURCE FILES ###

SOURCES =	main.cpp \
			Harl.cpp \
			
OBJS    = $(SOURCES:.cpp=.o)

### RULES ###

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.cpp *.hpp
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
