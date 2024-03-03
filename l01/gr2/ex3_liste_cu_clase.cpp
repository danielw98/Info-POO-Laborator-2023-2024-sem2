#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int info;
    struct Node *next;
public:
    // GRESIT - copy paste nemodificat - am sters valoarea de return si initializarea ca pointer a Node-ului,
    // insa am pastrat variabila din functia initiala pe care am initializat-o, in loc de pointerul "this"
    // Node(int info)
    // {
    //     Node node;
    //     node.info = info;
    //     node.next = nullptr;
    // }
    Node(int info)
    {
        this->info = info;
        this->next = nullptr;
    }
};

class List {
private:
    Node *head;
public:
    // Constructor, echivalent cu o functie de initializare a variabilelor structurii
    // In cazul nostru particular, List List_New(void)
    // Initializam campurile pointer-ului this, care corespund campurilor structurii
    // Constructorul returneaza implicit, acesta este rolul lui, de a crea si initializa variabila
    List()
    {
        cout << "Constructor apelat" << endl;
        this->head = nullptr;
    }

    // Functiile (care se numesc metode in cadrul unei clase) care nu iau niciun parametru
    // e good practice sa zicem ca iau parametrul `void`, adica nimic.
    void print(void)
    {
        cout << "Print apelat" << endl;
        Node *ptr = this->head;
        while(ptr != nullptr)
        {
            cout << ptr->info << endl;
            ptr = ptr->next;
        }
    }

    void append(int info)
    {
        cout << "Append apelat" << endl;
        Node *nodeToAdd = new Node(info);
        if(this->head == nullptr)
        {
            this->head = nodeToAdd;
            return;
        }
        Node *crt = this->head;
        while(crt->next != nullptr)
        {
            crt = crt->next;
        }
        crt->next = nodeToAdd;
    }

    // Destructor - echivalent cu o functie de tip List_Delete(List *l) / List_Free(List *l)
    // Avanataj: se apeleaza automat daca variabila nu a fost alocata dinamic! :-)
    ~List()
    {
        cout << "Destructor apelat";
        Node *crt = this->head;
        while(crt != nullptr)
        {
            Node *toDelete = crt;
            crt = crt->next;
            delete toDelete;
        }
    }
};


int main()
{
    List list;
    list.append(10);
    list.append(20);
    list.print();
    return 0;
}