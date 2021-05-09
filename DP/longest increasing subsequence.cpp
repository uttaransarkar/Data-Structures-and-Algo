/*Given an array with N elements, you need to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are 
sorted in strictly increasing order.*/

using namespace std;

 int lis(int arr[], int n) {
		
	int *output = new int[n];
    output[0] = 1;
    for(int i=1; i<n; i++) {
        output[i] = 1;
        for(int j=i-1; j>=0; j--) {
            if(arr[i] < arr[j])
                continue;
            int tempAns = output[j]+1;
            if(tempAns > output[i])
                output[i] = tempAns;
        }
    } 
    int maximum = 0;
    for(int i=0; i<n; i++) {
    	if(maximum < output[i])
        maximum = output[i];
    }
    return maximum;
 }
