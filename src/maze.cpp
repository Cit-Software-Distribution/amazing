#include <iostream>
#include <vector>
#include "maze.h"
#include "generators.h"

Maze::Maze(int w, int h) : width(w), height(h), grid(h, std::vector<Cell>(w)) {}

void Maze::generate(GenAlgo algo, int x, int y) {
  switch (algo) {
    case GenAlgo::DFS:
      generate_DFS(*this, x, y);
    break;
  }
}

//prints maze
void Maze::display() {

    //top border
    for (int x = 0; x < width; ++x) {
        std::cout << (grid[0][x].walls[0] ? "+---" : "+   ");
    }
    std::cout << "+\n";

    for (int y = 0; y < height; ++y) {
        std::cout << (grid[y][0].walls[3] ? "|" : " ");
        for (int x = 0; x < width; ++x) {
            std::cout << "   ";
            std::cout << (grid[y][x].walls[1] ? "|" : " ");
        }
        std::cout << "\n";

        for (int x = 0; x < width; ++x) {
            std::cout << "+";
            std::cout << (grid[y][x].walls[2] ? "---" : "   ");
        }
        std::cout << "+\n";
    }
}

