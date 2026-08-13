#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vpii a(m);
    map<int,vt> L;
    map<int,vt> R;
    for (int i = 0;i < m;i++) 
    {
        cin >> a[i].fi >> a[i].se;
        L[a[i].fi].push_back(a[i].se);
        R[a[i].se].push_back(a[i].fi);
    }
    for (auto& [l,f] : L) 
    {
        ranges::sort(f);
    }
    for (auto& [r,f] : R) 
    {
        ranges::sort(f);
    }
    int q;
    cin >> q;
    while (q--) 
    {
        int l,r;
        cin >> l >> r;
        auto it = ranges::lower_bound(L[l],r + 1);
        if (it == L[l].begin()) 
        {
            NO;
            continue;
        }
        it--;
        int rr = *it;
        auto it2 = ranges::lower_bound(R[r],l);
        if (it2 == R[r].end()) 
        {
            NO;
            continue;
        }
        int ll = *it2;
        if (ll == l && rr == r) 
        {
            if (it != L[l].begin() && (*(--it)) >= ll - 1) YES;
            else if (it2 != (--R[r].end()) && (*(++it2)) <= rr + 1) YES;
            else 
            {
                int f = 0;
                for (int j = l + 1;j <= r;j++) 
                {
                    if (L.contains(j) && !L[j].empty() && L[j][0] <= r) 
                    {
                        YES;
                        f = 1;
                        break;
                    }
                }
                if (f) continue;
                NO;
            }
            continue;
        }
        if (ll <= rr + 1) YES;
        else NO;
    }
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