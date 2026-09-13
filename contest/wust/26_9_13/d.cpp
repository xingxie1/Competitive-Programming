#include<bits/stdc++.h>
using namespace std;

using vt = vector<int>;
using vvt = vector<vector<int>>;

void solve()
{
    int n,m;
    cin >> n >> m;
    vt a(n),b(m);
    vvt pos(n + 1);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for (int i = 0;i < m;i++) cin >> b[i];
    int last = -1;
    for (int x : b)
    {
        auto it = ranges::upper_bound(pos[x],last);
        if (it == pos[x].end()) 
        {
            cout << "No" << endl;
            return ;
        }
        last = *it;
    }
    cout << "Yes" << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();

    return 0;
}