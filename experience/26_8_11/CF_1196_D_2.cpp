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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    auto check = [&](string& t) 
    {
        int l = 0,r = 0;
        int cnt = 0,ans = k;
        while (r < n)
        {
            if (s[r] != t[r]) cnt++;
            if (r - l + 1 == k)
            {
                ans = min(ans,cnt);
                cnt -= s[l] != t[l];
                l++;
            }
            r++;
        }
        return ans;
    };
    string t;
    while (t.size() < n) 
    {
        t += 'R';
        if (t.size() == n) break;
        t += 'G';
        if (t.size() == n) break;
        t += 'B';
    }
    int ans = check(t);
    t = "";
    while (t.size() < n) 
    {
        t += 'G';
        if (t.size() == n) break;
        t += 'B';
        if (t.size() == n) break;
        t += 'R';
    }
    ans = min(ans,check(t));
    t = "";
    while (t.size() < n) 
    {
        t += 'B';
        if (t.size() == n) break;
        t += 'R';
        if (t.size() == n) break;
        t += 'G';
    }
    ans = min(ans,check(t));
    cout << ans << endl;
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