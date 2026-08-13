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
    int n ;
    cin >> n;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvt g(26);
    vt deg(26);
    for (int i = 0;i < n - 1;i++) 
    {
        int m = a[i].size();
        int f = 0;
        for (int j = 0;j < m;j++) 
        {
            if (j >= a[i + 1].size()) break;
            if (a[i][j] != a[i + 1][j])  
            {
                int x = a[i][j] - 'a';
                int y = a[i + 1][j] - 'a';
                g[x].push_back(y);
                deg[y]++;
                f = 1;
                break;
            }
        }
        if (!f && a[i + 1].size() < a[i].size()) 
        {
            cout << "Impossible" << endl;
            return ;
        }
    }
    pqueue<int,vt,greater<>> q;
    int cnt = 0;
    string ans;
    for (int i = 0;i < 26;i++)
    {
        if (!deg[i]) 
        {
            q.push(i);
            cnt++;
        }
    }
    while (!q.empty()) 
    {
        int x = q.top();
        q.pop();
        ans += 'a' + x;
        for (int y : g[x]) 
        {
            deg[y]--;
            if (!deg[y])
            {
                q.push(y);
                cnt++;
            }
        }
    }
    if (ans.size() != 26) cout << "Impossible" << endl;
    else cout << ans << endl;
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