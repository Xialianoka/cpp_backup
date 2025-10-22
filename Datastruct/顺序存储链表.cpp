#include <iostream>
#define Maxsize 100
#define OK 1
#define ERROR -1
#define OVERFLOW -2
typedef int Status;
using namespace std;

typedef struct
{
    int *elem;
    int length;
} SqList;

// 初始化链表
Status InitList_Sq(SqList &L)
{
    L.elem = new int[100];
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    return OK;
}

// 销毁链表
void DestroyList(SqList &L)
{
    if (L.elem)
        delete L.elem;
}

// 清空链表
void ClearList(SqList &L)
{
    L.length = 0;
}

// 求链表长度
int GetLength(SqList &L)
{
    return (L.length);
}

// 判断链表是否为空
int IsEmpty(SqList &L)
{
    if (L.length == 0)
        return 1;
    else
        return 0;
}

// 链表取第i个值(随机存取)
int GetElem(SqList L, int i, int &e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i - 1];
    return OK;
}

// 顺序按值查找
int LocalElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
        if (L.elem[i] == e)
            return i + 1;
    return 0;
}

// 在第i个位置插入元素
Status ListInsert_Sq(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return ERROR;
    if (L.length == Maxsize)
        return ERROR;
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    L.length++;
    return OK;
}

// 在第i个位置删除元素
Status ListDelete_Sq(SqList &L, int i)
{
    if (i < 1 || i > L.length)
        return ERROR;
    for (int j = i; j <= L.length - 1; j++)
    {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    return OK;
}

//循环遍历输出链表
void OutputList_Sq(SqList L){
    cout << "遍历输出当前链表中的元素：\n";
    for (int i = 0; i < L.length; i++)
    {
        cout << L.elem[i] << " ";
    }
    cout << "\n共" << GetLength(L) << "个元素\n";
}

int main()
{
    int i, e = 0;
    SqList L;

    cout << InitList_Sq(L) << endl; // 链表初始化，成功则输出1

    // 给链表赋值1~50
    for (i = 1; i <= 50; i++)
    {
        ListInsert_Sq(L, i, i);
    }
    OutputList_Sq(L);

    //在第i个位置插入元素e
    cout << "\n请输入插入位置：\n";
    cin >> i;
    cout << "请输入要插入的元素：\n";
    cin >> e;
    cout << ListInsert_Sq(L, i, e) << endl; // 在第i个位置插入元素e，成功则输出1

    OutputList_Sq(L);

    // 删除第i个元素
    cout << "输入要删除的位置:\n";
    cin >> i;
    ListDelete_Sq(L, i);
    OutputList_Sq(L);

    //查询元素e的位置
    cout << "输入要查询的值：\n";
    cin >> e;
    cout << "该值的位置为第" << LocalElem(L, e) << "位\n";

    DestroyList(L);

    system("pause");
    return 0;
}