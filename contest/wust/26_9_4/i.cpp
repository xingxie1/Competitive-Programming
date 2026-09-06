#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using vpii = vector<pii>;

void solve()
{
    int n,m;
    cin >> n >> m;
    vt a(n),b(m);
    double s1 = 0,s2 =0 ;
    for (int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        s1 += 1.0 * (x + 1) / 2;
    }
    for (int i = 0;i < m;i++)
    {
        int x;
        cin >> x;
        s2 += 1.0 * (x + 1) / 2;
    }
    if (s1 > s2) cout << "ALICE" << endl;
    else if (s1 == s2) cout << "TIED" << endl;
    else cout << "BOB" << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();

}