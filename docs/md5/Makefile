CC=gcc
EXEC_NAME=run
LIBS=-lcrypto
CFLAGS=-Wall
OBJ=main.o

all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC_NAME) $(LIBS)
	
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
clean:
	rm $(OBJ) $(EXEC_NAME)
