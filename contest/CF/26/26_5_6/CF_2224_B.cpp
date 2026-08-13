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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    mset<int> st;
    for (int x : a) st.insert(x);
    int mx = *(--st.end());
    st.erase(st.find(mx));
    vt b = {mx};
    int x = 0;
    while (1)
    {
        if (st.contains(x)) 
        {
            b.push_back(x);
            st.erase(st.find(x));
            x++;
        }
        else break;
    }
    while (!st.empty()) 
    {
        int x = *st.begin();
        b.push_back(x);
        st.erase(st.begin());
    }
    int mex = 0;
    set<int> has;
    ll ans = 0;
    for (int x : b) 
    {
        has.insert(x);
        while (has.contains(mex)) mex++;
        mx = max(mx,x);
        ans += mx + mex;
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