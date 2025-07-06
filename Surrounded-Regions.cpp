#include<iostream>
#include<vector>

using namespace std;



// answer starts here -----------------
vector<int> x = {-1, 1, 0, 0};
vector<int> y = {0, 0, -1, 1};
void DFS(vector<vector<char>> &ans, vector<vector<int>> &vis, int row, int col)
{
    vis[row][col] = 1;
    for (int i = 0; i < 4; i++)
    {
        int r = row + x[i];
        int c = col + y[i];
        if (r >= 0 && r < ans.size() && c >= 0 && c < ans[0].size() && !vis[r][c] && ans[r][c] == 'O')
        {
            DFS(ans, vis, r, c);
        }
    }
}

void solve(vector<vector<char>> &board){
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++){
        if (board[0][i] == 'O' && vis[0][i] == 0){
            DFS(board, vis, 0, i);
        }
        if (board[n - 1][i] == 'O' && vis[n - 1][i] == 0){
            DFS(board, vis, n - 1, i);
        }
    }

    for (int i = 0; i < n; i++){
        if (board[i][0] == 'O' && vis[i][0] == 0){
            DFS(board, vis, i, 0);
        }
        if (board[i][m - 1] == 'O' && vis[i][m - 1] == 0){
            DFS(board, vis, i, m - 1);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (vis[i][j] == 0 && board[i][j] == 'O'){
                board[i][j] = 'X';
            }
        }
    }
}

// answer ends here -----------------


int main(){
    vector<vector<char>> board = {{'X','X','X','X'},
                                 {'X','O','O','X'},
                                 {'X','X','O','X'},
                                 {'X','O','X','X'}};
    
    int n=board.size();                
    int m=board[0].size();                

    solve(board);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<board[i][j]<<" ";
        }cout<<endl;
    }
}