#include<iostream>

using namespace std;


int possibleStringCount(string word){
    int cnt = 0;
    for (int i = 1; i < word.length(); i++){
        if (word[i - 1] == word[i]){
            cnt++;
        }
    }

    return cnt + 1;
}

int main(){
    string str = "abbcccc";
    
    int ans = possibleStringCount(str);

    cout<<ans<<endl;
}