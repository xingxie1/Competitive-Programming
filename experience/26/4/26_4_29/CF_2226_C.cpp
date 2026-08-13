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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ranges::sort(a);
    int l = 0,r = n + 1;
    auto check = [&](int m)
    {
        set<int> st;
        vt b;
        for (int x : a)
        {
            if (x < m && !st.contains(x))
            {
                st.insert(x);
            }
            else b.push_back(x);
        }
        int mex = 0;
        for (int x : b)
        {
            while (st.contains(mex)) mex++;
            if (x >= 2 * mex + 1) 
            {
                st.insert(mex);
                mex++;
            }
        }
        while (st.contains(mex)) mex++;
        return mex >= m;
    };
    while (l + 1 < r)
    {
        int m = l + r >> 1;
        if (check(m)) l = m;
        else r = m;
    } 
    cout << l << endl;
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