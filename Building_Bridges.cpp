#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(vector<pair<int, int>> &v, int n)
{
    int dp[n + 1];
    fill(dp, dp + n + 1, INT_MAX);
    dp[0] = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int idx = upper_bound(dp, dp + n + 1, v[i].second) - dp;
        if (v[i].second > dp[idx - 1] && v[i].second < dp[idx])
        {
            dp[idx] = v[i].second;
        }
    }
    for (int i = n; i >= 0; i--)
    {
        if (dp[i] != INT_MAX)
        {
            return i;
        }
    }
    return 1;
}
int BuildingBridges(vector<int> &v1, vector<int> &v2, int n)
{
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back({v1[i], v2[i]});
    }
    sort(v.begin(), v.end());
    return func(v, n);
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase)
    {
        int n;
        cin >> n;
        vector<int> v1(n), v2(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v1[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v2[i];
        }
        int sol = BuildingBridges(v1, v2, n);
        cout << sol << endl;
        testcase--;
    }
    return 0;
}
