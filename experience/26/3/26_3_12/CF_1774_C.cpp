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
    string s;
    cin >> s;
    vt p0(n,-1),p1(n,-1);
    for (int i = 0;i < n - 1;i++)
    {
        p0[i + 1] = p0[i];
        p1[i + 1] = p1[i];
        if (s[i] == '0') p0[i + 1] = i;
        else p1[i + 1] = i;
    }
    for (int i = 2;i <= n;i++)
    {
        int j = i - 2;
        if (s[j] == '1') cout << p0[j + 1] + 2 << " ";
        else cout << p1[j + 1] + 2 << " ";
    }
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