// Given an array of integers, find the one that appears an odd number of times.

// There will always be only one integer that appears an odd number of times.

// Examples
// [7] should return 7, because it occurs 1 time (which is odd).
// [0] should return 0, because it occurs 1 time (which is odd).
// [1,1,2] should return 2, because it occurs 1 time (which is odd).
// [0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
// [1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int hoare_sort(int *A, const int F, const int L)
{
    if (F >= L)
        return 0;
    int count = 0;
    int M = (F + L) / 2;
    int med = A[M];
    int i = F, j = L;
    int buf;
    do
    {
        count++;
        while (A[i] < med)
        {
            i++;
            count++;
        }
        count++;
        while (A[j] > med)
        {
            j--;
            count++;
        }

        count++;
        if (i <= j)
        {
            count++;
            int buf = A[i];
            A[i] = A[j];
            A[j] = buf;
            i++;
            j--;
        }
        count++;
    } while (i <= j);

    count++;
    if (F < j)
        count += hoare_sort(A, F, j);
    count++;
    if (i < L)
        count += hoare_sort(A, i, L);
    return count;
}

int find_odd(size_t length, const int array[length])
{
    int* new_array = (int*)malloc(sizeof(int)*length);
    for (int i = 0; i < length; i++)
        new_array[i] = array[i];
    hoare_sort(new_array, 0, length - 1);
    int  counter = 1;
    for (int i = 0; i < length; i++)
    {
        
        if (new_array[i] != new_array[i+1])
        {
            if(counter%2 == 1) 
            {
                int buf = new_array[i];
                free(new_array);
                return buf;
            }
            counter = 1;
            continue;
        }
        counter++;
        
        
    }
    
    
    free(new_array);
    return 0;
}

typedef struct node
{
    int data;
    int count;
    struct node *next;
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

Node* Add(Node* head, int data)
{
    if (!head) 
    {
        head = createNode(data);
        return head;
    }
    if (head->data == data)
    {
        head->count++;
        return head;
    }
    Node* local_head = head;
    while (local_head->next)
    {
        if (local_head->next->data == data) 
        {
            local_head->next->count++;
            return head;
        }
        if (local_head->next->data < data) local_head = local_head->next; else break;
    }

    if(local_head == head)
    {
        if (head->data > data)
        {
            Node* buf = createNode(data);
            buf->next = head;
            head = buf;
            return head;
        }  
    }

    if(!local_head->next) 
    {
        local_head->next = createNode(data);
        return head;
    }

    Node* buf = local_head->next;
    local_head->next = createNode(data);
    local_head->next->next = buf;
    return head;
}

int find_odd1(size_t length, const int array[length])
{
    Node* head = NULL;
    for (int i = 0; i < length; i++)
        head = Add(head, array[i]);
    Node* local_head = head;
    while (local_head)
    {
        if (local_head->count%2 == 1)
            return local_head->data;
        local_head = local_head->next;
    }
    return -100000001;
}

// x xor x = 0 and xor is commutative
int find_odd2(size_t length, const int array[length])
{
  int odd_int = 0;

  for (size_t i = 0; i < length; i++)
    odd_int ^= array[i];

  return odd_int;
}

int main()
{
    int array[] = {28, 28};
    printf("%d", find_odd2(sizeof(array) / sizeof(array[0]), array));
}