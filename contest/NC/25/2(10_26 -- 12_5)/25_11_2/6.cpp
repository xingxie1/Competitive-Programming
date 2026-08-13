#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

long long c(int m,int n)
{
    return 1LL * (m - 1) * m / 2 + m;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    set<int> s;
    int mn = INT_MAX,mx = 0;
    for (int i = 0;i < n;i++) 
    {
        int x,y;
        cin >> x >> y;
        s.insert(x);
        s.insert(y);
        mx = max({mx,x,y});
        mn = min({mn,x,y});
    }
    long long ans = 0;
    int last = 0;
    auto it = s.begin();
    while (it != s.end())
    {
        int x = *it;
        int m1 = x - last - 1;
        if (m1 >= 1) ans += c(m1,2);
        last = x;
        it++;
    }
    if (m - mx >= 1) ans += c(m - mx,2);
    ans += 1LL * (mn - 1) * (m - mx);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}