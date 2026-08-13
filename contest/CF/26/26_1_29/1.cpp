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
    vt a(n);
    if (n == 2)
    {
        cout << "1 2" << endl;
        return ;
    }
    if (n == 3)
    {
        cout << "2 1 3" << endl;
        return ;
    }
    int s = 1;
    for (int i = n - 2;i >= 0;i -= 2) a[i] = s++;
    int j;
    if (n % 2 == 0) j = 1;
    else j = 0;
    for (int i = j;i < n;i += 2) a[i] = s++;
    for (int x : a) cout << x << " ";
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