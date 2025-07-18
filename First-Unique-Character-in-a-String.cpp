#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

int firstUniqChar(string s) {
        unordered_map <char,int> mp;

        for(char i:s){
            mp[i]++;
        }

        for(int i=0;i<s.length();i++){
            if(mp[s[i]] == 1){
                return i;
            }
        }

        return -1;
}


int main(){
    string s = "loveleetcode";


    int ans = firstUniqChar(s);

    cout<<ans;
    // ans -> 2

}