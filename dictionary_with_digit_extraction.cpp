#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    long long int value;
    string name;
    Node *next;
    Node *HashTable[10];
};

class Hashing : public Node
{
public:
    Hashing()
    {
        for (int i = 0; i < 10; i++)
        {
            HashTable[i] = NULL;
        }
    }

    int Digit_Extraction(long long int value)
    {
        string mystr;
        mystr = to_string(value);

        string val = mystr.substr(1, 4);

        int hashval = stoi(val);

        return (hashval % 10);
    }

    //    int Hashfunction(long long int value){
    //        return (value%10);
    //    }

    Node *create_node(long long int value, string name)
    {
        Node *temp = new Node;
        // Node *Name= new Node;
        //  Name->name=name;
        temp->next = NULL;
        temp->value = value;
        temp->name = name;
        return temp;
    }

    void insertElement(long long int hashval, string name)
    {
        int hash_val = Digit_Extraction(hashval);
        Node *temp = new Node;
        Node *head = new Node;

        head = create_node(hashval, name);
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
    int searching(long long int hashval)
    {
        long long int hash_val = Digit_Extraction(hashval);
        Node *temp = new Node;

        // temp = HashTable[hash_val];
        if (temp == HashTable[hash_val])
        {
            cout << "This user is present at  location " << hash_val << endl;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            cout << "This user is present at location " << hash_val << endl;
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
                cout << " ->  " << temp->value << " : " << temp->name;
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};
int main()
{
    Hashing h;
    int ch;
    string name;
    long long int data;

    do
    {
        cout << "\n1.insert \n2.display\n3.seaching \n 4. Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter the 10 digit number  :" << endl;
            cin >> data;
            cout << "Number inserted :" << data << endl;
            cout << "\nEnter name :" << endl;
            cout << "Name inserted " << endl;
            cin >> name;
            h.insertElement(data, name);

            break;
        case 2:
            h.display();
            break;
        case 3:
            cout << "Enter the value for the searching :" << endl;
            cin >> data;

            h.searching(data);
            break;
        }

    } while (ch != 4);
    return 0;
}