#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode* CreateNodeList(int value) {
    ListNode* NewNode = malloc(sizeof(ListNode)); 
    if (NewNode == NULL) return NULL; 
    NewNode->next = NULL;   
    NewNode->val = value;  
    return NewNode;
}


int SumNodes(ListNode* l) {
    int sum = 0;
    int multiplicador = 1; 
    ListNode* ptr = l;

    while (ptr != NULL) {
        sum += (ptr->val * multiplicador);
        multiplicador *= 10; 
        ptr = ptr->next;
    }
    return sum;
}


ListNode* separateList(int sum) {
    if (sum == 0) return CreateNodeList(0); 

    ListNode* head = NULL; 
    ListNode* tail = NULL;

    while (sum > 0) { 
        int digit = sum % 10; 
        ListNode* newNode = CreateNodeList(digit);  
        
        if (head == NULL) { 
            head = newNode; 
            tail = head; 
        } else {
            tail->next = newNode; 
            tail = tail->next;
        }
        sum /= 10; 
    }
    return head;
}

void freeList(ListNode* head) {
    ListNode* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

 struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    return separateList(SumNodes(l1) + SumNodes(l2));

  }

int main() {

    ListNode* la = CreateNodeList(2);
    la->next = CreateNodeList(4);
    la->next->next = CreateNodeList(3);

    ListNode* lb = CreateNodeList(5);
    lb->next = CreateNodeList(6);
    lb->next->next = CreateNodeList(4);

    int sum = SumNodes(la);
    printf("Soma calculada: %d\n", sum);

    ListNode *l4 = addTwoNumbers(la,lb);
    printf("%d + %d = %d\n", SumNodes(la), SumNodes(lb), SumNodes(l4));

    ListNode* ptr = l4;

    while(ptr != NULL){
        printf("%d\n",ptr->val);
        ptr = ptr->next;
    }

   
    freeList(la);
    freeList(l4);

    return 0;
}