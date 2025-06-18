#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void reverseString(vector<char>& s) {
    reverse(s.begin(),s.end());
}

int main(){
    vector<char> s = {'h','e','l','l','o'};

    reverseString(s);

    for(int i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }

    return 0;
}