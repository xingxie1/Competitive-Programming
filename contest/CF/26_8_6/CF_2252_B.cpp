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
    int n;
    string s;
    cin >> n >> s;
    int f = 1;
    for (int i = 1;i < n;i++)
    {
        if (s[i] == s[i - 1]) f = 0;
    }
    if (f)
    {
        cout << 0 << endl;
        return ;
    }
    vt cnt(2),need(2);
    for (int i = 0;i < n;i++)
    {
        int j = i;
        while (j < n && s[j] == s[i]) j++;
        cnt[s[i] - '0'] += (j - i); 
        need[s[i] - '0'] += (j - i - 1); 
        i = j - 1;
    }
    
    if (need[0] == need[1]) 
    {
        cout << need[0] + need[1] << endl;
    }
    else 
    {
        if (need[0] > need[1])
        {
            int d = need[0] - need[1];
            int ans = need[0] + need[1];
            if (d == 1) {}
            else if (d == 2) ans++;
            else if (d == 3) ans += 2;
            else if (d == 4) 
            {
                cout << -1 << endl;
                return ;
            }  
            d -= (s[0] == '1');
            d -= (s[n - 1] == '1');
            if (d <= 1) 
            {
                cout << ans << endl;
            }
            else cout << -1 << endl;
        }
        else 
        {
            int d = need[1] - need[0];
            int ans = need[0] + need[1];
            if (d == 1) {}
            else if (d == 2) ans++;
            else if (d == 3) ans += 2;
            else  
            {
                cout << -1 << endl;
                return ;
            }  
            d -= (s[0] == '0');
            d -= (s[n - 1] == '0');
            if (d <= 1) 
            {
                cout << ans << endl;
            }
            else cout << -1 << endl;
        }
        // int mx = max(need[0],need[1]);
        // if (need[0] < need[1])
        // {
        //     if (cnt[0] < mx - 1 || (s[0] != '0' && s[n - 1] != '0')) 
        //     {
        //         cout << -1 << endl;
        //         return ;
        //     }
        // }
        // if (need[1] < need[0]) 
        // {
        //     if (cnt[1] < mx - 1 || (s[0] != '1' && s[n - 1] != '1'))
        //     {
        //         cout << -1 << endl;
        //         return ;
        //     }
        // }
        // cout << 2 * mx - 1 << endl;
    }
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