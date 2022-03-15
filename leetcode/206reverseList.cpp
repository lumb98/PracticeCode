#include <iostream>
#include <vector>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode* temp1=nullptr;
        ListNode* temp2;

        //一个节点有两个有用的变量，分别是自己的地址和下一个的地址，储存这两个地址即可，前一个地址给temp1，下一个地址给temp2，把前一个地址赋给下一个地址，当前地址赋给temp1作为下次迭代的上一个地址，就完成了反转，再把下一个地址赋给当前地址，完成链表的迭代。
        while(head->next!=nullptr){
            temp2=head->next;
            head->next=temp1;
            temp1=head;
            head=temp2;
        }
        //temp2=head->next;
        head->next=temp1;
        return head;
    }

// private:
//     ListNode* temp1,temp2;
};