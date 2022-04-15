CC = gcc
CFLAGS = -W -Wall
TARGET = main
DTARGET = main_debug
OBJECT = main.c product.o manager.o
all : $(TARGET)
$(TARGET) : $(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(OBJECT)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean:
	rm *.o main main_debug

