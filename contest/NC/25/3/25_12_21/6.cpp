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
    for (int i = 0;i < n;i++) cin >> a[i];
    vector<pair<int,int>> b;
    for (int i = 0;i < n;i++)
    {
        b[i] = {a[i], i};
    }
    sort(b.begin(),b.end());
    int l = 0,r = 0,len = 0,bestl = 0,bestr = 0;
    while (r < n)
    {
        while (b[r].fi - b[l].fi > n - 1)
        {
            l++;
        }
        if (r - l + 1 > len)
        {
            len = r - l + 1;
            bestl = l;
            bestr = r;
        }
        r++;
    }
    int k = n - len;
    cout << k << endl;
    if (!k) return ;

    int L = b[bestr].fi - (len - 1);

    vector<int> used(n, 0);
    multiset<int> have;
    for (int i = bestl; i <= bestr; i++) {
        used[b[i].second] = 1;
        have.insert(b[i].first);
    }

    vector<int> need;
    for (int x = L; x <= L + n - 1; x++)
     {
        auto it = have.find(x);
        if (it != have.end()) 
        {
            have.erase(it);
        } 
        else 
        {
            need.push_back(x);
        }
    }

    int j = 0;
    for (int i = 0; i < n; i++)
     {
        if (!used[i])
        {
            cout << i + 1 << " " << need[j++] << endl;
        }
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