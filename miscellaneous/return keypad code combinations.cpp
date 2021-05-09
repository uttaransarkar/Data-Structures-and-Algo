#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string n,arr[1000];
    if(num == 0){
        output[0] = "";
        return 1;
    }
    int c = keypad(num/10, output);
    int a = num%10;

    switch(a){
        case 0:
        case 1: n = "";
            break;
        case 2: n = "abc";
            break;
        case 3: n = "def";
            break;
        case 4: n = "ghi";
            break;
        case 5: n = "jkl";
            break;
        case 6: n = "mno";
            break;
        case 7: n = "pqrs";
            break;
        case 8: n = "tuv";
            break;
        case 9: n = "wxyz";
            break;
        default: exit(1);
    }
    for(int i = 0; i<c; i++){
        arr[i] = output[i]; 
    }
    if(n.size()==3){
        for(int i = 0; i<c; i++){
        	output[i] = output[i]+n[0]; 
    	}
    	for(int j=c;j<2*c;j++){
            output[j] = arr[j-c]+n[1];
    	}
    	for(int k=2*c;k<3*c;k++){
        	output[k] = arr[k-2*c]+n[2];
    	}
        return c*3;
        
    }
    else if(n.size()==4){
        for(int i = 0; i<c; i++){
        	output[i] = output[i]+n[0]; 
    	}
    	for(int j=c;j<2*c;j++){
            output[j] = arr[j-c]+n[1];
    	}
    	for(int k=2*c;k<3*c;k++){
        	output[k] = arr[k-2*c]+n[2];
    	}
        for(int l=3*c;l<4*c;l++){
        	output[l] = arr[l-3*c]+n[3];
    	}
        return 4*c;
    }  
    // else{
    //     for(int i = 0; i<c; i++){
    //     	output[i] = output[i]+n[0]; 
    // 	}
    //     return c;
    // }
}