#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
class Node {
    public:
        int value;
        int left_Thread;
        int right_Thread;
        class Node *left_Node;
        class Node *right_Node;
};
typedef class Node ThreadNode;
typedef ThreadNode *ThreadBinaryTree;
ThreadBinaryTree rootNode;
//�N���w���ȥ[�J��G���޽u��
void Add_Node_To_Tree(int value) {
    ThreadBinaryTree newnode;
    ThreadBinaryTree previous;
    newnode=new ThreadNode;     
    newnode->value=value;
    newnode->left_Thread=0;
    newnode->right_Thread=0;
    newnode->left_Node=NULL;
    newnode->right_Node=NULL;
    ThreadBinaryTree current;
    ThreadBinaryTree parent;
    previous=new ThreadNode;
    previous->value=value;
    previous->left_Thread=0;
    previous->right_Thread=0;
    previous->left_Node=NULL;
    previous->right_Node=NULL;
    int pos;
    //�]�w�޽u�G���𪺶}�Y�`�I
    if(rootNode==NULL) {
        rootNode=newnode;
        rootNode->left_Node=rootNode;
        rootNode->right_Node=NULL;
        rootNode->left_Thread=0;
        rootNode->right_Thread=1;
        return;
    }
    //�]�w�}�Y�`�I�ҫ����`�I
    current=rootNode->right_Node;
    if(current==NULL){
        rootNode->right_Node=newnode;
        newnode->left_Node=rootNode;
        newnode->right_Node=rootNode;
        return ;
    }
    parent=rootNode; //���`�I�O�}�Y�`�I
    pos=0; //�]�w�G���𤤪���i��V
    while(current!=NULL) {
        if(current->value>value) {
            if(pos!=-1) {
                pos=-1;
                previous=parent;
            }
            parent=current;
            if(current->left_Thread==1)
                current=current->left_Node;
            else
                current=NULL;
        }
        else {
            if(pos!=1) {
                pos=1;
                previous=parent;
            }
            parent=current;
            if(current->right_Thread==1)
                current=current->right_Node;
            else
                current=NULL;
        }
    }
    if(parent->value>value) {
        parent->left_Thread=1;
        parent->left_Node=newnode;
        newnode->left_Node=previous;
        newnode->right_Node=parent;
    }
    else {
        parent->right_Thread=1;
        parent->right_Node=newnode;
        newnode->left_Node=parent;
        newnode->right_Node=previous;
    }
    return ;
}
//�޽u�G���𤤧Ǩ��X
void trace() {
    ThreadBinaryTree tempNode;
    tempNode=rootNode;
    do {
        if(tempNode->right_Thread==0)
            tempNode=tempNode->right_Node;
        else
        {
            tempNode=tempNode->right_Node;
            while(tempNode->left_Thread!=0)
                tempNode=tempNode->left_Node;
        }
        if(tempNode!=rootNode)
            cout<<"["<<setw(3)<<tempNode->value<<"]"<<endl;
      } while(tempNode!=rootNode);
} 
int main(void)
{
    int i=0;
    int array_size=11;
    cout<<"�޽u�G����g�إ߫�,�H���ǰl�ܯ঳�ƧǪ��ĪG"<<endl;
    cout<<"�Ĥ@�ӼƦr���޽u�G���𪺶}�Y�`�I,���C�J�Ƨ�"<<endl;
    int data1[]={0,10,20,30,100,399,453,43,237,373,655};
    for(i=0;i<array_size;i++)
        Add_Node_To_Tree(data1[i]);
    cout<<"===================================="<<endl;
    cout<<"�d�� 1 "<<endl;
    cout<<"�Ʀr�Ѥp��j���ƧǶ��ǵ��G��: "<<endl;
    trace();
    int data2[]={0,101,118,87,12,765,65};
    rootNode=NULL;//�N�޽u�G���𪺾���k�s
    array_size=7;//��2�ӽd�Ҫ��}�C���׬�7
    for(i=0;i<array_size;i++)
        Add_Node_To_Tree(data2[i]);    
    cout<<"===================================="<<endl;
    cout<<"�d�� 2 "<<endl;
    cout<<"�Ʀr�Ѥp��j���ƧǶ��ǵ��G��: "<<endl;
    trace();
    cout<<endl; 
	return 0;
}
