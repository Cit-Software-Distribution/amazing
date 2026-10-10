#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "generators.h"

struct Cell {
  enum Side { Top, Right, Bottom, Left };

  bool visited = false;
  bool walls[4] = {true, true, true, true};
};

class Maze {
  int width, height;
  std::vector<std::vector<Cell>> grid;

  public:
    Maze(int w, int h);

    int get_width() const { return width; }
    int get_height() const { return height; }
    Cell& cell(int x, int y) { return grid[y][x]; }
    const Cell& cell(int x, int y) const { return grid[y][x]; }

    void generate(GenAlgo algo, int start_x = 0, int start_y = 0);
    void to_json();
};

#endif
