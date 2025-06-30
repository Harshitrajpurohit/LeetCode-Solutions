#include <iostream>

using namespace std;

bool areAlmostEqual(string s1, string s2){
    int left = 0;
    int right = s1.length();

    while (left <= right){
        if (s1[left] == s2[left]){
            left++;
        }
        if (s1[right] == s2[right]){
            right--;
        }
        if (s1[left] != s2[left] && s1[right] != s2[right]){
            swap(s2[left], s2[right]);
            if (s1 == s2){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    string s1 = "bank", s2 = "kanb";

    cout << areAlmostEqual(s1, s2);
    // ans -> true
}