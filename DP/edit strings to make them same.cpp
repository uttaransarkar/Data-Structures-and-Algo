/*Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps 
required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character */

#include<iostream>
#include<cstring>
using namespace std;

int editDistance_helper(string s1, string s2, int **dp) {
    int m = s1.size();
    int n = s2.size();
    
    if(s1.size()==0 || s2.size()==0) {
        return max(s1.size(),s2.size());
    }
    if(dp[m][n] != -1) {
        return dp[m][n];
    }
    
    int ans;
    if(s1[0] == s2[0]) {
        ans = editDistance_helper(s1.substr(1),s2.substr(1),dp);
    }
    else {
        int x = editDistance_helper(s1,s2.substr(1),dp) + 1;				//delete
        int y = editDistance_helper(s1.substr(1),s2.substr(1),dp) + 1;		//replace
        int z = editDistance_helper(s1.substr(1),s2,dp) + 1;				//insert
        ans = min(x,min(y,z));
    }
    dp[m][n] = ans;
    return ans;
}

int editDistance(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
	int m = s1.size();
    int n = s2.size();
    int **dp = new int*[m+1];
    for(int i=0; i<=m; i++) {
        dp[i] = new int[n+1];
        for(int j=0; j<=n; j++) {
            dp[i][j] = -1;
        }
    }
    
    return editDistance_helper(s1,s2,dp);
}