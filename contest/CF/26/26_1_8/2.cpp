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

void solve()
{
    int n,k;
    cin >> n >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int cnt = 0;
    map<int,int> see;
    priority_queue<int> pq;
    for (int x : a)
    {
        if (see.count(x)) cnt++;
        else pq.push(x);
        see[x] ++;
    }
    while (cnt < n - k + 1)
    {
        pq.pop();
        cnt++;
    }
    vt b;
    while (!pq.empty()) 
    {
        b.push_back(pq.top());
        pq.pop();
    }
    int j = 0;
    for (int i = b.size() - 1;i >= 0;i--) 
    {
        if (j != b[i]) break;
        j++;
    }
    cout << j << endl;
    // for (int x : b) cout << x << " ";
    // cout << endl;
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