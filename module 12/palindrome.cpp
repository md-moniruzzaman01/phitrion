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

void print_forward(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
};
bool reverse_doubly(Node *head, Node *tail, bool flag)
{
    for (Node *i = head, *j = tail; i != j && i->prev != j; i = i->next, j = j->prev)
    {

        if (i->val != j->val)
        {
            flag = true;
            break;
        }
    }
    return flag;
};
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    bool flag = false;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        };
        insert_at_tail(head, tail, val);
    };
    flag = reverse_doubly(head, tail, flag);

    if (flag)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
};