#include <iostream>
#include <vector>

using namespace std;

char findTheDifference(string s, string t)
{
    vector<int> a(26, 0);
    for (char i : t)
    {
        int val = int(i - 97);
        a[val]++;
    }
    for (char i : s)
    {
        int val = int(i - 97);
        a[val]--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (a[i] > 0)
            return char(i + 97);
    }

    return '\0';
}

int main(){
    string s = "abcd";
    string t = "abcde";

    char ans = findTheDifference(s,t);

    cout<<ans<<endl;
    // ans -> e
}