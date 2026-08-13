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
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt cnt;
    int ans = 0;
    for (string s : a) 
    {
        int c = 0;
        ans += s.size();
        while (s.back() == '0')
        {
            c++;
            s.pop_back();
        }
        cnt.push_back(c);
    }
    ranges::sort(cnt,{},[&](int x){return -x;});
    for (int i = 0;i < n;i++)
    {
        ans -= cnt[i];
        i++;
    }
    // cout << ans << endl;
    if (ans > m) cout << "Sasha" << endl;
    else cout << "Anna" << endl;
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