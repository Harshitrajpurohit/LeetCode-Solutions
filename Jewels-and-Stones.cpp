#include<iostream>
#include<algorithm>

using namespace std;

int numJewelsInStones(string jewels, string stones) {
        int cnt=0;
        for(char i:stones){
            auto it = find(jewels.begin(),jewels.end(),i);
            if(it != jewels.end()){
                cnt++;
            }
        }

        return cnt;
    }

int main(){
    string jewels = "aA", stones = "aAAbbbb";

    cout<<numJewelsInStones(jewels, stones)<<endl;
    // ans -> 3
}