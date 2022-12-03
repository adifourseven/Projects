#include<stdio.h>
#include<stdlib.h>
#pragma pack(1);

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE First,int no)//1
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if (*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        *First = newn;
    }
}

void InsertLast(PPNODE First,int no)//2
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = NULL;
    newn->data = no;
    newn->next = NULL;

    temp = *First;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newn;
    newn->next = NULL;
}

void DeleteFirst(PPNODE First)//3
{
    PNODE temp = *First;
    if (*First == NULL)
    {
        return;
    }
    else
    {
        (*First) = (*First)->next;
        free(temp);
    }
    
}

void DeleteLast(PPNODE First)//4
{
    PNODE temp = *First;

    if (*First == NULL)
    {
        return;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    
}

void InsertAtPos(PPNODE First,int no,int iPos)
{
    int NodeCnt = 0;
    NodeCnt = Count(*First);

    PNODE temp = NULL;

    if (iPos < 1 || iPos > (NodeCnt+1))   //FILTER
    {
        printf("Invalid Position");
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(First,no);
    }
    else if(iPos == (NodeCnt+1))
    {
        InsertLast(First,no);
    }
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        int iCnt = 0;
        temp = *First;

        for(iCnt = 1;iCnt < iPos-1;iCnt++)
        {
            temp = temp->next;
        }

       newn->next = temp->next;
       temp->next = newn;
    }
}

void DelAtPos(PPNODE First,int iPos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    int NodeCnt = 0;
    NodeCnt = Count(*First);

    if (iPos < 1 || iPos > NodeCnt)
    {
        return;
    }

    if (iPos == 1)
    {
       DeleteFirst(First);
    }
    else if(iPos == NodeCnt)
    {
        DeleteLast(First);
    }
    else
    {
        int iCnt = 0;
        temp1 = *First;
        for(iCnt = 1;iCnt < (iPos-1);iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = temp2->next;
    }
}
void Display(PNODE First)//5
{
    printf("elements from the linked list are : \n");

    while (First != NULL)
    {
        printf("| %d | -> ",First->data);
        First = First->next;
    }

    printf("NULL\n");
    
}

int Count(PNODE First)//6
{
    int iCnt = 0;
    while (First != NULL)
    {
         iCnt++;
        First = First->next;
    }
    return iCnt;
}

int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);
    InsertLast(&Head,101);
    InsertLast(&Head,111);

    //DeleteFirst(&Head);
    DeleteLast(&Head);

    InsertAtPos(&Head,99,4);
    DelAtPos(&Head,4);


     Display(Head);
     printf("-----------------------------------------------\n");
     iRet = Count(Head);
     printf("Number of nodes in linked list are: %d\n",iRet);

    return 0;
}