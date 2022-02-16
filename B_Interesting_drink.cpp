#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    int d_size = *max_element(x.begin(), x.end());
    vector<int> dp(d_size + 1, 0);
    for (auto c : x)
        dp[c] += 1;
    dp[0] = 0;
    for (int i = 0; i < d_size; ++i)
        dp[i + 1] += dp[i];
    int q;
    cin >> q;
    int c;
    vector<int> qs;
    while (q--)
    {
        cin >> c;
        if (c > d_size)
            cout << x.size() << endl;
        else
            cout << dp[c] << endl;
    }

    return 0;
}