node* skipMdeleteN(node  *head, int M, int N) {
    // Write your code here
    if(M<=0){
        return NULL;
    }
	node *temp1 = head,*temp2=NULL,*ptr=NULL;
    int c1=1,c2=0;
    while(temp1!=NULL){
        while(c1!=M && temp1->next!=NULL){
            temp1 = temp1->next;
        	c1++;
        }
        temp2 = temp1->next;
        c1 = 1;
        c2 = 0;
        while(c2!=N && temp2!=NULL){
            ptr = temp2;
            temp2 = temp2->next;
            delete ptr;
            c2++;
        }
        temp1->next = temp2;
        temp1 = temp2;
    }
    return head;del