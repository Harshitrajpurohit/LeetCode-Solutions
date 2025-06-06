#include<iostream>
#include<vector>

using namespace std;

int MaxSubarray(vector<int> arr){

    int max = INT_MIN;
    int sum=0;

    for(int i:arr){
        sum+=i;
        if(sum>max){
            max=sum;
        }
        if(sum<=0){
            sum=0;
        }

    }

    return max;
}

int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    
    int ans = MaxSubarray(arr);
    
    cout<<ans<<endl;
    // ans -> 6
}