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
    int n, q;
    cin >> n >> q;
    int N = 1 << n;
    vt a(N),s(N + 1);
    for (int i = 0;i < N;i++) 
    {
        cin >> a[i];
        s[i + 1] = s[i] ^ a[i];
    }

    while (q--)
    {
        int b, c;
        cin >> b >> c;
        b--;
        int ans = 0;
        for (int i = 0;i < n;i++)
        {
            int ops = b ^ 1 << i;
            int skill = s[ops] ^ s[ops + (1 << i)];
            if (c > skill || (c == skill && b < ops)) {}
            else ans += (1 << i);
            b = min(b,ops);
            c ^= skill;
        }
        cout << ans << endl;
    }
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