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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    if (n == 1)
    {
        cout << 1 << endl;
        return ;
    }
    set<int> st;
    map<int,int> cnt;
    for (int i = 0;i <= 30;i++) st.insert(1 << i);
    for (int x : a) cnt[x]++;
    // for (int x : st) cout << x << " ";
    int ans = 0;
    for (int x : a)
    {
        int f = 0;
        for (int y : st)
        {
            if (cnt.count(y - x)) 
            {
                if (x != y - x || cnt[x] >= 2)
                {
                    // cout << x << " " << y << endl;
                    f = 1;
                    break;
                }
            }
        }
        if (!f) 
        {
            ans++;
        }
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