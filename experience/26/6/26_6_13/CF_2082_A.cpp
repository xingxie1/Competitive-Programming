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
    int n , m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int ans = 0;
    int cc = 0;
    for (int i = 0;i < n;i++)
    {
        int cnt = 0;
        for (char c : a[i]) cnt += (c == '1');
        if (cnt % 2 == 1) cc++;
    }
    ans = cc;
    cc = 0;
    for (int j = 0;j < m;j++) 
    {   
        int cnt = 0;
        for (int i = 0;i < n;i++) 
        {
            if (a[i][j] == '1') 
            {
                cnt++;
            }
        }
        if (cnt % 2) cc++;
    }
    ans = max(ans,cc);
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