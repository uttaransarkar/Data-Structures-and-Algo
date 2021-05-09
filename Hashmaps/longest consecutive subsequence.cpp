/* You are given an array of unique integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers 
using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.
*/
#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	//Your Code goes here
    unordered_map<int,bool> m;
    unordered_map<int,int> m1;
    vector<int> ans;
    for(int i=0;i<n;i++){
        m[arr[i]] = true;
        if(m1.count(arr[i]))
            continue;
        m1[arr[i]] = i;
    }
    int start=0,j=0,finalStart=n,startIndex=0;
    for(int i=0;i<n;i++){
        vector<int> temp;
        //count=1;
        if(m[arr[i]]==true){
            start = arr[i];
            temp.push_back(start);
            j = start+1;
            while(true){
                if(m.count(j)>0){
                    //count++;
                    m[j] = false;
                    temp.push_back(j);
                }
                else
                    break;
                j++;
            }
            j = start-1;
            while(true){
                if(m.count(j)>0){
                    temp.push_back(j);
                    start = j;
                    m[j] = false;
                    
                    //count++;
                }
                else
                    break;
                j--;
            }
        }
        startIndex = m1[start];
        if(temp.size()>ans.size()){
            ans = temp;
            sort(ans.begin(),ans.end());
            finalStart = m1[ans[0]];
        }
        if(temp.size()==ans.size() && startIndex<finalStart){
            ans = temp;
        }
    }
    return ans;
}