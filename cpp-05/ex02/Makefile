NAME= bureaucrat
CPP_C= c++
CPP_FLAG= -Wall -Werror -Wextra -std=c++98

SRC_DIR= ./src
SRC= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJ_DIR= ./obj
OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CPP_C) $(CPP_FLAG) -o $@ -c $<

$(NAME): $(addprefix $(OBJ_DIR)/, $(OBJ))
	$(CPP_C) $(CPP_FLAG) $(addprefix $(OBJ_DIR)/, $(OBJ)) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
