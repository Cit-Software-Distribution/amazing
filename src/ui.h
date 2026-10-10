#ifndef UI_H
#define UI_H

#include <iostream>

class Maze;

enum class OutputStyle {
  CrossAndLine,
  Block
};

void print(const Maze& maze, OutputStyle style, std::ostream& out = std::cout);

#endif
