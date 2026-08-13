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
    int n,k;
    cin >> n >> k;
    set<int> a;
    vt b;
    for (int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        if (!a.contains(x))
        {
            a.insert(x);
            b.push_back(i + 1);
        }
    }
    if (a.size() >= k) 
    {
        cout << "YES" << endl;
        int cnt = 0;
        for (int x : b) 
        {
            cout << x << " ";
            cnt++;
            if (cnt == k) break;
        }
    }
    else cout << "NO" << endl;

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