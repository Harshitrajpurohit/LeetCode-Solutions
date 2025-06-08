#include<iostream>
#include<vector>

using namespace std;

vector<int> SortArray(vector<int> arr1, vector<int> arr2){
    int n = arr1.size();
    int m = arr2.size();
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            if(ans.size() == 0 || ans.back() != arr1[i]){
                ans.push_back(arr1[i]);
                i++;
            }
        }else if (arr1[i] > arr2[j]){
            if(ans.size() == 0 || ans.back() != arr2[j]){
                ans.push_back(arr2[j]);
                j++;
            }
        }else {
            if (ans.size() == 0 || ans.back() != arr1[i]) {
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }
    while(j<m){
        if(ans.size()==0 || ans.back() != arr2[j]){
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n){
        if(ans.size()==0 || ans.back() != arr1[i]){
            ans.push_back(arr1[i]);
            i++;
        }
    }

    return ans;
}

int main(){
    vector<int> arr1 = {1,2,3,4,5}; 
    vector<int> arr2 = {2,3,5,6};
    
    vector<int> ans = SortArray(arr1,arr2);

    for(int it:ans){
        cout<<it<<" ";
    }
    
}