class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;

        // Explicit case handling for left and right children
        if (root->left) {
            if (root->right) {
                root->left->next = root->right;
            } else {
                Node* nextNode = root->next;
                while (nextNode) {
                    if (nextNode->left) {
                        root->left->next = nextNode->left;
                        break;
                    }
                    if (nextNode->right) {
                        root->left->next = nextNode->right;
                        break;
                    }
                    nextNode = nextNode->next;
                }
            }
        }

        if (root->right) {
            Node* nextNode = root->next;
            while (nextNode) {
                if (nextNode->left) {
                    root->right->next = nextNode->left;
                    break;
                }
                if (nextNode->right) {
                    root->right->next = nextNode->right;
                    break;
                }
                nextNode = nextNode->next;
            }
        }

        // Correct order of recursive calls:
        connect(root->right);  // Process the right child first
        connect(root->left);   // Then process the left child

        return root;
    }
};