SRC = main.cpp Bureaucrat.cpp Form.cpp 
OBJ = $(SRC:.cpp=.o)
CC = g++
FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = Bureaucrat

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.Phony: all clean fclean re 