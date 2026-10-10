#include <string>
#include <vector>
#include "ui.h"
#include "maze.h"

namespace {

void printCrossAndLine(const Maze& maze, std::ostream& out) {
  const int width = maze.get_width();
  const int height = maze.get_height();

  // top border
  for (int x = 0; x < width; ++x) {
    out << (maze.cell(x, 0).walls[Cell::Top] ? "+---" : "+   ");
  }
  out << "+\n";

  for (int y = 0; y < height; ++y) {
    out << (maze.cell(0, y).walls[Cell::Left] ? "|" : " ");
    for (int x = 0; x < width; ++x) {
      out << "   " << (maze.cell(x, y).walls[Cell::Right] ? "|" : " ");
    }
    out << "\n";

    for (int x = 0; x < width; ++x) {
      out << "+" << (maze.cell(x, y).walls[Cell::Bottom] ? "---" : "   ");
    }
    out << "+\n";
  }
}

void printBlock(const Maze& maze, std::ostream& out) {
  const int width = maze.get_width();
  const int height = maze.get_height();
  std::vector<std::vector<bool>> solid(2 * height + 1, std::vector<bool>(2 * width + 1, true));

  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      const Cell& c = maze.cell(x, y);
      const int cx = 2 * x + 1;
      const int cy = 2 * y + 1;

      solid[cy][cx] = false;
      if (!c.walls[Cell::Top])    solid[cy - 1][cx] = false;
      if (!c.walls[Cell::Right])  solid[cy][cx + 1] = false;
      if (!c.walls[Cell::Bottom]) solid[cy + 1][cx] = false;
      if (!c.walls[Cell::Left])   solid[cy][cx - 1] = false;
    }
  }

  for (const auto& row : solid) {
    std::string line;
    for (bool s : row) {
      line += s ? "██" : "  ";
    }
    out << line << "\n";
  }
}

}

void print(const Maze& maze, OutputStyle style, std::ostream& out) {
  switch (style) {
    case OutputStyle::CrossAndLine:
      printCrossAndLine(maze, out);
    break;

    case OutputStyle::Block:
      printBlock(maze, out);
    break;
  }
}
