#include <stdio.h>
#include <stdlib.h>

struct CLLNode
{ // definindo a estrutura
    int data;
    struct CLLNode *next;
};

struct CLLNode *head = NULL; // define a head pra NULL (lista vazia)

//length of the list
int length(struct CLLNode *head)
{                                   //calcular a length
    struct CLLNode *current = head; //define current = head (ou seja aponta pro 1 node)
    int count = 0;
    if (head == NULL)
        return 0;

    do
    {
        current = current->next; //circula a lista ate chegar no ponto inicial (head)
        count++;
    } while (current != head);

    return count;
}

// display list using iteration
void printList(struct CLLNode *head)
{
    struct CLLNode *current = head; //define o ponto inicial
    if (head == NULL)
        return;

    do
    {
        printf("%d-->", current->data);
        current = current->next;
    } while (current != head);
}

// Insert at the beginning of the list
void insertAtBeginInCLL(struct CLLNode **head, int data)
{
    struct CLLNode *current = *head;
    struct CLLNode *newNode = (struct CLLNode *)(malloc(sizeof(struct CLLNode))); //alocar espaço pro novo node
    if (!newNode)
    {
        printf("Memory Error");
        return;
    }
    newNode->data = data;    //define os dados
    newNode->next = newNode; //aponta pra ele mesmo
    if (current == NULL)
    {                    //se current for nulo (ou seja, se a lista so tiver a head)
        *head = newNode; //head vai apontar pro novo node
        return;
    }

    while (current->next != *head) //girar a lista ate chegar no 1 elemento (head)
        current = current->next;

    newNode->next = *head; // head ->  newNode   newNode -> Head
    current->next = newNode;
    *head = newNode;
}

// insert item at the end of the list
void insertAtEndInCLL(struct CLLNode **head, int data)
{
    struct CLLNode *current = *head;                                              //tmp pra apontar pra head
    struct CLLNode *newNode = (struct CLLNode *)(malloc(sizeof(struct CLLNode))); //aloca espaço pro novo node
    if (!newNode)
    {
        printf("Memory Error");
        return;
    }
    newNode->data = data;
    while (current->next != *head) //girando a lista ate o 1 elemento antes da head
        current = current->next;

    newNode->next = newNode; //newnode aponta pra ele mesmo

    if (*head == NULL)
        *head = newNode;
    else
    {
        newNode->next = *head;   //define pra apontar pra head, visto q é o ultimo
        current->next = newNode; //define o penultimo node pra apontar pro novo
    }
}

void deleteLastNodeFromCLL(struct CLLNode **head)
{                                                   //deletar o ultimo node
    struct CLLNode *temp = *head, *current = *head; //tmp q aponta pra head e current q tbm aponta pra head

    if (*head == NULL)
    {
        printf("List empty!");
        return;
    }
    while (current->next != *head)
    {                            //girando ate o elemento antes da head
        temp = current;          //armazenando o o ponteiro antes da head
        current = current->next; //armazenando a head
    }
    temp->next = current->next;
    free(current);
    return;
}
void deleteFrontNodeFromCLL(struct CLLNode **head)
{
    struct CLLNode *temp = *head;
    struct CLLNode *current = *head;

    if (*head == NULL)
    {
        printf("List empty");
        return;
    }

    while (current->next != *head) //traversing the list
        current = current->next;   //chegando ultimo node antes da head

    current->next = (*head)->next; //define o current next pra apontar pro q a head apontava
    *head = (*head)->next;         // head

    //antes -> head -> depois
    // tmp -> head
    // antes -> head

    free(temp);
    return;
}