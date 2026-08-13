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
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    ll s,m;
    cin >> s >> m;
    ll lb = m & -m;
    if (s % lb) 
    {
        cout << -1 << endl;
        return ;
    }
    ll l = -1,r = LLONG_MAX / 2;
    auto check = [&](ll x)
    {
        ll sum = s;
        for (int i = 59;i >= 0;i--)
        {
            if ((m >> i) & 1)
            {
                ll c = min(x,sum / (1LL << i));
                sum -= c * (1LL << i);
            }
        }
        return sum == 0;
    };
    while (l + 1 < r)
    {
        ll m = l + (r - l) / 2;
        if (check(m)) r = m;
        else l = m;
    }
    if (r == LLONG_MAX / 2) cout << -1 << endl;
    else cout << r << endl;
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