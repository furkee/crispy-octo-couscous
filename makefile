files = $(wildcard *.hpp *.cpp)
flags = -std=c++14
compilables = structures/Graph.cpp main.cpp
object = executeMe

${object}: ${files}
	g++ ${flags} ${compilables} -o ${object}

clean:
	rm hash