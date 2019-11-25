all: main main_bt copy
main: main.cpp
	g++ -g -o main main.cpp
main_bt: main_backtrace.cpp
	g++ -g -o main_bt main_backtrace.cpp
copy: copy.cpp
	g++ -g -o copy copy.cpp

clean:
	rm main

