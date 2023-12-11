NAME			=	megaphone

SRC_FILES		=	megaphone.cpp

SRCS			= 	$(SRC_FILES)

BUILD_DIR		=	build
OBJS			=	$(SRC_FILES:%.cpp=$(BUILD_DIR)/%.o)

CC				=	c++
CC_FLAGS		=	-Wextra -Werror -Wall -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o:  %.cpp
	@mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re