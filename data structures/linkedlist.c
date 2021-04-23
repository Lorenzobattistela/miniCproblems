#include <stdio.h>
#include <stdlib.h>

struct listNode
{
    int data;
    struct listNode *next;
};

int singlyListLength(struct listNode *head)
{
    int count = 0;
    struct listNode *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void insertInSinglyLinkedList(struct listNode **head, int data, int pos)
{
    int k = 1;
    struct listNode *q, *p;
    struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode)); //cria um novo node, aloca espaço pra ele
    if (!newNode)
    {
        printf("Memory Error\n");
        return;
    }
    newNode->data = data;      //define a propriedade data
    p = *head;                 //coloca o ponteiro p pra apontar pro mesmo lugar q o head (nesse caso, null)
    if (pos == 1 || p == NULL) //se o ponteiro for o primeiro ou se apontar para NULL,
    {
        newNode->next = *head; //define a propriedade next do novo node para que aponte para o mesmo lugar que o head (que seria NULL se fosse o 1 elemento)
        *head = newNode;       // define a head para apontar para  o novo  node
    }
    else
    {
        while (p != NULL && (k < pos)) // enquanto p for diferente de NULL e k (k = 1 no inicio) for menor que a posição,
        {
            k++;         // incrementa k
            q = p;       // define o pointero q para apontar para p
            p = p->next; //define p para apontar para a propriedade next do p, que pode ser outro elemento ou NULL, se for o ultimo
        }
        newNode->next = q->next; //define a propriedade next do novo node para ser igual a  de q (que foi definida no loop anterior), para inserir no meio da lista
        q->next = newNode;       //define a propriedade next de q como sendo o novo node (aponta para ele)
    }
}
void deleteNodeFromLinkedList(struct listNode **head, int pos) // n sei pq **head
{
    int k = 1;
    struct listNode *p, *q;
    p = *head;         //coloca o ponteiro p para apontar pro mesmo lugar que a  head (ou o 1 elemento ou NULL se for vazia)
    if (*head == NULL) //se head for null, a lista ta vazia
    {
        printf("List Empty\n");
        return;
    }
    else if (pos == 1) //se posição = 1
    {
        *head = (*head)->next; //propriedade next do head (nao sei pq ta em parenteses) vai apontar pro next do que ela tava apontando, ou seja, pular um node
        free(p);               //libera o node que foi deletado
    }
    else
    {
        while (p != NULL && k < pos) //mesmo loop do insert
        {
            k++;
            q = p;
            p = p->next;
        }
        if (p == NULL)
        {
            printf("Position does not exist\n");
        }
        else //se p != NULL
        {
            q->next = p->next; // a propriedade next do q vai apontar pra propriedade next do ponteiro p (que foi definida no loop)
            free(p);           //o ponteiro p vai ser liberado (deletado)
        }
    }
}
void printSLList(struct listNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data); //lê o dado dentro da head
        head = head->next;         // definir a próxima posição de memória a ser lida
        printf("\n");
    }
}

int SinglyLinkedList_test()
{
    struct listNode *head = NULL; //testes
    insertInSinglyLinkedList(&head, 5, 5);
    insertInSinglyLinkedList(&head, 2, 5);
    printf("Elements in List:%d\n", singlyListLength(head));
    printSLList(head);
    deleteNodeFromLinkedList(&head, 1);
    printSLList(head);
    return 0;
}