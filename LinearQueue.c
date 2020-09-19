#include <stdio.h>
#include <stdlib.h>



// node struct requires a value and pointer to next node in list
typedef struct node
{
    int value;
    struct node *next;
}
node;

int enqueue(node*, int);
node *dequeue(node*);

// List of size 0
node *list = NULL;

int main(void)
{
    // Add value to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->value = 1;
    n->next = NULL;
    list = n;

    enqueue(list, 2);
    enqueue(list, 3);
    enqueue(list, 4);

    //printf("%i\n", list->next);
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->value);
    }
    printf("\n");

    list = dequeue(list);

    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->value);
    }


    // Free list
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}

int enqueue(node *list, int value)
{
  // Build new node with value
  node *new_node = malloc(sizeof(node));
  if (new_node == NULL)
  {
      return 1;
  }
  new_node->value = value;
  new_node->next = NULL;

  node *current_node = list;

  // Add node to beginning if head pointing to nothing
  if (current_node->next == NULL)
  {
    current_node->next = new_node;
    return 0;
  }

  // Add node to queue
  while (current_node->next != NULL)
  {
    current_node = current_node->next;
  }
  current_node->next = new_node;

  return 0;
}

node *dequeue(node *list)
{
  // Makes the head of the list point to the second value of the list, orphaning the first one
  list = list->next;
  return list;
}
