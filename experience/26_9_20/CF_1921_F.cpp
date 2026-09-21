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
    int n,q;
    cin >> n >> q;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int B = sqrt(n);
    vvll sum(n,vll(B + 1));
    vvll pre(n,vll(B + 1));

    for (int d = 1;d <= B;d++)
    {
        for (int i = 0;i < n;i++)
        {
            pre[i][d] = a[i];
            sum[i][d] = a[i] * (i / d + 1);
            if (i >= d) 
            {
                pre[i][d] += pre[i - d][d];
                sum[i][d] += sum[i - d][d];
            }
        }
    }

    while (q--)
    {
        int s,d,k;
        cin >> s >> d >> k;
        s--;
        if (d > B)
        {
            ll ans = 0;
            for (int i = s;i <= s + d * (k - 1);i += d) ans += a[i] * ((i - s) / d + 1);
            cout << ans << " ";
        }
        else 
        {
            int s2 = s + d * (k - 1);
            ll ans = sum[s2][d];
            ll x = pre[s2][d];
            if (s >= d) 
            {
                ans -= sum[s - d][d];
                x -= pre[s - d][d];
            }
            ans -= s / d * x;
            cout << ans << " ";
        }
    }
    cout << endl;
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