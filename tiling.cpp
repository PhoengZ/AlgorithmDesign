#include <cstdio>
#include <tuple>
#include <vector>

std::vector<std::tuple<int, int, int>> answers;

void gen(int L, int offsetX, int offsetY, int x, int y) {
  if (L == 2) {
    int rot;
    if (!x && !y) {
      rot = 0;
    } else if (x && !y) {
      rot = 1;
    } else if (!x) {
      rot = 2;
    } else {
      rot = 3;
    }
    answers.emplace_back(rot, offsetX, offsetY);
    return;
  }
  int mid = L / 2;
  if (x < mid & y < mid) {
    gen(mid, offsetX, offsetY, x, y);
    gen(2, offsetX + mid - 1, offsetY + mid - 1, 0, 0);
  } else {
    gen(mid, offsetX, offsetY, mid - 1, mid - 1);
  }
  if (x >= mid && y < mid) {
    gen(mid, offsetX + mid, offsetY, x - mid, y);
    gen(2, offsetX + mid - 1, offsetY + mid - 1, 1, 0);
  } else {
    gen(mid, offsetX + mid, offsetY, 0, mid - 1);
  }
  if (x < mid && y >= mid) {
    gen(mid, offsetX, offsetY + mid, x, y - mid);
    gen(2, offsetX + mid - 1, offsetY + mid - 1, 0, 1);
  } else {
    gen(mid, offsetX, offsetY + mid, mid - 1, 0);
  }
  if (x >= mid && y >= mid) {
    gen(mid, offsetX + mid, offsetY + mid, x - mid, y - mid);
    gen(2, offsetX + mid - 1, offsetY + mid - 1, 1, 1);
  } else {
    gen(mid, offsetX + mid, offsetY + mid, 0, 0);
  }
}

int main() {
  int L, X, Y;
  scanf("%d%d%d", &L, &X, &Y);
  gen(L, 0, 0, X, Y);
  printf("%lu\n", answers.size());
  int rot;
  for (auto &tup : answers) {
    std::tie(rot, X, Y) = tup;
    printf("%d %d %d\n", rot, X, Y);
  }
  return 0;
}
//กอปมา งง 
/**
4 1 2

 */

