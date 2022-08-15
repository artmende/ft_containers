# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artmende <artmende@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 13:54:56 by artmende          #+#    #+#              #
#    Updated: 2022/08/15 17:57:13 by artmende         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS_VECTOR_FT =	../main_vector_ft.cpp
SRCS_STACK_FT =		../main_stack_ft.cpp
SRCS_MAP_FT =		../main_map_ft.cpp
SRCS_SET_FT =		../main_set_ft.cpp

SRCS_VECTOR_STD =	../main_vector_std.cpp
SRCS_STACK_STD =	../main_stack_std.cpp
SRCS_MAP_STD =		../main_map_std.cpp
SRCS_SET_STD =		../main_set_std.cpp

OBJS_VECTOR_FT = $(SRCS_VECTOR_FT:.cpp=.o)
OBJS_STACK_FT = $(SRCS_STACK_FT:.cpp=.o)
OBJS_MAP_FT = $(SRCS_MAP_FT:.cpp=.o)
OBJS_SET_FT = $(SRCS_SET_FT:.cpp=.o)

OBJS_VECTOR_STD = $(SRCS_VECTOR_STD:.cpp=.o)
OBJS_STACK_STD = $(SRCS_STACK_STD:.cpp=.o)
OBJS_MAP_STD = $(SRCS_MAP_STD:.cpp=.o)
OBJS_SET_STD = $(SRCS_SET_STD:.cpp=.o)

RM = rm -f

NAME_VECTOR_FT = vector_test_ft
NAME_STACK_FT = stack_test_ft
NAME_MAP_FT = map_test_ft
NAME_SET_FT = set_test_ft

NAME_VECTOR_STD = vector_test_std
NAME_STACK_STD = stack_test_std
NAME_MAP_STD = map_test_std
NAME_SET_STD = set_test_std

all: $(NAME_VECTOR_FT) $(NAME_VECTOR_STD) $(NAME_STACK_FT) $(NAME_STACK_STD) $(NAME_MAP_FT) $(NAME_MAP_STD) $(NAME_SET_FT) $(NAME_SET_STD)


$(NAME_VECTOR_FT): $(OBJS_VECTOR_FT)
	@$(CXX) -o $(NAME_VECTOR_FT) $(CXXFLAGS) $(OBJS_VECTOR_FT)

$(NAME_VECTOR_STD): $(OBJS_VECTOR_STD)
	@$(CXX) -o $(NAME_VECTOR_STD) $(CXXFLAGS) $(OBJS_VECTOR_STD)


$(NAME_STACK_FT): $(OBJS_STACK_FT)
	@$(CXX) -o $(NAME_STACK_FT) $(CXXFLAGS) $(OBJS_STACK_FT)

$(NAME_STACK_STD): $(OBJS_STACK_STD)
	@$(CXX) -o $(NAME_STACK_STD) $(CXXFLAGS) $(OBJS_STACK_STD)


$(NAME_MAP_FT): $(OBJS_MAP_FT)
	@$(CXX) -o $(NAME_MAP_FT) $(CXXFLAGS) $(OBJS_MAP_FT)

$(NAME_MAP_STD): $(OBJS_MAP_STD)
	@$(CXX) -o $(NAME_MAP_STD) $(CXXFLAGS) $(OBJS_MAP_STD)

$(NAME_SET_FT): $(OBJS_SET_FT)
	@$(CXX) -o $(NAME_SET_FT) $(CXXFLAGS) $(OBJS_SET_FT)

$(NAME_SET_STD): $(OBJS_SET_STD)
	@$(CXX) -o $(NAME_SET_STD) $(CXXFLAGS) $(OBJS_SET_STD)

.cpp.o:
	@$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

clean:
	@$(RM) $(OBJS_VECTOR_FT) $(OBJS_VECTOR_STD) $(OBJS_STACK_FT) $(OBJS_STACK_STD) $(OBJS_MAP_FT) $(OBJS_MAP_STD) $(OBJS_SET_FT) $(OBJS_SET_STD)

fclean: clean
	@$(RM) $(NAME_VECTOR_FT) $(NAME_VECTOR_STD) $(NAME_STACK_FT) $(NAME_STACK_STD) $(NAME_MAP_FT) $(NAME_MAP_STD) $(NAME_SET_FT) $(NAME_SET_STD)

re: fclean all

.PHONY: clean fclean re all
