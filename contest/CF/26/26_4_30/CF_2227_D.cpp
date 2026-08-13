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
    int N = 2 * n;
    vt a(N);
    for (int i = 0;i < N;i++) cin >> a[i];
    int p1 = -1,p2 = -1;
    for (int i = 0;i < N;i++)
    {
        if (a[i] == 0) 
        {
            if (p1 == -1) p1 = i;
            else p2 = i;
        }
    }
    auto f = [&](int j)
    {
        int l = j - 1,r = j + 1;
        set<int> st;
        st.insert(0);
        while (l >= 0 && r < N) 
        {
            if (a[l] != a[r]) break;
            st.insert(a[l]);
            st.insert(a[r]);
            l--;
            r++;
        }
        int mex = 0;
        for (int x : st) 
        {
            if (mex == x) mex++;
            else break;
        }
        return mex;
    };
    int ans = max(f(p1),f(p2));
    int L = p1 - 1,R = p2 + 1;
    int flag = 1;
    set<int> st = {0};
    while (L >= 0 && R < N) 
    {
        if (a[L] != a[R]) break;
        st.insert(a[L]);
        L--;
        R++;
    }
    int l = p1 + 1,r = p2 - 1;
    while (l <= r)
    {
        if (a[l] != a[r]) 
        {
            flag = 0;
            break;
        }
        st.insert(a[l]);
        l++;
        r--;
    }
    if (flag) 
    {
        int mex = 0;
        for (int x : st) 
        {
            if (mex == x) mex++;
            else break;
        }
        ans = max(ans,mex);
    }
    cout << ans << endl;
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