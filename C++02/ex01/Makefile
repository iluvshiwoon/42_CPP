CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Fixed

# Source files
SRCS = main.cpp Fixed.cpp

# Object directory
OBJ_DIR = obj

# Object files with directory prefix
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Rule to compile .cpp to .o in obj directory
$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
