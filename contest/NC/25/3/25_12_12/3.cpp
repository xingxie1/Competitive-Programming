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
    int n;
    cin >> n;
    vt a(n);
    pqueue<double,vector<double>,greater<>> pq;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        pq.push(a[i]);
    }
    while (pq.size() > 1)
    {
        double x = pq.top();
        pq.pop();
        double y = pq.top();
        pq.pop();
        pq.push(sqrt(1.0 * x * y));
    }
    printf("%.6lf",pq.top());

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