int partition(int input[],int si,int ei){
    int x = input[si],c=0,i=si,j=ei;
    for(int i=si+1; i<=ei; i++){
        if(input[i]<=x)
            c++;
    }
    int temp = input[si+c];
    input[si+c] = input[si];
    input[si] = temp;
    while(i!=si+c && j!=si+c){
        if(input[i]<=x)
            i++;
        else if(input[j]>x)
            j--;
        else{
            temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
    return (si+c);
}

void qs(int input[],int si,int ei){
	if(si>=ei){
        return;
    }
    int c = partition(input,si,ei);
    qs(input,si,c-1);
    qs(input,c+1,ei);
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    int si = 0,ei = size-1;
	qs(input,si,ei);
}
