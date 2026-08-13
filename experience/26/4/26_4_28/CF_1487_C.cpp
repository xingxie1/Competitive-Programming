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
    int n;
    cin >> n;
    if (n % 2)
    {
        int sum = n * (n - 1) / 2;
        int cnt = sum  / n;
        for (int j = 1;j < n;j++)
        {
            for (int i = 0;i < min(cnt,n - j);i++) cout << 1 << " ";
            for (int i = cnt;i < n - j;i++) cout << -1 << " ";
        }
        cout << endl;
    }
    else 
    {
        int mx = n / 2 - 1;
        for (int j = 1;j < n;j++)
        {
            for (int i = 0;i < min(mx,n - j);i++) cout << 1 << " ";
            if (n - j <= mx) continue;
            cout << 0 << " ";
            for (int i = mx + 1;i < n - j;i++) cout << -1 << " ";
        }
        cout << endl;
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