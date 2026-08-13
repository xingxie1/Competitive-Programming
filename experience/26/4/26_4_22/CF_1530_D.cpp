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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt b(n);
    vt vis(n + 1);
    int cnt = 0;
    set<int> st;
    for (int i = 1;i <= n;i++) st.insert(i);
    for (int i = 0;i < n;i++) 
    {
        if (vis[a[i]]) continue;
        vis[a[i]] = 1;
        st.erase(a[i]);
        b[i] = a[i];
        cnt++;
    }
    vt p(n + 1);
    for (int i = 0;i < n;i++)
    {
        int& x = b[i];
        if (x) 
        {
            p[x] = i;
            continue;
        }
        x = *st.begin();
        st.erase(st.begin());
        p[x] = i;
    }
    vt pp;
    for (int i = 0;i < n;i++)
    {
        if (b[i] == i + 1)
        {
            if (a[i] == b[i]) 
            {
                pp.push_back(i);
            }
            else 
            {
                int j = p[a[i]];
                swap(b[i],b[j]);
                p[b[i]] = i;
                p[b[j]] = j;
            }
        }
    }
    // for (int x : pp) cout << x << " ";
    // cout << endl;
    if (pp.size() % 2)  cnt--;
    for (int i = 0;i < pp.size() / 2;i+=2)
    {
        int j1 = pp[i],j2 = pp[i + 1];
        swap(b[j1],b[j2]);
    }
    if (pp.size() % 2)
    {
        int j = pp.back();
        for (int i = 0;i < n;i++)
        {
            if (a[i] == b[i] && i != j) 
            {
                swap(b[i],b[j]);
                break;
            }
        }
    }
    cout << cnt << endl;
    for (int x : b) cout << x << " " ;
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