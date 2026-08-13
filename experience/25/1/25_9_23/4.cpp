// #include<bits/stdc++.h>
// using namespace std;

// int N = 5000;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);


//     int n;
//     cin >> n;
//     vector<string> a(4);
//     for (int i = 0;i < 4;i++)
//     {
//         a[i].resize(n);
//     }
//     char c = 'a';
//     if (n == 1)
//     {
//         cout << -1 << endl;
//         return 0;
//     }
//     if (n % 2 == 0)
//     {
//         for (int j = 0;j < n;j+=2)
//         {   
//             a[0][j] = a[0][j+1] = c;
//             a[3][j] = a[3][j+1] = c;
//             c++;
//             if (c == 'z' + 1) c -= 26;
//         }
//         c = 'b';
//         a[1][0] = a[2][0] = c++;
//         for (int j = 1;j < n - 1;j+=2)
//         {
//             a[1][j] = a[1][j+1] = c;
//             a[2][j] = a[2][j+1] = c;
//             c++;
//             if (c == 'z' + 1) c -= 26;
//         }
//         a[1][n-1] = a[2][n-1] = c;
//     }
//     else 
//     {
//         char c = 'a';
//         for (int j = 0;j < n-1;j+=2)
//         {
//             a[0][j] = a[0][j+1] = c++;
//             if (c == 'z' + 1) c -= 26;
//             a[1][j] = a[1][j+1] = c++;
//             if (c == 'z' + 1) c -= 26;
//         }
//         a[0][n-1]  = a[1][n-1] = c++;
//         if (c == 'z' + 1) c -= 26;
//         a[2][0] = a[3][0] = 'z';
//         c = 'a';
//         for (int j = 1;j < n;j+=2)
//         {
//             a[2][j] = a[2][j+1] = c++;
//             if (c == 'z' + 1) c -= 26;
//             a[3][j] = a[3][j+1] = c++;
//             if (c == 'z' + 1) c -= 26;
//         }
//     }
//     for (int i = 0;i < 4;i++)
//     {
//         for (int j = 0;j < n;j++)
//         {
//             cout << a[i][j];
//         }
//         cout << endl;
//     }


//     return 0;
// }

