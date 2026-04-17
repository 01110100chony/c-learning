#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* CreateNodeList(int value) {
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    if (newNode == NULL) return NULL;
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

int ListToValue(struct ListNode* l) {
    int sum = 0;
    int multiplicador = 1;
    struct ListNode* ptr = l;

    while (ptr != NULL) {
        sum += ptr->val * multiplicador;
        multiplicador *= 10;
        ptr = ptr->next;
    }

    return sum;
}

struct ListNode* ValueToList(int sum) {
    if (sum == 0) return CreateNodeList(0);

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    while (sum > 0) {
        int digit = sum % 10;
        struct ListNode* newNode = CreateNodeList(digit);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        sum /= 10;
    }

    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return ValueToList(ListToValue(l1) + ListToValue(l2));
}