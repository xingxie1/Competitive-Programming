#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int x,y;
    cin >> x >> y;
    stack<int> st1,st2;
    vt a,b;
    while (x)
    {
        st1.push(x % 2);
        x /= 2;
    }
    while (y)
    {
        st2.push(y % 2);
        y /= 2;
    }
    while (st1.size() < st2.size()) st1.push(0);
    while (st2.size() < st1.size()) st2.push(0);
    int ans = 0;
    while (!st1.empty()) a.push_back(st1.top()),st1.pop();
    while (!st2.empty()) b.push_back(st2.top()),st2.pop();
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while (!st1.empty() && !st2.empty())
    {
        if (st1.top() == st2.top())
        {
            ans *= 2;
            st1.pop();
            st2.pop();
        }
        else 
        {
            ans = ans * 2 + 1;
            st1.pop();
            st2.pop();
        }
    }
    while (!st1.empty())
    {
        if (st1.top())
        {
            ans = ans * 2 + 1;
        }
        else ans *= 2;
        st1.pop();
    }
    if (ans == 0) cout << 0 << endl;
    else 
        cout << 1 << endl << ans << endl;
    
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