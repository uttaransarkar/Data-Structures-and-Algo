/*Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.*/

#include <bits/stdc++.h>
int solve(vector < vector <int> > &dp,string S,string V) {
	if(S.size() == 0)
        return 1000;
    if(V.size() <= 0) 
        return 1;
    if(dp[S.size()][V.size()])
        return dp[S.size()][V.size()];
	int i;
    for(i=0; i<V.length(); i++) {
        if(S[0]==V[i]) {
        	break;
        }
    }
    if(i == V.size())
        return 1;
    
    int a = solve(dp,S.substr(1),V);
    int b = solve(dp,S.substr(1),V.substr(i+1))+1;
    
    int ans = min(a,b);
    dp[S.size()][V.size()] = ans;
    return ans;
}

int solve(string S,string V) {
    vector < vector <int> > dp(S.size()+1,vector<int>(V.size()+1,0));
    return solve(dp,S,V);
}