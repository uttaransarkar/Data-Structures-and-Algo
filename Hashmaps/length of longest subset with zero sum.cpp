/*Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.*/
#include <unordered_map>
using namespace std;
int lengthOfLongestSubsetWithZeroSum(int* arr, int size){
  
  // Write your code here
	unordered_map<int,int> m;
    int sum=0,max=0,count=0;
    for(int i=0; i<size; i++){
        sum += arr[i];
        if(sum==0)
            count = i+1;
        else if(m.count(sum))
            count = i-m[sum];
        else
            m[sum] = i;
        if(count>max)
            max = count;
    }
    return max;
}