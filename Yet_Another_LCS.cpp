// Solution by Apurba Saha

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef APURBA
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
const int N = 200 + 5;
typedef pair<int, int> pii;

int n, m, k;
string s, t;

int dp[N][N][N];

int solve(int i, int j, int rem)
{
    assert(i <= n && j <= m && rem >= 0);
    if (i == n && j == m)
    {
        return rem / 2;
    }
    int &ret = dp[i][j][rem];
    if (ret != -1)
        return ret;
    int ans = 0;
    if (i < n)
    {
        // do nothing
        ans = max(ans, solve(i + 1, j, rem));
    }
    if (j < m)
    {
        // do nothing
        ans = max(ans, solve(i, j + 1, rem));
    }
    if (i < n && j < m && s[i] == t[j])
    {
        // do nothing
        ans = max(ans, 1 + solve(i + 1, j + 1, rem));
    }
    if (rem)
    {
        if (j < m)
        {
            // add at index i
            ans = max(ans, 1 + solve(i, j + 1, rem - 1));
        }
        if (i < n)
        {
            // add at index j
            ans = max(ans, 1 + solve(i + 1, j, rem - 1));
        }
        if (i < n && j < m && rem >= 2)
        {
            // do nothing
            ans = max(ans, 1 + solve(i + 1, j + 1, rem - 2));
        }
    }
    return ret = ans;
}

int32_t main()
{
#ifndef APURBA
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    cin >> n >> m >> k;
    cin >> s >> t;
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, k) << "\n";
    return 0;
}
