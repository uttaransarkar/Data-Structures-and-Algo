/* Given a string expression which consists only ‘}’ and ‘{‘. The expression may not be balanced. You need to find the minimum number of bracket reversals 
which are required to make the expression balanced.
Return -1 if the given expression can't be balanced. */

#include <stack>
int len(char str[]){
	int i=0,c=0;
    while(str[i]!='\0'){
        c++;
        i++;
    }
    return c;
}

int countBracketReversals(char input[]){
	// Write your code here
	stack<char> s;
    int l = len(input);
    if(l%2!=0)
        return -1;
	for(int i=0;input[i]!='\0';i++){
		if(input[i]=='{')
			s.push(input[i]);
        if(input[i]=='}'){
            if(s.empty())
                s.push(input[i]);
            else {
                if(s.top()=='{')
                	s.pop();
            	else
                	s.push(input[i]);
            }
        }
    }
    char c1,c2;
    int count=0;
    while(!s.empty()){
        c1 = s.top();
        s.pop();
        c2 = s.top();
        s.pop();
        if(c1==c2)
            count++;
        else
            count+=2;
    }
    return count;
}
