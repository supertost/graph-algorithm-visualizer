#include "readwrite.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

bool readGraphData(const char *filepath, VisualGraph &vgraph) {

    std::fstream filein(filepath, std::ios::in);

    if (!filein.is_open()) {

        std::cout << "Unable to open file\n\n";
        return false;
    }

    std::cout << "File: " << filepath << " found.\n";

    vgraph.clearGraph();

    std::string line;
    while (getline(filein, line)) {
        std::stringstream ss(line);

        int node;
        ss >> node;
        vgraph.addNode(node);

        float x;
        float y;
        ss >> x >> y;
        vgraph.setNodePosition(node, sf::Vector2f(x, y));

        int neighbor;
        while (ss >> neighbor) {

            vgraph.addEdge(node, neighbor);
        }
    }

    filein.close();

    return true;
}

bool saveGraphData(const char *filepath, VisualGraph &vgraph) {

    std::fstream fileout(filepath, std::ios::out);

    if (!fileout.is_open()) {

        std::cout << "Unable to open file\n";
        return false;
    }

    const std::map<int, Node> &nodes = vgraph.getNodesMap();
    const std::map<int, std::vector<int>> &edges = vgraph.getEdgesMap();

    for (const std::pair<const int, Node> &node : nodes) {

        std::string line;
        line.append(std::to_string(node.first));

        sf::Vector2f nodePos = node.second.getPosition();
        line.append(" ");
        line.append(std::to_string(nodePos.x));
        line.append(" ");
        line.append(std::to_string(nodePos.y));

        for (const int neighbor : edges.at(node.first)) {

            line.append(" ");
            line.append(std::to_string(neighbor));
        }

        fileout << line << "\n";
    }

    fileout.close();

    return true;
}


bool readConfig(Config &config) {

    std::fstream filein(config.filepath.c_str(), std::ios::in);

    if (!filein.is_open()) {
        // Ask the user to create a config folder in the root folder of the application.
        std::cout << "Config file not found at location: " << config.filepath << "\n";
        return false;
    }

    
    std::string line;
    while (getline(filein, line)) {

        std::stringstream ss(line);

        std::string setting;
        ss >> setting;

        std::cout << "Setting: " << setting << "\n";

        if (!(setting.compare("smoothScroll"))) {

            int value;
            ss >> value;
            config.smoothScroll = value;
            std::cout << "Start value for smoothscroll: " << config.smoothScroll << "\n";
        }
    }
    
    return true;
}

bool saveConfig(Config &config) {

    // To be fixed, just a working one for single setting

    std::fstream fileout(config.filepath.c_str(), std::ios::out);

    fileout << "smoothScroll" << " " << config.smoothScroll << "\n";

    return true;
}