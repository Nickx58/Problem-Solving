#include <iostream>
#include <queue>
using namespace std;

typedef struct node
{
  int data;
  int priority;

  struct node *next;

} Node;

Node *newNode(int d, int p)
{
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = d;
  temp->priority = p;
  temp->next = NULL;

  return temp;
}

int peek(Node **head)
{
  return (*head)->data;
}

void pop(Node **head)
{
  Node *temp = *head;
  (*head) = (*head)->next;
  free(temp);
}

void push(Node **head, int d, int p)
{
  Node *start = (*head);

  // Create new Node
  Node *temp = newNode(d, p);
  if ((*head)->priority > p)
  {
    temp->next = *head;
    (*head) = temp;
  }
  else
  {
    while (start->next != NULL &&
           start->next->priority < p)
    {
      start = start->next;
    }

    temp->next = start->next;
    start->next = temp;
  }
}

int isEmpty(Node **head)
{
  return (*head) == NULL;
}

int main()
{

  // Create a Priority Queue
  // 7->4->5->6
  Node *pq = newNode(4, 1);
  push(&pq, 5, 2);
  push(&pq, 6, 3);
  push(&pq, 7, 0);

  while (!isEmpty(&pq))
  {
    cout << " " << peek(&pq);
    pop(&pq);
  }
  return 0;
}
