#include <iostream>
#include <vector>

using namespace std;

bool isArraySpecial(vector<int> &nums){
    int n = nums.size();

    for (int j = 1; j < n; j++){
        if (nums[j] % 2 == 0 && (nums[j - 1] % 2 == 0)){
            return false;
        }
        if (nums[j] % 2 == 1 && (nums[j - 1] % 2 == 1)){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> arr = {4,3,1,6};

    bool ans = isArraySpecial(arr);

    cout<<ans<<endl;
}