#include "maze.h"
#include "generators.h"
#include "ui.h"

int main() {
    Maze maze(15, 15);
    maze.generate(GenAlgo::DFS);
    print(maze, OutputStyle::Block);
    return 0;
}
