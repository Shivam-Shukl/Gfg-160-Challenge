class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        
        Node* fast =head;
        Node* slow = head;
        while(slow && fast && fast-> next)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast  == slow  )
            {
                return true;
            }
        }
        return false;
    }
};
