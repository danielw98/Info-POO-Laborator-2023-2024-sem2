#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int info;
    struct Node *next;
};

Node* Node_New(int info)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->info = info;
    node->next = nullptr;
    return node;
}

struct List {
    Node *head;
};

List List_New(void);
void List_Append(List *myList, int info);
void List_Print(List *myList);
void List_Delete(List *myList);

List List_New(void)
{
    cout << "Lista Initializata - echivalent cu Constructor Apelat" << endl;
    List myList;
    myList.head = nullptr;
    return myList;
}

void List_Print(List *myList)
{
    cout << "Print apelat" << endl;
    Node *crt = myList->head;
    while(crt != nullptr)
    {
        cout << crt->info << endl;
        crt = crt->next;
    }
}

void List_Append(List *myList, int info)
{
    cout << "Append apelat" << endl;
    Node *nodeToAdd = Node_New(info);
    if(myList->head == nullptr)
    {
        myList->head = nodeToAdd;
        return;
    }
    Node *crt = myList->head;
    while(crt->next != nullptr)
    {
        crt = crt->next;
    }
    crt->next = nodeToAdd;
}

void List_Delete(List *myList)
{
    cout << "Eliberarea memoriei listei - echivalent cu Destructor apelat" << endl;
    cout << "A trebuit ca functia sa fie apelata explicit chiar daca variabila de tip List este alocata static" << endl; 
    Node *crt = myList->head;
    while(crt != nullptr)
    {
        Node *toDelete = crt;
        crt = crt->next;
        free(toDelete);
    }
}

int main()
{
    List myList = List_New();
    List_Append(&myList, 10);
    List_Append(&myList, 20);
    List_Print(&myList);
    List_Delete(&myList);
    return 0;
}