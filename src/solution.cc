#include "solution.hpp"

std::vector<std::pair<unsigned int, unsigned int>> SolveMaze(
    const std::vector<std::vector<char>>& maze,
    unsigned int start_row,
    unsigned int start_col) {
  std::vector<std::vector<bool>> visited(
      maze.size(), std::vector<bool>(maze[0].size(), false));
  std::vector<std::pair<unsigned int, unsigned int>> path;
  SolveMazeRecursive(maze, start_row, start_col, path, visited);
  return path;
}

bool SolveMazeRecursive(
    const std::vector<std::vector<char>>& maze,
    unsigned int row,
    unsigned int col,
    std::vector<std::pair<unsigned int, unsigned int>>& path,
    std::vector<std::vector<bool>>& visited) {
  visited[row][col] = true;
  path.push_back({row, col});

  if (maze[row][col] == 'X') return true;

  // South, North, East, West
  const int kDr[] = {1, -1, 0, 0};
  const int kDc[] = {0, 0, 1, -1};

  for (int i = 0; i < 4; i++) {
    int nr = static_cast<int>(row) + kDr[i];
    int nc = static_cast<int>(col) + kDc[i];

    if (nr < 0 || nc < 0) continue;

    auto ur = static_cast<unsigned int>(nr);
    auto uc = static_cast<unsigned int>(nc);

    if (ur >= maze.size() || uc >= maze[0].size()) continue;
    if (maze[ur][uc] == '#') continue;
    if (visited[ur][uc]) continue;

    if (SolveMazeRecursive(maze, ur, uc, path, visited)) return true;
  }

  path.pop_back();
  return false;
}