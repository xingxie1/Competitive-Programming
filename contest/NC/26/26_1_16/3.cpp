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

vector<int> f(int n)
{
    vector<int> a(n);
    int mx = n / 2 + 1;
    for (int i = 0;i < mx;i++) a[i] = i + 1;
    int x = mx - 1;
    for (int i = mx;i < n;i++) a[i] = x--;
    return a;
}
void solve()
{
    int n;
    cin >> n;
    cout << n << " : ";
    if (n <= 2 || n == 4) 
    {
        cout << -1 << endl;
        return ;
    }
    else if (n % 2 == 1)
    {
        vector<int> a = f(n);
        for (int x : a) cout << x << " ";
        cout << endl;
    }
    else 
    {
        if ((n / 2) % 2 == 1)
        {
            vt a1 = f(n / 2),a2 = f(n / 2);
            for (int x : a1) cout << x << " ";
            for (int x : a2) cout << x << " ";
            cout << endl;
        }
        else 
        {
            int n1 = n / 2 - 1,n2 = n / 2 + 1;
            vt a1 = f(n1),a2 = f(n2);
            for (int x : a1) cout << x << " ";
            for (int x : a2) cout << x << " ";
            cout << endl;
        }
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