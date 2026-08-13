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
    string s;
    cin >> s;
    vpii a(m);
    for (int i = 0;i < m;i++) 
    {
        cin >> a[i].fi >> a[i].se;
        a[i].fi--;
        a[i].se--;
    }
    vt next1(n + 1,n),pre0(n + 1,-1);
    for (int i = n - 1;i >= 0;i--)
    {
        if (s[i] == '1') next1[i] = i;
        else next1[i] = next1[i + 1];
    }
    for (int i = 0;i < n;i++) 
    {
        if (s[i] == '0') pre0[i + 1] = i;
        else pre0[i + 1] = pre0[i];
    }
    set<pii> st;
    for (auto& [l,r] : a)
    {
        int L = next1[l];
        int R = pre0[r + 1];
        if (L > R)
        {
            L = R= -1;
        }
        st.insert({L,R});
    }
    cout << st.size() << endl;
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