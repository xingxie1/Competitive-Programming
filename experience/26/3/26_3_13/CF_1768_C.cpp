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
    vt a(n);
    set<int> st1,st2;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        st1.insert(i + 1);
        st2.insert(i + 1);
    }
    map<int,int> cnt;
    for (int x : a)
    {
        cnt[x]++;
        if (cnt[x] > 2) 
        {
            cout << "NO" << endl;
            return ;
        }
    }
    vt p(n),q(n);
    for (int i = 0;i < n;i++)
    {
        if (st1.contains(a[i])) 
        {
            p[i] = a[i];
            st1.erase(a[i]);
        }
        else 
        {
            q[i] = a[i];
            st2.erase(a[i]);
        }
    }
    for (int i = 0;i < n;i++)
    {
        if (p[i] == 0)
        {
            int x = q[i];
            auto it = st1.upper_bound(x);
            if (it == st1.begin()) 
            {
                cout << "NO" << endl;
                return ;
            }
            it--;
            p[i] = *it;
            st1.erase(it);
        }
        if (q[i] == 0)
        {
            int x = p[i];
            auto it = st2.upper_bound(x);
            if (it == st2.begin()) 
            {
                cout << "NO" << endl;
                return ;
            }
            it--;
            q[i] = *it;
            st2.erase(it);
        }
    }
    cout << "YES" << endl;
    for (int x : p) cout << x << " ";
    cout << endl;
    for (int x : q) cout << x << " ";
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