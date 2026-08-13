#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,k;
    cin >> n >> k;
    vt c(n + 1);
    for (int i = 1;i <= n;i++) cin >> c[i];
    set<int> st;
    for (int i = 0;i < k;i++) 
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    vvt g(n + 1);
    vt deg(n + 1);
    for (int i = 1;i <= n;i++) 
    {
        int m;
        cin >> m;
        for (int j = 0;j < m;j++) 
        {
            int x;
            cin >> x;
            g[x].push_back(i);
            deg[i]++;
        }
    }
    queue<int> q;
    vll dp(n + 1,LLONG_MAX / 2);
    vll sum(n + 1);
    for (int i = 1;i <= n;i++) 
    {
        if (st.contains(i)) dp[i] = 0;
        else dp[i] = c[i];
    }
    for (int i = 1;i <= n;i++) 
    {
        if (!deg[i]) 
        {
            q.push(i);
        }
    }
    while (!q.empty()) 
    {
        int x = q.front();
        q.pop();
        for (int y : g[x]) 
        {
            deg[y]--;
            sum[y] += dp[x];
            if (!deg[y]) 
            {
                dp[y] = min(dp[y],sum[y]);
                q.push(y);
            }
        }
    }
    for (int i = 1;i <= n;i++) 
    {
        if (st.contains(i)) cout << 0 << " ";
        else cout << dp[i] << " ";
    }
    cout << endl;
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