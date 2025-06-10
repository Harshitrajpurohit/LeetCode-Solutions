#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;


// First Folution By Sorting
bool hasDuplicateUsingSort(vector<int> arr){
    sort(arr.begin(),arr.end());
    int first=0;
    for(int second = 1; second<arr.size();second++){
        if(arr[second] == arr[first]){
            return true;
        }
    }

    return false;
}


// Second Solution By Set
bool hasDuplicateUsingSet(vector<int> arr){
    unordered_set<int> s(arr.begin(),arr.end());

    if(s.size() == arr.size())return false;

    return true;
}
int main(){
    vector<int> arr = {1,1,1,3,3,4,3,2,4,2};

    bool ans = hasDuplicateUsingSort(arr);
    // bool ans = hasDuplicateUsingSet(arr);

    cout<< ans << " ";
}