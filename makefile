COMP=g++
CFLAGS=-Wall -Wextra

SOURCE=main.cpp
NAME=app

HEADERPATHS=
LIBPATH=
LIBLINK=$(LIBPATH) glew32.lib libglfw3.a

all:
	$(COMP) $(CFLAGS) $(HEADERPATHS) $(LIBLINK) $(SOURCE) -o $(NAME)
#-L/libraries/lib/GLEW -L/libraries/lib/GLFW
#-I/libraries/include/GL -I/libraries/include/GLFW
#