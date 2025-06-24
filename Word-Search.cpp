#include <iostream>
#include <vector>

using namespace std;

vector<int> x = {0, 0, -1, 1};
vector<int> y = {-1, 1, 0, 0};
int dfs(vector<vector<char>> &board, vector<vector<int>> &vis, int row, int col, string word, int idx)
{
    if (idx == word.size())
    {
        return true;
    }

    for (int i = 0; i < 4; i++)
    {
        int r = row + x[i];
        int c = col + y[i];

        if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && vis[r][c] == 0 && board[r][c] == word[idx])
        {
            vis[r][c] = 1;
            if (dfs(board, vis, r, c, word, idx + 1))
                return true;
            vis[r][c] = 0;
        }
    }

    return false;
}


bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();

    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[idx])
            {
                vector<vector<int>> vis(n, vector<int>(m, 0));
                vis[i][j] = 1;
                if (dfs(board, vis, i, j, word, idx + 1))
                    return true;
            }
        }
    }

    return false;
}


int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";

    int ans = exist(board, word);

    cout<<ans<<endl;
    // ans -> true
}