
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GCD(int a, int b){
    while (a > 0 && b > 0){
        if (a > b) a = a % b;
        else b = b % a;
    }
    if (a == 0)
        return b;
    return a;
}

int findMin(vector<int> arr){
    int mini = INT_MAX;
    for (int it : arr){
        if (mini > it){
            mini = it;
        }
    }
    return mini;
}
int findMax(vector<int> arr){
    int maxi = INT_MIN;
    for (int it : arr){
        if (maxi < it){
            maxi = it;
        }
    }
    return maxi;
}
int findGCD(vector<int> &nums)
{
    int mini = findMin(nums);
    int maxi = findMax(nums);

    return GCD(maxi, mini);
}

int main(){
    vector<int> arr = {2,5,6,9,10};

    cout<< findGCD(arr);
    // ans -> 2
}