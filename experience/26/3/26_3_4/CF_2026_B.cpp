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
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ll l = 0,r = LLONG_MAX;
    auto check = [&](ll x)
    {   
        int cnt = 0;
        for (int i = 0;i < n;i ++)
        {
            if (i == n - 1)
            {
                cnt++;
                break;
            }
            if (a[i + 1] - a[i] > x) 
            {
                cnt++;
            }
            else i++;
        }
        if (cnt > 1) return 0;
        return 1;
    };
    while (l + 1 < r)
    {
        ll m = l + (r  -l) / 2;
        if (check(m)) r = m;
        else l = m;
    }
    cout << r << endl;
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