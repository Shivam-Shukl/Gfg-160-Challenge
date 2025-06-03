
class Solution {
  public:
    Node* trim(Node* num)
    {
        Node* temp =num;
        while(temp -> data == 0)
        {
            temp = temp -> next;
        }
        return temp;
    }
    Node* rev(Node* head)
    {
        Node* prev = NULL;
        while(head)
        {
            Node* temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    Node* solve(Node* num1, Node* num2)
    {
        int carry =0;
        Node* head = new Node(-1);
        Node* temp = head;
        
        while(num1 != NULL && num2 != NULL)
        {
            int d1 = num1 -> data;
            int d2 = num2 -> data;
            int final = d1 + d2 + carry;
            carry = final / 10;
            final = final % 10;
            Node* newNode = new Node(final);
            temp -> next = newNode;
            temp = newNode;
            num1 = num1 -> next;
            num2 = num2 -> next;
        }
        while(num1!= NULL)
        {
            int d1 = num1 -> data;
            int final = d1 + carry;
            carry = final /10;
            final= final %10;
            Node* newNode = new Node(final);
            temp -> next = newNode;
            temp = newNode;
            num1 = num1 -> next;
        }
        while(num2!= NULL)
        {
            int d2 = num2 -> data;
            int final = d2 + carry;
            carry = final /10;
            final= final %10;
            Node* newNode = new Node(final);
            temp -> next = newNode;
            temp = newNode;
            num2 = num2 -> next;
        }
        if(carry!= 0)
        {
            Node* newNode = new Node(carry);
            temp -> next = newNode;
            temp = newNode;
        }
        if(head -> next)
            head = head -> next;
        return head;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
    
        //trimming
        num1 = trim(num1);
        num2 = trim(num2);
        
        //reversing the linked list
        num1 = rev(num1);
        num2 = rev(num2);
        
        // directly adding 
        Node* ans = solve(num1,num2);
        
        // reversing the result
        ans = rev(ans);
        
        return ans;
        
    }
};
