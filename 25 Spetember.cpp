class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    Node* reverse_linked_list(Node* curr){
        Node* curr_prev = NULL;
        Node* curr_next = NULL;
        
        while(curr != NULL){
            curr_next = curr->next;
            curr->next = curr_prev;
            curr_prev = curr;
            curr = curr_next;
        }
        
        return curr_prev;
    }
    
    bool isPalindrome(Node *head)
    {
        Node* slow = head;
        Node* fast = head;
        
        if(head == NULL || head->next == NULL){
            return true;
        }
        
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow->next = reverse_linked_list(slow->next); // Reversing the second half of LL 
        
        slow = slow->next; // 
        
        while(slow != NULL){
            if(head->data != slow->data){
                return false;
            }
            
            head = head->next;
            slow = slow->next;
        }
        
        return true;
    }
};