#include<iostream>
#include<vector>
#include<map>

using namespace std;

// TC-> O(n log(n)) + O(n); SC-> O(n)
int majorityElementByMap(vector<int> arr){
    map<int,int> freq;

    for(int i=0;i<arr.size();i++){
        freq[arr[i]]++;
    }

    int maxi = 0;
    int ans;

    for(auto i:freq){
        if(maxi < i.second){
            maxi = i.second;
            ans = i.first;
        }
    }
    return ans;

}

// TC-> O(n) SC-> O(n)
int majorityElement(vector<int> arr){
    
    int cnt=0;
    int ele;

    for(int i=0;i<arr.size();i++){
        if(cnt==0){
            cnt=1;
            ele = arr[i];
        }else if(arr[i]==ele){
            cnt++;
        }else{
            cnt--;
        }
    }
    int cnt1=0;
    for(int i=0;i<arr.size();i++){
        if(ele == arr[i]){
            cnt1++;
        }
    }

    if(cnt1 > arr.size()/2){
        return ele;
    }
    return -1;
}



int main(){
    vector<int> arr = {2,2,1,1,1,2,2};

    int ans = majorityElementByMap(arr);
    int ans = majorityElement(arr);
    cout<<ans<<endl;
}