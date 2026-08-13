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
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i].fi;
        a[i].se = i + 1;
    }
    sort(a.begin(),a.end());
    cout << a[0].se << " " << a[1].se << " " << a[2].se;
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