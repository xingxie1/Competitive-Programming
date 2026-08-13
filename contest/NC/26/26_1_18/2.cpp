#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    vector a(4,vector<int>(4));
    for (int i = 0;i < 4;i++)
    {
        for (int j = 0;j < 4;j++) cin >> a[i][j];
    }
    int flag = 1;
    for (int i = 0;i < 4;i++)
    {
        vt cnt(4);
        for (int j = 0;j < 4;j++)
        {
            cnt[a[i][j] - 1] ++;
        }
        for (int x : cnt) 
        {
            if (x >= 2) flag = 0;
        }
        if (!flag) break;
    }
    if (!flag)
    {
        cout << "NO" << endl;
        return ;
    }
    for (int j = 0;j < 4;j++)
    {
        vt cnt(4);
        for (int i = 0;i < 4;i++)
        {
            cnt[a[i][j] - 1] ++;
        }
        for (int x : cnt) 
        {
            if (x >= 2) flag = 0;
        }
        if (!flag) break;
    }
    if (!flag)
    {
        cout << "NO" << endl;
        return ;
    }
    for (int i = 0;i < 4;i += 2)
    {
        for (int j = 0;j < 4;j += 2)
        {
            vt cnt(4);
            cnt[a[i][j] - 1]++;
            cnt[a[i][j + 1] - 1]++;
            cnt[a[i + 1][j] - 1]++;
            cnt[a[i + 1][j + 1] - 1]++;
            for (int x : cnt) 
            {
                if (x >= 2) flag = 0;
            }
            if (!flag) break;
        }
    }
    if (!flag)
    {
        cout << "NO" << endl;
        return ;
    }
    cout << "YES" << endl;
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