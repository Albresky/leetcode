#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool exist(vector<vector<char>> &board, string word) {
        M = board.size();
        N = board[0].size();
        WLEN = word.length();

        for (int m = 0; m < M; ++m)
            for (int n = 0; n < N; ++n) {
                if (board[m][n] == word[0]) {
                    vector<vector<bool>> visited(M, vector<bool>(N, false));
                    if (dfs(board, word, visited, m, n, 0)) return true;
                }
            }
        return false;
    }

   private:
    int M, N, WLEN;

    bool dfs(vector<vector<char>> &board, string &word, vector<vector<bool>> &visited, int m, int n, int idx) {
        if (m < 0 || m >= M || n < 0 || n >= N) return false;
        if (visited[m][n] || board[m][n] != word[idx]) return false;
        if (idx == WLEN - 1) return true;

        visited[m][n] = true;

        if (dfs(board, word, visited, m, n + 1, idx + 1)) return true;
        if (dfs(board, word, visited, m + 1, n, idx + 1)) return true;
        if (dfs(board, word, visited, m, n - 1, idx + 1)) return true;
        if (dfs(board, word, visited, m - 1, n, idx + 1)) return true;

        visited[m][n] = false;
        return false;
    }
};

int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCEFSADEESE";

    Solution s;
    cout << s.exist(board, word) << endl;
    return 0;
}