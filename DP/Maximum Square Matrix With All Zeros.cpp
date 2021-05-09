/*Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.*/

using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int dp[row][col];
    int ans=0;
    for(int i=0; i<row; i++) {
        dp[i][0] = (arr[i][0]==0) ? 1 : 0;
    }
    for(int i=0; i<col; i++) {
        dp[0][i] = (arr[0][i]==0) ? 1 : 0;
    }
    for(int i=1; i<row; i++) {
        for(int j=1; j<col; j++) {
            if(arr[i][j]==1)
                dp[i][j] = 0;
            else {
            	dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
        	}
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}