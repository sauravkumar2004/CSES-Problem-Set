#include<iostream>
#include<climits>
#include<vector>
using namespace std;
vector<int> dp;
vector<int> lastdigit(int n){
    vector<int> ans;
    while(n>0){
        if(n%10!=0){
            ans.push_back(n%10);
        }
        n=n/10;
    }
    return ans;
}
int Remove(int n){
    if(n==0) return 0;
    if(n<=9) return 1;
    vector<int> digit=lastdigit(n);
    int result=INT_MAX;
    if(dp[n]!=-1) return dp[n];
    for (auto i = 0u; i < digit.size(); i++) {
    result = min(result, Remove(n - digit[i]));
}
    return dp[n]=1+result;

}
int main(){
    dp.clear();
    dp.resize(10000000,-1);
   int n;
    cin>>n;
    cout<<Remove(n)<<"\n";
}