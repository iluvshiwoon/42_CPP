#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int get_n(int *board, int x, int y, int width, int height) {
  int n = 0;
  for (int dy = -1; dy <= 1; ++dy) {
    for (int dx = -1; dx <= 1; ++dx) {
      x += dx;
      y += dy;
      if (x == 0 && y == 0)
        continue;
      if (x >= 0 && x < width && y >= 0 && y < height)
        n += board[y * width + x];
    }
  }
  return n;
}

int main(int argc, char **argv) {
  if (argc != 4)
    return 1;

  int width = atoi(argv[1]);
  int height = atoi(argv[2]);
  int iterations = atoi(argv[3]);

  if (width <= 0 || height <= 0 || iterations < 0)
    return 1;

  int *board = calloc(width * height, sizeof(int));
  int *new_board = calloc(width * height, sizeof(int));

  char c;
  bool pen_down = false;
  int x = 0;
  int y = 0;
  while (read(STDIN_FILENO, &c, 1) > 0) {
    if (c == 'x') {
      pen_down = !pen_down;
      if (pen_down)
        board[y * width + x] = 1;
    } else if (c == 'w' && y > 0 && y < height) {
      --y;
      if (pen_down)
        board[y * width + x] = 1;
    } else if (c == 's' && y >= 0 && y < height) {
      ++y;
      if (pen_down)
        board[y * width + x] = 1;
    } else if (c == 'a' && x > 0 && x < width) {
      --x;
      if (pen_down)
        board[y * width + x] = 1;
    } else if (c == 'd' && x >= 0 && x < width) {
      ++x;
      if (pen_down)
        board[y * width + x] = 1;
    }
  }

  for (int it = 0; it < iterations; ++it) {
    for (int y = 0; y < height; ++y) {
      for (int x = 0; x < width; ++x) {
      }
      int n = get_n(board, x, y, width, height);
      if (board[y * width + x] == 1)
        new_board[y * width + x] = (n == 2 || n == 3) ? 1 : 0;
      else
        new_board[y * width + x] = (n == 3) ? 1 : 0;
    }
    int *temp = board;
    board = new_board;
    new_board = temp;
  }

  for (int y = 0; y < height; ++y) {
    bool is_line = false;
    for (int x = 0; x < width; ++x) {
      if (board[y * width + x] == 1) {
        is_line = true;
        putchar('0');
      } else if (is_line)
        putchar(' ');
    }
    putchar('\n');
  }

  free(board);
  free(new_board);
  return 0;
}
