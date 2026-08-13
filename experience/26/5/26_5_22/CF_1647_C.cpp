#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
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
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vector<string> b(n);
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) b[i] += '0';
    }
    if (a == b) 
    {
        cout << 0 << endl;
        return ;
    }
    vvt ans;
    for (int i = n - 1;i >= 0;i--) 
    {
        for (int j = m - 1;j >= 0;j--) 
        {
            if (a[i][j] != b[i][j]) 
            {
                int f = 0;
                if (j - 1 >= 0) 
                {
                    vt tmp = {i,j - 1,i,j};
                    ans.push_back(tmp);
                    f = 1;
                    b[i][j - 1] = '0';
                    b[i][j] = '1';
                }
                if (f) continue;
                if (i - 1 >= 0)
                {
                    vt tmp = {i - 1,j,i,j};
                    ans.push_back(tmp);
                    f = 1;
                    b[i - 1][j] = '0';
                    b[i][j] = '1';
                    f = 1;
                }
                if (!f) 
                {
                    cout << -1 << endl;
                    return ;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto& b : ans) cout << b[0] + 1 << " " << b[1] + 1 << " " << b[2] + 1 << " " << b[3] + 1 << endl;
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