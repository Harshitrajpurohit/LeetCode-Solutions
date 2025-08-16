#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals){

    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    ans.push_back(intervals[0]);
    for (int i = 1; i < n; i++){
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (ans.back()[0] <= start && ans.back()[1] >= end){
            continue;
        }

        if (ans.back()[1] >= start){
            swap(ans.back()[1], end);
        }
        else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}



int main() {
    vector<vector<int>> arr= {{1,3},{2,6},{8,10},{15,18}};
    
    
    vector<vector<int>> ans = merge(arr);
    
    for(int i=0;i<ans.size();i++){
        cout<<"{ ";
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<"}";
    }
    // ans -> { 1  6 }{ 8  10 }{ 15  18 }
    
    
    return 0;
}





