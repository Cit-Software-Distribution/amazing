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
