#include <vector>
#include <random>
#include <algorithm>
#include "generators.h"
#include "maze.h"

void generate_DFS(Maze& maze, int x, int y) {
    maze.cell(x, y).visited = true;
    std::vector<int> dirs = {0, 1, 2, 3};

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(dirs.begin(), dirs.end(), g);

    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};

    for (int i : dirs) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < maze.get_width() && ny >= 0 && ny < maze.get_height() && !maze.cell(nx, ny).visited) {
            maze.cell(x, y).walls[i] = false;
            maze.cell(nx, ny).walls[(i + 2) % 4] = false;
            generate_DFS(maze, nx, ny);
        }
    }
}
