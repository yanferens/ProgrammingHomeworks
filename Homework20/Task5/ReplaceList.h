#pragma once

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* push_back(Node* head, int data);
void printList(Node* head);
Node* findLastEl(Node* head);

Node* replaceElements1(Node* head, Node* node1);
Node* replaceElements2(Node* head, Node* node1, Node* node2);

void clear(Node* head);