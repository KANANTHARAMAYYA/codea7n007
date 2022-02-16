#include<bits/stdc++.h>
using namespace std;

int max_pieces(int a,int b,int c,int n){
    if(n < 0)
        return INT_MIN;
    if(n == 0)
        return 0;
    return 1 + max(max(max_pieces(a,b,c,n-a),max_pieces(a,b,c,n-b)),max_pieces(a,b,c,n-c));
}
int dp_max_pieces(int a,int b,int c,int n){
    vector<int> dp(n+1,INT_MIN);
    dp[0] = 0;
    for(int i = 0; i <= n; ++i){
        if(i - a >= 0)
            dp[i] = max(dp[i],dp[i-a]+1);
        if(i - b >= 0)
            dp[i] = max(dp[i],dp[i-b]+1);
        if(i - c >= 0)
            dp[i] = max(dp[i],dp[i-c]+1);
    }
    return dp[n];
}
int main(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    cout<<dp_max_pieces(a,b,c,n)<<endl;
    return 0;
}