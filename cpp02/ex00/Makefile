SRC =	main.cpp	\
		Fixed.cpp	\

OBJS = $(SRC:.cpp=.o)

NAME = a.out

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJ) -o $@ $^

%.o: %.cpp Fixed.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all