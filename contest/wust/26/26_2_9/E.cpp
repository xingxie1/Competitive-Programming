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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector a(n,vector<char>(m,'.'));
    if (k == 0)
    {
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < m;j++) cout << a[i][j] << " ";
            cout << endl;
        }
        return ;
    }
    for (int i = 1;i < n;i += 2)
    {
        for (int j = 1;j < m;j += 2)
        {
            a[i][j] = '*';
            k--;
            if (k == 0) break;
        }
        if (k == 0) break;
    }
    if (k > 0)
    {
        for (int i = 1;i < n;i+=2)
        {
            for (int j = 0;j < m;j++)
            {
                if (a[i][j] != '*')
                {
                    a[i][j] = '*';
                    k--;
                    if (k == 0) break;
                }
            }
            if (k == 0) break;
        }
    }
    if (k > 0)
    {
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < m;j++)
            {
                if (a[i][j] != '*')
                {
                    a[i][j] = '*';
                    k--;
                    if (k == 0) break;
                }
            }
            if (k == 0) break;
        }
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++) cout << a[i][j] << " ";
        cout << endl;
    }


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