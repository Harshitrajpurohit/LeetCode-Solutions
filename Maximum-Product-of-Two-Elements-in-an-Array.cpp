#include<iostream>
#include<vector>

using namespace std;

int maxProduct(vector<int> &nums){
    int largest = nums[0];
    int largest_idx = 0;
    int sec_largest = 0;

    for (int i = 1; i < nums.size(); i++){

        if (nums[i] >= largest){
            largest = nums[i];
            largest_idx = i;
        }
    }
    nums.erase(nums.begin() + largest_idx);

    for (int i = 0; i < nums.size(); i++){
        if (sec_largest < nums[i]){
            sec_largest = nums[i];
        }
    }
    return (largest - 1) * (sec_largest - 1);
}

int main(){
    vector<int> nums = {3,4,5,2};

    cout<<maxProduct(nums);
    // ans-> 12
}