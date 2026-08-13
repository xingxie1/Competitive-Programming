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
    int n,p;
    cin >> n >> p;
    vt a(n);
    set<int> st;
    map<int,int> cnt;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        a[i] %= p;
        st.insert(a[i]);
        cnt[a[i]]++;
    }
    int ans = 0;
    for (int x : st)
    {
        auto it = st.upper_bound(p - 1 - x);
        if (it != st.begin()) 
        {
            it--;
            int y = *it;
            // cout << x << " " << y << endl;
            if (x != y || cnt[x] > 1) ans = max(ans,(x + y) % p);
        }
        it = st.upper_bound(2 * p - 1 - x);
        if (it == st.begin()) continue;
        it--;
        int y = *it;
        // cout << x << " " << y << endl;
        if (x != y || cnt[x] > 1) ans = max(ans,(x + y) % p);
    }
    cout << ans << endl;


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