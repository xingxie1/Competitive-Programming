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

void solve()
{
    int n,m;
    cin >> n >> m;
    int N = n + m + 1;
    vt a(N),b(N);
    for (int i = 0;i < N;i++) cin >> a[i];
    for (int i = 0;i < N;i++) cin >> b[i];
    vt type(N);
    int ca = 0,cb = 0;
    ll sum = 0;
    int lasta = -1,lastb = -1;
    for (int i = 0;i < N;i++)
    {
        if (a[i] > b[i])
        {
            if (ca >= n + 1) 
            {
                type[i] = 2;
                cb++;
                sum += b[i];
                lastb = i;
            }
            else 
            {
                type[i] = 1;
                ca++;
                sum += a[i];
                lasta = i;
            }
        }
        else 
        {
            if (cb >= m + 1)
            {
                type[i] = 1;
                ca ++;
                sum += a[i];
                lasta = i;
            }
            else 
            {
                type[i] = 2;
                cb++;
                sum += b[i];
                lastb = i;
            }
        }
    }
    int last,t;
    if (ca == n + 1) 
    {
        last = lasta;
        t = 1;
    }
    else 
    {
        last = lastb;
        t = 2;
    }
    // cout << lasta << " " << lastb << endl;
    for (int i = 0;i < N;i++)
    {
        ll ans = sum;
        if (type[i] == t)
        {
            if (t == 1) ans -= a[i];
            else ans -= b[i];
        }
        else
        {
            if (t == 1) ans = ans - b[i] - a[lasta] + b[lasta];
            else ans = ans - a[i] - b[lastb] + a[lastb];
        }
        cout << ans << " ";
    }
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