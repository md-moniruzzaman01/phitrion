#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print_forward(Node *head)
{
    Node *tmp = head;
    cout << "L -> ";
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
};

void print_backward(Node *tail)
{
    Node *tmp = tail;
    cout << "R -> ";
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
};

void insert_at_head(Node *&head, Node *&tail, int val)
{

    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;
};
void insert_at_tail(Node *&head, Node *&tail, int val)
{

    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
};

void insert_at_any_pos(Node *&head, int idx, int val)
{

    Node *tmp = head;
    Node *newnode = new Node(val);
    for (int i = 1; i < idx; i++)
    {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    tmp->next->prev = newnode;
    tmp->next = newnode;
    newnode->prev = tmp;
};

int get_size(Node *head)
{
    int size = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        size++;
        tmp = tmp->next;
    }
    return size;
}
int main()
{

    int q;
    cin >> q;

    Node *head = NULL;
    Node *tail = NULL;
    int val;
    for (int i = 0; i < q; i++)
    {
        int x, v;
        cin >> x >> v;

        int size = get_size(head);

        if (x < 0 || x > size)
        {
            cout << "Invalid" << endl;
            continue;
        }

        if (x == 0)
        {
            insert_at_head(head, tail, v);
            print_forward(head);
            print_backward(tail);
        }
        else if (x == size)
        {
            insert_at_tail(head, tail, v);
            print_forward(head);
            print_backward(tail);
        }

        else
        {
            insert_at_any_pos(head, x, v);
            print_forward(head);
            print_backward(tail);
        }
    };

    return 0;
}
