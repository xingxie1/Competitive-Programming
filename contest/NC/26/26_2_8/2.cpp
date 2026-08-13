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
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vpii b;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (a[i][j] == '*') b.push_back({i,j});
        }
    }
    int xx = -1;
    for (int i = 0;i < 4;i++)
    {
        int cnt = 0;
        for (int j = 0;j < 4;j++)
        {
            if (j == i) continue;
            if (b[i].fi == b[j].fi || b[i].se == b[j].se) cnt++;
        }
        if (cnt == 3)
        {
            xx = i;
            break;
        }
    }
    // cout << xx;
    int x = b[xx].fi,y = b[xx].se;
    // cout << x << y << endl;
    if (x - 1 >= 0 && x - 2 >= 0 && a[x-1][y] == '*' && a[x-2][y] == '*')  cout << "L" << endl;
    else if (x + 1 < n && x + 2 < n && a[x+1][y] == '*' && a[x+2][y] == '*') cout << "L" << endl;
    else if (y - 1 >= 0 && y - 2 >= 0 && a[x][y-1] == '*' && a[x][y-2] == '*') cout << "L" << endl;
    else if (y + 1 < n && y + 2 < n && a[x][y+1] == '*' && a[x][y+2] == '*') cout << "L" << endl;
    else cout << "T" << endl;
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