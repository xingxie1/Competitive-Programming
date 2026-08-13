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
    int n,m;
    cin >> n >> m;
    vvt g(n);
    vvt f(n);
    for (int i = 0;i < n;i++) 
    {
        string s;
        cin >> s;
        for (int j = i;j < i + m;j++)
        {
            if (s[j - i] == '1')
            {
                g[i].push_back(j + 1);
                f[j + 1].push_back(i);
            }
        }
    }
    vt dis1(n,INT_MAX / 2),dis2(n,INT_MAX / 2);
    dis1[0] = 0;
    dis2[n - 1] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) 
    {
        int x = q.front();
        q.pop();
        for (int y : g[x]) 
        {
            if (dis1[y] > dis1[x] + 1)
            {
                q.push(y);
                dis1[y] = dis1[x] + 1;
            }
        }
    }
    q.push(n - 1);
    while (!q.empty()) 
    {
        int x = q.front();
        q.pop();
        for (int y : f[x]) 
        {
            if (dis2[y] > dis2[x] + 1)
            {
                q.push(y);
                dis2[y] = dis2[x] + 1;
            }
        }
    }
    for (int i = 1;i < n - 1;i++) 
    {
        int ans = INT_MAX / 2;
        for (int x = max(i - m,0);x <= i - 1;x++) 
        {
            if (dis1[x] == INT_MAX / 2) continue;
            for (int y : g[x]) 
            {
                if (y <= i || y >= n) continue;
                ans = min(ans,dis1[x] + 1 + dis2[y]);
            }
        }
        if (ans == INT_MAX / 2) cout << -1 << " ";
        else cout << ans << " ";
    }
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