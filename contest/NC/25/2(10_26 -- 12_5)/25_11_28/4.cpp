#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int a,b,l,r;
    cin >> a >> b>> l >> r;
    int d = b - a,cnt = 0;
    vector<int> fact;
    for (int i = 1;i * i <= d;i++)
    {
        if (d % i == 0) 
        {
            fact.push_back(i);
            if(i * i != d) fact.push_back(d / i);
        }
    }
    for (int c : fact)
    {
        long long x = b + c;
        if (x >= l && x <= r) cnt++;
    }
    cout << cnt << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}