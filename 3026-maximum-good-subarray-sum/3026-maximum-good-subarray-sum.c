#define MAX_HASH 2999
#define RAND 299
#define ABS(x) (x>=0?x:(-(x)))
#define val2Key(x) (ABS(x+RAND)%MAX_HASH)
#define MAX(x,y) (x>y?x:y)
typedef struct node{
    int val;
    long long sum;
    struct node* next;
}node;

void addHash(int val, long long sum, node** table){ // if node exists, update the val to the max one.
    int key = val2Key(val);
    for(node* cur = table[key];cur!=NULL;cur=cur->next){
        if(cur->val == val){
            cur->sum = MAX(cur->sum,sum);
            return;
        }
    }
    node* n = (node*)malloc(sizeof(node));
    n->val = val;
    n->sum = sum;
    n->next = table[key];
    table[key] = n;
}

bool getSum(int val, node** table, long long* pSum){
    int key = val2Key(val);
    for(node* cur = table[key];cur!=NULL;cur=cur->next){
        if(cur->val == val){
            *pSum = cur->sum;
            return true;
        }
    }
    return false;
}

long long maximumSubarraySum(int* nums, int numsSize, int k) {
    node** table = (node**)calloc(MAX_HASH,sizeof(node*));
    long long curSum = 0;
    for(int i = 0;i<numsSize;i++){
        curSum += nums[i];
    }
    addHash(nums[numsSize-1],curSum,table);
    curSum-=nums[numsSize-1];
    long long curMax = LLONG_MIN;
    for(int i = numsSize-2;i>=0;i--){
        long long targetSum = 0;
        int targetNum1 = nums[i]+k;
        int targetNum2 = nums[i]-k;
        if(getSum(targetNum1,table,&targetSum)){
            curMax = MAX(curMax,nums[i] + (targetSum - curSum));
        }
        if(getSum(targetNum2,table,&targetSum)){
            curMax = MAX(curMax,nums[i] + (targetSum - curSum));
        }
        addHash(nums[i],curSum,table);
        curSum-=nums[i];
    }

    for(int i = 0;i<MAX_HASH;i++){
        for(node* cur = table[i];cur!=NULL;){
            node* temp = cur;
            cur=cur->next;
            free(temp);
        }
    }
    free(table);
    return curMax==LLONG_MIN?0:curMax;
}