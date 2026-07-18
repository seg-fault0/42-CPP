SRCS =	main.cpp	\
		RPN.cpp		\

HEADER = RPN.hpp	\

NAME = RPN

CC = c++
FLAGS = -std=c++98 #-Wall -Wextra -Werror
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $@

%.o : %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
