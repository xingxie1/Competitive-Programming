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

struct chocolate{
    int h,w,id;
};
void solve()
{
    int n,H,W;
    cin >> n >> H >> W;
    vector<chocolate> a(n);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i].h >> a[i].w;
        a[i].id = i;
    }
    sort(a.begin(),a.end(),[&](const auto& b,const auto& c){
        if (b.h == c.h) return b.w > c.w;
        return b.h > c.h;
    });
    

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