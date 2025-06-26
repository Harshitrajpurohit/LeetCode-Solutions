#include<iostream>
#include<vector>

using namespace std;

bool isAnagram(string s, string t) {
        int arr[26];

        for(int i=0;i<26;i++){
            arr[i] = 0;
        }

        for(char i: s){
            arr[i-'a'] += 1;
        }

        for(char i: t){
            arr[i-'a'] -= 1;
        }

        for(int i=0;i<26;i++){
            if(arr[i] != 0)return false;
        }
        return true;
}

int main(){
    string s = "anagram";
    string t = "nagaram";

    cout<<boolalpha<< isAnagram(s,t);
    // ans-> true
}