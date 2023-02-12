COMP=g++
CFLAGS=-Wall -Wextra

SOURCE=main.cpp
NAME=app

HEADERPATHS=-I/libraries/include/GL -I/libraries/include/GLFW
LIBPATH=-L/libraries/lib/GLEW -L/libraries/lib/GLFW
LIBLINK=$(LIBPATH) -lglfw3 -lglew32.lib

all:
	$(COMP) $(CFLAGS) $(HEADERPATHS) $(LIBLINK) $(SOURCE) -o $(NAME)