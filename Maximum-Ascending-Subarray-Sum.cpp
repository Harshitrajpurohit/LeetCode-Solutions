#include<iostream>
#include<vector>

using namespace std;

int maxAscendingSum(vector<int> &nums){
    int tSum = 0;
    int sum = 0;
    int n = nums.size();
    sum = nums[0];
    for (int i = 1; i < n; i++){
        if (nums[i - 1] >= nums[i]){
            tSum = max(tSum, sum);
            sum = 0;
        }
        sum += nums[i];
    }

    tSum = max(tSum, sum);

    return tSum;
}

int main(){
    vector<int> nums = {10,20,30,5,10,50};

    cout<< maxAscendingSum(nums);
    // ans -> 65
    return 0;
}