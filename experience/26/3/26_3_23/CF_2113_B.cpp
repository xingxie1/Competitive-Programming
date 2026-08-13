#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int w,h,a,b;
    cin >> w >> h >> a >> b;
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) swap(x1,x2);
    if (y1 > y2) swap(y1,y2);
    int dx = x2 - (x1 + a),dy = y2 - (y1 + b);
    if (x1 == x2)
    {
        if (dy % b) 
        {
            cout << "No" << endl;
            return ;
        }
    }
    if (y1 == y2)
    {
        if (dx % a) 
        {
            cout << "No" << endl;
            return ;
        }
    }
    if (dx % a && dy % b)
    {
        cout << "No" << endl;
        return ;
    }
    cout << "Yes" << endl;
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