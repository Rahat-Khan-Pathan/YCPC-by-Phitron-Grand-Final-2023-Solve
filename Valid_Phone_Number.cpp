#include <bits/stdc++.h>
#define ll long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
using namespace std;
void solve()
{
    string s;
    cin >> s;
    bool ans = true;
    if (s.size() != 14)
    {
        no;
        return;
    }
    string frst = s.substr(0, 4);
    if (frst != "+880")
    {
        no;
        return;
    }
    string scnd = s.substr(4, 2);
    if (scnd[0] == '1' && (scnd[1] >= '2' && scnd[1] <= '9'))
    {
        string third = s.substr(6, 8);
        for (char c : third)
        {
            if (c >= '0' && c <= '9')
                continue;
            else
            {
                no;
                return;
            }
        }
        yes;
    }
    else
    {
        no;
    }
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