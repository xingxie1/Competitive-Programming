#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> a(n);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i].fi;
        a[i].se = a[i].fi;
    }
    sort(a.begin(),a.end());
    if (m  < n / 2)
    {
        cout << -1 << endl;
        return ;
    }


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