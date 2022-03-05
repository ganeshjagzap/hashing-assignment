#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
} * HashTable[10];

class Hashing
{
public:
    Hashing()
    {
        for (int i = 0; i < 10; i++)
        {
            HashTable[i] = NULL;
        }                             // 652624
    }       
   int digit_extract(int value){
       return (value%1000);
   }
    // int HashFunction(int value)
    // {
    //     return (value % 10);
    // }
    Node *create_node(int value)
    {
        Node *temp = new Node;
        temp->next = NULL;
        temp->value = value;
        return temp;
    }

    void insertElement(int value)
    {
        int hash_val = digit_extract(value);
        Node *temp = new Node;
        Node *head = new Node;
        head = create_node(value);
        temp = HashTable[hash_val];
        if (temp == NULL)
        {
            HashTable[hash_val] = head;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = head;
        }
    }
    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            Node *temp = new Node;
            temp = HashTable[i];
            cout << "(" << i << ") ";
            while (temp != NULL)
            {
                cout << "-> " << temp->value;
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};
int main()
{
    Hashing h;
    int data, ch;

    do
    {
        cout << "\n1.insert \n2.display\n3.Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter the number to be inserted :";
            cin >> data;
            h.insertElement(data);
            cout << "Number inserted :" << data << endl
                 << endl;
            break;
        case 2:
            h.display();
            break;
        }

    } while (ch != 3);
    return 0;
}