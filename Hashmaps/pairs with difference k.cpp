
#include<unordered_map>
void printPairs(int *input, int n, int k) {
	// Write your code here
    unordered_map<int,int> m;
    if(k==0){
        for(int i=0;i<n;i++){
            if(m.count(input[i]))
                m[input[i]]++;
            else
                m[input[i]]=0;
            
            if(m[input[i]]){
                int t=m[input[i]];
                for(int j=0;j<t;j++)
                    cout<<(input[i])<<" "<<(input[i])<<endl;
            }
        }
    }
    else{
    	for(int i=0; i<n; i++) {
			m[input[i]]++;        
    	}
    	int num=0;
   		for(int i=0; i<n; i++) {
        	num = input[i];
        	if(num==num+k && num==num-k){
            	for(int j=0;j<2*m[num];j++){
                	cout<<num<<" "<<num<<endl;
            	}
        	}
        	else{
        		if(m.count(num+k)){
            		for(int j=0; j<m[num]*m[num+k]; j++){
                		cout<<min(num,num+k)<<" "<<max(num,num+k)<<endl;
            		}
        		}
        		if(m.count(num-k)){
            		for(int j=0; j<m[num]*m[num-k]; j++){
                		cout<<min(num,num-k)<<" "<<max(num,num-k)<<endl;
            		}
        		}    
        	}
        	m[num] = 0;
    	}    
    }
}