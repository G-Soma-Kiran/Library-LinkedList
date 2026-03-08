# LinkedList Library in C
An oops style and encapulated and abstracted Linked List library implementation driven to mimic pythons list behaviour in pure C.
<br>
This project explores how low-level libraries can provide clean methods and abstraction even without object-oriented pprogramming. The library hides its internal data structures and exposes operations through a structured interface.
<br>
# Motivation
While learning C , I was amazed by the idea of libraries. I wanted to create my own library one day with all useful functions that had to be written everytime otherwise. for example:- ceil , floor etc.... So to tk=ake a step forward in the diraction of that goal I tried to make a samll scale library as a trial. As i was fairly new to the Linked List idea , I thought why not make a Library on this to futhur improve my intuition and knowledge.
<br>
# Features
- Encapsulated data structure and abstracted methods.<br>
- Clean oops like mechanisms<br>
- Modular header and implementation files<br>
- Efficient functions with negative indexing and error handling <br>
- array like assignment possible<br>
- Iterator support for traversal<br>
## Example usage
#include<stdio.h>
#include<LinkedList.h>
int main(){
  List mylist = list.Initialize();
  for(int i=1;i<=100;i++){
    list.Append(mylist , i);
    list.Append(mylist , i+1);
  }
  printf("Before removing duplicates : ");
  list.Print(mylist);
  list.RemoveDuplictes(mylist);

  printf("After removing duplicates : ");
  list.Print(mylist);
  printf("Length of List after removing duplicates is %d\n",list.Len(mylist));

  Iter Traverse = list.Iter.start(mylist);
  while(list.Iter.is_incomplete(Traverse)){
        if(list.Iter.data(Traverse) % 2 == 0){
            list.Iter.delete(mylist , Traverse);
        }else{
            Traverse = list.Iter.next(mylist , Traverse);
        }
  }
  Traverse = list.Iter.stop(mylist , Traverse);
  
  printf("After Traversing mylist : ");
  list.Print(mylist);
  return 0;
}

