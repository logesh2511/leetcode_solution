typedef struct Node {
    struct ChildNode* children;
    int cnt;
} Node;
typedef struct ChildNode {
    int key;
    Node* node;
    struct ChildNode* next;
} ChildNode;
Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->children = NULL;
    node->cnt = 0;
    return node;
}
Node* findOrCreateChild(Node* node, int key) {
    ChildNode* current = node->children;
    ChildNode* prev = NULL;
    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        ChildNode* newChild = (ChildNode*)malloc(sizeof(ChildNode));
        newChild->key = key;
        newChild->node = createNode();
        newChild->next = NULL;

        if (prev == NULL) {
            node->children = newChild;
        } else {
            prev->next = newChild;
        }

        return newChild->node;
    }

    return current->node;
}
void freeTrie(Node* node) {
    if (node == NULL) return;
    ChildNode* current = node->children;
    while (current != NULL) {
        freeTrie(current->node);
        ChildNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(node);
}
long long countPrefixSuffixPairs(char** words, int wordsSize) {
    long long ans = 0;
    Node* trie = createNode();
    for (int i = 0; i < wordsSize; ++i) {
        char* s = words[i];
        Node* node = trie;
        int m = strlen(s);
        for (int j = 0; j < m; ++j) {
            int p = s[j] * 32 + s[m - j - 1];
            node = findOrCreateChild(node, p);
            ans += node->cnt;
        }
        ++node->cnt;
    }
    freeTrie(trie);
    return ans;
}
