    node* arrange_LinkedList(node* head)
    {
        //write your code here
        node *ohead=NULL,*otail=NULL,*ehead=NULL,*etail=NULL,*temp=head;
        while(temp!=NULL){
            if(temp->data%2==1){
                if(ohead==NULL){
                    ohead = temp;
                    otail = temp;
                } else {
                    otail->next = temp;
                    otail = temp;
                }
            } else { 
                if(ehead==NULL){
                    ehead = temp;
                    etail = temp;
                } else {
                    etail->next = temp;
                    etail = temp;
                }
            }
            temp = temp->next;
        }
        if(ohead==NULL){
            etail->next = NULL;
            return ehead;
        }
        else if(ehead==NULL){
            otail->next = NULL;
            return ohead;
        } 
        else {
            etail->next = NULL;
            otail->next = ehead;
            return ohead;
        }
    }
