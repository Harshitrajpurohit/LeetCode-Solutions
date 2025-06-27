#include <iostream>
#include <algorithm>

using namespace std;

int hammingWeight(int n)
{

    string s = "";

    while (n > 0)
    {
        int bit = n % 2;
        s.push_back('0' + bit);
        n = n / 2;
    }
    reverse(s.begin(), s.end());
    int cnt = 0;
    for (char i : s)
    {
        if (i == '1')
        {
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    int n = 11;
    cout<< hammingWeight(n);
    // ans -> 3
}