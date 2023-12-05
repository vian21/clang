all: compile run

program:=playground.c

compile:
	@cc ${program}
run:
	@./a.out
	
clean:
	@echo "Deleting executables"
	find . -maxdepth 1 -type f -executable -delete