#include<iostream>
#include<vector>

using namespace std;

void sortColors(vector<int> &colors){
    int left = 0;
    int right = colors.size()-1;
    int mid = 0;

    while(mid<=right){
        if(colors[mid] == 0){
            swap(colors[mid],colors[left]);
            mid++;
            left++;
        }
        else if(colors[mid]==1){
            mid++;
        }else{
            swap(colors[mid], colors[right]);
            mid++;
            right--;
        }
    }
}

int main(){
    vector<int> colors = {2,0,2,1,1,0};

    sortColors(colors);

    for(int i:colors){
        cout<<i<<" ";
    }
    // and -> 0 0 1 1 2 2
}