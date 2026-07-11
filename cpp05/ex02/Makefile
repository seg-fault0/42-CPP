SRCS =	main.cpp					\
		Bureaucrat.cpp				\
		AForm.cpp					\
		PresidentialPardonForm.cpp	\
		RobotomyRequestForm.cpp		\
		ShrubberyCreationForm.cpp	\

HEADER =	Bureaucrat.hpp				\
			AForm.hpp					\
			PresidentialPardonForm.hpp	\
			RobotomyRequestForm.hpp		\
			ShrubberyCreationForm.hpp	\

NAME = Forms

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
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
