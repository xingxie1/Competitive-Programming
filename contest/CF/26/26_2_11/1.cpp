#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int x;
    cin >> x;
    auto d = [&](int n)
    {
        int ret = 0;
        while (n)
        {
            ret += n % 10;
            n /= 10;
        }
        return ret;
    };
    for (int i = x;i <= x + 100;i++)
    {
        if (i - d(i) == x) 
        {
            cout << 10 << endl;
            return ;
        }
    }
    cout << 0 << endl;
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