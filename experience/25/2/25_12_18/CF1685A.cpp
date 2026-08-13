// https://codeforces.com/problemset/problem/1685/A
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
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    if (n & 1)
    {
        cout << "NO" << endl;
        return ;
    }
    sort(a.begin(),a.end());
    int k = n / 2;
    for (int i = 0; i < k; i++) 
    {
        b[2 * i] = a[i];
        b[2 * i + 1] = a[ i + k];
    }
    for (int i = 1;i < n - 1;i++)
    {
        if ((b[i] >= b[i - 1] && b[i] <= b[i + 1]) || (b[i] <= b[i - 1] && b[i] >= b[i + 1]))
        {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
    for (int x : b)cout << x << " ";
    cout << endl;
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