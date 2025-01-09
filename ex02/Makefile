#=================== NAME ===================#

NAME = PmergeMe

#================ COMPILATOR ================#

CPP = c++

#=================== FLAGS ==================#

CFLAGS = -Wall -Wextra -Werror -g -std=c++98

#================== SOURCES =================#

SRCS =  PmergeMe.cpp \
		main.cpp \

#============== OBJECT FILES ================#

OBJS = $(SRCS:.cpp=.o)

#==========GENERATION BINARY FILES ==========#

%.o : %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@


#================= COLORS ===================#

GREEN = \033[32m
RESET = \033[0m

#================ UTILS PART ================#

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN) EXECUTABLE READY !$(RESET)"

clean: 
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
