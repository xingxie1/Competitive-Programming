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
    vt ans,a;
    for (int i = 1;i <= sqrt(n);i++)
    {
        for (int j = i + 1;j <= sqrt(n);j++)
        {
            if (i * i + j * j <= n) 
            {
                a.push_back(i * i + j * j);
            }
        }
    }
    sort(a.begin(),a.end());
    for (int i = 0;i < a.size();i++)
    {
        int flag = 0;
        if (i + 1 < a.size() && a[i + 1] == a[i])
        {
            flag = 1;
            while (i + 1 < a.size() && a[i + 1] == a[i]) i++;
        }
        if (flag == 0) ans.push_back(a[i]);
        
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
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