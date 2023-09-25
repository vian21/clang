all: compile run

program:=functions.c

compile:
	@cc ${program}
run:
	@./a.out