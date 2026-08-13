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
    vvt a(3,vt(3));
    vt cnt(10);
    for (int i = 0;i < 3;i++)
    {
        int sum = 0;
        for (int j = 0;j < 3;j++)
        {
            cin >> a[i][j];
            sum += a[i][j];
            cnt[a[i][j]]++;
            if (cnt[a[i][j]] >= 2) 
            {
                cout << "No" << endl;
                return ;
            }
        }
        if (sum != 15)
        {
            cout << "No" << endl;
            return ;
        }
    }
    for (int j = 0;j < 3;j++)
    {
        int sum = 0;
        for (int i = 0;i < 3;i++)
        {
            sum += a[i][j];
        }
        if (sum != 15) 
        {
            cout << "No" << endl;
            return ;
        }
    }
    int sum = a[0][0] + a[1][1] + a[2][2];
    if (sum != 15) 
    {
        cout << "No" << endl;
        return ;
    }
    sum = a[0][2] + a[1][1] + a[2][0];
    if (sum != 15) 
    {
        cout << "No" << endl;
        return ;
    }
    cout << "Yes" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}