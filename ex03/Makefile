CC = c++
CFLAGS = -g -O0 -Wall -Werror -Wextra -std=c++98
RM = rm -f

NAME = interface

SRC = main.cpp AMateria.cpp MateriaSource.cpp Ice.cpp Cure.cpp Character.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ) 
	
fclean:
	@$(RM) $(NAME) $(OBJ)

re: fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

leak:
	leaks --atExit -- ./$(NAME)