all: read write mmap_test main
read: read.cpp
	g++ -g -o read read.cpp
write: write.cpp
	g++ -g -o write write.cpp
mmap_test: mmap_test.cpp
	g++ -g -o mmap_test mmap_test.cpp
main: ./mmap父子进程匿名映射.cpp
	g++ -g -o main ./mmap父子进程匿名映射.cpp
clean: 
	rm read write file mmap_test main

