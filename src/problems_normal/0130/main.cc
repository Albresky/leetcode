#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int m = 0;
  int n = 0;

  void dfs(vector<vector<char>> &board, int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') {
      return;
    }
    board[x][y] = 'Z';
    dfs(board, x - 1, y);
    dfs(board, x + 1, y);
    dfs(board, x, y - 1);
    dfs(board, x, y + 1);
  }

public:
  void solve(vector<vector<char>> &board) {
    m = board.size();

    if (!m) return;

    n = board[0].size();
    for (int i = 0; i < m; ++i) {
      dfs(board, i, 0);
      dfs(board, i, n - 1);
    }
    for (int i = 0; i < n; ++i) {
      dfs(board, 0, i);
      dfs(board, m - 1, i);
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'Z')
          board[i][j] = 'O';
        else if (board[i][j] == 'O')
          board[i][j] = 'X';
      }
    }
  }
};

int main() {
  vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'X', 'O', 'X'},
                                {'X', 'O', 'X', 'X'}};
  Solution s;
  s.solve(board);
  for (auto &vec : board) {
    for (auto &v : vec) cout << v << ' ';
    cout << endl;
  }
  return 0;
}