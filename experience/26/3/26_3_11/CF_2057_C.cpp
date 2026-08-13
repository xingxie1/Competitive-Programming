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
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int l,r;
    cin >> l >> r;
    int d = l ^ r;
    int k = bit_width((uint32_t) d);
    int n = bit_width((uint32_t) r);
    int mask = ~((1 << k) - 1);
    int pre = l & mask;
    int a = pre;
    a |= 1 << (k - 1);
    int b = pre;
    b |= ((1 << (k - 1)) - 1);
    int c = l;
    while (c == a || c == b) c++;
    cout << a << " " << b << " " << c << endl;
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