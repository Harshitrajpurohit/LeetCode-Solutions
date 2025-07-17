#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<vector<int>> &matrix){

    int n = matrix.size();
    for (int i = 0; i < n / 2; i++){
        for (int j = i; j < n - i - 1; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - i - 1][n - 1 - j];
            matrix[n - i - 1][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = temp;
        }
    }
}


int main(){
    vector<vector<int>> vec = {{1,2,3},
                               {4,5,6},
                               {7,8,9}};
    
    rotate(vec);

    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec.size();j++){
            cout<<vec[i][j]<<" ";
        }cout<<endl;
    }
}