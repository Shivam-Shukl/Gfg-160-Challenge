class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // Your code here
        Node* temp = head;
        int size = 0;
        while(temp)
        {
            size += 1;
            temp = temp -> next;
        }
        k = k % size;
        if(k==0) return head;
        temp = head;
        int i=1;
        while(k!=i)
        {
            temp = temp ->next;
            i++;
        }
        Node* newNode = head;
        head = temp -> next;
        temp ->next = NULL;
        
        temp = head;
        while(temp ->next)
        {
            temp = temp ->next;
        }
        temp ->next = newNode;
        return head;
    
    }
};
