#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// answer starts here -----------------
vector<int> x = {-1, 1, 0, 0};
vector<int> y = {0, 0, -1, 1};
void bfs(int n, int m, int row, int col, vector<vector<char>> &grid)
{

    grid[row][col] = '2';
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty())
    {
        int currow = q.front().first;
        int curcol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = currow + x[i];
            int ncol = curcol + y[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1')
            {
                grid[nrow][ncol] = '2';
                q.push({nrow, ncol});
            }
        }
    }
}

void dfs(int n, int m, int row, int col, vector<vector<char>> &grid)
{
    if (row < 0 || row >= n || col < 0 || col >= m && grid[row][col] != '1')
        return;

    grid[row][col] = '0';
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + x[i];
        int ncol = col + y[i];
        dfs(n, m, nrow, ncol, grid);
    }
}

int numIslands(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    for (int row = 0; row < n; row++){
        for (int col = 0; col < m; col++){
            if (grid[row][col] == '1'){
                cnt++;
                bfs(n, m, row, col, grid);
            }
        }
    }
    return cnt;
}

// answer ends here -----------------

int main(){
    vector<vector<char>> board = {{'1', '1', '0', '0','0'},
                                 {'1', '1', '0', '0','0'},
                                 {'0', '0', '1', '0','0'},
                                 {'0', '0', '0', '1','1'}};

    int n = board.size();
    int m = board[0].size();

    cout<<numIslands(board);
    // ans -> 3

    return 0;
}