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
    vvt a;
    map<pii,int> cnt;
    for (int i = 0;i < n;i++)
    {
        int l,r;
        cin >> l >> r;
        cnt[{l,r}]++;
        vt tmp = {l,r,i};
        a.push_back(tmp);
    }
    auto c = a;
    ranges::sort(a,{},[&](auto& b) {
        return pair{b[0],-b[1]};
    });
    mset<int> st;
    vll L(n,LLONG_MIN),R(n,LLONG_MAX);
    for (auto& g : a) 
    {   
        int l = g[0],r = g[1],id = g[2];
        auto it = st.lower_bound(r);
        if (it != st.end()) R[id] = *it;
        st.insert(r);
    }
    ranges::sort(a,{},[&](auto& b) {
        return pair{-b[1],b[0]};
    });
    st.clear();
    for (auto& g : a) 
    {   
        int l = g[0],r = g[1],id = g[2];
        auto it = st.upper_bound(l);
        if (it != st.begin()) L[id] = *(--it);
        st.insert(l);
    }
    vll ans(n);
    for (int i = 0;i < n;i++) 
    {
        int l = c[i][0],r = c[i][1];
        if (cnt[{l,r}] > 1) ans[i] = 0;
        else if (L[i] == LLONG_MIN || R[i] == LLONG_MAX) ans[i] = 0;
        else ans[i] = (l - L[i]) + (R[i] - r);
    }
    for (ll x : ans) cout << x << endl;


    
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