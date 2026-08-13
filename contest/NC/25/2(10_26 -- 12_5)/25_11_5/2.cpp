#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    string s;
    cin >> s;
    stack<char> st;
    int n = s.size();
    for (int i = 0;i < n;i++)
    {
        if (!st.empty())
        {
            if (s[i] == ')' && st.top() == '(') st.pop();
            else if (s[i] == '}' && st.top() == '{') st.pop();
            else if (s[i] == ']' && st.top() == '[') st.pop();
            else st.push(s[i]);
        }
        else st.push(s[i]);
    }
    if (st.empty()) cout << "Yes" << endl;
    else cout << "No";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}