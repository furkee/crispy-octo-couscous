files = $(wildcard **/*.hpp **/*.cpp)
flags = -std=c++14 -O3
compilables = structures/Graph.cpp utils/GraphReader.cpp main.cpp
object = executeMe

${object}: ${files}
	g++ ${flags} ${compilables} -o ${object}

clean:
	rm ${object}