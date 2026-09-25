#ifndef MAZE
#define MAZE 
#include <vector>
#include "generators.h"

struct Cell {
    bool visited = false;
    bool walls[4] = {true, true, true, true}; //top, right, bottom, left
};

class Maze {
  int width, height;
  std::vector<std::vector<Cell>> grid;

  public:
    Maze(int w, int h);

    int get_width() const { return width; }
    int get_height() const { return height; }
    Cell& cell(int x, int y) { return grid[y][x]; }

    void generate(GenAlgo algo, int x = 0, int y = 0);
    void display();
    void to_json();
};

#endif
