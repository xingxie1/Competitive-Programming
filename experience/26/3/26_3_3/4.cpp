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
    int n,x,y;
    cin >> n >> x >> y;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int mni = x;
    for (int i = x;i < y;i++)
    {
        if (a[i] < a[mni]) mni = i;
    }
    int mn = a[mni];
    reverse(a.begin() + x,a.begin() + mni);
    reverse(a.begin() + mni,a.begin() + y);
    reverse(a.begin() + x,a.begin() + y);
    vt tmp;
    for (int i = 0;i < x;i++) tmp.push_back(a[i]);
    for (int i = y;i < n;i++) tmp.push_back(a[i]);
    int j = tmp.size();
    for (int i = 0;i < tmp.size();i++)
    {
        if (tmp[i] > mn) 
        {
            j = i;
            break;
        }
    }
    vt ans;
    for (int i = 0;i < j;i++) ans.push_back(tmp[i]);
    for (int i = x;i < y;i++) ans.push_back(a[i]);
    for (int i = j;i < tmp.size();i++) ans.push_back(tmp[i]);

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