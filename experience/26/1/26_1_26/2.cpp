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
    int n, m, h;
    cin >> n >> m >> h;

    vector<pair<int,ll>> res(n);

    for (int i = 0; i < n; i++) 
    {
        vector<int> a(m);
        for (int j = 0; j < m; j++) cin >> a[j];
        sort(a.begin(), a.end());

        ll time = 0, penalty = 0;
        int cnt = 0;
        for (int j = 0; j < m; j++) 
        {
            time += a[j];
            if (time > h) break;
            cnt++;
            penalty += time;
        }
        res[i] = {cnt, penalty};
    }

    int rank = 1;
    for (int i = 1; i < n; i++) 
    {
        if (res[i].fi > res[0].fi) rank++;
        else if (res[i].fi == res[0].fi && res[i].se < res[0].se) rank++;
    }

    cout << rank << "\n";
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