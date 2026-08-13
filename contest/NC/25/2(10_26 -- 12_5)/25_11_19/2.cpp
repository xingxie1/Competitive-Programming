#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    stack<char> st;
    for (char c : s)
    {
        if (!st.empty() && c == ')' && st.top() == '(')
        {
            st.pop();
        }
        else st.push(c);
    }
    if (st.empty()) cout << 0 << endl;
    else 
    {
        string tmp;
        while (!st.empty())
        {
            tmp += st.top();
            st.pop();
        }
        reverse(tmp.begin(),tmp.end());
        int cnt = 0;
        for (char c : tmp)
        {
            if (st.empty())
            {
                if (c == ')') cnt++;
                else st.push(c);
            }
            else 
            {
                if (c == '(') st.push(c);
            }
        }
        cout << cnt + st.size() << endl;
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