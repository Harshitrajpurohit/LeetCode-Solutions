#include<iostream>
#include<vector>
using namespace std;


vector<int> x = {0, 0, -1, 1};
vector<int> y = {-1, 1, 0, 0};

void DFS(vector<vector<char>> &board, int row, int col){
    board[row][col] = ',';

    for (int i = 0; i < 4; i++){
        int r = row + x[i];
        int c = col + y[i];

        if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && board[r][c] == 'X'){
            DFS(board, r, c);
        }
    }
}
int countBattleships1(vector<vector<char>> &board){
    int n = board.size();
    int m = board[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] == 'X'){
                DFS(board, i, j);
                cnt++;
            }
        }
    }

    return cnt;
}


// second method 
int countBattleships2(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.')continue;
                else if(i && board[i-1][j] == 'X')continue;
                else if(j && board[i][j-1] == 'X')continue;
                cnt++;
            }
        }

        return cnt;
}

int main(){
    vector<vector<char>> board = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};

    // int ans = countBattleships1(board);
    int ans = countBattleships2(board);

    cout<<ans<<endl;

}