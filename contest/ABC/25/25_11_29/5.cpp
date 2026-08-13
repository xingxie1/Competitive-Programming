#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt x(n),r(n);
    for (int i = 0;i < n;i++) cin >> x[i] >> r[i];
    unordered_map<ll,int> s1,s2;
    for (int i = 0;i < n;i++)
    {
        ll a = x[i] - r[i],b = x[i] + r[i];
        s1[a] ++;
        s1[b] ++;
    }
    for (int i = 0;i < n;i++)
    {
        ll a = x[i] - r[i],b = x[i] + r[i];
        if (s1[a] < s1[b]) 
        {
            if (!s2.count(a)) 
            {
                s2[a]++;
            }
            else 
            {
                s2[b]++;
            }
            s1[b]--;
            s1[a]--;
        }
        else 
        {
            if (!s2.count(b))
            {
                s2[b]++;
            }
            else s2[a]++;
            s1[a]--;
            s1[b]--;
        }
    }
    cout << s2.size();
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