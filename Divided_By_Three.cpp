#include <bits/stdc++.h>
#define ll long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
using namespace std;
void solve()
{
    string s;
    cin >> s;
    ll ans = 0;
    for (char c : s)
    {
        ans += (c - '0');
    }
    if (ans % 3 == 0)
        yes;
    else
        no;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}