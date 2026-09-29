#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,q;
    cin >> n >> q;
    vt a(n + 1);
    vt tmp;
    for (int i = 1;i <= n;i++) 
    {
        cin >> a[i];
        tmp.push_back(a[i]);
    }

    ranges::sort(tmp);
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    for (int i = 1;i <= n;i++) a[i] = ranges::lower_bound(tmp,a[i]) - tmp.begin();

    int m = tmp.size();
    int B = sqrt(n / 5);
    int cc = (n + B - 1) / B;
    vvt cnt(cc + 1,vt(m));
    vvt mxcnt(cc + 1,vt(cc + 1));
    auto bel = [&](int x) 
    {
        return (x - 1) / B;
    };
    for (int b = 0;b < cc;b++)
    {
        cnt[b + 1] = cnt[b];
        int L = b * B + 1;
        int R = min(n,(b + 1) * B);
        for (int i = L;i <= R;i++) cnt[b + 1][a[i]]++;
    }

    for (int i = 0;i < cc;i++)
    {
        vt f(m);
        int ans = -1,ansc = 0;
        for (int j = i;j < cc;j++)
        {
            int L = j * B + 1;
            int R = min(n,(j + 1) * B);
            for (int k = L;k <= R;k++) 
            {
                f[a[k]]++;
                if (f[a[k]] > ansc)
                {
                    ans = a[k];
                    ansc = f[a[k]];
                }
                else if (f[a[k]] == ansc)
                {
                    ans = min(ans,a[k]);
                }
            }
            mxcnt[i][j] = ans;
        }
    }

    int lastans = 0;
    while (q--)
    {
        int l,r;
        cin >> l >> r;
        l = (l + lastans - 1) % n + 1;
        r = (r + lastans - 1) % n + 1;
        if (l > r) swap(l,r);
        int ans = -1,ansc = 0;
        int bl = bel(l);
        int br = bel(r);
        umap<int,int> ccnt;
        if (bl + 1 > br - 1)
        {
            for (int i = l;i <= r;i++) 
            {
                auto id = a[i];
                ccnt[id]++;
                if (ccnt[id] > ansc) 
                {
                    ansc = ccnt[id];
                    ans = id;
                }
                else if (ccnt[id] == ansc)
                {
                    ans = min(ans,id);
                }
            }
        }
        else 
        {
            ans = mxcnt[bl + 1][br - 1];
            ansc = cnt[br][ans] - cnt[bl + 1][ans];
            for (int i = l;i <= (bl + 1) * B;i++)
            {
                ccnt[a[i]]++;
                int ccc = cnt[br][a[i]] - cnt[bl + 1][a[i]];
                if (ccc + ccnt[a[i]] > ansc) 
                {
                    ans = a[i];
                    ansc = ccc + ccnt[a[i]];
                }
                else if (ccc + ccnt[a[i]] == ansc)
                {
                    ans = min(ans,a[i]);
                }
            }
            for (int i = br * B + 1;i <= r;i++)
            {
                ccnt[a[i]]++;
                int ccc = cnt[br][a[i]] - cnt[bl + 1][a[i]];
                if (ccc + ccnt[a[i]] > ansc) 
                {
                    ans = a[i];
                    ansc = ccc + ccnt[a[i]];
                }
                else if (ccc + ccnt[a[i]] == ansc)
                {
                    ans = min(ans,a[i]);
                }
            }
        }
        cout << tmp[ans] << endl;
        lastans = tmp[ans];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}