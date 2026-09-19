#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define fi first
#define se second
using vt = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using vpii = vector<pii>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n;
    cin >> n;
    vt a(n),b(n),c(n);
    vll ha(n),hb(n),hc(n);
    map<int,ll> p;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        ha[i] = rng();
        p[a[i]] = ha[i];
    }
    for (int i = 0;i < n;i++) 
    {
        cin >> b[i];
        hb[i] = p[b[i]]; 
    }
    for (int i = 0;i < n;i++) 
    {
        cin >> c[i];
        hc[i] = p[c[i]];
    }
    vll prea(n + 1),preb(n + 1),prec(n + 1);
    for (int i = 0;i < n;i++) prea[i + 1] = prea[i] ^ ha[i];
    for (int i = 0;i < n;i++) preb[i + 1] = preb[i] ^ hb[i];
    for (int i = 0;i < n;i++) prec[i + 1] = prec[i] ^ hc[i];
    int ans = 0;
    for (int i = 0;i < n;i++)
    {
        if (prea[i + 1] == preb[i + 1] || prea[i + 1] == prec[i + 1] || preb[i + 1] == prec[i + 1]) ans++;
    }
    cout << ans << endl;    
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();

    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long
// #define fi first
// #define se second
// using vt = vector<int>;
// using vll = vector<ll>;
// using pii = pair<int,int>;
// using vpii = vector<pii>;

// class FenwickTree
// {
//     vll tr;
// public:
//     FenwickTree(int n) : tr(n + 1){}
//     void update(int i,int v) 
//     {
//         for (;i < tr.size();i += i & -i) tr[i] += v;
//     }
//     int pre(int i) 
//     {
//         int res = 0;
//         for (;i > 0;i &= i - 1) res += tr[i];
//         return res;
//     }
// };
// void solve()
// {
//     int n;
//     cin >> n;
//     vpii a(n),b(n),c(n);
//     for (int i = 0;i < n;i++) cin >> a[i].fi,a[i].se = i + 1;
//     for (int i = 0;i < n;i++) cin >> b[i].fi,b[i].se = i + 1;
//     for (int i = 0;i < n;i++) cin >> c[i].fi,c[i].se = i + 1;
//     FenwickTree tr1(n),tr2(n),tr3(n);
//     sort(a.begin(),a.end(),[&](auto& x,auto&y){
//         return x.fi < y.fi;
//     });
//     sort(b.begin(),b.end(),[&](auto& x,auto&y){
//         return x.fi < y.fi;
//     });
//     sort(c.begin(),c.end(),[&](auto& x,auto&y){
//         return x.fi < y.fi;
//     });
//     int ans = 0;
//     for (int i = 0;i < n;i++)
//     {
//         tr1.update(a[i].se,1);
//         tr2.update(b[i].se,1);
//         tr3.update(c[i].se,1);
//         int f1 = tr1.pre(n) == i + 1;
//         int f2 = tr2.pre(n) == i + 1;
//         int f3 = tr3.pre(n) == i + 1;
//         int cnt = f1 + f2 + f3;
//         if (cnt >= 2) ans++;
//     }
//     cout << ans << endl;
// }

// int main()
// {
//     cin.tie(0);
//     ios::sync_with_stdio(0);

//     int _ = 1;
//     cin >> _;
//     while (_--) solve();

//     return 0;
// }
