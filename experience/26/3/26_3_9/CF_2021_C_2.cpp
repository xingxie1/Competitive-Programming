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
    int n,m,q;
    cin >> n >> m >> q;
    vt a(n),b(m),pos(n + 1);
    set<int> st;
    vector<set<int>> s(n + 1);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 0;i < m;i++) 
    {
        cin >> b[i];
        s[b[i]].insert(i);
    }
    auto get_fi = [&](int x)
    {
        if (s[x].empty()) return INT_MAX;
        else return *s[x].begin();
    };
    vt fi(n + 1,INT_MAX);
    for (int i = 1;i <= n;i++)
    {
        fi[i] = get_fi(i);
    }
    auto calc = [&](int i)
    {
        if (i <= 0 || i >= n) return 0;
        return fi[a[i - 1]] > fi[a[i]] ? 1 : 0;
    };
    int sum = 0;
    for (int i = 1;i < n;i++)
    {
        sum += calc(i);
    }
    auto print = [&]()
    {
        if (sum == 0) cout << "YA" << endl;
        else cout << "TIDAK" << endl;
    };
    print();
    while (q--)
    {
        int i,t;
        cin >> i >> t;
        i--;
        int u = b[i];
        if (u == t)
        {
            print();
            continue;
        }
        vt tmp = {pos[u],pos[u] + 1,pos[t],pos[t] + 1};
        ranges::sort(tmp);
        tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
        for (int j : tmp) sum -= calc(j);

        s[u].erase(i);
        s[t].insert(i);
        b[i] = t;
        fi[u] = get_fi(u);
        fi[t] = get_fi(t);
        for (int j : tmp) sum += calc(j);
        print();
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