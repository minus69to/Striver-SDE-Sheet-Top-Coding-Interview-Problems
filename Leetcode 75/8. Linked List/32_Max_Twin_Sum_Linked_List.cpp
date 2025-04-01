#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createLinkedList(vector<int> values)
{
    if (values.empty())
    {
        return nullptr;
    }

    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;

    for (int i = 1; i < values.size(); i++)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

void printLinkedList(ListNode *head)
{
    ListNode *current = head;

    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteLinkedList(ListNode *head)
{
    ListNode *current = head;

    while (current != nullptr)
    {
        ListNode *temp = current;
        current = current->next;
        delete (temp);
    }
}

class Solution
{
public:
    ListNode *findMid(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;

            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    int pairSum(ListNode *head)
    {
        ListNode *midHead = findMid(head);
        ListNode *revHead = reverseList(midHead);

        int ans = 0;

        while (revHead != nullptr)
        {
            ans = max(ans, head->val + revHead->val);

            head = head->next;
            revHead = revHead->next;
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    ListNode *head = createLinkedList({1, 2, 3, 4, 5, 6});
    printLinkedList(head);

    cout << solution.pairSum(head);
    // printLinkedList(head);

    return 0;
}