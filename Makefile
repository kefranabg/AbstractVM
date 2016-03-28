##
## Makefile for Makefile in /home/abgral_f/dev/avm
## 
## Made by abgral_f
## Login   <abgral_f@epitech.net>
## 
## Started on  Wed Feb 12 14:31:08 2014 abgral_f
## Last update Thu Feb 27 18:29:44 2014 abgral_f
##

RM	= rm -f

CC	= g++

NAME	= avm

PATH1	= include/

PATH2	= src/

SRC	= $(PATH2)main.cpp				\
	  $(PATH2)Parser.cpp				\
	  $(PATH2)Open.cpp				\
	  $(PATH2)Execute.cpp				\
	  $(PATH2)createOperand.cpp                     \
	  $(PATH2)Operations.cpp                        \
	  $(PATH2)specOperand.cpp                       \
	  $(PATH2)virtualMachine.cpp                    \
	  $(PATH2)operandCreator.cpp	                \
	  $(PATH2)run_avm.cpp		                \

OBJS	= $(SRC:.cpp=.o)

CPPFLAGS= -W -Wall -Werror -Wextra -I $(PATH1) -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)
	@echo -en "\t\033[32m> " $(NAME) " compiled\033[0m\n"

clean:
	$(RM) $(OBJS)
	@echo -en "\t\033[35m> " $(NAME) " cleaned\033[0m\n"

fclean: clean
	$(RM) $(NAME)
	@echo -en "\t\033[31m> " $(NAME) " executable removed\033[0m\n"

re: fclean all
