#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> a(n);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(),a.end());
    vt ans(m);
    

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