NAME = Polymorphism

HEADER =	Animal.hpp		\
			Dog.hpp			\
			Cat.hpp			\
			WrongAnimal.hpp	\
			WrongCat.hpp	\

SRC =	main.cpp		\
		Animal.cpp		\
		Dog.cpp			\
		Cat.cpp			\
		WrongAnimal.cpp	\
		WrongCat.cpp	\

OBJS = $(SRC:.cpp=.o)

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJ) -o $@ $^

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all