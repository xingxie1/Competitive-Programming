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
    int h,w,q;
    cin >> h >> w >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int r;
            cin >> r;
            cout << r * w << endl;
            h -= r;
        }
        else 
        {
            int c;
            cin >> c;
            cout << h * c << endl;
            w -= c;
        }
    }

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