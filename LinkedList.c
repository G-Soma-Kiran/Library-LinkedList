#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


static int divide(int a[],int low,int high){
    int i=low-1;
    int pivot=a[high];
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    return (i+1);
    
}
static void quickselect(int a[],int low,int high,int target,int selectorflag){
    if(low<high)
    {int p=divide(a,low,high);
    if(p+1 == target){
        return ;
    }else if(!(selectorflag^(p+1 < target)))
    {return quickselect(a,low,p-1,target,selectorflag);}
    else
    {return quickselect(a,p+1,high,target,selectorflag);}}

}
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
typedef struct LList{
    int length;
    Node *next;
    Node *last;
}LList;


LList *Initialize()//Initializes a LList object(head) and initializes the parameters of head. Returns a pointer to LList. 
{
    LList *temp = malloc(sizeof(LList));
    temp->length=0;
    temp->next = NULL;
    temp->last=NULL;
    return temp;
}
static void Append(LList* head, int value){//adds element to end of LList.
    if(head == NULL){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return;
    }
    head->length++;
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->next=NULL;
    temp->data=value;
    if(head->last == NULL){
        head->next=temp;
        head->last=temp;
        return ;
    }
    (head->last)->next=temp;
    head->last=temp;


}
static int Insert(LList *head, int number, int position)//Inserts a number into the LList.Returns 1 if insertion was success else 0.  
{
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(position < 0){
        position = head->length +1+position;
    }
    if(position<=0 || position>(head->length +1)){    
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional argument is\n\tposition : %d\n\x1b[0m",__func__,head->length,position);
        exit(1);
        return 0;
    }
    if(position==(head->length + 1)){
        Append(head,number);
        return 1;
    }


    (head->length)++;
    int i = 0;
    Node *HEAD = head->next;
    Node *temp = (Node *)malloc(sizeof(Node));
    if (position == 1)
    {
        temp->next = head->next;                     
        temp->data = number;
        head->next = temp;
        if(head->length == 1){
        head->last=temp;
        }
    }
    else
    {
        while (i < position - 2)
        {   
            if (HEAD == NULL || HEAD->next == NULL) 
            {   (head->length)--;
                free(temp);
                return 0;
            }
            HEAD = HEAD->next;
            
            i++;
        }
        
        temp->next = HEAD->next;
        temp->data = number;
        HEAD->next = temp;
        if(temp->next == NULL){
            head->last=temp;
        }
    }
    return 1;
    
}
static void Print(LList *head) // prints LList elements in order.
{   if(head == NULL){
    
    fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return;
    }
    Node *HEAD = head->next;
    if(head->length > 1)
    printf("[ ");
    else
    printf("[");
    while (HEAD != NULL)
    {
        printf("%d", HEAD->data);
        if(HEAD->next != NULL){
            printf(", ");
        }
        HEAD = HEAD->next;
    }if(head->length <=1)
    printf("]\n");
    else
    printf(" ]\n");
}
static int Pop(LList *head,int position){ //Pops an element of list with given position and returns the popped value.terminates running code if head is invalid or any other error. 
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(position < 0){
        position = head->length + 1  + position;
    }

    if(position<=0 || position>(head->length)){       
        if(head->length>0)
        fprintf(stderr,"\x1b[31mKeyError : In function =>'%s' ; Can only pop element with position in range : 1<=position<=%d; But given position : %d\n\x1b[0m",__func__,head->length,position);
        else
        fprintf(stderr,"\x1b[31mKeyError : In function =>'%s' ; LList is empty; But given position : %d\n\x1b[0m",__func__,head->length,position);
        exit(1);
    }
    (head->length)--;
    Node * HEAD= head->next;
    if(position==1){
        if(head->last == head->next){
            head->last=NULL;
        }
        head->next=(head->next)->next;
        int value=HEAD->data;
        free(HEAD);
        
        return value;
    }else
    {int i=0;
    while(i<position-2){
        HEAD=HEAD->next;
        i++;
    }
    Node*temp=HEAD->next;
     HEAD->next=temp->next;
     int value = temp->data;
     free(temp);
        if(temp->next == NULL){
            head->last=HEAD;
        }
     return value;

    }
}
static int Len(LList * head){  //returns the head->length variable's value.Else for invalid head program terminates.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    return head->length;
}
static void Reverse(LList * head){//Reverses LList using my own technique.O(n).
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return;
    }
    Node* HEAD=head->next;
    head->last=head->next;
    head->next=NULL;
    while(HEAD != NULL){
        Node* temp = HEAD->next;
        HEAD->next = head->next;
        head->next = HEAD;
        HEAD=temp;
    }
}
static void std_Reverse(LList * head){//Traditional reversing technique
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return;
    }
    head->last=head->next;
    Node*HEAD=(head)->next;
    Node* prev=NULL;
    Node*next;
    while((HEAD) != NULL){
        next=HEAD->next;
        HEAD->next=prev;
        prev=HEAD;
        HEAD=next;
        
    }
    (head)->next=prev;

}
static void recurse_reverse_helper(Node* firstnode){
    if(firstnode == NULL ||firstnode->next == NULL){
        return;
    }
    recurse_reverse_helper(firstnode->next);
    firstnode->next->next = firstnode;
    firstnode->next = NULL;
    return;

}
static void recurse_Reverse(LList* head ){//reverses list using recursion.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return;
    }
    recurse_reverse_helper(head->next);
    Node* temp = head->last;
    head->last = head->next;
    head->next = temp;
}
static void Reverse_sublist(LList * head , int start , int end){//reverses a sublist of a given list according to parameters.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return;
    }
    if(head->length == 1 || head->length == 0){
        return ;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end < 0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        return ;
    }

    Node* prev = NULL;
    Node* curr = head->next;
    Node* future = NULL;
    Node* connect_start = NULL;
    Node* connect_end= NULL;
    int position = 1;
    while(position != start){
        prev = curr;
        curr = curr->next;
        position++;
    }
    connect_start = prev;
    connect_end = curr;
    while(position != end+1){
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;
        position++;
    }
    if(start == 1){
        head->next = prev;
    }else{
    connect_start->next = prev;
    }
    connect_end->next = curr;

    if(end == head->length){
        head->last = connect_end;
    }

}
static void Delete(LList** head){//Takes address of LList object and frees all the memory allocated for it including the head.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return;
    }
    if((*head) == NULL){
        free(*head);
        return;
    }
    Node * HEAD=(*head)->next;
    while(HEAD != NULL){
        Node* temp=HEAD;
        HEAD=HEAD->next;
        free(temp);
    }
    free(*head);
    *head= NULL;
}
static int _find_core(LList* head , int Target ,int start , int end , int k ,int lastflag){ //Returns the position of target element if found as per the parameters else returns 0.If head is invalid or any other error occurs then terminates the program.
    
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(head->length == 0){
        return 0;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
    int i=1; 
    int position=1;
    int find_last_position=0;
    Node* HEAD=head->next;
    while(HEAD!=NULL && i<=end){
        if( lastflag || i<start || k>1 || HEAD->data != Target)
        {
            if(i>=start && HEAD->data == Target){
                find_last_position=position;
                k--;
            }
            HEAD=HEAD->next;
            i++;
        }
        else
        {return position;}
        position++;
    }
    if(lastflag){
        return find_last_position;
    }

    return 0;
}
      static int Find(LList* head,int Target){//Returns the position of target element if found as per the parameters else returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
        }
       return _find_core(head,Target,1,Len(head),1,0);
        }
      static int Find_in_range(LList* head,int Target,int start,int end){//Returns the position of target element if found as per the parameters else returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
        }
        if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
       return _find_core(head,Target,start,end,1,0);
   }
      static int Find_kth(LList* head,int Target,int k){//Returns the position of target element if found as per the parameters else returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-finding of %d;\n\x1b[0m",__func__,k,Target);
            exit(1);
            return 0;
        }
    return _find_core(head,Target,1,Len(head),k,0);
   }
      static int Find_kth_in_range(LList* head,int Target,int k,int start,int end){//Returns the position of target element if found as per the parameters else returns 0.If head is invalid or any other error occurs then terminates the program.
       if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-finding of %d;\n\x1b[0m",__func__,k,Target);
            exit(1);
            return 0;
        }
    return _find_core(head,Target,start,end,k,0);
   }
      static int Find_last(LList* head,int Target){//Returns the position of target element if found as per the parameters else returns 0.If head is invalid or any other error occurs then terminates the program.
       if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
        return _find_core(head,Target,1,Len(head),1,1);
   }
      static int Find_last_in_range(LList* head,int Target,int start,int end){//Returns the position of target element if found as per the parameters else returns 0.If head is invalid or any other error occurs then terminates the program.
       if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        return _find_core(head,Target,start,end,1,1);
   }
static LList* _find_all_core(LList* head , int Target , int start , int end ,int mode){//Returns a List containing positions of Target in a given list as per parameters .If head is invalid or any other error occurs then terminates the program.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return NULL;
    }
    if(head->length == 0){
        return Initialize();
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        return 0;
    }
    Node* HEAD = head->next;
    LList* Return = Initialize();
    int position =1;
    while(HEAD != NULL && position <= end){
        if(HEAD->data == Target && position>=start){
            if(mode){
                Insert(Return , position , 1);
            }else{
                Append(Return , position);
            }
        }
        HEAD = HEAD->next;
        position++;
    }
    return Return;
}
      static LList* FindAll(LList* head , int Target){//Returns a List containing positions of Target in a given list as per parameters .If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return NULL;
    }
        return _find_all_core(head , Target , 1 , head->length ,0 );
        }
      static LList* FindAll_in_range(LList* head , int Target , int start , int end ){//Returns a List containing positions of Target in a given list as per parameters .If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return NULL;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        return _find_all_core(head , Target , start , end ,0);
       }
static int _count_core(LList* head , int value ,int start ,int end){//counts the total occurences of a given value in LList as per parameters.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(head->length == 0){
        return 0;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'Count'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",head->length,start,end);
        return 0;
    }
    int count=0;
    int i=1;
    Node*HEAD=head->next;
    while(i<=end){
        if(i>=start)
        {if((HEAD->data) == value){
            count++;
        }}
        HEAD=HEAD->next;
        i++;
    }
    return count;
}
      static int Count(LList* head,int value){//counts the total occurences of a given value in LList as per parameters.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }   
        return _count_core(head,value,1,Len(head));
       }
      static int Count_in_range(LList* head,int value,int start,int end){//counts the total occurences of a given value in LList as per parameters.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }   
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        return _count_core(head,value,start,end);
       }
static int _remove_core(LList* head , int value , int start , int end , int k , int lastflag){//removes the occurence of a given value in LList as per parameters and returns the position of the occurance.If no removal takes place returns 0.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(head->length == 0){
        return 0;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end < 0){
        end = head->length +1+end;
    }
    if(start>end || start<=0 || end<=0 || start > head->length || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'Remove'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",head->length,start,end);
        return 0;
    }
    int position=1;
    Node * prev =NULL;
    Node * search= head->next;
    if(lastflag == 0)
    {
    while(search != NULL && position <= end){
        if((search->data) == value ){
            if(k!=0 && ((position >= start) && (position <= end)))
            {k--;}
            if(k==0 && ((position >= start) && (position <= end)))
            {if(position==1){
                if(search->next == NULL)
                {head->last=NULL;}
                head->next=search->next;
                free(search);    
                head->length--;
                return position;
            }
            prev->next=search->next;
            free(search);
            head->length--;
            if(prev->next == NULL){
                head->last=prev;
            }
            return position;}
        }
        prev=search;
        search=search->next;
        position++;
        
    }
    }else{
        Node* Last = NULL;
        Node* prev_Last = NULL;
        int last_position =0;
        while(search != NULL && position <= end){
            if((search->data) == value ){
                k--;
                Last = search;
                prev_Last = prev;
                last_position = position;
                if(k==0){
                    break;
                }
                
            }
            prev=search;
            search=search->next;
            position++;
        
    }
    if(last_position >= start && last_position <= end)
            {if(last_position==1){
                if(Last->next == NULL)
                {head->last=NULL;}
                head->next=Last->next;
                free(Last);    
                head->length--;
                return last_position;
            }
            prev_Last->next=Last->next;
            free(Last);
            head->length--;
            if(prev_Last->next == NULL){
                head->last=prev_Last;
            }
            return last_position;}
    }

    return 0;
}
      static int Remove(LList* head , int value){//removes the occurence of a given value in LList as per parameters and returns the position of the occurance.If no removal takes place returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
        return _remove_core(head , value , 1, head->length ,0, 0);
       }
      static int Remove_in_range(LList* head , int value , int start , int end){//removes the occurence of a given value in LList as per parameters and returns the position of the occurance.If no removal takes place returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        return _remove_core(head , value , start, end , 0,0);
       }
      static int Remove_kth(LList* head , int value , int k){//removes the occurence of a given value in LList as per parameters and returns the position of the occurance.If no removal takes place returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-removal of %d;\n\x1b[0m",__func__,k,value);
            exit(1);
            return 0;
        }
        return _remove_core(head , value , 1, head->length , k,0);
       }
      static int Remove_kth_in_range(LList* head , int value , int k , int start ,int end){//removes the occurence of a given value in LList as per parameters and returns the position of the occurance.If no removal takes place returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        if(k<=0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-removal of %d;\n\x1b[0m",__func__,k,value);
            exit(1);
            return 0;
        }
        return _remove_core(head , value , start , end , k , 0);
       }
      static int Remove_last(LList* head , int value){//removes the occurence of a given value in LList as per parameters and returns the position of the occurance.If no removal takes place returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
        return _remove_core(head , value , 1, head->length , -1 ,1);
       }
      static int Remove_last_in_range(LList* head , int value , int start , int end){//removes the occurence of a given value in LList as per parameters and returns the position of the occurance.If no removal takes place returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        return _remove_core(head , value , start , end , -1 , 1);
       }
static int _remove_from_end_core(LList* head , int value , int start , int end , int k){
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(head->length == 0){
        return 0;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end < 0){
        end = head->length +1+end;
    }
    if(start>end || start<=0 || end<=0 || start > head->length || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'Remove_from_end'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",head->length,start,end);
        return 0;
    }

        LList* range = _find_all_core(head , value , start , end ,1);
        while(range->next->data > end){
            if(range->length == 0){
                free(range);
                return 0;
            }
            Pop(range , 1);
        }
        if(range->length < k){
            return 0;
        }
        for(int i=0 ; i < k-1 ; i++){
            if(range->length == 0){
                free(range);
                return 0;
            }
            Pop(range , 1);
        }

        if(range->next->data < start){
            return 0;
        }

        int position = 1;
        Node* Traverse = head->next;
        Node* pre_traverse = NULL;
        while(position != range->next->data){
            pre_traverse = Traverse;
            Traverse = Traverse->next;
            position++;
        }
        if(position == 1){
            Pop(head , 1);
            head->length++;
        }else if(position == head->length){
            pre_traverse->next = Traverse->next;
            head->last = pre_traverse;
            free(Traverse);
        }else{
            pre_traverse->next = Traverse->next;
            free(Traverse);
        }
        head->length--;
        Delete(&range);
        return position;

       }
      static int Remove_kth_from_end(LList* head , int value , int k){//removes the occurence of a given value in LList as per parameters and returns the position of the occurance.If no removal takes place returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-removal from end of %d;\n\x1b[0m",__func__,k,value);
            exit(1);
            return 0;
        }
    return _remove_from_end_core(head , value , 1 , head->length , k);
       }
      static int Remove_kth_from_end_in_range(LList* head , int value , int k , int start , int end){//removes the occurence of a given value in LList as per parameters and returns the position of the occurance.If no removal takes place returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-removal from end of %d;\n\x1b[0m",__func__,k,value);
            return 0;
        }
    return _remove_from_end_core(head , value , start , end , k);
       }
static int _remove_all_core(LList* head, int value , int start , int end , int k){//Removes all occurences of a given value from LList as per parameters and Returns the count of removed elements.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(head->length == 0){
        return 0;
    }
        if(start < 0 ){
        start = head->length +1+start;
        }
        if(end < 0){
            end = head->length +1+end;
        }
        if(start>end || start<=0 || end<=0 || start > head->length || end > head->length){
            fprintf(stderr,"\x1b[31mValueError : In function =>'RemoveAll'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",head->length,start,end);
            return 0;
        }

        int position=1;
        int count=0;
        Node * search=head->next;
        Node * pre_search=NULL;
        while(search !=NULL && k>0 && position<=end){
            if(search->data == value && position>=start){
                k--;
                if(pre_search == NULL){
                    head->next=search->next;
                }else{
                    if(search->next == NULL){
                        head->last = pre_search;
                    }
                    pre_search->next=search->next;
                }
                Node * temp=search;
                search=search->next;
                free(temp);
                count++;

            }else{
                pre_search=search;
                search=search->next;
            }
            position++;
        }
    head->last=pre_search;
    head->length-=count;
    if(head->length == 0){
        head->last = NULL;
    }
    return count;
}
      static int RemoveAll(LList* head , int value){//Removes all occurences of a given value from LList as per parameters and Returns the count of removed elements.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
        return _remove_all_core(head , value , 1 , head->length , head->length+1);
       }
      static int RemoveAll_in_range(LList* head , int value , int start , int end){//Removes all occurences of a given value from LList as per parameters and Returns the count of removed elements.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        return _remove_all_core(head , value , start , end , head->length+1);
       }
      static int Remove_K(LList* head , int value , int k){//Removes all occurences of a given value from LList as per parameters and Returns the count of removed elements.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-removals of %d;\n\x1b[0m",__func__,k,value);
            exit(1);
            return 0;
        }
    return _remove_all_core(head , value , 1 , head->length , k);
       }
      static int Remove_K_in_range(LList* head , int value , int k ,int start , int end ){//Removes all occurences of a given value from LList as per parameters and Returns the count of removed elements.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-removals of %d;\n\x1b[0m",__func__,k,value);
            exit(1);
            return 0;
        }
    return _remove_all_core(head , value , start , end , k);
       }
static int _remove_all_from_end_core(LList* head , int value , int start , int end , int k){//Removes all occurences of a given value from LList as per parameters and Returns the count of removed elements.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(head->length == 0){
        return 0;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end < 0){
        end = head->length +1+end;
    }
    if(start>end || start<=0 || end<=0 || start > head->length || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'Remove_K_from_end'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",head->length,start,end);
        return 0;
    }
        LList* range = _find_all_core(head , value , start , end, 0);
        if(range->length < k){
            return 0;
        }
        while(range->length > k){
            Pop(range , 1);
        }
        Node* pre_Traverse = NULL;
        Node* Traverse = head->next;
        int position =1;
        while(range->length != 0){
            if(position == range->next->data){
                if(position == 1){
                    Traverse = Traverse->next;
                    Pop(head , 1);
                    head->length++;
                }else if(Traverse->next == NULL){
                    pre_Traverse->next = Traverse->next;
                    head->last = pre_Traverse;
                    Node* temp = Traverse;
                    Traverse = Traverse->next;
                    free(temp);
                }else {
                pre_Traverse->next = Traverse->next;
                Node* temp = Traverse;
                Traverse = Traverse->next;
                free(temp);
                }
                Pop(range , 1);
                head->length--;
            }else{
            pre_Traverse = Traverse;
            Traverse = Traverse->next;
            }
            position++;
        }
        Delete(&range);
        return 1;

}
      static int Remove_K_from_end(LList* head , int value , int k){//Removes all occurences of a given value from LList as per parameters and Returns the count of removed elements.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-removals form end of %d\n;\x1b[0m",__func__,k,value);
            exit(1);
            return 0;
        }
    return _remove_all_from_end_core(head , value , 1 , head->length , k);
       }
      static int Remove_K_from_end_in_range(LList* head , int value , int k , int start , int end){//Removes all occurences of a given value from LList as per parameters and Returns the count of removed elements.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-removals from end of %d\n;\x1b[0m",__func__,k,value);
            exit(1);
            return 0;
        }
    return _remove_all_from_end_core(head , value , start , end , k);
       }
static void Clear(LList * head){//Frees all allocated memory for nodes and leaves the head i.e LList pointer.Essentially empties the LList.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return ;
    }
    if(head->length == 0){
        return ;
    }
    Node * HEAD=head->next;
    while(HEAD != NULL){
        Node* temp=HEAD;
        HEAD=HEAD->next;
        free(temp);
    }
    head->next=NULL;
    head->last=NULL;
    head->length=0;
}
static void RemoveDuplictes(LList* head){//Removes all the duplicates from LList.Mutates original LList and makes it a LList with only unique elements using hashing.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return ;
    }
    if(head->length == 0 || head->length == 1){
        return;
    }
    int alpha= ((head->length)*4)/3;
    int size = 1;
    while(size< alpha){
       size = size*2;
    }
    LList **freq=malloc(size*sizeof(LList*));
    for(int i=0;i<size;i++){
        freq[i]=NULL;
    }
    if(freq == NULL){
        printf("Malloc failed\n");
        return ;
    }
    
    Node* Traverse = head->next;
    head->next=NULL;
    head->length=0;
    head->last=NULL;
    
    while(Traverse != NULL){
        unsigned int hash = ((unsigned int)Traverse->data) & (size-1);
        int found;
        if(freq[hash] == NULL){
            freq[hash]=Initialize();
        }else{
            found = Find(freq[hash] , Traverse->data);
            if(found){
                Node* temp =Traverse;
                Traverse = Traverse->next;
                free(temp);
                continue;
            }
        }
        Append(freq[hash] , Traverse->data);
        Append(head , Traverse->data);
        Node* temp =Traverse;
        Traverse = Traverse->next;
        free(temp);
    }
    
    
    for(int i=0;i<size;i++){
        Delete(&freq[i]);
    }
    free(freq);
    
}
static void Sort(LList * head , int mode){//Sorts the LList using a knock off of (selection and bubble sort). my own implementation.mode=>takes 1 for ascending and -1 for descending.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return;
    }
    if(mode!= 1 && mode!= -1){
        
        fprintf(stderr,"\x1b[31mError : In function =>'%s' ; Can only accept <int>'1' or <int>'-1' but given argument : %d\n\x1b[0m",__func__,mode);
        exit(1);
    }
    if(mode==-1){
        mode=0;
    }
    if(head->length<=1){
        return;
    }
    int FirstMinFlag=1;
    int min=(head->next)->data;
    Node* LoopState = head->next;
    Node* Traversal=head->next;
    Node* minimum=NULL;
    Node* pre_minimum=NULL;
    while(LoopState != NULL){
        if(!(FirstMinFlag))
        {pre_minimum=head->last;
            if(pre_minimum->next == NULL){
                return;
            }
        LoopState=pre_minimum->next;}
        Traversal=LoopState;
        minimum=Traversal;
        min=Traversal->data;
        while((Traversal->next) != NULL){
            if((mode ^ ((Traversal->next)->data < min))){
                minimum=Traversal->next;
                min=(Traversal->next)->data;
                pre_minimum=Traversal;
            }
            Traversal=Traversal->next;
        }
        if(FirstMinFlag){
            head->last=minimum;   
        }
        if( pre_minimum != NULL){
        pre_minimum->next=minimum->next;
        minimum->next=head->next;
        head->next=minimum;
        }
        if(FirstMinFlag){
            pre_minimum=head->next;
            FirstMinFlag=0;
        }
    
        
    } 
    
    
}
static Node* _merge_core(Node* left , Node* right , int SelectorFlag){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    Node * result;
    if(!(SelectorFlag ^ (left->data <= right->data))){
        result=left;
        result->next = _merge_core(left->next , right , SelectorFlag);
    }else{
        result=right;
        result->next = _merge_core( left , right->next , SelectorFlag);
    }
    return result;
    // LList * left=Initialize();
    // LList* right=Initialize();
    // Node* temp=low;
    // while(temp != mid->next){
    //     Append(left,temp->data);
    //     temp=temp->next;
    // }
    // while(temp != high->next){
    //     Append(right,temp->data);
    //     temp=temp->next;
    // }
    // Node* traverse_left=left->next;
    // Node* traverse_right=right->next;
    // while(traverse_left != NULL && traverse_right != NULL){
    //     if(traverse_left->data < traverse_right->data){
    //         low->data = traverse_left->data;
    //         low=low->next;
    //         traverse_left=traverse_left->next;
    //     }else{
    //         low->data = traverse_right->data;
    //         low=low->next;
    //         traverse_right=traverse_right->next;
    //     }
    // }
    // if(traverse_left == NULL){
    //     while(traverse_right != NULL){
    //         low->data = traverse_right->data;
    //         low=low->next;
    //         traverse_right=traverse_right->next;
    //     }
    // }
    // if(traverse_right == NULL){
    //     while(traverse_left != NULL){
    //         low->data = traverse_left->data;
    //         low=low->next;
    //         traverse_left=traverse_left->next;
    //     }
    // }
    // Delete(&left);
    // Delete(&right);

}
static Node* m_divide(Node* low , int SelectorFlag){
    if( low == NULL || low->next == NULL ){
        return low;
    }
    Node* slow=low;
    Node* fast=low;
    Node* left=low;
    while(fast->next != NULL && fast->next->next !=NULL){
        fast=(fast->next)->next;
        slow=slow->next; 
    }
    
    Node* mid=slow;
    Node*right=mid->next;
    mid->next=NULL;
    left = m_divide(left , SelectorFlag);
    right = m_divide(right , SelectorFlag);
    return _merge_core(left,right,SelectorFlag);


}
static void MergeSort(LList* head , int mode){//mode=>takes 1 for ascending and -1 for descending.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return;
    }
    if(mode!= 1 && mode!= -1){
        
        fprintf(stderr,"\x1b[31mError : In function =>'%s'; Can only accept <int>'1' or <int>'-1' but given argument : %d\n\x1b[0m",__func__,mode);
        exit(1);
    }
    if(head->length <= 1){
        return ;
    }
    if(mode == -1){
        mode=0;
    }
    head->next = m_divide(head->next , mode); 
    Node* temp= head->next;
    while(temp!= NULL && temp->next != NULL){
        temp=temp->next;
    }
    head->last=temp;

    return;
 
}
 
static void my_merge_core(Node* low,Node* mid ,Node* high,int SelectorFlag){
    LList * left=Initialize();
    LList* right=Initialize();
    Node* temp=low;
    while(temp != mid->next){
        Append(left,temp->data);
        temp=temp->next;
    }
    while(temp != high->next){
        Append(right,temp->data);
        temp=temp->next;
    }
    Node* traverse_left=left->next;
    Node* traverse_right=right->next;
    while(traverse_left != NULL && traverse_right != NULL){
        if(!(SelectorFlag^(traverse_left->data < traverse_right->data))){
            low->data = traverse_left->data;
            low=low->next;
            traverse_left=traverse_left->next;
        }else{
            low->data = traverse_right->data;
            low=low->next;
            traverse_right=traverse_right->next;
        }
    }
    if(traverse_left == NULL){
        while(traverse_right != NULL){
            low->data = traverse_right->data;
            low=low->next;
            traverse_right=traverse_right->next;
        }
    }
    if(traverse_right == NULL){
        while(traverse_left != NULL){
            low->data = traverse_left->data;
            low=low->next;
            traverse_left=traverse_left->next;
        }
    }
    Delete(&left);
    Delete(&right);

}
static void my_m_divide(Node* low,Node* high,int SelectorFlag){
    if(low==high){
        return;
    }
    Node* mid=low;
    Node* fast=low;
    while(fast!= NULL && fast->next!=NULL && fast->next != high->next && fast->next->next != high->next){
        fast=(fast->next)->next;
        mid=mid->next;
    }
    my_m_divide(low,mid , SelectorFlag);
    my_m_divide(mid->next,high, SelectorFlag);
    my_merge_core(low,mid,high,SelectorFlag);
}
static void my_MergeSort(LList* head , int mode){//mode=>takes 1 for ascending and -1 for descending.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return;
    }
    if(mode!= 1 && mode!= -1){
        
        fprintf(stderr,"\x1b[31mError : In function =>'%s'; Can only accept <int>'1' or <int>'-1' but given argument : %d\n\x1b[0m",__func__,mode);
        exit(1);
    }
    if(head->length <= 1){
        return ;
    }
    if(mode == -1){
        mode=0;
    }
    my_m_divide(head->next,head->last,mode);
    return;
 
}

static int _replace_core(LList* head , int oldValue , int newValue , int start , int end , int k , int lastflag){//Replaces oldValue with a newValue as per parameters and Returns the position of the replaced number .If no replacement takes place then returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(head->length == 0){
        return 0;
    }
        if(start < 0 ){
        start = head->length +1+start;
        }
        if(end < 0){
            end = head->length +1+end;
        }
        if(start>end || start<=0 || end<=0 || start > head->length || end > head->length){
            fprintf(stderr,"\x1b[31mValueError : In function =>'Replace'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",head->length,start,end);
            return 0;
        }
        int position =1;
        int last_position=0;
        Node * HEAD=head->next;
        Node* Last = NULL;
        while(HEAD != NULL && position<=end){
            if(HEAD->data == oldValue){
                if(position>=start){
                    Last = HEAD;
                    last_position=position;
                    if(k!=0)
                    {k--;}
                }
                if(lastflag == 0){
                    if(position >= start && k==0){
                        HEAD->data = newValue;
                        return position;
                    }
                }
            }
            HEAD=HEAD->next;
            position++;
        }

        if(Last != NULL && (lastflag == 1)){
            Last->data = newValue;
            return last_position;  
        }
        return 0;
}
      static int Replace(LList* head , int oldValue , int newValue){//Replaces oldValue with a newValue as per parameters and Returns the position of the replaced number .If no replacement takes place then returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
        return _replace_core(head , oldValue , newValue , 1,head->length,0,0);
       }
      static int Replace_in_range(LList* head , int oldValue , int newValue , int start ,int end){//Replaces oldValue with a newValue as per parameters and Returns the position of the replaced number .If no replacement takes place then returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        return _replace_core(head , oldValue,newValue,start,end,0,0);
       }
      static int Replace_kth(LList* head , int oldValue , int newValue , int k){//Replaces oldValue with a newValue as per parameters and Returns the position of the replaced number .If no replacement takes place then returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return -1;
        }
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-replacement of %d to %d;\n\x1b[0m",__func__,k,oldValue,newValue);
            exit(1);
            return 0;
        }
        return _replace_core(head , oldValue,newValue,1,head->length,k,0);
       }
      static int Replace_kth_in_range(LList* head , int oldValue , int newValue ,int k , int start ,int end){//Replaces oldValue with a newValue as per parameters and Returns the position of the replaced number .If no replacement takes place then returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return -1;
        }
        if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
         if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-replacement of %d to %d;\n\x1b[0m",__func__,k,oldValue,newValue);
            exit(1);
            return 0;
        }
        return _replace_core(head , oldValue,newValue,start,end,k,0);
       }
      static int Replace_last(LList* head ,int oldValue,int newValue){//Replaces oldValue with a newValue as per parameters and Returns the position of the replaced number .If no replacement takes place then returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
        return _replace_core(head , oldValue,newValue,1,head->length,-1,1);
       }
      static int Replace_last_in_range(LList* head , int oldValue , int newValue ,int start , int end){//Replaces oldValue with a newValue as per parameters and Returns the position of the replaced number .If no replacement takes place then returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
        
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        return _replace_core(head , oldValue,newValue,start,end,-1,1);
       }
static int _replace_from_end_core(LList* head , int oldValue , int newValue , int start , int end , int k){//Replaces oldValue with a newValue as per parameters and Returns the position of the replaced number .If no replacement takes place then returns 0.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(head->length == 0){
        return 0;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end < 0){
        end = head->length +1+end;
    }
    if(start>end || start<=0 || end<=0 || start > head->length || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'Replace_from_end'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",head->length,start,end);
        return 0;
    }

        LList* range = _find_all_core(head , oldValue , start , end ,1);
        while(range->next->data > end){
            if(range->length == 0){
                free(range);
                return 0;
            }
            Pop(range , 1);
        }
        if(range->length < k){
            return 0;
        }
        for(int i=0 ; i < k-1 ; i++){
            if(range->length == 0){
                free(range);
                return 0;
            }
            Pop(range , 1);
        }

        if(range->next->data < start){
            return 0;
        }
        Node* Traverse = head->next;
        int position = 1;
        while(position != range->next->data){
            Traverse = Traverse->next;
        }
        Traverse->data = newValue;
        Delete(&range);
        return position;

}
      static int Replace_kth_from_end(LList* head , int oldValue , int newValue , int k){//Replaces oldValue with a newValue as per parameters and Returns the position of the replaced number .If no replacement takes place then returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return -1;
        }    
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-replacement from end of %d to %d;\n\x1b[0m",__func__,k,oldValue,newValue);
            exit(1);
            return 0;
        }
        return _replace_from_end_core(head , oldValue ,newValue , 1 , head->length , k);
        }
      static int Replace_kth_from_end_in_range(LList* head , int oldValue , int newValue , int k,int start , int end ){//Replaces oldValue with a newValue as per parameters and Returns the position of the replaced number .If no replacement takes place then returns 0.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return -1;
        }   
        if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-replacement from end of %d to %d;\n\x1b[0m",__func__,k,oldValue,newValue);
            exit(1);
            return 0;
        }
        return _replace_from_end_core( head ,  oldValue ,  newValue ,  start ,  end ,  k);
       }
static int _replace_all_core(LList* head , int oldValue , int newValue , int start , int end ,int k){//Replaces all occurences of oldValue with newValue as per parameters.Returns total number of numbers replaced.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return -1;
        }
        if(head->length == 0){
            return 0;
        }
        if(start < 0 ){
        start = head->length +1+start;
        }
        if(end < 0){
            end = head->length +1+end;
        }
        if(start>end || start<=0 || end<=0 || start > head->length || end > head->length){
            fprintf(stderr,"\x1b[31mValueError : In function =>'RemoveAll'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",head->length,start,end);
            return 0;
        }

        int count =0;
        int position = 1;
        Node * HEAD=head->next;
        while(HEAD != NULL && k>0 && position<=end){
            if(HEAD->data == oldValue && position>=start ){
                k--;
                HEAD->data = newValue;
                count++;
            }
            HEAD=HEAD->next;
            position++;
        }
        return count;
}
      static int ReplaceAll(LList* head , int oldValue , int newValue ){//Replaces all occurences of oldValue with newValue as per parameters.Returns total number of numbers replaced.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return -1;
        }
        return _replace_all_core(head , oldValue ,newValue,1,head->length,head->length+1);
       }
      static int ReplaceAll_in_range(LList* head , int oldValue , int newValue , int start , int end ){//Replaces all occurences of oldValue with newValue as per parameters.Returns total number of numbers replaced.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return -1;
        }  
        if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }     
        return _replace_all_core(head ,oldValue,newValue,start,end,head->length+1);
       }
      static int Replace_K(LList* head , int oldValue , int newValue ,int k){//Replaces all occurences of oldValue with newValue as per parameters.Returns total number of numbers replaced.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return -1;
        }
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-replacements of %d to %d;\n\x1b[0m",__func__,k,oldValue,newValue);
            exit(1);
            return 0;
        }
        return _replace_all_core(head ,oldValue,newValue,1,head->length,k);
       }
      static int Replace_K_in_range(LList* head , int oldValue , int newValue , int k,int start , int end ){//Replaces all occurences of oldValue with newValue as per parameters.Returns total number of numbers replaced.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return -1;
        }
        if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for \n\t%d-replacements of %d;\n\x1b[0m",__func__,k,oldValue);
            exit(1);
            return 0;
        }
        return _replace_all_core(head ,oldValue,newValue,start,end,k); 
       }
static int _replace_all_from_end_core(LList* head , int oldValue , int newValue , int start , int end , int k){//Replaces all occurences of oldValue with newValue as per parameters.Returns total number of numbers replaced.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(head->length == 0){
        return 0;
    }
    if(start < 0 ){
        start = head->length +1+start;
    }
    if(end < 0){
        end = head->length +1+end;
    }
    if(start>end || start<=0 || end<=0 || start > head->length || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'Replace_K_from_end'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",head->length,start,end);
        return 0;
    }
        LList* range = _find_all_core(head , oldValue , start , end, 0);
        if(range->length < k){
            return 0;
        }
        while(range->length > k){
            Pop(range , 1);
        }
        Node* Traverse = head->next;
        int position = 1;
        while(range->length != 0){
            if(position == range->next->data){
                Traverse->data = newValue;
                Pop(range , 1);
            }
            Traverse = Traverse->next;
            position++;
        }
        Delete(&range);
        return 1;
}
      static int Replace_K_from_end(LList* head , int oldValue , int newValue , int k ){//Replaces all occurences of oldValue with newValue as per parameters.Returns total number of numbers replaced.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return -1;
        }
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for %d-replacements from end of %d to %d;\n\x1b[0m",__func__,k,oldValue,newValue);
            exit(1);
            return 0;
        }
        return _replace_all_from_end_core( head ,  oldValue ,  newValue ,  1 ,  head->length ,  k);
       }
      static int Replace_K_from_end_in_range(LList* head , int oldValue , int newValue , int k , int start , int end){//Replaces all occurences of oldValue with newValue as per parameters.Returns total number of numbers replaced.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return -1;
        }
        if(start < 0 ){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end;
    }
    if(start > end || start<=0 || start > head->length || end<=0 || end > head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : positional arguments are => 1<=start<=end<=%d ; But requested positional arguments are\n\tstart : %d\n\tend : %d\n\x1b[0m",__func__,head->length,start,end);
        exit(1);
        return 0;
    }
        if(k <= 0){
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted k values are positive; But requested for %d-replacements from end of %d to %d;\n\x1b[90m'NULL'\n\x1b[0m",__func__,k,oldValue,newValue);
            exit(1);
            return 0;
        }
        return _replace_all_from_end_core( head ,  oldValue ,  newValue ,  start ,  end ,  k);
       }
int* __EA__(LList* head , int position ){ //Returns a pointer to node containing element with required position.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return NULL;
        }
        if(position < 0){
            position = (head->length +1+position);
        }
        if(position<=0 || position>head->length){
                if(head->length>0)
                fprintf(stderr,"\x1b[31mKeyError : In function =>'%s'; position out of bounds : Accepted : 1<=position<=%d;But requested positional access : %d\n\x1b[0m",__func__,head->length,position);
                else
                
                fprintf(stderr,"\x1b[31mKeyError : In function =>'%s'; LList is empty but requested positional access : %d\n\x1b[0m",__func__,position);
                exit(1);
        }
        Node* HEAD=head->next;
        int i=1;
        while(i<position){
            HEAD=HEAD->next;
            i++;
        }
        return &(HEAD->data);
}
static LList* Copy(LList* head){//Takes a pointer to LList variable and returns a pointer to new LList which is a copy of LList given as argument.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return NULL;
    }
    LList* HEAD_C=malloc(sizeof(LList));
    HEAD_C=Initialize();
    Node* HEAD=head->next;
    while(HEAD != NULL){
        Append(HEAD_C,HEAD->data);
        HEAD=HEAD->next;
    }
    return HEAD_C;

}
static LList *Slice(LList *head,int start,int end,int step){//Return a new LList which is a slice of LList as per given values without mutating original LList.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return NULL;
    }
    if(step == 0){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; step cannot be 0\n\x1b[0m",__func__);
        return NULL;
    }
    if(start<0){
        start = head->length +1+start;
    }
    if(end<0){
        end = head->length +1+end; 
    }
    if(step>0 && start > end || end<0 && start<end){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; LList is slicable for [%d:%d:>0(positive)] or [%d:%d:<0(negative)]: But requested [%d:%d:%d]\n\x1b[0m",__func__,1,head->length,head->length,1,start,end,step);
        return NULL;
    }
    if(start<=0 || start>head->length || end <= 0 || end>head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; LList is slicable for [%d:%d:>0(positive)] : But requested [%d:%d:%d]\n\x1b[0m",__func__,1,head->length,start,end,step);
        return NULL;
    }
    // int i=1;
    if(step > 0){
    int i = 1;
    Node* HEAD=head->next;
    while(i<start){
        HEAD = HEAD->next;
        i++;
    }
    LList * New=Initialize();
    while(HEAD!=NULL && i<=end){
        // if(((i-start+step)%step)==0 && ((i-start+step)/step)>=1 ){
        //     Append(New,HEAD->data);
        // }
        // i++;
        Append(New , HEAD->data);
        i+=step;
        int jump=step;
        while(HEAD != NULL && jump>0 ){
            HEAD=HEAD->next;
            jump--;
        }
    }
    return New;
}else{
    int i = 1;
    step = -1*(step);
    end+=(start-end)%step;
    Node* HEAD=head->next;
    while(i<end){
        HEAD = HEAD->next;
        i++;
    }
    LList * New=Initialize();
    while(HEAD!=NULL && i<=start){
        // if(((i-start+step)%step)==0 && ((i-start+step)/step)>=1 ){
        //     Append(New,HEAD->data);
        // }
        // i++;
        Insert(New , HEAD->data,1);
        i+=step;
        int jump=step;
        while(HEAD != NULL && jump>0 ){
            HEAD=HEAD->next;
            jump--;
        }
    }
    return New;
}
}
static int Swap(LList* head,int position1,int position2){//Swaps the data of elements of given LList with positions ==> position1,position2.Returns 1 if swap success else returns 0.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(position1 < 0){
            position1 = head->length +1+position1 ;
    }
    if(position2 <0){
        position2 = head->length +1+position2;
    }
    if(position1<=0 || position1>head->length || position2<=0 || position2>head->length){
       fprintf(stderr,"\x1b[31mKeyError : In function =>'%s' ; Can swap elements with positional values in range 1<=position<=%d; But requested to swap for %d,%d\n\x1b[0m",__func__,head->length,position1,position2);
       exit(1);
       return 0;
    }
    int i=1;
    Node * temp1=head->next;
    Node* temp2=head->next;
    int max=position1>position2?position1:position2;
    while(i<max){
        if(i<position1){
            temp1=temp1->next;
        }
        if(i<position2){
            temp2=temp2->next;
        }
        i++;
    }
    int temp=temp1->data;
    temp1->data=temp2->data;
    temp2->data=temp;
    return 1;
}
static int _max_core_qselect(LList* head , int k , int flag){//flag=1 for k_max flag=0 for k_min.
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(head->length<k){
        fprintf(stderr,"\x1b[33mWarning : In function =>'k_max'; LList length is : %d But requested for '%d'-maximum\n\x1b[0m",Len(head),k);
    }
    if(head->length == 1){
        return head->next->data;
    }
    int *p=(int*)malloc((head->length)*sizeof(int));
    Node* HEAD=head->next;
    int i=0;
    while(HEAD != NULL){
        p[i]=HEAD->data;
        HEAD=HEAD->next;
        i++;
    }
    quickselect(p,0,(head->length -1),k,flag);
    int v= p[(flag)*(head->length - k) + (!flag)*(k-1)];
    free(p);
    return v;

}
static int _max_core(LList* head,int k,int flag){
    if(head == NULL){
        
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        exit(1);
        return -1;
    }
    if(head->length == 0){
        fprintf(stderr,"\x1b[31mValueError : In function =>'k_max'; LList is empty ; requested %d - max \n\x1b[0m",k);
        return -1;
    }
    if(head->length<k){
        fprintf(stderr,"\x1b[33mWarning : In function =>'k_max'; LList length is : %d But requested for '%d'-maximum\n\x1b[0m",Len(head),k);
    }
    if(head->length == 1){
        return head->next->data;
    }
    LList* heap=Initialize();
    Node* traverse_heap=heap->next;
    Node* HEAD=head->next;
    // Append(heap,(HEAD->data));
    // k--;
    // HEAD=HEAD->next;
    while(HEAD != NULL){
        int i=1;
        traverse_heap=heap->next;
        while((traverse_heap != NULL) && ((HEAD->data) > (traverse_heap->data))){ 
            traverse_heap=traverse_heap->next;
            i++;
        }
        Insert(heap,HEAD->data,i);
        if(heap->length > k){
            Pop(heap,1);
        }
        HEAD=HEAD->next;

    }
    int k_maxi_val=heap->next->data;
    int k_mini_val=heap->last->data;
    Delete(&heap);
    if(flag)
    return k_maxi_val;
    else
    return k_mini_val;


}
      static int Max(LList* head){//Returns the maximum value of LList.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return -1;
        }
        return _max_core_qselect(head,1,1);
       }
      static int Min(LList* head){//Returns the minnimum value of LList.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return -1;
        }
        return _max_core_qselect(head,1,0);
       }
      static int kth_Max(LList* head,int k){//Returns the kth maximum value of LList.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return -1;
        }
        if(head->length < k){
            return _max_core(head , k,1);
        }
        return _max_core_qselect(head,k,1);
       }
      static int kth_Min(LList* head,int k){//Returns the kth minimum value of LList.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return -1;
        }
        if(head->length < k){
            return _max_core(head,k,0);
        }
            return _max_core_qselect(head,k,0);
        }
static LList* Cut(LList * head,int front,int back,int mode){//Cuts the portion of LList starting at front and ending at back.Returns the cut LList as a new LList if mode ==1 else returns NULL.For wrong input returns NULL.If head is invalid or any other error occurs then terminates the program.   
        if(head == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s' ; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
            exit(1);
            return NULL;
        }
        if(front < 0){
            front = head->length +1+front ;
        }
        if(back<0){
            back = head->length +1+back;
        }
        if(front > back || front <=0 || front>head->length|| back<=0 ||back>head->length){
            
            fprintf(stderr,"\x1b[31mKeyError : In function =>'%s' ; Can cut LList if 1<=front,back<=%d and front>=back; But requested front : %d , back : %d\n\x1b[0m",__func__,head->length,front,back);
            exit(1);
            return NULL;
        }
        if(mode != 1 && mode != 0){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'%s' ; Accepted : values of mode => 0,1; But requested : %d\n\x1b[0m",__func__,mode);
            exit(1);
            return NULL;
        }
        //1 2 3 4 5
        Node * pre_front=head->next;
        Node* f;
        Node * exact_back=head->next;
        int i=1;
        while(i<back){
            if(i<front-1){
                pre_front=pre_front->next;
            }
            exact_back=exact_back->next;
            i++;
        }
        if(front==1){
            head->next=exact_back->next;
            f=pre_front;
        }else{
            f=pre_front->next;
            pre_front->next=exact_back->next;
        }
        if(back==head->length){
            if(front==1){
                head->last=NULL;
            }else{
                head->last=pre_front;
            }
        }
        (head->length)-=(back-front +1);

        if(mode==1){
            LList* new =Initialize();
            new->length+=(back-front +1);
            new->last=exact_back;
            new->next=f;
            exact_back->next=NULL;
            return new;
        }
        else
        {while(f != exact_back){
            Node * temp=f;
            f=f->next;
            free(temp);
        }
        free(exact_back);
    return NULL;}

}
static int Compare(LList* arg1 , LList* arg2){//Compares two LLists similar to comparing to works to fit in a dictionary.If head is invalid or any other error occurs then terminates the program.
    if(arg1 == NULL || arg2 == NULL){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        if(arg1 == NULL){
            printf("Argument-1 is \x1b[90m'NULL'\n\x1b[0m");
        }else{
            printf("Argument-2 is \x1b[90m'NULL'\n\x1b[0m");
        
        }
        exit(1);
        return -1;
    }
    if(Len(arg1) == 0){
        return -1;
    }
    if(Len(arg2) == 0){
        return 1;
    }
    Node * Traverse_arg1 = arg1->next;
    Node * Traverse_arg2 = arg2->next;
    while(Traverse_arg1 != NULL && Traverse_arg2 != NULL){
        if(Traverse_arg1->data > Traverse_arg2->data){
            return 1;
        }
        if(Traverse_arg1->data < Traverse_arg2->data){
            return -1;
        }
        Traverse_arg1 = Traverse_arg1->next;
        Traverse_arg2 = Traverse_arg2->next;
    }
    if(Traverse_arg1 == NULL && Traverse_arg2 != NULL){
        return -1;
    }
    if(Traverse_arg1 != NULL && Traverse_arg2 == NULL){
        return 1;
    }
    if(Traverse_arg1 == NULL && Traverse_arg2 == NULL){
        return 0;
    }

}
static void Join(LList* head , LList * tail , int position_of_joining_in_head){//Joins two list2 to list1 completely i.e second list does not exist after joining.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL || tail == NULL){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        if(head == NULL){
            printf("Argument-1 is \x1b[90m'NULL'\n\x1b[0m");
        }else{
            printf("Argument-2 is \x1b[90m'NULL'\n\x1b[0m");
        
        }
        exit(1);
        return;
    }
    if(position_of_joining_in_head < 0){
        position_of_joining_in_head = head->length +1+ position_of_joining_in_head ;
    }
    if(position_of_joining_in_head <=0 || position_of_joining_in_head> head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted position for joining is 1<=position<=%d ; But requested for : %d\n\x1b[0m",__func__,head->length,position_of_joining_in_head);
        return;
    }
    Node* HEAD = head->next;
    Node* connect_end = NULL;
    int position=1;
    while(position != position_of_joining_in_head){
        HEAD = HEAD->next;
        position++;
    }
    connect_end = HEAD->next;
    HEAD->next = tail->next;
    tail->last->next = connect_end;
    if(position_of_joining_in_head == head->length){
        head->last = tail->last;
    }
    head->length += tail->length;
    tail->next = NULL;
    tail->length = 0;
    tail->last = NULL;
}
static void Extend(LList* head , LList* tail , int position_of_extension_in_head){//Extends list2 to list1 and the list2 remais as it was => no mutation take place.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL || tail == NULL){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m",__func__);
        if(head == NULL){
            printf("Argument-1 is \x1b[90m'NULL'\n\x1b[0m");
        }else{
            printf("Argument-2 is \x1b[90m'NULL'\n\x1b[0m");
        }
        return;
    }
    if(position_of_extension_in_head < 0){
        position_of_extension_in_head = head->length +1+ position_of_extension_in_head ;
    }
    if(position_of_extension_in_head <=0 || position_of_extension_in_head> head->length){
        fprintf(stderr,"\x1b[31mValueError : In function =>'%s'; Accepted position for extension is 1<=position<=%d ; But requested for : %d\n\x1b[0m",__func__,head->length,position_of_extension_in_head);
        return;
    }
    int t = head->length;
    Node* Traverse_head = head->next;
    Node* Traverse_tail = tail->next;
    int position = 1;
    while(position != position_of_extension_in_head){
        Traverse_head = Traverse_head->next;
        position++;
    }
    Node* temp = head->last;
    head->last = Traverse_head;
    Traverse_head = Traverse_head->next;
    head->last->next = NULL;
    while(Traverse_tail != NULL){
        Append(head , Traverse_tail->data);
        Traverse_tail = Traverse_tail->next;
    }
    head->last->next = Traverse_head;
    if(position_of_extension_in_head != t)
    {head->last = temp;}
}

static Node* Iter_start(LList* head){//Returns a Node pointer pointiing to the dummy Node.If head is invalid or any other error occurs then terminates the program.
    if(head == NULL){
        fprintf(stderr,"\x1b[31mValueError : In function =>'Iter.start'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m");
        exit(1);
        return NULL;
    }
    Node* dummy = malloc(sizeof(Node));
    dummy->next = head->next;
    return dummy;
}
static Node* Iter_next(LList* head ,Node* Element){//Returns a Node pointer to the next node of a given node.If head is invalid or any other error occurs then terminates the program.
        if(head == NULL){
            fprintf(stderr,"\x1b[31mValueError : In function =>'Iter.next'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m");
            exit(1);
            return NULL;
        }
        if(Element == NULL){ 
            fprintf(stderr,"\x1b[31mValueError : In function =>'Iter.next'; Accepted : Iter ; But given =>\x1b[90m'NULL'\n\x1b[0m");
            exit(1);
            return NULL;
        } 
        if(Element->next == head->next){
            Node* temp = Element->next;
            free(Element);
            return temp;
        }
    return Element->next;
}
static int Iter_data(Node* Element){//Returns the data of next node to given node.If head is invalid or any other error occurs then terminates the program.
        if(Element == NULL || Element->next == NULL){
            fprintf(stderr,"\x1b[31mValueError : In function =>'Iter.data'; Accepted : Iter ; But given =>\x1b[90m'NULL'\n\x1b[0m");
            exit(1);
            return -1;
        }
    return Element->next->data;
}
static void Iter_set_data(Node* Element , int value){//sets the data of next node to given node to value.If head is invalid or any other error occurs then terminates the program.
    if(Element == NULL || Element->next == NULL){
            
            fprintf(stderr,"\x1b[31mValueError : In function =>'Iter.set_data'; Accepted : iter ; But given =>\x1b[90m'NULL'\n\x1b[0m");
            exit(1);
            return ;
    }
    Element->next->data = value;
    return;
}
static void Iter_delete(LList* head , Node* Element){//Deletes the next Node.If head is invalid or any other error occurs then terminates the program. 
    if(head == NULL){
        fprintf(stderr,"\x1b[31mValueError : In function =>'Iter.delete'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m");
        exit(1);
        return ;
    }
    if(Element == NULL || Element->next == NULL){
            fprintf(stderr,"\x1b[31mValueError : In function =>'Iter.delete'; Accepted : Iter ; But given =>\x1b[90m'NULL'\n\x1b[0m");
            exit(1);
            return ;
    }

    if(Element->next->next == NULL){
        if(head->next != Element->next){
            head->last = Element;
        }
        else{
            head->last = NULL;
        }
    }

    if(head->next == Element->next){
        Node* temp = Element->next;
        Element->next = Element->next->next;
        head->next=Element->next;
        free(temp);
        head->length--;
        return;
    }else{
        Node* temp = Element->next;
        Element->next = Element->next->next;
        free(temp);
        head->length--;
        return;
    }
}
static int Iter_is_incomplete(Node* Element){//Returns 1 if Traversal is incomplete.Returns 0 if traversal is complete.If head is invalid or any other error occurs then terminates the program.
    if(Element == NULL || Element->next == NULL){
        return 0;
    }else{ 
        return 1;
    }
}
static Node* Iter_stop(LList* head , Node* Element){//Makes sure of no memory leak by freeing the dummy Node.
    if(head == NULL){
        fprintf(stderr,"\x1b[31mValueError : In function =>'Iter.stop'; Accepted : LList* ; But given =>\x1b[90m'NULL'\n\x1b[0m");
        exit(1);
        return NULL;
    }
    if(Element == NULL){ 
        fprintf(stderr,"\x1b[31mValueError : In function =>'Iter.next'; Accepted : Iter ; But given =>\x1b[90m'NULL'\n\x1b[0m");
        exit(1);
        return NULL;
    }
    if(head->next == Element->next){
        free(Element);
    }
    return NULL;
}

typedef struct iterate{
Node*(*start)(LList* head);
Node* (*next)(LList* head ,Node* Element);
int (*data)(Node* Element);
void (*set_data)( Node* Element , int value);
void (*delete)(LList* head , Node* Element);
int (*is_incomplete)(Node* Element);
Node* (*stop)(LList* head , Node* Element);
}iterate;


typedef struct funcops{
LList* (*Initialize)(void);
void (*Append)(LList* , int );
int (*Insert)(LList* , int , int);
void (*Print)(LList*);
int (*Pop)(LList *,int );
int (*Len)(LList * );
void (*Reverse)(LList * );
void (*std_Reverse)(LList * );
void (*recurse_Reverse)(LList*);
void (*Reverse_sublist)(LList * head , int start , int end);
void (*Delete)(LList** );
int (*Find)(LList* ,int );
int (*Find_in_range)(LList* ,int ,int ,int );
int (*Find_kth)(LList* ,int ,int );
int (*Find_kth_in_range)(LList* ,int ,int ,int ,int );
int (*Find_last)(LList* ,int );
int (*Find_last_in_range)(LList* ,int ,int ,int );
LList* (*FindAll)(LList* head , int Target);
LList* (*FindAll_in_range)(LList* head , int Target , int start , int end );
int (*Count)(LList* ,int );
int (*Count_in_range)(LList* ,int ,int ,int );
int (*Remove)(LList*  , int );
int (*Remove_in_range)(LList* , int , int , int );
int (*Remove_kth)(LList* , int , int );
int (*Remove_kth_in_range)(LList* , int , int , int ,int );
int (*Remove_last)(LList* , int );
int (*Remove_last_in_range)(LList* , int , int , int );
int (*Remove_kth_from_end)(LList* head , int value , int k);
int (*Remove_kth_from_end_in_range)(LList* head , int value , int k , int start , int end);
int (*RemoveAll)(LList* head , int value);
int (*RemoveAll_in_range)(LList* head , int value , int start , int end);
int (*Remove_K)(LList* head , int value , int k);
int (*Remove_K_in_range)(LList* head , int value , int k ,int start , int end );
int (*Remove_K_from_end)(LList* head , int value , int k);
int (*Remove_K_from_end_in_range)(LList* head , int value , int k , int start , int end);
void (*Clear)(LList * );
void (*RemoveDuplictes)(LList* );
void (*Sort)(LList *  , int );
void (*MergeSort)(LList*  , int );
void (*my_MergeSort)(LList*  , int );
int (*Replace)(LList* head , int oldValue , int newValue);
int (*Replace_in_range)(LList* head , int oldValue , int newValue , int start ,int end);
int (*Replace_kth)(LList* head , int oldValue , int newValue , int k);
int (*Replace_kth_in_range)(LList* head , int oldValue , int newValue ,int k , int start ,int end);
int (*Replace_last)(LList* head ,int oldValue,int newValue);
int (*Replace_last_in_range)(LList* head , int oldValue , int newValue ,int start , int end);
int (*Replace_kth_from_end)(LList* head , int oldValue , int newValue , int k);
int (*Replace_kth_from_end_in_range)(LList* head , int oldValue , int newValue , int k,int start , int end );
int (*ReplaceAll)(LList* head , int oldValue , int newValue );
int (*ReplaceAll_in_range)(LList* head , int oldValue , int newValue , int start , int end );
int (*Replace_K)(LList* head , int oldValue , int newValue ,int k);
int (*Replace_K_in_range)(LList* head , int oldValue , int newValue , int k,int start , int end );
int (*Replace_K_from_end)(LList* head , int oldValue , int newValue , int k );
int (*Replace_K_from_end_in_range)(LList* head , int oldValue , int newValue , int k , int start , int end);
LList* (*Copy)(LList* );
LList *(*Slice)(LList *,int ,int ,int );
int (*Swap)(LList* ,int ,int );
int (*Max)(LList* );
int (*Min)(LList* );
int (*kth_Max)(LList* ,int );
int (*kth_Min)(LList* ,int );
LList* (*Cut)(LList * ,int ,int ,int );
int (*Compare)(LList* arg1 , LList* arg2);
void (*Join)(LList* head , LList * tail , int position_of_joining_in_head);
void (*Extend)(LList* head , LList* tail , int position_of_extension_in_head);
iterate Iter;
}funcops;

const funcops list = {
    .Print = Print,
    .Insert=Insert,
    .Initialize = Initialize,
    .Append = Append,
    .Pop=Pop,
    .Len=Len,
    .Reverse = Reverse,
    .std_Reverse=std_Reverse,
    .recurse_Reverse=recurse_Reverse,
    .Reverse_sublist=Reverse_sublist,
    .Find=Find,
    .Find_in_range=Find_in_range,
    .Find_kth=Find_kth,
    .Find_kth_in_range=Find_kth_in_range,
    .Find_last=Find_last,
    .Find_last_in_range=Find_last_in_range,
    .FindAll=FindAll,
    .FindAll_in_range=FindAll_in_range,
    .Count=Count,
    .Count_in_range=Count_in_range,
    .Remove=Remove,
    .Remove_in_range=Remove_in_range,
    .Remove_kth=Remove_kth,
    .Remove_kth_in_range=Remove_kth_in_range,
    .Remove_last=Remove_last,
    .Remove_last_in_range=Remove_last_in_range,
    .Remove_kth_from_end=Remove_kth_from_end,
    .Remove_kth_from_end_in_range=Remove_kth_from_end_in_range,
    .RemoveAll=RemoveAll,
    .RemoveAll_in_range=RemoveAll_in_range,
    .Remove_K=Remove_K,
    .Remove_K_in_range=Remove_K_in_range,
    .Remove_K_from_end=Remove_K_from_end,
    .Remove_K_from_end_in_range=Remove_K_from_end_in_range,
    .Delete=Delete,
    .Clear=Clear, 
    .RemoveDuplictes=RemoveDuplictes,
    .Sort=Sort,
    .MergeSort=MergeSort,
    .my_MergeSort=my_MergeSort,
    .Replace=Replace,
    .Replace_in_range=Replace_in_range,
    .Replace_kth=Replace_kth,
    .Replace_kth_in_range=Replace_kth_in_range,
    .Replace_last=Replace_last,
    .Replace_last_in_range=Replace_last_in_range,
    .Replace_kth_from_end=Replace_kth_from_end,
    .Replace_kth_from_end_in_range=Replace_kth_from_end_in_range,
    .ReplaceAll=ReplaceAll,
    .ReplaceAll_in_range=ReplaceAll_in_range,
    .Replace_K=Replace_K,
    .Replace_K_in_range=Replace_K_in_range,
    .Replace_K_from_end=Replace_K_from_end,
    .Replace_K_from_end_in_range=Replace_K_from_end_in_range,
    .Copy=Copy,
    .Slice=Slice,
    .Swap=Swap,
    .Max=Max,
    .Min=Min,
    .kth_Max=kth_Max,
    .kth_Min=kth_Min,
    .Cut=Cut,
    .Compare=Compare,
    .Join=Join,
    .Extend=Extend,
    .Iter.start = Iter_start,
    .Iter.next = Iter_next,
    .Iter.data = Iter_data,
    .Iter.set_data=Iter_set_data,
    .Iter.delete=Iter_delete,
    .Iter.is_incomplete=Iter_is_incomplete,
    .Iter.stop=Iter_stop,
};

