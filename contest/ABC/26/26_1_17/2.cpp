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
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    int q;
    cin >> q;
    vector<string> a(q);
    for (int i = 0;i < q;i++) cin >> a[i];
    map<char,int> cnt1,cnt2;
    for (char c : s) cnt1[c]++;
    for (char c : t) cnt2[c]++;
    for (string ss : a)
    {
        int flag1 = 1,flag2 = 1;
        for (char c : ss)
        {
            if (!cnt1.count(c)) flag1 = 0;
            if (!cnt2.count(c)) flag2 = 0;
        }
        if (flag1 && flag2) cout << "Unknown" << endl;
        else if (flag1) cout << "Takahashi" << endl;
        else cout << "Aoki" << endl;
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