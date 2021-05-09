
int knapsack(int* weights, int* values, int n, int maxWeight){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
	int dp[maxWeight+1] = {0};
    for(int i=0; i<n; i++) {
        dp[i] = max(dp[i],values[i]+dp[i-weights[i]]);
    }
    return dp[maxWeight];
}