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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,k;
    cin >> n >> k;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    set<int> st1,st2; 
    int l = 0,r = 0;
    vt p;
    while (r < k)
    {
        st1.insert(a[r]);
        if (b[r] != -1) st2.insert(b[r]);
        else p.push_back(r);
        r++;   
    }
    ranges::reverse(p);
    for (int i = 0;i < r;i++)
    {
        if (!st2.contains(a[i]))
        {
            if (!p.empty())
            {
                int j = p.back();
                p.pop_back();
                b[j] = a[i];
                st2.insert(b[j]);
            }
            else 
            {
                cout << "NO" << endl;
                return ;
            }
        }
    }
    if (st1 != st2)
    {
        cout << "NO" << endl;
        return ;
    }
    queue<int> q;
    st1.erase(a[l]);
    if (st1.contains(b[l])) q.push(b[l]);
    st2.erase(b[l]);
    l++;
    int last = k;
    // for (int x : b) cout << x << " ";
    // cout << endl;
    while (r < n)
    {
        st1.insert(a[r]);
        if (!st2.contains(a[r])) q.push(a[r]);
        if (b[r] == -1) 
        {
            while (!q.empty() && !st1.contains(q.front())) q.pop();
            if (!q.empty())
            {
                int x = q.front();
                // cout << x << endl;
                q.pop();
                b[r] = x;
                st2.insert(x);
            }
        }
        else 
        {
            if (!st1.contains(a[r])) 
            {
                cout << "NO" << endl;
                return ;
            }
            st2.insert(b[r]);
        }
        if (st1 != st2) 
        {
            cout << "NO" << endl;
            return ;
        }
        st1.erase(a[l]);
        if (st1.contains(b[l])) q.push(b[l]);
        st2.erase(b[l]);
        l++;
        r++;
    }
    // for (int x : st1) cout << x << " ";
    // cout << endl;
    // for (int x : st2) cout << x << " ";
    // cout << endl;
    cout << "YES" << endl;
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