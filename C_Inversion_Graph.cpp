#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &vis, vector<vector<int>> &adj, int root)
{
    vis[root] = 1;
    for (auto x : adj[root])
        if (!vis[x])
            dfs(vis, adj, x);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (v[i] > v[j])
                {
                    adj[v[j]].push_back(v[i]);
                    adj[v[i]].push_back(v[j]);
                }
            }
        }
        vector<int> vis(n + 1, 0);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (auto x : adj[i])
            {
                if (!vis[x])
                {
                    ans += 1;
                    dfs(vis, adj, x);
                }
            }
        }
        cout<<ans<<endl;
        
    }
    /* code */

    return 0;
}