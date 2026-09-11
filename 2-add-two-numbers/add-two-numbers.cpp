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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);          // 哑节点，方便构建结果链表
        ListNode* current = &dummy;
        int carry = 0;              // 进位
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // 取当前位的值，若链表已空则视为 0
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            
            int sum = x + y + carry;
            carry = sum / 10;                        // 计算新的进位
            current->next = new ListNode(sum % 10);  // 当前位的数字
            
            current = current->next;
            
            // 移动指针
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        return dummy.next;
    }
};
