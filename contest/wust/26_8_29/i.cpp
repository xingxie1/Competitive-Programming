#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;

void solve()
{
    int n,m;
    cin >> n >> m;   
    int lasti = 0,lastx = 0;
    int f = 1;
    vpii a(m);
    for (int i = 0;i < m;i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    ranges::sort(a);
    for (auto& [x,y] : a)
    {
        int d = x - lasti;
        if (!(y - lastx == d || d >= y + 1)) 
        {
            f = 0;
        }
        lasti = x;
        lastx = y;
    }
    if (f) cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();

}