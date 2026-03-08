# LinkedList Library in C
An oops style and encapulated and abstracted Linked List library implementation driven to mimic python's list behaviour in pure C.
<br>
This project explores how low-level libraries can provide clean methods and abstraction even without object-oriented programming. The library hides it's internal data structures and exposes operations through a structured interface.
<br>
# Motivation
While learning C , I was amazed by the idea of libraries. I wanted to create my own library one day with all useful functions that had to be written everytime otherwise. for example:- ceil , floor etc.... So to take a step forward in the direction of that goal I tried to make a small scale library as a trial. As i was fairly new to the Linked List idea , I thought why not make a Library on this to futhur improve my intuition and knowledge.
<br>
# Features
- Encapsulated data structure and abstracted methods.<br>
- Clean oops like mechanisms<br>
- Modular header and implementation files<br>
- Efficient functions with negative indexing and error handling <br>
- array like assignment possible<br>
- Iterator support for traversal<br>
## Example usage
<pre>
#include &ltstdio.h&gt <br>
#include &ltLinkedList.h&gt <br>
int main(){<br>
  List mylist = list.Initialize();<br>
  for(int i=1;i<=20;i++){<br>
    list.Append(mylist , i);<br>
    list.Append(mylist , i+1);<br>
  }<br>
  printf("Before removing duplicates : ");<br>
  list.Print(mylist);<br>
  list.RemoveDuplictes(mylist);<br>
<br>
  printf("After removing duplicates : ");<br>
  list.Print(mylist);<br>
  printf("Length of List after removing duplicates is %d\n",list.Len(mylist));<br>
<br>
  Iter Traverse = list.Iter.start(mylist);<br>
  while(list.Iter.is_incomplete(Traverse)){<br>
        if(list.Iter.data(Traverse) % 2 == 0){<br>
            list.Iter.delete(mylist , Traverse);<br>
        }else{<br>
            Traverse = list.Iter.next(mylist , Traverse);<br>
        }<br>
  }<br>
  Traverse = list.Iter.stop(mylist , Traverse);<br>
  <br>
  printf("After Traversing mylist : ");<br>
  list.Print(mylist);
  return 0;
}
</pre>

## Process to install project in your machine
<pre>
- Copy and Paste the header (.h) file in root_dir\MinGW\include
- make directories as follows
   => some_dir\Library\lib\
- Copy and Paste the libLinkedList.a file in that diectory
- write a sample code in any directory and while compliling use the following command
    => gcc sample_code.c -Lsome_dir/Library/lib -lLinkedList -o a
- run the code using
    => ./a
</pre>
## Project structure (Ideally)
<pre>
Windows-SSD(C:)
├── MinGW/
│   └── include/
|         └──LinkedList.h
│
├── Library/
│     └── lib/
|          └──libLinkedList.a
│
├──MyFolder/
│      └── sample_code.c
<br>compile command : gcc sample_code.c -LC:/Library/lib -lLinkedList -o a
</pre>
<pre>
# Alternate process
If the above process does not work or the windows policy blocks exe fike from running then :-
-Make a directory project
-Make directories => include,lib
-make a file sample_code.c
-write your code
-compile with the following command
    => gcc sample_code.c -Iinclude -Llib -lLinkedList -o a
-run exe file using
    => ./a
</pre>
## project structure (Alternate)
<pre>
project/
│
├── include/
│   └── LinkedList.h
│
├── lib/
│   └── libLinkedList.a
│
└── sample_code.c
</pre>
