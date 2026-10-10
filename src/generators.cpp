#include <vector>
#include <random>
#include <algorithm>
#include <utility>
#include "generators.h"
#include "maze.h"

void generate_DFS(Maze& maze, int x, int y) {
    maze.cell(x, y).visited = true;
    std::vector<int> dirs = {0, 1, 2, 3};

    std::random_device rand_dev;
    static std::mt19937 rng(rand_dev());
    std::shuffle(dirs.begin(), dirs.end(), rng);

    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};

    for (int i : dirs) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (new_x >= 0 && new_x < maze.get_width() && new_y >= 0 && new_y < maze.get_height() && !maze.cell(new_x, new_y).visited) {
            maze.cell(x, y).walls[i] = false;
            maze.cell(new_x, new_y).walls[(i + 2) % 4] = false;
            generate_DFS(maze, new_x, new_y);
        }
    }
}

void generate_Prim(Maze& maze, int x, int y) {
    std::random_device rand_dev;
    static std::mt19937 rng(rand_dev());

    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};

    std::vector<std::pair<int, int>> frontier; //unvisited cells adjacent to visited cells
    frontier.push_back({x, y});

    //while there are unvisited cells
    while (!frontier.empty()) {
        int idx = rng() % frontier.size(); //picks random unvisited cell
        int cur_x = frontier[idx].first;
        int cur_y = frontier[idx].second;
        frontier.erase(frontier.begin() + idx); // removes from unvisited list
 
        if (maze.cell(cur_x, cur_y).visited) continue;
        maze.cell(cur_x, cur_y).visited = true;

        std::vector<int> dirs = {0, 1, 2, 3};
        std::shuffle(dirs.begin(), dirs.end(), rng); //randomizes directions

        // connect to one visited neighbor
        for (int i : dirs) {
            int new_x = cur_x + dx[i];
            int new_y = cur_y + dy[i];

            if (new_x >= 0 && new_x < maze.get_width() && new_y >= 0 && new_y < maze.get_height() && maze.cell(new_x, new_y).visited) {
                maze.cell(cur_x, cur_y).walls[i] = false;
                maze.cell(new_x, new_y).walls[(i + 2) % 4] = false;
                break;
            }
        }

        // add the unvisited neighbors to the frontier
        for (int i = 0; i < 4; i++) {
            int new_x = cur_x + dx[i];
            int new_y = cur_y + dy[i];

            if (new_x >= 0 && new_x < maze.get_width() && new_y >= 0 && new_y < maze.get_height() && !maze.cell(new_x, new_y).visited) {
                frontier.push_back({new_x, new_y});
            }
        }
    }
}

void generate_BinaryTree(Maze& maze) {
    std::random_device rand_dev;
    static std::mt19937 rng(rand_dev());

    int width = maze.get_width();
    int height = maze.get_height();

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            maze.cell(x, y).visited = true;

            bool can_go_up = y > 0;
            bool can_go_right = x < width - 1;

            //top-right corner: nothing to connect
            if (!can_go_up && !can_go_right) continue;

            //randomly carve up or right; on the top row or right column there is only one option
            bool go_up;
            if (!can_go_up) go_up = false;
            else if (!can_go_right) go_up = true;
            else go_up = rng() % 2 == 0;

            if (go_up) {
                maze.cell(x, y).walls[Cell::Top] = false;
                maze.cell(x, y - 1).walls[Cell::Bottom] = false;
            } else {
                maze.cell(x, y).walls[Cell::Right] = false;
                maze.cell(x + 1, y).walls[Cell::Left] = false;
            }
        }
    }
}
