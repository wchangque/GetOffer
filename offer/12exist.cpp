/* 剑指 Offer 12. 矩阵中的路径
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false
提示：

1 <= board.length <= 200
1 <= board[i].length <= 200
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool helper(vector<vector<char>> &board, vector<vector<bool>> &vis, int x, int y, string &word, int i)
    {
        if (i == word.size())
            return true;
        vis[x][y] = true;
        if (x > 0 && !vis[x - 1][y] && board[x - 1][y] == word[i] && helper(board, vis, x - 1, y, word, i + 1))
            return true;
        if (y > 0 && !vis[x][y - 1] && board[x][y - 1] == word[i] && helper(board, vis, x, y - 1, word, i + 1))
            return true;
        if (x < board.size() - 1 && !vis[x + 1][y] && board[x + 1][y] == word[i] && helper(board, vis, x + 1, y, word, i + 1))
            return true;
        if (y < board[0].size() - 1 && !vis[x][y + 1] && board[x][y + 1] == word[i] && helper(board, vis, x, y + 1, word, i + 1))
            return true;
        vis[x][y] = false;
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        if (m == 0 || word.empty())
            return false;
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == word[0] && helper(board, vis, i, j, word, 1))
                    return true;
            }
        }
        return false;
    }
};
int main()
{

    return 0;
}