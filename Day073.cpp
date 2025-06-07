class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow)
            {
                slow = head;
                if(slow == fast) // head node
                {
                    while(fast -> next!= head)
                    {
                        fast = fast -> next;
                    }
                    fast -> next = nullptr;
                }else{
                    while(slow->next != fast -> next)
                    {
                        slow  = slow -> next;
                        fast  = fast -> next;
                    }
                    fast -> next = nullptr;
                }

            }
        }
    }
};
