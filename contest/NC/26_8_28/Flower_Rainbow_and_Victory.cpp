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
    cin >> n;
    string s,t;
    cin >> s >> t;
    vt cnt(4);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '0' && t[i] == 'B') cnt[0]++;
        else if (s[i] == '1' && t[i] == 'R') cnt[1]++;
        else if (s[i] == '0' && t[i] == 'R') cnt[2]++;
        else cnt[3]++;
    }
    int c1 = 0,c2 = 0;
    while (1) 
    {
        if (cnt[0] == 0 && cnt[1] == 0 && cnt[2] == 0 && cnt[3] == 0) break;
        if (cnt[3]) 
        {
            cnt[3]--;
            c1++;
        }
        else if (cnt[2]) 
        {
            cnt[2]--;
            c1++;
        }
        else if (cnt[0]) 
        {
            cnt[0]--;
            c1++;
        }
        else if (cnt[1]) cnt[1]--;

        if (cnt[0] == 0 && cnt[1] == 0 && cnt[2] == 0 && cnt[3] == 0) break;

        if (cnt[2]) 
        {
            cnt[2]--;
            c2++;
        }else if (cnt[3]) 
        {
            cnt[3]--;
            c2++;
        }
        else if (cnt[1]) 
        {
            cnt[1]--;
            c2++;
        }
        else if (cnt[0]) cnt[0]--;
    }
    if (c1 > c2) cout << "Rainbow" << endl;
    else if (c1 == c2) cout << "Draw" << endl;
    else cout << "Flower" << endl;
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