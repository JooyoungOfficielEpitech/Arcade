##
## EPITECH PROJECT, 2018
## ArcadeApplication
## File description:
## Makefile
##

CXX		=	g++

INC		=	-I inc/

CXXFLAGS	+=	-Wall -Wextra -pedantic -std=c++17 -fPIC $(INC)

LDFLAGS		=	-ldl

## arcade

NAME		=	arcade

SRC		=	core/main.cpp				\
			games/menu.cpp				\
			lib/loadLib.cpp				\
			lib/loadGame.cpp			\
			lib/tools.cpp				\
			lib/readDir.cpp				\
			games/score.cpp				\

OBJ		=	$(SRC:.cpp=.o)

## plugin sfml

NAME_SFML	=	lib/lib_arcade_sfml.so

SRC_SFML	=	lib/sfml.cpp				\
			lib/tools.cpp				\

OBJ_SFML	=	$(SRC_SFML:.cpp=.o)

LDFLAGS_SFML	=	-shared -fPIC -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio

## plugin sdl

NAME_SDL	=	lib/lib_arcade_sdl.so

SRC_SDL		=	lib/sdl.cpp				\
			lib/tools.cpp				\

OBJ_SDL		=	$(SRC_SDL:.cpp=.o)

LDFLAGS_SDL	=	-shared -fPIC -lSDL2 -Lbonus -lSDL2_image -lSDL2_ttf -Wl,-rpath=bonus
#LDFLAGS_SDL	=	-shared -fPIC -lSDL2 -lSDL2_image -lSDL2_ttf


## plugin libcaca

NAME_CACA	=	lib/lib_arcade_libcaca.so

SRC_CACA	=	lib/libcaca.cpp \
				lib/tools.cpp

OBJ_CACA	=	$(SRC_CACA:.cpp=.o)

LDFLAGS_CACA	=	-shared -fPIC -lcaca

## pacman

NAME_PACMAN	=	games/lib_arcade_pacman.so

SRC_PACMAN	=	games/pacmanGame.cpp		\
			lib/tools.cpp			\
			games/score.cpp			\

OBJ_PACMAN	=	$(SRC_PACMAN:.cpp=.o)

LDFLAGS_PACMAN	=	-shared -fPIC

## snake

NAME_SNAKE	=	games/lib_arcade_nibbler.so

SRC_SNAKE	=	games/nibbler/nibbler.cpp	\
			lib/tools.cpp			\
			games/score.cpp			\

OBJ_SNAKE	=	$(SRC_SNAKE:.cpp=.o)

LDFLAGS_SNAKE	=	-shared -fPIC

all:			core games graphicals

core:			$(NAME)

games:			$(NAME_PACMAN)  $(NAME_SNAKE)

graphicals:		$(NAME_SFML) $(NAME_SDL) $(NAME_CACA)

$(NAME_SFML):		$(OBJ_SFML)
			$(CXX) $(OBJ_SFML) -o $(NAME_SFML) $(LDFLAGS_SFML)

$(NAME_SDL):		$(OBJ_SDL)
			$(CXX) $(OBJ_SDL) -o $(NAME_SDL) $(LDFLAGS_SDL)

$(NAME_CACA):		$(OBJ_CACA)
			$(CXX) $(OBJ_CACA) -o $(NAME_CACA) $(LDFLAGS_CACA)

$(NAME_PACMAN):		$(OBJ_PACMAN)
			$(CXX) $(OBJ_PACMAN) -o $(NAME_PACMAN) $(LDFLAGS_PACMAN)

$(NAME_SNAKE):		$(OBJ_SNAKE)
			$(CXX) $(OBJ_SNAKE) -o $(NAME_SNAKE) $(LDFLAGS_SNAKE)

$(NAME):		$(OBJ)
			$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
			$(RM) $(OBJ_SFML) $(OBJ_SDL) $(OBJ_CACA) $(OBJ_PACMAN) $(OBJ_SNAKE) $(OBJ)

fclean:			clean
			$(RM) $(NAME_SFML) $(NAME_SDL) $(NAME_CACA) $(NAME_PACMAN) $(NAME_SNAKE) $(NAME)

re:			fclean all

.PHONY:			clean fclean re all
