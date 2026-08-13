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
    int n,k;
    cin >> n >> k;
    vt a(n);
    unordered_set<int> s;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    int cnt = 0;
    int x = -1,y = -1,z = -1;
    for (int i =1;i <= n;i++)
    {
        if (!s.contains(i))
        {
            x = i;
            break;
        }
    }
    if (x == -1)
    {
        x = a[0];
        y = a[1];
        z = a[2];
    }
    else 
    {
        z = a[n - 1];
        for (int i = 1;i <= n;i++)
        {
            if (i != x && i != z) 
            {
                y = i;
                break;
            }
        }
    }
    while (k)
    {
        cout << x << " ";
        k--;
        if (k == 0) break;
        cout << y << " ";
        k--;
        if (k == 0) break;
        cout << z << " ";
        k--;
    }
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