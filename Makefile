VM = vm

CXX  = g++

CXXFLAGS = -g -Wall -Wextra -Werror -Wfatal-errors -MD -std=c++11 -I./incs/

VMSRCS	 = $(foreach dir,$(shell find srcs -type d),$(wildcard $(dir)/*.cpp))

OBJS_VM = $(VMSRCS:.cpp=.o)

all:     $(VM)

$(VM):  $(OBJS_VM)
	$(CXX) -o $(VM) $(OBJS_VM) $(CXXFLAGS) 
clean:
	rm -f $(OBJS_VM)

fclean:	clean
	rm -f $(VM)

re:	fclean all

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

-include $(DEPS)

.PHONY: all clean fclean re
