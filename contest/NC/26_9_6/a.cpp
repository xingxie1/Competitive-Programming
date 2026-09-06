#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vvt = vector<vt>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve()
{
    int n;
    cin >> n;
    vector<pair<char,int>> a(n);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    map<int,int> lastx,lastt;
    stack<pii> st;
    string ans;
    vt p(n);
    set<int> er;
    for (int i = 0;i < n;i++)
    {
        if (a[i].fi == '+') 
        {
            if (lastt.count(a[i].se))
            {
                while (1) 
                {
                    if (er.count(st.top().se))
                    {
                        st.pop();
                        continue;
                    }
                    if (st.top().fi == a[i].se) 
                    {
                        st.pop();
                        p[lastt[a[i].se]]++;
                        break;
                    }
                    st.pop();
                    p[lastt[a[i].se]]++;
                    // ans += '-';
                }
                lastt.erase(a[i].se);
                lastx[a[i].se] = i;
            }
            else
            {
                if (lastx.count(a[i].se)) 
                {
                    er.insert(lastx[a[i].se]);
                    p[lastx[a[i].se]]++;
                }
                lastx[a[i].se] = i;
            }
            st.push({a[i].se,i});
        }
        else if (a[i].fi == 'T')
        {
            lastt[a[i].se] = i;
            // lastx.erase(a[i].se);
        }
        else 
        {
            if (lastt.count(a[i].se)) 
            {
                while (1) 
                {
                    if (er.count(st.top().se))
                    {
                        st.pop();
                        continue;
                    }
                    if (st.top().fi == a[i].se) 
                    {
                        st.pop();
                        p[lastt[a[i].se]]++;
                        break;
                    }
                    st.pop();
                    p[lastt[a[i].se]]++;
                }
                lastt.erase(a[i].se);
                lastx.erase(a[i].se);
            }
            else 
            {
                if (lastx.count(a[i].se)) 
                {
                    er.insert(lastx[a[i].se]);
                    p[lastx[a[i].se]]++;
                    lastx.erase(a[i].se);
                }
            }
        }
    }
    for (int i = 0;i < n;i++) 
    {
        if (a[i].fi == '+') ans += '+';
        else if (a[i].fi == 'T' || a[i].fi == 'F') ans += '?';
        while (p[i]--) ans += '-';
    }
    // while (!st.empty()) 
    // {
    //     if (er.count(st.top().se))
    //     {
    //         st.pop();
    //         continue;
    //     }
    //     st.pop();
    //     ans += '-';
    // }
    cout << ans << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();
}