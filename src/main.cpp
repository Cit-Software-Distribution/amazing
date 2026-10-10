#include "maze.h"
#include "generators.h"
#include "ui.h"

int main() {
    Maze maze(15, 15);
    maze.generate(GenAlgo::Prim);
    print(maze, OutputStyle::Block);
    return 0;
}
