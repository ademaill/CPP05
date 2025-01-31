CXX = c++
CFLAGSXX = -Wall -Werror -Wextra -std=c++98
NAME = Bureaucrat
SRCS = main.cpp Bureaucrat.cpp Form.cpp
HEADER = Bureaucrat.hpp
OBJ = $(SRCS:.cpp=.o)

$(NAME): $(OBJ)
		$(CXX) $(CFLAGSXX) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
		$(CXX) $(CFLAGSXX) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all fclean clean re
