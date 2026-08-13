#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

string bit(int a)
{
    stack<int> st;
    while (a)
    {
        int x = a % 2;
        st.push(x);
        a /= 2;
    }
    string s;
    while (!st.empty())
    {
        s += st.top();
        st.pop();
    }
    return s;
}
void solve()
{
    int n;
    cin >> n;
    n*=2;
    vll a(n);
    vector<string> b(n);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    for (int i = 0;i < n;i++)
    {
        b[i] = bit(a[i]);
    }
    long long ans = 17179869183;
    int cnt = 0;
    for (int i = 0;i < n && cnt < n/2;i++)
    {
        if (b[i] >= b[i+1]) ans &= a[i];
    }
    cout << ans << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t --) solve();
    return 0;
}