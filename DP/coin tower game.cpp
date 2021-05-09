/*Whis and Beerus are playing a new game today . They form a tower of N coins and make a move in alternate turns . Beerus being the God plays first . 
In one move player can remove 1 or X or Y coins from the tower . The person to make the last move wins the Game . Can you find out who wins the game ?

Sample Input :
 4 2 3
Sample Output :
 Whis
 */
 
string solve(int n, int x, int y)
{
	// Write your code here .
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        int a = (dp[i-1])^1;
        int b = ((i-x>=1) ? dp[i-x] : 0)^1;
        int c = ((i-y>=1) ? dp[i-y] : 0)^1;
        dp[i] = max(a,max(b,c));
    }
    if(dp[n] == 0)
        return "Whis";
    else
        return "Beerus";
}