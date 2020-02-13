#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
class Node //���|�쵲�`�I���ŧi
{
   public:
   int data; //���|��ƪ��ŧi
   class Node *next;//���|���Ψӫ��V�U�@�Ӹ`�I
};
typedef class Node Stack_Node;//�w�q���|���`�I���s���A
typedef Stack_Node *Linked_Stack;//�w�q��C���|���s���A
Linked_Stack top=NULL;//���V���|���ݪ�����

//�P�_�O�_���Ű��|
int isEmpty() 
{
    if(top==NULL) return 1;
    else return 0;
}
//�N���w����Ʀs�J���|
void push(int data)
{
    Linked_Stack new_add_node; //�s�[�J�`�I������
    //�t�m�s�`�I���O����
    new_add_node=new Stack_Node;
    new_add_node->data=data;//�N�ǤJ���ȫ��w���`�I�����e
    new_add_node->next=top;//�N�s�`�I���V���|������
    top=new_add_node;//�s�`�I�������|������
}
//�q���|���X���
int pop()
{
    Linked_Stack ptr; //���V���|���ݪ�����
    int temp;
    if(isEmpty()) //�P�_���|�O�_����,�p�G�O�h�Ǧ^-1
    {
        cout<<"===�ثe���Ű��|==="<<endl;
        return -1;
    }
    else
    {
        ptr=top;//���V���|������
        top=top->next;//�N���|���ݪ����Ы��V�U�@�Ӹ`�I
        temp=ptr->data;//���X���|�����
        free(ptr);//�N�`�I���Ϊ��O��������
        return temp;//�N�q���|���X����Ʀ^�ǵ��D�{��
    }
}
//�D�{��
int main(void)
{
    int value;
    int i;
    cout<<"�Ш̧ǿ�J10�����:"<<endl;
    for(i=0;i<10;i++)
    {
        cin>>value;
        push(value);
    }
    cout<<"===================="<<endl;
    while(!isEmpty()) //�N��Ƴ���q���ݼu�X
        cout<<"���|�u�X�����Ǭ�:"<<setw(2)<<pop()<<endl; 
    cout<<"===================="<<endl;    
    return 0; 
}
