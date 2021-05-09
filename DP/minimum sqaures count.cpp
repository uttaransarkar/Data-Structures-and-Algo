/*Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as
1 is the minimum count of numbers required. */

int minCount(int n)
{
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i=2; i<=n; i++) {
        arr[i] = i;
        for(int j=1; j<=sqrt(i); j++) {
            int x = j*j;
            int count = arr[i-x]+1;
            arr[i] = min(arr[i],count);
        }
    }
    return arr[n];
}
