#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode* head)
{
    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *head = new ListNode(0), *tail = head; // 结果链表的头尾指针
    int carry = 0; // 进位
    while (l1 || l2 || carry)
    {
        int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = val / 10;
        tail->next = new ListNode(val % 10);;
        tail = tail->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return head->next;
}

int main() 
{
    freopen("input.txt", "r", stdin);
    ListNode *head1 = NULL, *tail = NULL;
    for (int i = 0; i < 3; ++i)
    {
        int tmp;
        cin >> tmp;
        ListNode* p = new ListNode(tmp);
        if (tail == NULL)
        {
            head1 = tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }
    /* print_list(head1); */
    ListNode *head2 = NULL;
    tail = NULL;
    for (int i = 0; i < 3; ++i)
    {
        int tmp;
        cin >> tmp;
        ListNode* p = new ListNode(tmp);
        if (tail == NULL)
        {
            head2 = tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }
    /* print_list(head2); */
    ListNode* result = addTwoNumbers(head1, head2);
    print_list(result);
    return 0;
}
