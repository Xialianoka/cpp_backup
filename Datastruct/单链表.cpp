#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} node;

// 头结点指针域为空
node *InitList_L()
{
    node *L = new node;
    L->next = NULL;
    return L;
}
// 判断链表是否为空
int ListEmpty(node Head)
{
    if (Head.next)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
// 链表销毁
void delete_List(node *Head)
{
    node *p = new node;

    while (Head)
    {
        p = Head;
        Head = Head->next;
        delete p;
    }
}

// 取链表第i个值
int GetElem(node *L, int i)
{
    node *p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    return p->data;
}

// 按值查找
node *LocateElem(node *L, int e)
{
    node *p = new node;
    p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}

// 在i个节点插入元素
void *ListInsert(node *L, int i, int data)
{
    int j = 0;
    node *p = new node;
    p->data = data;
    p->next = NULL;
    node *pT = L;
    while (pT && j < (i - 1))
    {
        pT = pT->next;
        j++;
    }
    p->next = pT->next;
    pT->next = p;
}

// 删除第i个结点
void ListDelete(node *L, int i)
{
    node *pT = L;
    for (int j = 0; j < i; j++)
    {
        pT = pT->next;
    }
    node *p = pT->next;
    pT->next = p->next;
    delete p;
    return;
}

// 前插法创建单链表
void add_nodeH(node *L, int data)
{
    node *p = new node;
    p->data = data;
    p->next = L->next;
    L->next = p;
}

//尾插法创建单链表
void add_nodeR(node *L, int data)
{
    node *p = new node;
    p->data = data;
    p->next = NULL;
    node *pT;
    for (pT = L; pT->next != NULL; pT = pT->next)
        ;
    pT->next = p;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    
}