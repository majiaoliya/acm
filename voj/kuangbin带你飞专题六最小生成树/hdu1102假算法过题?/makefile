all: main mt copy
main: main.cpp
	g++ -g -o main main.cpp
mt: maketest.cpp
	g++ -g -o mt maketest.cpp
copy: copy.cpp
	g++ -g -o copy copy.cpp
clean:
	rm main mt copy
