NAME			=	Account

HEADERS_FILES	=	Account.hpp \

HEADERS			= $(HEADERS_FILES)

SRC_FILES		=	tests.cpp \
					Account.cpp

SRCS			= 	$(SRC_FILES)

BUILD_DIR		=	build
OBJS			=	$(SRC_FILES:%.cpp=$(BUILD_DIR)/%.o)

CC				=	c++
CC_FLAGS		=	-std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o:  %.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

.PHONY: all clean fclean re