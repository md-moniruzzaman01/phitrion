#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    void push(int val)
    {
        sz++;
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }

        tail->next = newnode;
        tail = newnode;
    };
    void pop()
    {
        sz--;
        Node *deleteNode = head;
        head = head->next;
        delete deleteNode;
    }
    int front()
    {
        return head->val;
    }
    int back()
    {
        return tail->val;
    };
    int size()
    {
        return sz;
    }
    bool empty()
    {
        return head == NULL;
    }
};
int main()
{

    return 0;
}