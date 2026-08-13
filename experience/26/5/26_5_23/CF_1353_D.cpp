#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

struct tii{
    int len,l,r;
    bool operator < (const tii other) const
    {
        if (len != other.len) return len < other.len;
        return l > other.l;
    }
};
void solve()
{
    int n;
    cin >> n;
    vt a(n + 1);
    pqueue<tii> pq;
    pq.push({n,1,n});
    for (int i = 1;i <= n;i++) 
    {
        auto tmp = pq.top();
        pq.pop();
        int len = tmp.len,l = tmp.l,r = tmp.r;
        int id;
        if ((r - l + 1) % 2) id = (l + r) / 2;
        else id = (l + r - 1) / 2;
        a[id] = i;
        if (id != l) pq.push({id - l,l,id - 1});
        if (id != r) pq.push({r - id,id + 1,r});
    }
    for (int i = 1;i <= n;i++) cout << a[i] << " ";
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