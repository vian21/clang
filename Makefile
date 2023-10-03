all: compile run

program:=playground.c

compile:
	@cc ${program}
run:
	@./a.out