#ifndef GENERATORS_H
#define GENERATORS_H

class Maze;

enum class GenAlgo {
  DFS,
  Prim
};

void generate_DFS(Maze& maze, int x, int y);

// void generate_Prim(Maze& maze);

#endif
