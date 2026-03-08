#ifndef LIST_H
#define LIST_H

#define ListElement(list, position) (*(__EA__((list) , (position))))

typedef struct Node Node;
typedef struct LList LList;

typedef LList* List;
typedef Node* Iter;

typedef struct iterate{
Iter (*start)(List list);
Iter (*next)(List list ,Iter Element);
int (*data)(Iter Element);
void (*set_data)( Iter Element , int value);
void (*delete)(List list , Iter Element);
int (*is_incomplete)(Iter Element);
Iter (*stop)(List list , Iter Element);
}iterate;

typedef struct funcops {

    List (*Initialize)(void);
    void (*Append)(List list, int value);
    int  (*Insert)(List list, int number, int position);
    void (*Print)(List list);
    int  (*Pop)(List list, int position);
    int  (*Len)(List list);
    void (*Reverse)(List list);
    void (*std_Reverse)(List list);
    void (*recurse_Reverse)(List list);
    void (*Reverse_sublist)(List list, int start, int end);
    void (*Delete)(List* list);
    
    int  (*Find)(List list, int Target);
    int  (*Find_in_range)(List list, int Target, int start, int end);
    int  (*Find_kth)(List list, int Target, int k);
    int  (*Find_kth_in_range)(List list, int Target, int k, int start, int end);
    int  (*Find_last)(List list, int Target);
    int  (*Find_last_in_range)(List list, int Target, int start, int end);

    List (*FindAll)(List list, int Target);
    List (*FindAll_in_range)(List list, int Target, int start, int end);

    int  (*Count)(List list, int value);
    int  (*Count_in_range)(List list, int value, int start, int end);

    int  (*Remove)(List list, int value);
    int  (*Remove_in_range)(List list, int value, int start, int end);
    int  (*Remove_kth)(List list, int value, int k);
    int  (*Remove_kth_in_range)(List list, int value, int k, int start, int end);
    int  (*Remove_last)(List list, int value);
    int  (*Remove_last_in_range)(List list, int value, int start, int end);

    int  (*Remove_kth_from_end)(List list, int value, int k);
    int  (*Remove_kth_from_end_in_range)(List list, int value, int k , int start, int end);

    int  (*RemoveAll)(List list, int value);
    int  (*RemoveAll_in_range)(List list, int value, int start, int end);

    int  (*Remove_K)(List list, int value, int k);
    int  (*Remove_K_in_range)(List list, int value, int k, int start, int end);
    int  (*Remove_K_from_end)(List list, int value, int k);
    int  (*Remove_K_from_end_in_range)(List list, int value, int k, int start, int end);

    void (*Clear)(List list);
    void (*RemoveDuplictes)(List list);

    void (*Sort)(List list, int mode);
    void (*MergeSort)(List list, int mode);
    void (*my_MergeSort)(List list, int mode);

    int  (*Replace)(List list, int oldValue, int newValue);
    int  (*Replace_in_range)(List list, int oldValue, int newValue, int start, int end);
    int  (*Replace_kth)(List list, int oldValue, int newValue, int k);
    int  (*Replace_kth_in_range)(List list, int oldValue, int newValue, int k, int start, int end);
    int  (*Replace_last)(List list, int oldValue, int newValue);
    int  (*Replace_last_in_range)(List list, int oldValue, int newValue, int start, int end);

    int  (*Replace_kth_from_end)(List list, int oldValue, int newValue, int k);
    int  (*Replace_kth_from_end_in_range)(List list, int oldValue, int newValue, int k, int start, int end);

    int  (*ReplaceAll)(List list, int oldValue, int newValue);
    int  (*ReplaceAll_in_range)(List list, int oldValue, int newValue, int start, int end);

    int  (*Replace_K)(List list, int oldValue, int newValue, int k);
    int  (*Replace_K_in_range)(List list, int oldValue, int newValue, int k , int start, int end);

    int  (*Replace_K_from_end)(List list, int oldValue, int newValue, int k);
    int  (*Replace_K_from_end_in_range)(List list, int oldValue, int newValue, int k , int start, int end);

    List (*Copy)(List list);
    List (*Slice)(List list, int start, int end, int step);
    int  (*Swap)(List list, int position1, int position2);
    int  (*Max)(List list);
    int  (*Min)(List list);
    int  (*kth_Max)(List list, int k);
    int  (*kth_Min)(List list, int k);
    List (*Cut)(List list, int front, int back, int mode);

    int  (*Compare)(List list1, List list2);
    void (*Join)(List list1, List list2, int position_of_joining_in_list1);
    void (*Extend)(List list1, List list2, int position_of_extension_in_list1);
    iterate Iter;

} funcops;

extern const funcops list;

int* __EA__(List list , int position );

#endif