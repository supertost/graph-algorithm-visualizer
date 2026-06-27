files = main.cpp algorithm/Graph.cpp algorithm/BFS.cpp algorithm/DFS.cpp algorithm/Dijkstra.cpp

# SFML stuff
uiProgram = ui/program.cpp
uiScreens = ui/screens/menu.cpp ui/screens/graphEditor.cpp ui/screens/textScale.cpp ui/screens/settings.cpp ui/screens/bfsScreen.cpp ui/screens/updateLayouts.cpp
uiStructures = ui/ui_structures/Button/Button.cpp ui/ui_structures/Label/Label.cpp ui/ui_structures/Textbox/Textbox.cpp ui/ui_structures/PopUp/PopUp.cpp
uiGraphStructures = ui/ui_structures/Graph/Node.cpp ui/ui_structures/Graph/VisualGraph.cpp
uiAlgorithms = ui/vgraph_algorithms/bfs/vbfs.cpp

# io
io = io/readwrite.cpp

# External libraries
exlibs = third_party_libraries/tinyfiledialogs/tinyfiledialogs.cpp

algorithms = ui/menu.cpp algorithm/Graph.cpp algorithm/BFS.cpp algorithm/DFS.cpp algorithm/Dijkstra.cpp

all:
	clang++ $(files) -o main -Wall -Wextra -Werror

sfml:
	clang++ $(uiProgram) $(uiScreens) $(uiStructures) $(uiGraphStructures) $(exlibs) $(io) $(uiAlgorithms) -o menu -Wall -Wextra -Werror -lsfml-graphics -lsfml-window -lsfml-system