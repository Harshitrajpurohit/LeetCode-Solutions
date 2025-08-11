#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
    int itr = 0;
    vector<int> nums;
    int l = 0;
    int r = 0;

    while (l < m && r < n){
        if (nums1[l] > nums2[r]){
            nums.push_back(nums2[r]);
            r++;
        }
        else{
            nums.push_back(nums1[l]);
            l++;
        }
    }
    while (l < m){
        nums.push_back(nums1[l]);
        l++;
    }
    while (r < n){
        nums.push_back(nums2[r]);
        r++;
    }

    nums1 = nums;
}

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;

    merge(nums1, n, nums2, m);

    for(int i=0;i<n+m;i++){
        cout<<nums1[i]<<" ";
    }
    // ans -> 1 2 2 3 5 6

}