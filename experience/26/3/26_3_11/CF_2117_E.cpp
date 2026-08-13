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
    int n;
    cin >> n;
    vvt a(n,vt(2));
    for (int i = 0;i < n;i++) cin >> a[i][0];
    for (int i = 0;i < n;i++) cin >> a[i][1];
    vvt pos(n + 1,vt(2,-1));
    int j = -1;
    for (int i = n - 1;i >= 0;i--)
    {
        if (a[i][0] == a[i][1])
        {
            j = i;
            break;
        }
        int x = a[i][0],y = a[i][1];
        if (pos[x][0] != -1 || pos[y][1] != -1) 
        {
            j = i;
            break;
        } 
        if (pos[x][1] - i > 1 || pos[y][0] - i > 1) 
        {
            j = i;
            break;
        }
        pos[x][0] = i;
        pos[y][1] = i;
    }
    cout << j + 1 << endl;
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