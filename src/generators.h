#ifndef GENERATORS_H
#define GENERATORS_H

class Maze;

enum class GenAlgo {
  DFS,
};

void generate_DFS(Maze& maze, int x, int y);

#endif
