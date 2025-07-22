#include<iostream>
#include<string>

using namespace std;

string makeFancyString(string s) {
    string ans= "";
    int n = s.length();
        
    ans += s[0];
    if(n==1){
        return ans;
    }
    for(int i=1;i<s.length()-1;i++){
        if(s[i-1] == s[i] && s[i] == s[i+1]){
            continue;
        }else{
            ans+=s[i];
        }
    }
    ans+=s[n-1];
    return ans;
}


int main(){
    string s = "leeetcode";
    string ans = makeFancyString(s);
    cout<<ans<<endl;
    // ans -> leetcode
}