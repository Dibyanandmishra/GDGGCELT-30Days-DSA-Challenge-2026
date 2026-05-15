// Tree: Huffman Decoding

void decode_huff(node * root, string s) {
    
    node* curr = root;
    
    for(int i = 0; i < s.length(); i++) {
        
        // Move left for 0
        if(s[i] == '0')
            curr = curr->left;
        
        // Move right for 1
        else
            curr = curr->right;
        
        // If leaf node found
        if(curr->left == NULL && curr->right == NULL) {
            cout << curr->data;
            
            // Go back to root for next character
            curr = root;
        }
    }
}