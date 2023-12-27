// Solution by Apurba Saha

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef LOKAL
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
const int N = 1e5 + 5;
typedef pair<int, int> pii;

vector<int> divisors[N + 1];

void Divisors()
{
    int n = N;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            divisors[j].push_back(i);
        }
    }
}

vector<int> all[N];
ll val[N];

ll cal(vector<int> &a)
{
    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        ans += sum * a[i];
        sum += a[i];
    }
    return ans;
}

int32_t main()
{
#ifndef LOKAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    //    freopen("input.txt","r",stdin);
    Divisors();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j : divisors[a[i]])
        {
            all[j].push_back(a[i]);
        }
    }
    ll ans = 0;
    for (int i = N - 1; i >= 1; i--)
    {
        if (all[i].empty())
            continue;
        ll tmp = cal(all[i]);
        for (int j = i + i; j < N; j += i)
        {
            tmp -= val[j];
        }
        val[i] = tmp;
        tmp /= (i * 1ll * i);
        ans += tmp;
    }
    cout << ans << "\n";
    return 0;
}
