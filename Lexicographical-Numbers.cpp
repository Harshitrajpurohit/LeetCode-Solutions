#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

bool compareLexicographically(int a,int b){
    return to_string(a) < to_string(b);
}

vector<int> lexicalOrder(int n){

    vector<int> ans;
    for(int i=1;i<=n;i++){
        ans.push_back(i);
    }

    sort(ans.begin(), ans.end(), compareLexicographically);

    return ans;
}

int main(){
    int num = 13;

    vector<int> ans = lexicalOrder(num);

    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;

}
