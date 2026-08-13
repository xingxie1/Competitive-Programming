#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define endl '\n'
// const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    set<pair<ll,ll>> s;
    for (int i = 0;i < n;i++)
    {
        ll c,w;
        cin >> c >> w;
        auto it = s.lower_bound({w,0});
        if (it != s.end() && it->fi == w) 
        {
            c += it->se;
            s.erase(it);
        }
        s.insert({w,c});
    }
    // for (auto [w,c] : s) cout << w << " " << c << endl;
    // cout << "$$$$" << endl;
    ll ans = 0;
    while (s.size() > 1 || (s.size() == 1 && s.begin()->se > 1))
    {
        auto it = s.begin();
        ll w = it->fi,c = it->se;
        if (c % 2 == 0)
        {
            ll t = 2 * w;
            auto it2 = s.lower_bound({t,0});
            ll c2 = 0;
            if (it2 != s.end() && it2->fi == t) 
            {
                c2 = it2->se;
                s.erase(it2);
            }
            s.erase(it);
            ans += 1LL * w * c;
            ans %= MOD;
            s.insert({2 * w,c2 + c / 2});
        }
        else 
        {
            if (c > 1)
            {
                ll t = 2 * w;
                auto it2 = s.lower_bound({t,0});
                ll c2 = 0;
                if (it2 != s.end() && it2->fi == t) 
                {
                    c2 = it2->se;
                    s.erase(it2);
                }
                s.insert({2 * w,c2 + c / 2});
                ll d = c / 2;
                ans += 2LL * w * d;
                ans %= MOD;
            }
            auto i2 = it;
            i2++;
            if (i2 != s.end())
            {
                ll w3 = i2->fi,c3 = i2->se;
                auto i3 = s.lower_bound({w3 + w,0});
                if (i3 != s.end() && i3->fi == w3 + w)
                {
                    ll w4 = i3->fi,c4 = i3->se;
                    s.erase(i3);
                    s.insert({w4,c4 + 1});
                }
                else 
                {
                    s.insert({w3 + w,1});
                }
                ans += w3 + w;
                ans %= MOD;
                s.erase(i2);
                if (c3 > 1) s.insert({w3,c3 - 1});
            }
            s.erase(it);
        }
        ans %= MOD;
        // for (auto [w,c] : s) cout << w << " " << c << endl;
        // cout << ans << endl;
        // cout << "$$$$" << endl;
    }
    // for (auto [w,c] : s) cout << w << " " << c << endl;

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