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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

umap<int,vpii> p;
void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    mset<int> st;
    for (int x : a) st.insert(x);
    for (int x : a)
    {
        st.erase(st.find(x));
        if (st.contains(x) && st.contains(1))
        {
            YES;
            return ;
        }
        for (auto [a1,a2] : p[x])
        {
            if (st.contains(a1) && st.contains(a2)) 
            {
                YES;
                return ;
            }
        }
        st.insert(x);
    }
    NO;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    for (int i = 2;i <= sqrt(1e9);i++)
    {
        int cnt = 0;
        for (ll j = i;j < 1e9;j *= i)
        {
            cnt++;
            p[j].push_back({i,cnt});
        }
    }
    while (_ --) solve();

    return 0;
}