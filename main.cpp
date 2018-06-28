#include <iostream>

using namespace std;

struct node
{
    string key;
    int id;
    node* next;
};

int hashfunc(string key)
{
    int sum = 0;

    for(int i = 0; i < key.length(); i++)
    {
        sum += key[i] * (i + 1);
    }

    return sum;
}

int main()
{
    node* table[11] = {NULL};
    string keys[4] = {"abcdef", "bcdefa", "cdefab", "abcdfg"};
    int hash;
    int index;
    node* iter;

    for(int i = 0; i < 4; i++)
    {
        hash = hashfunc(keys[i]);
        index = hash % 11;
        iter = table[index];

        if(iter == NULL)
        {
            table[index] = new node;
            iter = table[index];
        }
        else
        {
            while(iter -> next != NULL)
            {
                iter = iter -> next;
            }
            iter -> next = new node;
            iter = iter -> next;
        }

        iter -> key = keys[i];
        iter -> id = i;
        iter -> next = NULL;
    }

    for(int i = 0; i < 4; i++)
    {
        hash = hashfunc(keys[i]);
        index = hash % 11;
        iter = table[index];
        cout << index << endl;

        while(iter != NULL && iter -> key != keys[i])
        {
            iter = iter -> next;
        }

        if(iter == NULL)
        {
            cout << "key not found!" << endl;
        }
        else
        {
            cout << "key: " << iter -> key << endl;
            cout << "id: " << iter -> id << endl;
        }
    }
    return 0;
}
