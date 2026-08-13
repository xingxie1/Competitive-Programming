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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;
int MOD = 676767677;

void solve()
{
    int x,y;
    cin >> x >> y;
    if (x == 0)
    {
        int cnt = 0;
        for (int i = 1;i <= sqrt(y);i++)
        {
            if (y % i == 0)
            {
                cnt ++;
                if (y / i != i) cnt++;
            }
        }
        cout << cnt << endl;
        for (int i = 0;i < y;i++) cout << -1 << " ";
        cout << endl;
        return ;
    }
    if (y == 0)
    {
        int cnt = 0;
        for (int i = 1;i <= sqrt(x);i++)
        {
            if (x % i == 0)
            {
                cnt ++;
                if (x / i != i) cnt++;
            }
        }
        cout << cnt << endl;
        for (int i = 0;i < x;i++) cout << 1 << " ";
        cout << endl;
        return ;
    }
    int N = x + y;
    vt a(N);
    for (int i = 0;i < y;i++) a[i] = -1;
    for (int i = y;i < N;i++) a[i] = 1;
    int s = 0,cnt = 1;
    for (int i = 0;i < N - 1;i++)
    {
        s += a[i];
        if (s != 0 && (x - y - s) % s == 0 && 1LL * (x - y - s) * s > 0) cnt++;
    }
    cout << cnt << endl;
    for (int x : a) cout << x << " ";
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