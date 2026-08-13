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

vt solve1(vt a,int j)
{
    ll sum = 0;
    int f = 0;
    vt ans;
    for (int i = j;i >= 0;i--) 
    {
        if (!f) 
        {
            if (a[i] > 0) 
            {
                ans.push_back(i);
                a[i] = -a[i];
                f = 1;
            }
        }
        else 
        {
            if (a[i] < 0) 
            {
                ans.push_back(i);
                f = 0;
            }
            else a[i] = -a[i];
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt ans;
    ll sum = 0;
    vll suf(n + 1) ;
    for (int i = n - 1;i >= 0;i--) suf[i] = suf[i + 1 ] + a[i];
    ll mx = accumulate(a.begin(),a.end(),0LL);
    int mxj = -1;
    for (int i = 0;i < n;i++) 
    {
        if (a[i] > 0) 
        {
            if (sum + suf[i + 1] - a[i] > mx) 
            {
                mx = sum + suf[i + 1] - a[i];
                mxj = i;
            }
        }
        sum += abs(a[i]);
    }
    if (mxj != -1) 
    {
        ans = solve1(a,mxj - 1);
        ans.push_back(mxj);
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x + 1 << " ";
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