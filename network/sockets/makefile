FLAGS:=-Wall
all: server client
	./server & ./client
server: server.c
	gcc ${FLAGS} $^ -o $@
client: client.c
	gcc ${FLAGS} $^ -o $@