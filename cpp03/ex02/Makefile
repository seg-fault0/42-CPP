SRC =	main.cpp		\
		ClapTrap.cpp	\
		ScavTrap.cpp 	\
		FragTrap.cpp	\

OBJS = $(SRC:.cpp=.o)

NAME = FragTrap

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJ) -o $@ $^

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all