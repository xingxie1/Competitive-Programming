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
    string s;
    cin >> s;
    int n = s.size();
    ll cnt = 0,ans = 0;
    vt vis(n);
    vt a(n);
    stack<int> st;
    for (int i = 0;i < n;i++) 
    {
        if (s[i] == '(') st.push(i);
        else if (!st.empty()) 
        {
            int j = st.top();
            vis[j] = 1; 
            st.pop();
            // cout << j << " " << i << "\n";
            ans += 1ll * (j + 1) * (n - i);
            // cnt += 2;
        }
        // a[i] = cnt;
        // ans += cnt;
    }
    // for (int i = 0; i < n; i++) {
    //     if (vis[i]) cout << i << "\n";
    // }
    cout << 2 * ans << "\n";
    // ll sum = ans;
    // // ans = 0;
    // // cout << sum << endl;
    // cout << ans << endl;
    // for (int i = 0;i < n;i++) 
    // {
    //     if (s[i] == '(' && vis[i]) 
    //     {
    //         sum -= 2LL * (n - i - 1);
    //         // cout << 2LL * (n - i - 1) << endl;
    //         // cout << i << " " << sum << endl;
    //         // continue;
    //     }
    //     if (sum >= 0) ans += sum;
    //     // cout << ans << endl;
    // }
    // // cout << endl;
    // cout << ans << endl;
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