#include <string>
using namespace std;

void returnPermutations(string input, int& count, string output[], string str){
    if(input.size()==0){
        output[count] = str;
        count++;
        return;
    }
    
    for(int i=0;i<input.size();i++){
        string temp = input.substr(0,i)+input.substr(i+1);
       	returnPermutations(temp,count,output,str+input[i]);
    }
}

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    int count=0;
    returnPermutations(input, count, output, "");
    
    return count;
}
