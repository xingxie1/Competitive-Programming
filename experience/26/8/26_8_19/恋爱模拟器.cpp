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

struct node
{
    int op;
    string n1,n2;
};
void solve()
{
    int n;
    cin >> n;
    vector<string> a(n),b(2 * n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < 2 * n;i++) cin >> b[i];
    vector<node> ans;
    for (int i = 0;i < n / 2;i++)
    {
        ans.push_back({1,a[i],a[i + n / 2]});
        ans.push_back({1,a[i],a[i + n / 2]});
        ans.push_back({1,a[i],a[i + n / 2]});
        ans.push_back({1,a[i],a[i + n / 2]});
        ans.push_back({1,a[i],a[i + n / 2]});
        ans.push_back({2,a[i],a[i + n / 2]});
    }
    if (n % 2) 
    {
        ans.push_back({1,a[n / 2],b[0]});
        ans.push_back({1,a[n / 2],b[0]});
        ans.push_back({1,a[n / 2],b[0]});
        ans.push_back({1,a[n / 2],b[0]});
        ans.push_back({1,a[n / 2],b[0]});
        ans.push_back({2,a[n / 2],b[0]});
    }
    cout << ans.size() << endl;
    for (int i = 0;i < ans.size();i++)
    {
        cout << ans[i].op << " " << ans[i].n1 << " " << ans[i].n2 << endl;
    }
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