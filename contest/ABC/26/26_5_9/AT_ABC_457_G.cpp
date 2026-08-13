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
    int n;
    cin >> n;
    vpii a(n);
    map<int,vt> t;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i].fi >> a[i].se;
        t[a[i].fi].push_back(a[i].se);
    }
    for (auto& [tt,f] : t) 
    {
        ranges::sort(f);
    }
    ll ans = 0;
    auto it = t.begin();
    while (it != t.end()) 
    {
        auto nit = it;
        nit++;
        if (nit == t.end()) 
        {
            int m = it->se.size();
            ans = max(ans,1ll * m);
            break;
        }
        int dt = nit->fi - it->fi;
        ll cnt = 0;
        int j = 0;
        for (int i = 0;i < it->se.size();) 
        {
            cnt++;
            if (abs(it->se[i] - nit->se[j]) <= dt)
            {
                i++;
                j++;
            }
            else 
            {
                cnt++;
                if (it->se[i] < nit->se[j]) 
                {
                    i++;
                    j++;
                    if (j == nit->se.size()) break;
                    while (i < it->se.size() && it->se[i] < nit->se[j] && abs(it->se[i] - nit->se[j]) > dt) i++;
                }
                else 
                {
                    j++;
                }
            }
            if (j == nit->se.size()) break;
        }
        while (j < nit->se.size()) 
        {
            j++;
            cnt++;
        }
        ans = max(ans,cnt);
        it++;
    }
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