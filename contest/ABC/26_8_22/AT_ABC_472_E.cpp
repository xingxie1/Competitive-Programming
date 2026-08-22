#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
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
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vvt g(n);
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    vt color(n,-1);
    vt pre(n,-1);
    for (int i = 0;i < n;i++)
    {
        if (color[i] != -1) continue;
        color[i] = 0;
        q.push(i);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int y : g[x])
            {
                if (color[y] == -1) 
                {
                    color[y] = color[x] ^ 1;
                    pre[y] = x;
                    q.push(y);
                }
                else if (color[y] == color[x]) 
                {
                    int cur = x;
                    vt ans;
                    set<int> st;
                    while (cur != -1) 
                    {
                        st.insert(cur);
                        ans.push_back(cur);
                        cur = pre[cur];
                    }
                    int s = -1;
                    vt tmp;
                    cur = y;
                    while (cur != -1) 
                    {
                        if (st.contains(cur) && s == -1) 
                        {
                            s = cur;
                            break;
                        }
                        tmp.push_back(cur);
                        cur = pre[cur];
                    }
                    while (ans.back() != s) ans.pop_back();
                    ranges::reverse(tmp);
                    ans.insert(ans.end(),tmp.begin(),tmp.end());
                    cout << ans.size() << endl;
                    for (int x : ans) cout << x + 1 << " ";
                    cout << endl;
                    return ;
                }
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}