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
    for (int i = 0;i < n;i++) cin >> a[i];
    if (a[0] != 0 && a[n - 1] == 0)
    {
        cout << 2 << endl;
        cout << 2 << " " << n << endl;
        cout << 1 << " " << 2 << endl;
    }
    else if (a[n - 1] != 0 && a[0] == 0)
    {
        cout << 2 << endl;
        cout << 1 << " " << n - 1 << endl;
        cout << 1 << " " << 2 << endl;
    }
    else if (a[0] == 0 && a[n - 1] == 0)
    {
        cout << 3 << endl;
        cout << 1 << " " << 2 << endl;
        cout << 2 << " " << n - 1 << endl;
        cout << 1 << " " << 2 << endl;
    }
    else 
    {
        int flag = 1,cnt = 0,j1 = -1,j2 = -1;
        for (int i = 0;i < n;i++) 
        {
            int x = a[i];
            if (x == 0) 
            {
                flag = 0;
                if (j1 == -1) j1 = i;
                else j2 = i;
                cnt++;
            }
        }
        if (flag)
        {
            cout << 1 << endl;
            cout << 1 << " " << n << endl;
        }
        else 
        {
            if (cnt >= 2)
            {
                cout << 3 << endl;
                cout << 1 << " " << j1 + 1 << endl;
                cout << 2 << " " << n - j1 << endl;
                cout << 1 << " " << 2 << endl;
            }
            else 
            {
                cout << 2 << endl;
                cout << 1 << " " << j1 + 1 << endl;
                cout << 1 << " " << n - j1 << endl;
            }
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