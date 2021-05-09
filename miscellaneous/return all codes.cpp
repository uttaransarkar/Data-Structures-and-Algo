/*Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible 
codes that can be generated from the given string. */

#include <string.h>
using namespace std;

char itoa(int n){
    char ch = 'a'+n-1;
    return ch;
}

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input[0]=='\0'){
        output[0]="";
        return 1;
    }
    if(input.size()==1){
        output[0]=itoa(input[0]-'0');
        return 1;
    }
    
    string op1[1000],op2[1000]; int c2=0;
	int c1 = getCodes(input.substr(1), op1);
    
    if(input.size()>1){
        if(stoi(input.substr(0,2))>=10 && stoi(input.substr(0,2))<=26){
        	c2 = getCodes(input.substr(2), op2);
        }
	    for(int i=0;i<c1;i++){
    	    output[i] = itoa(input[0]-'0')+op1[i];
    	}
    	for(int i=c1;i<c1+c2;i++){
        	output[i] = itoa(stoi(input.substr(0,2)))+op2[i-c1];
    	}
    }
    return c1+c2;
}
   