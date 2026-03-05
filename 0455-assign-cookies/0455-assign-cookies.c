int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);
    
    int contentChildren = 0;
    int gIndex = 0;
    int sIndex = 0; 
    
  
    while (gIndex < gSize && sIndex < sSize) {
       
        if (s[sIndex] >= g[gIndex]) {
            contentChildren++; 
            gIndex++;
        }
        sIndex++; 
    }
    
    return contentChildren;
}