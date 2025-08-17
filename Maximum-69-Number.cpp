#include <iostream>
#include <vector>
using namespace std;

int maximum69Number(int num){
    string s = to_string(num);
    string temp = s;
    string maxi = to_string(num);
    for(int i=0;i<s.length();i++){
        if(s[i] == '6'){
            s[i] = '9';
        }else{
            s[i] = '6';
        }
        maxi = max(maxi, s);
        s = temp;
    }

    return stoi(maxi);
}


int main(){
    int num = 9696;
    int ans = maximum69Number(num);
    cout<<ans<<endl;
    // ans -> 9996
}