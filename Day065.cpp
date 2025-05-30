class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node* prev = NULL;
        while(head){
            Node* temp = head->next;
            head ->next = prev ;
            prev = head;
            head = temp;
        }
        return prev;
    }
};
