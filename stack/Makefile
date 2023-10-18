BUILD_DIR=build/
FLAGS=-Wall -Wextra -Werror -Wpedantic -Wno-unused-but-set-variable

main.out: ${BUILD_DIR}Result.o ${BUILD_DIR}stack.o main.c
	@mkdir -p ${BUILD_DIR}
	@echo "Compiling project. Output:" $@
	gcc ${FLAGS} $^ -o $@

${BUILD_DIR}Result.o: Result.c
	@mkdir -p ${BUILD_DIR}
	gcc -c ${FLAGS} $^  -o $@

${BUILD_DIR}stack.o: stack.c
	@mkdir -p ${BUILD_DIR}
	gcc -c ${FLAGS} $^ -o $@

clean:
	@echo "removing build artifacts"
	@rm ${BUILD_DIR}*