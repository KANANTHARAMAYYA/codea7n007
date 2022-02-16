#include<bits/stdc++.h>
using namespace std;

int modkp(vector<int> &v,int val){
    int n = v.size();
    sort(v.begin(),v.end());
    int ans = 0;
    // while(j >= 0 and val > 0){
    //     if(val > v[j]){
    //         val-=v[j];
    //         ans++;
    //     }
    //     else if(val == v[j]){
    //         return ans + 1;
    //     }
    //     else
    //         j -= 1;
    // }
    for(int i = n-1 ;i >=0; i--){
        if(val >= v[i]){
        ans += (val / v[i]);
        val = val % v[i];
        }
    }
    return ans;
}

int main(){
    vector<int> v = {1,5,10,20,100};
    int n;
    cin>>n;
    cout<<modkp(v,n)<<endl;
    return 0;
}