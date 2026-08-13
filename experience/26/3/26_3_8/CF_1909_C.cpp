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
    vt c(n);
    vpii a;
    for (int i = 0;i < n;i++) 
    {
        int l;
        cin >> l;
        a.push_back({l,0});
    }
    for (int i = 0;i < n;i++) 
    {
        int r;
        cin >> r;
        a.push_back({r,1});
    }
    for (int i = 0;i < n;i++) cin >> c[i];
    ranges::sort(c);
    ranges::sort(a);
    stack<int> st;
    vt len;
    for (int i = 0;i < 2 * n;i++)
    {
        if (a[i].se == 0) st.push(a[i].fi);
        else 
        {
            int L = st.top();
            st.pop();
            len.push_back(a[i].fi - L);
        }
    }
    ll ans = 0;
    ranges::sort(len);
    for (int i = 0;i < n;i++)
    {
        ans += 1LL * len[i] * c[n - i - 1];
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