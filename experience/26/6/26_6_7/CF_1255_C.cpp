#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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

void solve()
{
    int n;
    cin >> n;
    vvt a(n - 2,vt(3));
    for (int i = 0;i < n - 2;i++) 
    {
        for (int j = 0;j < 3;j++) cin >> a[i][j];
        ranges::sort(a[i]);
    }
    ranges::sort(a);
    vt ans(n);
    for (int i = 1;i < n - 2;i++) 
    {
        int x1,x2 = -1,x3 = -1,x4;
        for (int j = 0;j < 3;j++) 
        {
            int f = 0;
            for (int j2 = 0;j2 < 3;j2++) 
            {
                if (a[i - 1][j] == a[i][j2]) f = 1;
            }
            if (!f) x1 = a[i - 1][j];
            else 
            {
                if (x2 == -1) x2 = a[i - 1][j];
                else x3 = a[i - 1][j];
            } 
        }
        for (int x : a[i]) 
        {
            if (x != x3 && x != x2) x4 = x;
        }
        ans[i - 1] = x1;
        ans[i + 2] = x4;
    }
    set<int> st;
    for (int i = 1;i <= n;i++) st.insert(i);
    for (int& x : ans) 
    {
        if (x != 0) st.erase(x);
    }
    for (int& x : ans) 
    {
        if (x == 0) 
        {
            x = *st.begin();
            st.erase(st.begin());
        }
    }
    for (int x : ans) cout << x << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}