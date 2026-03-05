 #include <stdbool.h>
#include <stdlib.h>
#include <string.h>


struct QueueNode {
    char *word;
    int length;
};


struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct QueueNode *array;
};


struct Queue *createQueue(unsigned capacity) {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (struct QueueNode *)malloc(queue->capacity * sizeof(struct QueueNode));
    return queue;
}


bool isFull(struct Queue *queue) {
    return (queue->size == queue->capacity);
}


bool isEmpty(struct Queue *queue) {
    return (queue->size == 0);
}


void enqueue(struct Queue *queue, char *word, int length) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear].word = word;
    queue->array[queue->rear].length = length;
    queue->size = queue->size + 1;
}


struct QueueNode dequeue(struct Queue *queue) {
    struct QueueNode item;
    item.word = NULL;
    item.length = -1;
    if (isEmpty(queue))
        return item;
    item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}


bool isAdjacent(char *word1, char *word2, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (word1[i] != word2[i])
            count++;
        if (count > 1)
            return false;
    }
    return count == 1;
}


int ladderLength(char *beginWord, char *endWord, char **wordList, int wordListSize) {
    int wordLength = strlen(beginWord);
    struct Queue *queue = createQueue(wordListSize);
    enqueue(queue, beginWord, 1);


    while (!isEmpty(queue)) {
        struct QueueNode current = dequeue(queue);
        if (strcmp(current.word, endWord) == 0)
            return current.length;


        for (int i = 0; i < wordListSize; i++) {
            if (!wordList[i]) continue;
            if (isAdjacent(current.word, wordList[i], wordLength)) {
                enqueue(queue, wordList[i], current.length + 1);
                wordList[i] = NULL;
            }
        }
    }
    return 0;
}


