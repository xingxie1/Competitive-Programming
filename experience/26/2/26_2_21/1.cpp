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
    int n,m,k;
    cin >> n >> m >> k;
    vvt a(n,vt(m));
    auto rm = [&](vt& b)
    {
        reverse(b.begin() + 1,b.end());
        reverse(b.begin(),b.end());
    };
    if (m % k == 0)
    {
        vt t(m);
        for (int i = 0;i < m;i++)
        {
            t[i] = i % k + 1;
        }

        for (int i = 0;i < n;i++)
        {
            a[i] = t;
            rm(t);
        }
    }
    else if (n % k == 0)
    {
        vt t(n);
        for (int i = 0;i < n;i++) t[i] = i % k + 1;
        for (int j = 0;j < m;j++)
        {
            for (int i = 0;i < n;i++)
            {
                a[i][j] = t[i];
            }
            rm(t);
        }
    }
    else 
    {
        int r = n,c = m;
        int group = n * m / k;
        for (int i = 2;i <= k;i++)
        {
            if (k % i) continue;
            int j = k / i;
            if (n % i == 0 && m % j == 0) 
            {
                r = i;
                c = j;
                break;
            }
        }
        vvt t(r,vt(c));
        int x = 1;
        for (int i = 0;i < r;i++)
        {
            for (int j = 0;j < c;j++)
            {
                t[i][j] = x++;
            }
        }
        for (int i = 0;i < n;i+=r)
        {
            for (int j = 0;j < m;j += c)
            {
                for (int ii = 0;ii < r;ii++)
                {
                    for (int jj = 0;jj < c;jj++)
                    {
                        a[i + ii][j + jj] = t[ii][jj];
                    }
                }
            }
        }
    }
    for (int i = 0;i < n;i++)
    {
        for (int x : a[i]) cout << x << " ";
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