/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Donât print the subsets, just save them in output.
***/

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    if(n==0){
        if(k==0){
            output[0][0]=0;
            return 1;
        } else {
            return 0;
		}
    }
    int oA[10000][50],oB[10000][50];
	int s1 = subsetSumToK(input+1, n-1, oA, k-input[0]);
    int s2 = subsetSumToK(input+1, n-1, oB, k);
    
    for(int i=0; i<s1; i++){
        //int a = sizeof(oA[i])/sizeof(int);
        output[i][0] = oA[i][0]+1; 
        output[i][1] = input[0];
        for(int j=2;j<output[i][0]+1;j++){
            output[i][j] = oA[i][j-1];
        }
    }
    for(int i=0; i<s2; i++){
        int b = sizeof(oB[i])/sizeof(int);
        output[i+s1][0] = oB[i][0]; 
        for(int j=1;j<b;j++){
            output[i+s1][j] = oB[i][j];
        }
    }
    return s1+s2;
}
