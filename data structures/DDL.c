#include <stdio.h>
#include <stdlib.h>

//DOUBLE LINKED LIST

struct DLLNode
{
    int data;
    struct DLLNode *prev; //node anterior
    struct DLLNode *next; //proximo node
};

//length of the list
int length(struct DLLNode *head)
{                                   //ja temos um ponteiro pro inicio da lista, pode começar apontando pra null
    struct DLLNode *current = head; //define current como head
    int count = 0;
    if (head == NULL)
        return 0;

    while (current != NULL)
    {
        current = current->next; //current = node1.next -> node2 -> node3.... nodex -> NULL
        count++;
    }
    return count;
}

// display list using iteration
void printList(struct DLLNode *head)
{
    struct DLLNode *current = head;
    if (head == NULL)
        return;
    while (current != NULL)
    {
        printf("%d-->", current->data);
        current = current->next; //current = node1.next -> node2 -> node3.... nodex -> NULL
    }
}

// Insert at the beginning of the list
void insertAtBeginning(struct DLLNode **head, int data)
{
    struct DLLNode *current = *head;
    struct DLLNode *newNode = (struct DLLNode *)(malloc(sizeof(struct DLLNode)));
    if (!newNode)
    {
        printf("Memory Error");
        return;
    }
    newNode->prev = NULL; //ddefine como nulo, pq o anterior é a head
    newNode->data = data;
    newNode->next = NULL; //ainda n tem nenhum node dps

    if (current == NULL)
    {                    //*head -> NULL
        *head = newNode; //head agr aponta pro novo node
        return;
    }

    newNode->next = *head; //head vai estar apontando pra null
    (*head)->prev = newNode;
    *head = newNode;
}

// insert item at the end of the list
void insertAtEnd(struct DLLNode **head, int data)
{
    struct DLLNode *current = *head;
    struct DLLNode *newNode = (struct DLLNode *)(malloc(sizeof(struct DLLNode)));
    if (!newNode)
    {
        printf("Memory Error");
        return;
    }
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    { //corner case, se tiver so 1 elemento
        *head = newNode;
        return;
    }

    while (current->next != NULL)
        current = current->next; //traversing the list
                                 //nnovo node e os outros ainda nao foram conectados
    // current points to tail node
    newNode->prev = current; //current -> new node
    current->next = newNode; //current <- newnode
}

void insert(struct DLLNode **head, int data, int position)
{
    int k = 1;
    struct DLLNode *temp, *newNode;
    newNode = (struct DLLNode *)malloc(sizeof(struct DLLNode));
    if (!newNode)
    { //Always check for memory errors
        printf("Memory Error");
        return;
    }
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    if (position == 1)
    { //Inserting a node at the beginning
        newNode->next = *head;
        newNode->prev = NULL;

        if (*head)
            (*head)->prev = newNode;

        *head = newNode;
        return;
    }
    temp = *head; //criando variavell temporaria
    while (k < position - 1 && temp->next != NULL)
    { //traversing the list ate chegar na posicao desejada
        temp = temp->next;
        k++;
    }

    if (k < position - 1)
    {
        printf("Desired position does not exist\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next)
        temp->next->prev = newNode;

    temp->next = newNode;
    return;
}

void deleteLastNode(struct DLLNode **head)
{
    struct DLLNode *temp = *head, *current = *head; //current e um temporario

    if (*head == NULL)
    {
        printf("List empty!");
        return;
    }
    while (current->next != NULL)
    { //traversing the list
        current = current->next;
    }
    temp = current->prev;
    temp->next = current->next;
    free(current); //deleting
    return;
}

void deleteFrontNode(struct DLLNode **head)
{
    struct DLLNode *temp = *head;

    if (*head == NULL)
    {
        printf("List empty");
        return;
    }
    temp = *head;
    *head = (*head)->next; //passando de node em node
    (*head)->prev = NULL;  // e definindo o previous como nulo
    free(temp);            //apagando o anterior
    return;
}

void delete (struct DLLNode **head, int position)
{ //apagar na posição x
    struct DLLNode *temp2, *temp = *head;
    int k = 1; //counter
    if (*head == NULL)
    {
        printf("List is empty");
        return;
    }
    //tmp *head
    if (position == 1)
    {                          //corner case 1 posição
        *head = (*head)->next; //head como sendo o next, ou seja seria o node 1

        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }
    while (k < position && temp->next != NULL)
    { //traversing list untill a nosa posição
        temp = temp->next;
        k++;
    }
    if (k < position - 1)
    {
        printf("Desired position does not exist\n");
        return;
    }

    temp2 = temp->prev;
    temp2->next = temp->next;

    if (temp->next) // Deletion from Intermediate Node
        temp->next->prev = temp2;

    free(temp);
    return;
}

int main()
{
    struct DLLNode *head = NULL;
    printf("%d \n", length(head));
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    printf("List length is %d \n", length(head));
    printList(head);
    printf("\n");
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 60);
    printf("List length is %d \n", length(head));
    printList(head);
    printf("\n");
    insert(&head, 15, 2);
    insert(&head, 35, 4);
    insert(&head, 55, 6);
    insert(&head, 115, 12);
    printf("List length is %d \n", length(head));
    printList(head);
    printf("\n");
    deleteFrontNode(&head);
    printf("List length is %d \n", length(head));
    printList(head);
    printf("\n");
    deleteLastNode(&head);
    printf("List length is %d \n", length(head));
    printList(head);
    printf("\n");
    delete (&head, 7);
    printf("List length is %d \n", length(head));
    printList(head);
    printf("\n");
    delete (&head, 2);
    printf("List length is %d \n", length(head));
    printList(head);
    printf("\n");
    return 0;
}