files = structures/HashTable.hpp main.cpp
flags = -std=c++14
compilables = main.cpp
object = hash

${object}: ${files}
	g++ ${flags} ${compilables} -o ${object}

clean:
	rm hash