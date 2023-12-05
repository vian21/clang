FLAGS:=-Wall

all: server client
	./server & ./client

server: server.c
	gcc ${FLAGS} $^ -o $@

client: client.c
	gcc ${FLAGS} $^ -o $@

clean:
	@echo "Deleting executables"
	find . -maxdepth 1 -type f -executable -delete
