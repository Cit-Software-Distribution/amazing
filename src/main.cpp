#include "maze.h"
#include "generators.h"

int main() {
    Maze maze(15, 15);
    maze.generate(GenAlgo::DFS, 0, 0);
    maze.display();
    return 0;
}
