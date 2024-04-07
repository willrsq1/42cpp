### COMPILATION ###

CC      = c++
FLAGS   = -Wall -Wextra -Werror -std=c++98

### EXECUTABLE ###

NAME    = RPN

### SOURCE FILES ###

SOURCES =	main.cpp \
			RPN.cpp \
			
OBJS    = $(SOURCES:.cpp=.o)

### RULES ###

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.cpp *.hpp
	$(CC) $(FLAGS) -c -o $@ $<

# template: clean
# 	@$(MAKE)
	
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re template
