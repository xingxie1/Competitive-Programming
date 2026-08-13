#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

const int N = 1e5 + 5;
int pow2[N];
void solve()
{
    int n;
    cin >> n;
    vt p(n),q(n);
    for (int i = 0;i < n;i++) cin >> p[i];
    int j = 0,k = 0;
    for (int i = 0;i < n;i++) 
    {
        cin >> q[i];
        if (p[i] > p[j])
        {
            j = i;
        }
        if (q[i] > q[k])
        {
            k = i;
        }
        pii op1 = {max(p[j],q[i - j]),min(p[j],q[i - j])};
        pii op2 = {max(q[k],p[i - k]),min(q[k],p[i - k])};
        if (op1 > op2) cout << (pow2[op1.fi] + pow2[op1.se]) % MOD << " ";
        else cout << (pow2[op2.fi] + pow2[op2.se]) % MOD << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    pow2[0] = 1;
    for (int i = 1;i < N;i++) pow2[i] = pow2[i - 1] * 2 % MOD;
    while (_ --) solve();

    return 0;
}