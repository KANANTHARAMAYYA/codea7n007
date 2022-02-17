#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        bool flag = false;
        for (int i = 0; i < n; ++i)
        {
            if (s1[i] == '1' and s2[i] == '1')
                flag = true;
        }
        if (flag)
            cout << "NO" << endl;
        else
        cout<<"YES"<<endl;
    }

    return 0;
}