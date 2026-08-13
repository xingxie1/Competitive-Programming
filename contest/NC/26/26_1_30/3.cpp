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
    int n,a0,a1;
    cin >> n >> a0 >> a1;
    string s;
    int cnt0 = 0,cnt1 = 0;
    for (int i = 0;i < n;i++)
    {
        int d0 = abs((cnt0 + 1) * a1 - cnt1 * a0); 
        int d1 = abs((cnt1 + 1) * a0 - cnt0 * a1);
        if (d0 < d1)
        {
            s += '0';
            cnt0++;
        }
        else 
        {
            s += '1';
            cnt1++;
        }
    }
    cout << s << endl;
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