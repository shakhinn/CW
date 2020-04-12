#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int dig;
    struct Node* next;
}Node;

typedef struct List{
    int num;
    struct Node* head;
}List;

List* merged(List* first, List* second){
    if (!(first->head) || !(second->head)) {
        if (first->head)
            return first;
        else
            return second;
    }
    List* new_block = (List*)malloc(sizeof(List));
    new_block->head = first->head;
    new_block->num = first->num + second->num;
    Node *cor1_1, *cor1_2, *cor2_1, *cor2_2;
    cor1_1 = first->head;
    cor1_2 = cor1_1->next;
    cor2_1 = second->head;
    cor2_2 = cor2_1->next;
    while (1){
        cor1_1->next = cor2_1;
        cor1_1 = cor1_2;
        if (cor1_1)
            cor1_2 = cor1_1->next;
        else
            break;

        cor2_1->next = cor1_1;
        cor2_1 = cor2_2;
        if (cor2_1)
            cor2_2 = cor2_1->next;
        else
            break;
    }
    free(first);
    free(second);
    return new_block;
}
void swap_p(Node **a, Node **b){
    Node *tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_nodes(Node *a_pred, Node *b_pred){
    if(a_pred == b_pred)
        return;
    Node *a = a_pred->next;
    Node *b = b_pred->next;
    if(b->next == a){ // if a > b in order
        swap_p(&a, &b);
        swap_p(&a_pred, &b_pred);
    }
    if(a->next == b){
        a_pred->next = b;
        a->next = b->next;
        b->next = a;
        return;
    }
    swap_p(&(a->next), &(b->next));
    swap_p(&(a_pred->next), &(b_pred->next));
}

int main(){
    List* first = malloc(sizeof(List));
    List* second = malloc(sizeof(List));
    first->head = malloc(sizeof(Node));
    Node* tmp = (Node*)malloc(sizeof(Node));
    first->head->next = tmp;
    second->head = malloc(sizeof(Node));
    Node*tmp1 = (Node*)malloc(sizeof(Node));
    second->head->next = tmp1;
    scanf("%d", &first->num);
   // scanf("%d", &second->num);
    int arr1[first->num];
    //int arr2[second->num];
    for(int i = 0; i < first->num; i++){
        scanf("%d", &arr1[i]);
    }
   /* for(int i = 0; i < second->num; i++){
        scanf("%d", &arr2[i]);
    }*/
    first->head->dig = arr1[0];
    for(int i = 1; i < first->num; i++){
        tmp->dig = arr1[i];
        tmp->next = (Node*)malloc(sizeof(Node));
        tmp->next->next = NULL;
        tmp = tmp->next;
    }
   /* second->head->dig = arr2[0];
    for(int i = 1; i < second->num; i++){
        tmp1->dig = arr2[i];
        tmp1->next = (Node*)malloc(sizeof(Node));
        tmp1->next->next = NULL;
        tmp1 = tmp1->next;
    }*/
    /*List* new_b = merged(first, second);
    while(new_b->head){
        printf("%d ", new_b->head->dig);
        new_b->head = new_b->head->next;
    }*/
    swap_nodes(first->head->next, first->head->next->next->next);
    while(first->head->next){
        printf("%d ", first->head->dig);
        first->head = first->head->next;
    }
}