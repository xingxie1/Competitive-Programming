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
    int n,m,L;
    cin >> n >> m >> L;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int last = 0;
    vt b(m);
    for (int i = 0;i < n;i++)
    {
        int d = a[i] - last;
        int M = min(m,n - i + 1);
        ranges::sort(b,{},[](auto& c) {return -c; });
        b[0] = 0;
        ranges::sort(b,{},[](auto& c) {return -c; });
        b.resize(M);
        ll sum = accumulate(b.begin(),b.end(),0LL);
        sum += d;
        for (int j = 0;j < b.size();j++)
        {
            if (sum >= 1LL * (M - j) * b[j])
            {
                ll ave = sum / (M - j);
                ll res = sum % (M - j);
                for (int k = j;k < b.size();k++)
                {
                    b[k] = ave;
                    if (res > 0) 
                    {
                        b[k]++;
                        res--;
                    }
                }
                break;
            }
            sum -= b[j];
        }
        last = a[i];
        // for (int x : b) cout << x << " ";
        // cout << endl;
    }
    ranges::sort(b,{},[](auto& c) {return -c; });
    b[0] = 0;
    ranges::sort(b,{},[](auto& c) {return -c; });
    ll ans = b[0] + L - a[n - 1];
    cout << ans << endl;
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