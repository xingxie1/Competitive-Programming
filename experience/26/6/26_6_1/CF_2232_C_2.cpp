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

void solve()
{
    int n,x,c;
    cin >> n >> x >> c;
    string s;
    cin >> s;
    int ca = 0;
    for (char ch : s) ca += (ch == 'A');
    int l = -1,r = ca + 1;
    auto check = [&](int p) 
    {
        int cnt = 0;
        int tab = 0;
        int ans = 0;
        for (char ch : s) 
        {
            if (ch == 'I') 
            {
                if (tab < x) 
                {
                    tab++;
                    ans++;
                }
            }
            else if (ch == 'E') 
            {
                if (1LL * tab * c > ans) 
                {
                    ans++;
                }
            }
            else 
            {
                cnt++;
                if (cnt <= p) 
                {
                    if (tab < x) 
                    {
                        tab++;
                        ans++;
                    }
                }
                else 
                {
                    if (1LL * tab * c > ans) 
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    };
    while (l + 1 < r) 
    {
        int m = (l + r) / 2;
        if (check(m) < check(m + 1)) l = m;
        else r = m;
    }
    cout << check(r) << endl;
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