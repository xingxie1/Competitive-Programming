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
    int n,m;
    cin >> n >> m;
    vt b(m),a(n + 1);
    for (int i = 0;i < m;i++) cin >> b[i];
    a[1] = b[m - 1];
    for (int i = 2;i <= n;i++) 
    {
        auto it = ranges::lower_bound(b,a[i]) - b.begin();
        int k;
        if (a[i] == 0) k = m - 2;
        else k = it; 
        if (k < 0) 
        {
            cout << -1 << endl;
            return ;
        }
        a[i] = b[k--];
        for (int j = i + i;j <= n;j += i) 
        {
            if (k < 0) 
            {
                cout << -1 << endl;
                return ;
            }
            a[j] = b[k];
        }
    }
    for (int i = 1;i <= n;i++) cout << a[i] << " ";
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