void merge(int input[], int si, int ei, int mid){
	int i=si,j=mid+1,n=0,k=0;
    n = (ei-si)+1;
    int arr[n];
    
    while(i<=mid && j<=ei){
        if(input[i]<input[j]){
            arr[k] = input[i];
            i++;
        } else {
            arr[k] = input[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        arr[k] = input[i];
        i++;
        k++;
    }
    while(j<=ei){
        arr[k] = input[j];
        j++;
        k++;
    }
    for(int m=si; m<=ei; m++){
        input[m] = arr[m-si];
    }
}

void merge_sort(int input[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    merge_sort(input, s, mid);
    merge_sort(input, mid+1, e);
    merge(input, s, e, mid);
}

void mergeSort(int input[], int length){
	// Write your code here
    int s = 0, e = length-1;
    merge_sort(input,s,e);
}
