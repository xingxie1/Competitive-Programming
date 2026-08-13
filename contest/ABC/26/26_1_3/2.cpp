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

int check(int a)
{
    int cnt = 0;
    while (1)
    {
        int sum = 0;
        while (a)
        {
            int x = a % 10;
            sum += x * x;
            a /= 10;
        }
        if (sum == 1) return 1;
        a = sum;
        cnt++;
        if (cnt > 10000) break;
    }
    return 0;
}
void solve()
{
    int n;
    cin >> n;
    if (check(n)) cout << "Yes" ;
    else cout << "No";
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