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
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<string> a(n),b(n);
    int s1 = 0,s2 = 0;
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    
    for (int i = 0;i < n;i++)
    {
        int s1 = 0,s2 = 0;
        for (int j = 0;j < m;j++)
        {
            s1 += a[i][j] - '0';
            s2 += b[i][j] - '0';
        }
        if (s1 % 3 != s2 % 3) 
        {
            cout << "NO" << endl;
            return ;
        }
    }
    for (int j = 0;j < m;j++)
    {
        int s1 = 0,s2 = 0;
        for (int i = 0;i < n;i++)
        {
            s1 += a[i][j] - '0';
            s2 += b[i][j] - '0';
        }
        if (s1 % 3 != s2 % 3) 
        {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
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