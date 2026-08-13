#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n,k;
    cin >> n>> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ll sum = 0,cnt = 0;
    priority_queue<int,vector<int>,greater<>> q(a.begin(),a.end());
    while (cnt < k)
    {
        while (!q.empty())
        {
            int x = q.top();
            if (x - sum <= 0) q.pop();
            else break;
        }
        if (q.empty()) cout << 0 << endl;
        else 
        {
            int x = q.top();
            x -= sum;
            cout << x << endl;
            sum += x;
            q.pop();
        }
        cnt++;
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