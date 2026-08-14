all: compile run

compile:
	gcc ./src/*.c -o ./bin/main.exe -I./src -L./bin/ -lSDL3

run:
	./bin/main.exe