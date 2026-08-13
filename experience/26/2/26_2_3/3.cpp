#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
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
    vt a(n),b(n),p(n),ia(n);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        a[i]--;
        ia[a[i]] = i;
    }
    for (int i = 0;i < n;i++) 
    {
        cin >> b[i];
        b[i]--;
        p[a[i]] = b[i];
    }
    int cnt = 0;
    for (int i = 0;i < n;i++)
    {
        if (p[i] == i || p[p[i]] != i) cnt++;
    }
    if (cnt > 1) 
    {
        cout << -1 << endl;
        return ;
    }
    vt q(n);
    int l = 0,r = n - 1;
    for (int i = 0;i < n;i++)
    {
        if (p[i] == i) q[ia[i]] = n / 2;
        else if (p[i] > i)
        {
            q[ia[i]] = l++;
            q[ia[p[i]]] = r--;
        }
    }
    vector<array<int,2>> ans;
    for (int i = 0;i < n;i++)
    {
        while (q[i] != i)
        {
            ans.push_back({i,q[i]});
            swap(q[i],q[q[i]]);
        }
    }
    cout << ans.size() << endl;
    for (auto [x, y] : ans)
    {
        cout << x + 1 << " " << y + 1 << endl;
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