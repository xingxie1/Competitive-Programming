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
    string s;
    cin >> s;
    string suf(n + 2,'9');
    for (int i = n - 1;i >= 0;i--) suf[i] = min(suf[i + 1],s[i]);
    auto f = [&](char x) -> string
    {
        string ans(n,'1');
        for (int i = 0;i < n;i++) 
        {
            if (s[i] < x) ans[i] = '1';
            else if (s[i] > x) ans[i] = '2';
            else 
            {
                if (suf[i + 1] < x) ans[i] = '2';
                else ans[i] = '1';
            }
        }
        string t;
        for (int i = 0;i < n;i++) 
        {
            if (ans[i] == '1') t += s[i];
        }
        for (int i = 0;i < n;i++) 
        {
            if (ans[i] == '2') t += s[i];
        }
        if (ranges::is_sorted(t)) return ans;
        return "";
    };
    for (char c = '0';c <= '9';c++) 
    {
        string ans = f(c);
        if (ans.size()) 
        {
            cout << ans << endl;
            return ;
        }
    }
    cout << "-" << endl;
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