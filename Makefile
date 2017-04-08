LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lm
CFLAGS = -Wall -std=c11 -Wextra -g -O0

OBJS = main.o entity.o player.o sprite.o bullet.o event.o component.o components/drawc.o components/positionc.o 

VirtPet: $(OBJS)

clean:
	find . -name "*.o" -exec rm {} \;
	find . -name "*~" -exec rm {} \;
	find . -name "\#*\#" -exec rm {} \;
	find . -name ".\#*" -exec rm {} \;
	find . -name VirtPet -exec rm {} \;

