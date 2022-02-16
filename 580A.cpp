#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> v){
    int n = v.size();
    int ans = 1;
    int fix;
    for(int i = 0; i < n; ++i){
        int prev = v[i];
        int temp = 1;
        for(int j = i+1; j < n; ++j){
            if(v[j] >= prev){
                prev = v[j];
                temp = temp + 1;
            }
            else 
                break;
        }
        ans = max(temp,ans);
    }
    return ans;
}
int lis_dp(vector<int> v){
    int n = v.size();
    vector<int> dp(n,0);
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        if(v[i] >= v[i-1])
            dp[i] = dp[i-1] + 1;
        else
            dp[i] = 1;
    }
    return *max_element(dp.begin(),dp.end());
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    vector<int> dp(n+1,0);
    for(int i = 0;i < n; ++i)
        cin>>v[i];
    cout<<lis_dp(v)<<endl;
}