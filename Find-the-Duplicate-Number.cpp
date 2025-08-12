#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findDuplicate(vector<int>& nums) {
    // set<int> st;
    // for(int it:nums){
    //     if(!st.empty()){
    //         if(st.find(it) != st.end()){
    //             return it;
    //         }
    //     }
    //     st.insert(it);
    // }

    // return 0;
    sort(nums.begin(), nums.end());

    for(int i=0;i<nums.size()-1;i++){
        if(nums[i] == nums[i+1]){
            return nums[i];
        }
    }

    return 0;
}


int main(){
    vector<int> nums1 = {1,3,4,2,2};

    int ans = findDuplicate(nums1);
    cout<<ans<<endl;
    // ans -> 2

}