/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        priority_queue<int,vector<int>,greater<int>> minHeap;
        
        for(int i=0;i<arr.size();i++)
        {
            Node *temp = arr[i];
            while(temp)
            {
                minHeap.push(temp -> data);
                temp = temp -> next;
            }
        }
        
        Node* head = new Node(-1);
        Node* temp = head;
        while(!minHeap.empty())
        {
            Node* newNode = new Node(minHeap.top());
            minHeap.pop();
            temp -> next = newNode;
            temp= temp -> next;
        }
        if(head->next)
        {
            return head -> next;
        }else{
            return NULL;
        }
    }
};
