include <unordered_map>
void intersection(int input1[], int input2[], int size1, int size2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */
	unordered_map<int,int> m;
	for(int i=0;i<size1;i++){
		m[input1[i]]++;
	}    
	for(int i=0;i<size2;i++){
		if(m.count(input2[i])>0){
			if(m[input2[i]]==0)
				continue;
			cout<<input2[i]<<endl;
			m[input2[i]] -= 1;
        }
	}
}
