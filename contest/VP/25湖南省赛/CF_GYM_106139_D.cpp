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
    if (n == m) 
    {
        if (n == 1) 
        {
            cout << 1 << endl;
            cout << "1 1 1" << endl;
            return ;
        }
        else if (n == 2) 
        {
            cout << 2 << endl;
            cout << "1 1 1" << endl;
            cout << "2 1 1" << endl;
            return ;
        }
        int ans = 0;
        ans += n - 1;
        cout << ans << endl;
        if (n % 2 == 0)
        {
            cout << "1 " << n << " " << n << endl;
            n--;
        }
        cout << 1 << " " << n / 2 + 1 << " " << n / 2 + 1 << endl;
        cout << 2 << " " << n / 2 + 1 << " " << n / 2 + 1 << endl;
        for (int i = 2;i <= n - 1;i++)
        {
            if (i == n / 2 + 1) continue;
            cout << 1 << " " << i << " " << i << endl;
        }
    }
    else 
    {
        cout << min(m,n) << endl;
        if (n < m) 
        {
            for (int i = 0;i < n;i++) cout << 1 << " " << i + 1 << " " << 1 << endl;
        }
        else 
        {
            for (int j = 0;j < m;j++) cout << 1 << " " << 1 << " " << j + 1 << endl;
        }
    }
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