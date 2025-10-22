#include <iostream>
using namespace std;

//先序遍历
void PreOrderTraverse(BiTree *T){
	if(T == NULL) return;
	else{
		std::cout << T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}

}

//中序遍历
void MidOrderTraverse(BiTree *T){
	if(T == NULL) return;
	else{
		
	}
}
