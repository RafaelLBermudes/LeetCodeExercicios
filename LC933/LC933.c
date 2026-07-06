typedef struct {
    int ping[10000];
    int front;
    int rear;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter *new = (RecentCounter *)malloc(sizeof(RecentCounter));

    new->front = 0;
    new->rear = -1;

    return new;
}

int recentCounterPing(RecentCounter* obj, int t) {
    int x = t - 3000;
    obj->rear++;
    obj->ping[obj->rear] = t;    
    while ( obj->rear >= obj->front && obj->ping[obj->front] < x ) {
        obj->front++;
    }
 
    return obj->rear - obj->front + 1;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/
