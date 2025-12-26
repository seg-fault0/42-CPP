SRCS = 	main.cpp	\
		Harl.cpp	\

FLAGS = -std=c++98 -Wall -Wextra -Werror

OBJS = $(SRCS:.cpp=.o)

NAME = harlFilter

all: $(NAME)

$(NAME):$(OBJS) Harl.hpp
	c++ $(FLAGS) $(OBJS) -o $(NAME) 

%.o: %.cpp
	c++ $(I) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all