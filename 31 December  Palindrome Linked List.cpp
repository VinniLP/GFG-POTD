/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    int findData(Node* p1){
        if(p1!=NULL) return -1;
        return p1->data;
    }
    bool helper(Node* p1,Node* &p2){
        if(!p1) return true;
        bool ans = helper(p1->next,p2);
        ans = ans & (p1->data == p2->data);
        p2 = p2->next;
        return ans;
    }
    bool isPalindrome(Node *head) {
        //  code here
        Node* p1=head;
        Node* p2=head;
        return helper(p1,p2);
    }
};