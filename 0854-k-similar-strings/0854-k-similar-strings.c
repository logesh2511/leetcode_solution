#define MAX_QUEUE_SIZE 10000
#define MAX_STRING_SIZE 100
typedef struct {
    char** data;
    int front;
    int rear;
    int size;
} Queue;
typedef struct Node {
    char* str;
    struct Node* next;
} Node;
typedef struct {
    Node* head;
} HashSet;
Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (char**)malloc(size * sizeof(char*));
    q->front = 0;
    q->rear = 0;
    q->size = size;
    return q;
}
bool isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}
void enqueue(Queue* q, char* str) {
    q->data[q->rear] = strdup(str);
    q->rear = (q->rear + 1) % q->size;
}
char* dequeue(Queue* q) {
    char* str = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    return str;
}
void freeQueue(Queue* q) {
    while (!isQueueEmpty(q)) {
        free(dequeue(q));
    }
    free(q->data);
    free(q);
}
HashSet* createHashSet() {
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));
    set->head = NULL;
    return set;
}
bool contains(HashSet* set, char* str) {
    Node* current = set->head;
    while (current) {
        if (strcmp(current->str, str) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}
void add(HashSet* set, char* str) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->str = strdup(str);
    newNode->next = set->head;
    set->head = newNode;
}
void freeHashSet(HashSet* set) {
    Node* current = set->head;
    while (current) {
        Node* next = current->next;
        free(current->str);
        free(current);
        current = next;
    }
    free(set);
}
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
char** nextStates(char* s, char* s2, int* returnSize) {
    int n = strlen(s);
    int i = 0;
    while (s[i] == s2[i]) {
        ++i;
    }
    char** res = (char**)malloc(n * sizeof(char*));
    *returnSize = 0;
    for (int j = i + 1; j < n; ++j) {
        if (s[j] == s2[i] && s[j] != s2[j]) {
            swap(&s[i], &s[j]);
            res[(*returnSize)++] = strdup(s);
            swap(&s[i], &s[j]);
        }
    }
    return res;
}
int kSimilarity(char* s1, char* s2) {
    Queue* q = createQueue(MAX_QUEUE_SIZE);
    HashSet* vis = createHashSet();
    enqueue(q, s1);
    add(vis, s1);
    int ans = 0;
    while (!isQueueEmpty(q)) {
        int size = q->rear - q->front;
        if (size < 0) size += q->size;
        for (int i = 0; i < size; ++i) {
            char* s = dequeue(q);
            if (strcmp(s, s2) == 0) {
                freeQueue(q);
                freeHashSet(vis);
                return ans;
            }
            int nextSize;
            char** next = nextStates(s, s2, &nextSize);
            for (int j = 0; j < nextSize; ++j) {
                if (!contains(vis, next[j])) {
                    add(vis, next[j]);
                    enqueue(q, next[j]);
                }
                free(next[j]);
            }
            free(next);
            free(s);
        }
        ++ans;
    }
    freeQueue(q);
    freeHashSet(vis);
    return -1; 
}
