#include<iostream>
#include<vector>
#include<map>

using namespace std;


int majorityElement(vector<int> arr){
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

int main(){
    vector<int> arr = {2,2,1,1,1,2,2};

    int ans = majorityElement(arr);
    cout<<ans<<endl;
}