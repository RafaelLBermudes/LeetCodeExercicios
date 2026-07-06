/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reorderList(struct ListNode* head) {
    if ( head == NULL ) {
        return;
    } else if ( head->next == NULL ) {
        return;
    }
    // caso a lista for vazia retorna
    int top = 0, i = 0;
    int *stack = malloc( sizeof(int) * 50000 );
    // inicializa a pilha
    struct ListNode* walk = head;
    // faz um ponteiro pra andar sobre a lista encadeada

    while ( walk != NULL ) {
        stack[top] = walk->val;
        top++;
        walk = walk->next;
        i++;
    } 
    // anda a lista inteira pra enxer a pilha

    i = 0;
    top--;
    int y = 1; 
    walk = head->next;

    while ( walk != NULL ) {
        if ( i % 2 == 1 ) {
            walk->val = stack[y];
            y++;
        } else {
            walk->val = stack[top];
            top--;
        }
        walk = walk->next;
        i++;
    }

}
