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
    vt a(n),ans;
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = n - 1;i >= 0;i--)
    {
        if (a[i] == 0) ans.push_back(0);
        else 
        {
            if (ans.empty()) 
            {
                cout << "NO" << endl;
                return;
            }
            int j = i;
            while (j >= 0 && a[j] == 1) j--;
            int cnt = i - j;
            for (int i = 1;i < cnt;i++) ans.push_back(0);
            ans.push_back(cnt);
            i = j + 1;
        }
    }
    cout << "YES" << endl;
    for (int x : ans) cout << x << " ";
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