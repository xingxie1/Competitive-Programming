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
    ll n,ed1,ed2,ed3;
    cin >> n >> ed1 >> ed2 >> ed3;
    mset<ll> st1,st2,st3;
    ll need1 = 0,need2 = 0,need3 = 0;
    for (int i = 0;i < n;i++)
    {
        int op,t;
        cin >> op >> t;
        if (op == 1)
        {
            st1.insert(t);
            need1 += t;
        }
        else if (op == 2) 
        {
            st2.insert(t);
            need2 += t;
        }
        else
        {
            st3.insert(t);
            need3 += t;
        }
    }
    ll mxtime = 0;
    cin >> mxtime;
    if(ed1 < need1 || ed2 < need2 ||ed3 < need3){
        NO;
        return ;
    }
    ll time = 0,ans = 0;
    while (!st1.empty() || !st2.empty() || !st3.empty())
    {
        // cout << ans << endl;
        ll mn1 = LLONG_MAX / 2,mn2 = LLONG_MAX / 2,mn3 = LLONG_MAX / 2;
        
        if (!st1.empty()) mn1 = *st1.begin();
        else 
        {
            // need1 = INT_MIN / 2;
            ed1 = LLONG_MAX;
        }
        if (!st2.empty()) mn2 = *st2.begin();
        else 
        {
            // need2 = INT_MIN / 2;
            ed2 = LLONG_MAX;
        }
        if (!st3.empty()) mn3 = *st3.begin();
        else 
        {
            // need3 = INT_MIN / 2;
            ed3 = LLONG_MAX;
        }
        auto f = [&](ll cur,ll n1,ll n2,ll ed1,ll ed2) 
        {
            if (cur + n1 <= ed1 && cur + n1 + n2 <= ed2) return true;
            return false;
        };
        if (mn1 <= mn2 && mn1 <= mn3) 
        {
            if (ed2 <= ed3 && f(time + mn1,need2,need3,ed2,ed3)) 
            {
                time += mn1;
                ans += time;
                need1 -= mn1;
                if (st1.empty()) 
                {
                    NO;
                    return ;
                }
                st1.erase(st1.begin());
                continue;
            }
            if (ed3 <= ed2 && f(time + mn1,need3,need2,ed3,ed2)) 
            {
                time += mn1;
                ans += time;
                need1 -= mn1;
                if (st1.empty()) 
                {
                    NO;
                    return ;
                }
                st1.erase(st1.begin());
                continue;
            }
            if (mn2 <= mn3)
            {
                if (ed1 <= ed3 && f(time + mn2,need1,need3,ed1,ed3)) 
                {
                    time += mn2;
                    ans += time;
                    need2 -= mn2;
                    if (st2.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st2.erase(st2.begin());
                    continue;
                }
                if (ed3 <= ed1 && f(time + mn2,need3,need1,ed3,ed1)) 
                {
                    time += mn2;
                    ans += time;
                    need2 -= mn2;
                    if (st2.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st2.erase(st2.begin());
                    continue;
                }
                if (ed1 <= ed2 && f(time + mn3,need1,need2,ed1,ed2)) 
                {
                    time += mn3;
                    ans += time;
                    need3 -= mn3;
                    if (st3.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st3.erase(st3.begin());
                    continue;
                }
                if (ed2 <= ed1 && f(time + mn3,need2,need1,ed2,ed1)) 
                {
                    time += mn3;
                    ans += time;
                    need3 -= mn3;
                    if (st3.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st3.erase(st3.begin());
                    continue;
                }
            }
            if (mn3 <= mn2) 
            {
                if (ed1 <= ed2 && f(time + mn3,need1,need2,ed1,ed2)) 
                {
                    time += mn3;
                    ans += time;
                    need3 -= mn3;
                    if (st3.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st3.erase(st3.begin());
                    continue;
                }
                if (ed2 <= ed1 && f(time + mn3,need2,need1,ed2,ed1)) 
                {
                    time += mn3;
                    ans += time;
                    need3 -= mn3;
                    if (st3.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st3.erase(st3.begin());
                    continue;
                }
                if (ed1 <= ed3 && f(time + mn2,need1,need3,ed1,ed3)) 
                {
                    time += mn2;
                    ans += time;
                    need2 -= mn2;
                    if (st2.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st2.erase(st2.begin());
                    continue;
                }
                if (ed3 <= ed1 && f(time + mn2,need3,need1,ed3,ed1)) 
                {
                    time += mn2;
                    ans += time;
                    need2 -= mn2;
                    if (st2.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st2.erase(st2.begin());
                    continue;
                }
            }
        }
        if (mn2 <= mn1 && mn2 <= mn3) 
        {
            if (ed1 <= ed3 && f(time + mn2,need1,need3,ed1,ed3)) 
            {
                time += mn2;
                ans += time;
                need2 -= mn2;
                if (st2.empty()) 
                {
                    NO;
                    return ;
                }
                st2.erase(st2.begin());
                continue;
            }
            if (ed3 <= ed1 && f(time + mn2,need3,need1,ed3,ed1)) 
            {
                time += mn2;
                ans += time;
                need2 -= mn2;
                if (st2.empty()) 
                {
                    NO;
                    return ;
                }
                st2.erase(st2.begin());
                continue;
            }
            if (mn1 <= mn3)
            {
                if (ed2 <= ed3 && f(time + mn1,need2,need3,ed2,ed3)) 
                {
                    time += mn1;
                    ans += time;
                    need1 -= mn1;
                    if (st1.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st1.erase(st1.begin());
                    continue;
                }
                if (ed3 <= ed2 && f(time + mn1,need3,need2,ed3,ed2)) 
                {
                    time += mn1;
                    ans += time;
                    need1 -= mn1;
                    if (st1.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st1.erase(st1.begin());
                    continue;
                }
                if (ed1 <= ed2 && f(time + mn3,need1,need2,ed1,ed2)) 
                {
                    time += mn3;
                    ans += time;
                    need3 -= mn3;
                    if (st3.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st3.erase(st3.begin());
                    continue;
                }
                if (ed2 <= ed1 && f(time + mn3,need2,need1,ed2,ed1)) 
                {
                    time += mn3;
                    ans += time;
                    need3 -= mn3;
                    if (st3.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st3.erase(st3.begin());
                    continue;
                }
            }
            if (mn3 <= mn1) 
            {
                if (ed1 <= ed2 && f(time + mn3,need1,need2,ed1,ed2)) 
                {
                    time += mn3;
                    ans += time;
                    need3 -= mn3;
                    if (st3.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st3.erase(st3.begin());
                    continue;
                }
                if (ed2 <= ed1 && f(time + mn3,need2,need1,ed2,ed1)) 
                {
                    time += mn3;
                    ans += time;
                    need3 -= mn3;
                    if (st3.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st3.erase(st3.begin());
                    continue;
                }
                if (ed2 <= ed3 && f(time + mn1,need2,need3,ed2,ed3)) 
                {
                    time += mn1;
                    ans += time;
                    need1 -= mn1;
                    if (st1.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st1.erase(st1.begin());
                    continue;
                }
                if (ed3 <= ed2 && f(time + mn1,need3,need2,ed3,ed2)) 
                {
                    time += mn1;
                    ans += time;
                    need1 -= mn1;
                    if (st1.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st1.erase(st1.begin());
                    continue;
                }
            }
        }
        if (mn3 <= mn1 && mn3 <= mn2) 
        {
            if (ed1 <= ed2 && f(time + mn3,need1,need2,ed1,ed2)) 
            {
                time += mn3;
                ans += time;
                need3 -= mn3;
                if (st3.empty())
                {
                    NO;
                    return ;
                }
                st3.erase(st3.begin());
                continue;
            }
            if (ed2 <= ed1 && f(time + mn3,need2,need1,ed2,ed1)) 
            {
                time += mn3;
                ans += time;
                need3 -= mn3;
                if (st3.empty()) 
                {
                    NO;
                    return ;
                }
                st3.erase(st3.begin());
                continue;
            }
            if (mn1 <= mn2)
            {
                if (ed2 <= ed3 && f(time + mn1,need2,need3,ed2,ed3)) 
                {
                    time += mn1;
                    ans += time;
                    need1 -= mn1;
                    if (st1.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st1.erase(st1.begin());
                    continue;
                }
                if (ed3 <= ed2 && f(time + mn1,need3,need2,ed3,ed2)) 
                {
                    time += mn1;
                    ans += time;
                    need1 -= mn1;
                    if (st1.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st1.erase(st1.begin());
                    continue;
                }
                if (ed1 <= ed3 && f(time + mn2,need1,need3,ed1,ed3)) 
                {
                    time += mn2;
                    ans += time;
                    need2 -= mn2;
                    if (st2.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st2.erase(st2.begin());
                    continue;
                }
                if (ed3 <= ed1 && f(time + mn2,need3,need1,ed3,ed1)) 
                {
                    time += mn2;
                    ans += time;
                    need2 -= mn2;
                    if (st2.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st2.erase(st2.begin());
                    continue;
                }
            }
            if (mn2 <= mn1) 
            {
                if (ed1 <= ed3 && f(time + mn2,need1,need3,ed1,ed3)) 
                {
                    time += mn2;
                    ans += time;
                    need2 -= mn2;
                    if (st2.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st2.erase(st2.begin());
                    continue;
                }
                if (ed3 <= ed1 && f(time + mn2,need3,need1,ed3,ed1)) 
                {
                    time += mn2;
                    ans += time;
                    need2 -= mn2;
                    if (st2.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st2.erase(st2.begin());
                    continue;
                }
                if (ed2 <= ed3 && f(time + mn1,need2,need3,ed2,ed3)) 
                {
                    time += mn1;
                    ans += time;
                    need1 -= mn1;
                    if (st1.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st1.erase(st1.begin());
                    continue;
                }
                if (ed3 <= ed2 && f(time + mn1,need3,need2,ed3,ed2)) 
                {
                    time += mn1;
                    ans += time;
                    need1 -= mn1;
                    if (st1.empty()) 
                    {
                        NO;
                        return ;
                    }
                    st1.erase(st1.begin());
                    continue;
                }
            }
        }
        NO;
        return ;
    }
    // cout << ans << endl;
    if (ans < mxtime) YES;
    else NO;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}