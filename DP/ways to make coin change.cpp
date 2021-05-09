/*Ways To Make Coin Change
Send Feedback
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, 
in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).

*/

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    int dp[value+1][numDenominations];
    for(int i=0; i<=numDenominations; i++) {
        dp[0][i] = 1;
    }
    for(int i=1; i<=value; i++) {
        for(int j=0; j<numDenominations; j++) {
            int a,b;
            if(i-denominations[j]>=0)
                a = dp[i-denominations[j]][j];
            else
                a = 0;
            if(j>=1)
                b = dp[i][j-1];
            else
                b = 0;
            dp[i][j] = a+b;
        }
    }
    return dp[value][numDenominations-1];
}
