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
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a(n,vector<char>(m));
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (i % 2 == 0 && j % 2 == 0) a[i][j] = '/';
            else if (i % 2 == 0 && j % 2 == 1) a[i][j] = '\\';
            else if (i % 2 == 1 && j % 2 == 0) a[i][j] = '\\';
            else a[i][j] = '/';
        }
    }
    for (int i = 0;i < n;i++) 
    {
        for (char c : a[i]) cout << c;
        cout << endl;
    }
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