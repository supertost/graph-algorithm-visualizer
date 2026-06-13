files = main.cpp algorithm/Graph.cpp algorithm/BFS.cpp algorithm/DFS.cpp algorithm/Dijkstra.cpp

# SFML stuff
uiProgram = ui/program.cpp
uiScreens = ui/screens/menu.cpp ui/screens/graphEditor.cpp ui/screens/textScale.cpp
uiStructures = ui/ui_structures/button/Button.cpp ui/ui_structures/label/Label.cpp ui/ui_structures/Textbox/Textbox.cpp

algorithms = ui/menu.cpp algorithm/Graph.cpp algorithm/BFS.cpp algorithm/DFS.cpp algorithm/Dijkstra.cpp

all:
	clang++ $(files) -o main -Wall -Wextra -Werror

sfml:
	clang++ $(uiProgram) $(uiScreens) $(uiStructures) -o menu -Wall -Wextra -Werror -lsfml-graphics -lsfml-window -lsfml-system