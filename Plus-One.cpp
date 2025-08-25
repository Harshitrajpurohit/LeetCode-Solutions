#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> plusOne(vector<int> &digits){
    vector<int> ans;
    int n = digits.size();
    int carry = 1;
    for (int i = n - 1; i >= 0; i--){
        int sum = digits[i] + carry;
        ans.push_back(sum % 10);
        carry = sum / 10;
    }
    if (carry){
        ans.push_back(carry);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> arr = {9,3,2,9};

    vector<int> ans = plusOne(arr);
    for(int it:ans){
        cout<<it<<" ";
    }
    // ans -> 9 3 3 0
}