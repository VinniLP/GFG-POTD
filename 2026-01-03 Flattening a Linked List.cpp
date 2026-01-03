class CompareNode {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // min-heap
    }
};

class Solution {
public:
    Node* flatten(Node* root) {
        if (!root) return NULL;

        priority_queue<Node*, vector<Node*>, CompareNode> pq;

        // Push all nodes
        Node* temp = root;
        while (temp) {
            Node* curr = temp;
            while (curr) {
                pq.push(curr);
                curr = curr->bottom;
            }
            temp = temp->next;
        }

        // Build flattened list USING bottom
        Node* head = pq.top();
        pq.pop();
        Node* curr = head;
        curr->next = NULL;

        while (!pq.empty()) {
            curr->bottom = pq.top();
            pq.pop();
            curr = curr->bottom;
            curr->next = NULL;
        }
        curr->bottom = NULL;

        return head;
    }
};
