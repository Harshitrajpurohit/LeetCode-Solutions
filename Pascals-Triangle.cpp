#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> generateRow(int i) {
        long long ans = 1;
        vector<int> row;
        row.push_back(1);
        for (int j = 1; j < i; j++) {
            ans = ans * (i - j);
            ans = ans / j;
            row.push_back(ans);
        }
        return row;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};

int main() {
    Solution s;
    int numRows = 5; // you can change this or take input
    vector<vector<int>> pascal = s.generate(numRows);

    for (auto &row : pascal) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
