files = main.cpp algorithm/Graph.cpp algorithm/BFS.cpp algorithm/DFS.cpp algorithm/Dijkstra.cpp

all:
	clang++ $(files) -o main -Wall -Wextra -Werror