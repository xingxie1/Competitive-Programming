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
    set<int> st;
    for (int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    
    int g = 0,last = *st.begin();
    for (auto it = ++st.begin();it != st.end();it++) 
    {
        g = gcd(g,*it - last);
        last = *it;
    }
    if (g == 0)
    {
        cout << 1 << endl;
        return ;
    }
    int t = *st.rbegin(),mn = *st.begin();
    ll ans = 0;
    for (auto it = st.begin();it != st.end();it++)
    {
        int x = *it;
        ans += (t - x) / g;
    }
    for (ll x = t - g;;x -= g)
    {
        if (x < mn)
        {
            ans += (t - x) / g;
            break;
        }
        if (!st.contains(x)) 
        {
            ans += (t - x) / g;
            break;
        }
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