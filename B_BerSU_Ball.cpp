#include <bits/stdc++.h>
using namespace std;
int tut(vector<int> &boys, vector<int> &girls)
{
    int n = boys.size();
    int m = girls.size();
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (abs(boys[i] - girls[j]) <= 1)
            {
                girls[j] = 1000;
                ans++;
                break;
            }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> b;
    int x;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        b.push_back(x);
    }

    int m;
    vector<int> g;
    cin >> m;
    vector<int> girls(110, 0);
    for (int i = 0; i < m; ++i){
        cin >> x, girls[x] += 1;
        g.push_back(x);
        }
       cout << tut(b,g) << endl;
  
    int ans = 0;
    for (auto x : b)
    {
        if (girls[x] > 0)
            girls[x] -= 1, ans++;
        else if (girls[x - 1] > 0)
            girls[x - 1] -= 1, ans++;
        else if (girls[x + 1] > 0)
            girls[x + 1] -= 1, ans++;
    }
   return 0;
}