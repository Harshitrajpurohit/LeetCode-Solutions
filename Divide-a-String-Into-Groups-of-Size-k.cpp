#include<iostream>
#include<vector>

using namespace std;

vector<string> divideString(string s, int k, char fill) {
    
    int n = s.size();
    vector<string> v;
    for (int i = 0; i < n; i += k) {
        string str = s.substr(i, k);
        while (str.size() < k) str += fill;
        v.push_back(str);
    }

    return v;
}

int main(){
    string s = "abcdefghij";

    int k = 3;
    char fill = 'x';

    vector<string> ans = divideString(s,k,fill);

    for(auto it:ans){
        cout<<it<<" ";
    }
    // ans -> ["abc","def","ghi","jxx"]
}