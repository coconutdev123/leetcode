/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head;
    if(list1 == nullptr){
        return list2;
    }
    if(list2==nullptr){
        return list1;
    }

    if(list1->val <= list2->val){
        head = list1;
        head->next = mergeTwoLists(list1->next, list2);
    }
    else{
        head = list2;
        head->next = mergeTwoLists(list1, list2->next);
    }
    return head;
}
