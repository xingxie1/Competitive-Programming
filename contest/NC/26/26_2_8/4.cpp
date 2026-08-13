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
    int a,b;
    cin >> a >> b;
    if (b == 3 || b == 6)
    {
        if (b == 3) cout << "1 3" << endl;
        else cout << "2 3" << endl;
    }
    else if (b == 9)
    {
        int res = a % 2;
        if (res == 1)
        {
            cout << "91 99" << endl;
        }
        else cout << "1 11" << endl;
    }
    else if (b == 0)
    {
        if (a == 1) 
        {
            cout << "1 11" << endl;
        }
        else cout << "1 2" << endl;
    }
    else cout << b << " 9" << endl;
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