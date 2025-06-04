class Solution {
  private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
  public:
    Node *cloneLinkedList(Node *head) {
        // Step 1: Create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        
        while (temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        
        // Step 2: Clone nodes added in between the original list
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while (originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;
            
            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }
        
        // Step 3: Copy the random pointer
        temp = head;
        while (temp != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        
        // Step 4: Reverse changes made in Step 2
        originalNode = head;
        cloneNode = cloneHead;
        
        while (originalNode != NULL && cloneNode != NULL) {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            
            if (originalNode != NULL) {
                cloneNode->next = originalNode->next;
            }
            
            cloneNode = cloneNode->next;
        }
        
        // Step 5: Return the cloned list head
        return cloneHead;
    }
};
