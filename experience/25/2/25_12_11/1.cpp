// https://codeforces.com/problemset/problem/1038/B
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
    int n;
    cin >> n;
    if (n == 1 || n == 2)
    {
        cout << "No" << endl;
        return ;
    }
    cout << "Yes" << endl;
    if (n & 1)
    {
        cout << 1 << " " << (n + 1) / 2 << endl;
        cout << n - 1 << " ";
        for (int i = 1;i <= n;i++)
        {
            if (i != (n + 1) / 2) cout << i << " ";
        }
        cout << endl;
    }
    else 
    {
        cout << 1 << " " << n / 2 << endl;
        cout<< n - 1 << " ";
        for (int i = 1;i <= n;i++)
        {
            if (i != n / 2) cout << i << " ";
        }
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