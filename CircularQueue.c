#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int enqueue(int*, int, int);
int dequeue(int*, int);
int ask(int*, int);

int length;
int front = 0;

int main(void)
{
  printf("Length of array: ");
  scanf("%i", &length);

  int arr[length];
  int rear = length - 1;
  for (int i = 0; i < length; i++)
  {
    printf("Value %d: ", i);
    scanf("%i", &arr[i]);
  }

  for (int i = front; i <= rear; i++)
  {
    printf("%i ", arr[i]);
  }

  printf("\n");
  for (int i = 0; i < 4; i++)
  {
    rear = ask(arr, rear);
  }
}

int ask(int *arr, int rear)
{
  int choice;
  printf("\nE or D? ");
  scanf("%i", &choice);

  if (choice == 2)
  {
    dequeue(arr, rear);
  }

  else if (choice == 1)
  {
    int val;
    printf("Number to add: ");
    scanf("%i", &val);
    rear = enqueue(arr, rear, val);
  }

  for (int i = 0; i < length; i++)
  {
    if (arr[i] == -1)
    {
      printf("X ");
      continue;
    }
    printf("%i ", arr[i]);
  }

  return rear;
}

int enqueue(int *arr, int rear, int val)
{
  // Check if list is full
  if ((front == rear + 1) || (front == 0 && rear == length - 1))
  {
    printf("List full\n");
    return 1;
  }
  // Modulo will only change value if rear == length
  rear = (rear + 1) % length;
  arr[rear] = val;
  printf("\n Inserted -> %d\n", val);

  return rear;
}

int dequeue(int *arr, int rear)
{
  // Check if list is full
  if (front == rear)
  {
    printf("List empty");
    return 1;
  }
  // 'Delete' curent value in head of array
  arr[front] = -1;
  // Head now represents next value along
  front++;
  return 0;
}
