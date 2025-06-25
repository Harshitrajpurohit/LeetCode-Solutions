#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    int largest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt += 1;
            }
            largest = max(largest, cnt);
        }
    }

    return largest;
}

int main()
{
    vector<int> arr = {100, 4, 200, 1, 3, 2};

    int ans = longestConsecutive(arr);

    cout<<ans<<endl;
    // ans -> 4

}