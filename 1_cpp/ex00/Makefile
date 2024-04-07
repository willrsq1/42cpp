### COMPILATION ###

CC      = c++
FLAGS   = -Wall -Wextra -Werror

### EXECUTABLE ###

NAME    = Zombie_ex00

### SOURCE FILES ###

SOURCES =	main.cpp \
			Zombie.cpp \
			newZombie.cpp \
			randomChump.cpp \
			
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
