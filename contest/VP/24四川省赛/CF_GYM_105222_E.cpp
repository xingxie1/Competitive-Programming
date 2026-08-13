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
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int f = 0;
    vvt cnt(n,vt(m));
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] == '.' && (i != 0 || j != m - 1)) 
            {
                NO;
                return ;
            }
            if (a[i][j] == '.') f = 1;
            if (a[i][j] == 'L') 
            {
                if (j - 1 < 0 || a[i][j - 1] != 'C') 
                {
                    NO;
                    return ;
                }
                if (j - 2 >= 0 && a[i][j - 2] == 'R')
                {
                    NO;
                    return ;
                }
                cnt[i][j - 1]++;
            }
            else if (a[i][j] == 'R') 
            {
                if (j + 1 >= m || a[i][j + 1] != 'C') 
                {
                    NO;
                    return ;
                }
                if (j + 2 < m && a[i][j + 2] == 'L')
                {
                    NO;
                    return ;
                }
                cnt[i][j + 1] ++;
            }
            else if (a[i][j] == 'U') 
            {
                if (i - 1 < 0 || a[i - 1][j] != 'C') 
                {
                    NO;
                    return ;
                }
                if (i - 2 >= 0 && a[i - 2][j] == 'D')
                {
                    NO;
                    return ;
                }
                cnt[i - 1][j]++;
            }
            else if (a[i][j] == 'D') 
            {
                if (i + 1 >= n || a[i + 1][j] != 'C') 
                {
                    NO;
                    return ;
                }
                if (i + 2 < n && a[i + 2][j] == 'U')
                {
                    NO;
                    return ;
                }
                cnt[i + 1][j]++;
            }
        }
    }
    if (!f) 
    {
        NO;
        return ;
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] == 'C' && cnt[i][j] != 2) 
            {
                NO;
                return ;
            }
        }
    }
    YES;
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