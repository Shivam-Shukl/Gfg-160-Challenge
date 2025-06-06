class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
        Node* slow = head;
        Node* fast = head;
        while(fast && fast -> next)
        {
            fast = fast ->next -> next;
            slow = slow -> next;
            if(fast == slow)
            {
                slow = head;
                while(slow != fast)
                {
                    fast = fast -> next;
                    slow = slow -> next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
