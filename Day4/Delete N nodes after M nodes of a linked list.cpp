class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        Node* node = head;
        while(node!=nullptr)
        {
            Node* prev = nullptr;
            for(int i=0; i<m && node!=nullptr; i++)
            {
                prev = node;
                node = node->next;
            }
            
            for(int i=0; i<n && node!=nullptr; i++)
            {
                Node* temp = node;
                node = node->next;
                delete temp;
            }
            prev->next = node;
        }
        return head;
    }
};
