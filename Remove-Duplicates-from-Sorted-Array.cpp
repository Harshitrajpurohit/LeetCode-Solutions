#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int> arr){
    int i=0;
    
    for(int j=1;j<arr.size();j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    vector<int> arr = {0,0,1,1,1,2,2,3,3,4};

    int uniqueElements = removeDuplicates(arr);

    cout<<uniqueElements<<endl;
    // ans -> 5
}