// Tree : Top View

#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
void topView(Node * root) {
    if(root == NULL) return;

    map<int, int> mp;

    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while(!q.empty()) {
        auto temp = q.front();
        q.pop();

        Node* curr = temp.first;
        int hd = temp.second;

        if(mp.find(hd) == mp.end()) {
            mp[hd] = curr->data;
        }

        if(curr->left != NULL) {
            q.push({curr->left, hd - 1});
        }

        if(curr->right != NULL) {
            q.push({curr->right, hd + 1});
        }
    }

    for(auto it : mp) {
        cout << it.second << " ";
    }
}
}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.topView(root);
    return 0;
}