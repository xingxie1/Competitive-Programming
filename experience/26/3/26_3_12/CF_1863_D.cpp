#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<string> g(n);
    vector<string> a(n);
    for (int i = 0;i < n;i++) a[i].resize(m);
    for (int i = 0;i < n;i++) cin >> g[i];
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            a[i][j] = '.';
        }
    }
    for (int i = 0;i < n;i++)
    {
        int c = 0;
        for (int j = 0;j < m;j++)
        {
            if (g[i][j] == 'U')
            {
                c++;
                if (c % 2)
                {
                    a[i][j] = 'B';
                    a[i + 1][j] = 'W';
                }
                else 
                {
                    a[i][j] = 'W';
                    a[i + 1][j] = 'B';
                }
            }
        }
        if (c % 2) 
        {
            cout << -1 << endl;
            return ;
        }
    }
    for (int j = 0;j < m;j++)
    {
        int c = 0;
        for (int i = 0;i < n;i++)
        {
            if (g[i][j] == 'L')
            {
                c++;
                if (c % 2)
                {
                    a[i][j] = 'B';
                    a[i][j + 1] = 'W';
                }
                else 
                {
                    a[i][j] = 'W';
                    a[i][j + 1] = 'B';
                }
            }
        }
        if (c % 2) 
        {
            cout << -1 << endl;
            return ;
        }
    }
    for (int i = 0;i < n;i++) cout << a[i] << endl;
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