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

ll query1(int l,int r)
{
    cout << 1 << " " << l << " " << r << endl;
    ll ret;
    cin >> ret;
    return ret;
}
ll query2(int l,int r)
{
    cout << 2 << " " << l << " " << r << endl;
    ll ret;
    cin >> ret;
    return ret;
} 
void solve()
{
    int n;
    cin >> n;
    ll sum = 1LL * n * (n + 1) / 2;
    int len = query2(1,n) - sum;
    int l = len,r = n;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        int len1 = query2(1,mid) - query1(1,mid);
        if (len1 == len) r = mid;
        else l = mid + 1;
    }
    cout << "! " << l - len + 1 << " " << l << endl;
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