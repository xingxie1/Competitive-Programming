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
    int k;
    cin >> k;
    string s,t;
    cin >> s >> t;
    vt c1(10),c2(10);
    for (int i = 0;i < 4;i++)
    {
        c1[s[i] - '0']++;
        c2[t[i] - '0']++;
    }
    double ans = 0;
    for (int i = 1;i <= 9;i++)
    {
        if (c1[i] + c2[i] + 1 > k) continue;
        c1[i]++;
        for (int j = 1;j <= 9;j++) 
        {
            if (c1[j] + c2[j] + 1 > k) continue;
            c2[j]++;
            ll sum1 = 0,sum2 = 0;
            for (int x = 1;x <= 9;x++)
            {
                sum1 += x * pow(10,c1[x]);
                sum2 += x * pow(10,c2[x]);
            }
            if (sum1 > sum2)
            {
                if (i == j)
                {
                    ans += 1.0 * (k - c1[i] - c2[i] + 2) * (k + 1 - c1[i] - c2[i]) / (1.0 * (9 * k - 8) * (9 * k - 9));
                }
                else 
                {
                    ans += 1.0 * (k - c1[i] - c2[i] + 1) * (k - c1[j] - c2[j] + 1) / (1.0 * (9 * k - 8) * (9 * k - 9));
                }
            }
            c2[j]--;
        }
        c1[i]--;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}