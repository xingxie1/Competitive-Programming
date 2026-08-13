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
    if (bit_width((uint32_t) a) < bit_width((uint32_t) b))
    {
        cout << "-1" << endl;
        return ;
    }
    if (a == b) 
    {
        cout << 0 << endl;
        return ;
    }
    int cnt = 0;
    vt ans;
    for (int bit = 0;bit <= 31;bit++)
    {
        if (((a >> bit) & 1) != ((b >> bit) & 1))
        {
            ans.push_back(1 << bit);
            a = a ^ (1 << bit);
            cnt++;
        }
    }
    cout << cnt << endl;
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