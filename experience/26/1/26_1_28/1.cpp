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
    int n,k,mx;
    cin >> n >> k >> mx;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    int l = -1,r = INT_MAX / 2;
    auto check = [&](int x)
    {
        vt tmp;
        if (x == 0)
        {
            for (int i = 0;i < k;i++)
            {
                tmp.push_back(i);
            }
            return tmp;
        }
        // cout << x << endl;
        if (a[0] >= x) 
        {
            int d = 0;
            while (d + x <= a[0]) 
            {
                tmp.push_back(d++);
                if (tmp.size() >= k) return tmp;
            }
        }
        for (int i = 1;i < n;i++)
        {
            int c = a[i] - a[i - 1] - 2 * x + 1;
            if (c > 0)
            {
                int d = a[i - 1] + x;
                for (int j = 0;j < c;j++)
                {
                    tmp.push_back(d++);
                    if (tmp.size() == k) return tmp;
                }
            }
        }
        if (a[n - 1] <= mx - x)
        {
            int d = a[n - 1] + x;
            while (d <= mx)
            {
                tmp.push_back(d++);
                if (tmp.size() == k) return tmp;
            }
        }
        return tmp;
    };
    vt ans;
    while (l + 1 < r)
    {
        int m = l + (r - l) / 2;
        if (check(m).size() >= k) 
        {
            l = m;
            ans = check(m);
        }
        else r = m;
    }
    for (int x : ans) cout << x << " ";
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