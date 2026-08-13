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
    int a,b;
    cin >> a >> b;
    int ans = 0;
    int s1 = 0,s2 = 0;
    int cnt0 = 0,cnt1 = 0;
    for (int i = 0;;i++)
    {
        s1 += pow(4,i);
        if (s1 > a)
        {
            cnt0 = i;
            break;
        }
    }
    for (int i = 0;;i++)
    {
        s2 += 2 * pow(4,i);
        if (s2 > b)
        {
            cnt1 = i;
            break;
        }
    }

    if (cnt0 <= cnt1) ans = max(ans,2 * cnt0);
    else ans = max(ans,2 * cnt1 + 1);

    s1 = 0,s2 = 0;
    for (int i = 0;;i++)
    {
        s1 += 2 * pow(4,i);
        if (s1 > a)
        {
            cnt1 = i;
            break;
        }
    }
    for (int i = 0;;i++)
    {
        s2 += pow(4,i);
        if (s2 > b)
        {
            cnt0 = i;
            break;
        }
    }

    if (cnt0 <= cnt1) ans = max(ans,2 * cnt0);
    else ans = max(ans,2 * cnt1 + 1);

    cout << ans << endl;
    
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