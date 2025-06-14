#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int ind = -1;

    for (int i = n - 2; i >= 0; i--){
        if (nums[i] < nums[i + 1]){
            ind = i;
            break;
        }
    }
    if (ind == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i=n-1; i>ind; i--){
        if (nums[i] > nums[ind]){
            swap(nums[i], nums[ind]);
            break;
        }
    }
    reverse(nums.begin() + ind + 1, nums.end());
}

int main(){
    vector<int> arr = {1,2,3};

    nextPermutation(arr);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    // ans -> [1,3,2]
}