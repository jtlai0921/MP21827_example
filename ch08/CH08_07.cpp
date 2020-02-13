/*
[�ܽd]:��@�H�쵲��C�إߦ�C
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
class Node
{
    public:
        int data;
        class Node *next;
};
typedef class Node QueueNode;
typedef QueueNode *QueueByLinkedList;
QueueByLinkedList front=NULL;
QueueByLinkedList rear=NULL;
//��kenqueue:��C��ƪ��s�J
void enqueue(int value) {
    QueueByLinkedList node; //�إ߸`�I
    node=new QueueNode;
    node->data=value;
    node->next=NULL;
    //�ˬd�O�_���Ŧ�C
    if (rear==NULL)
        front=node; //�s�إߪ��`�I������1�Ӹ`�I
    else
        rear->next=node; //�N�`�I�[�J���C������
    rear=node; //�N��C�����ݫ��Ы��V�s�[�J���`�I
}
//��kdequeue:��C��ƪ����X
int dequeue() 
{
    int value;
    //�ˬd��C�O�_���Ŧ�C
    if (!(front==NULL)) 
    {
        if(front==rear) rear=NULL;
        value=front->data; //�N��C��ƨ��X
        front=front->next; //�N��C���e�ݫ��Ы��V�U�@��
        return value;
    }
    else return -1;
}
int main(void)
{
    int temp;
    cout<<"�H�쵲��C�ӹ�@��C"<<endl;
    cout<<"===================================="<<endl;
    cout<<"�b��C�e�ݥ[�J��1����ơA����ƭȬ�1"<<endl;
    enqueue(1);
    cout<<"�b��C�e�ݥ[�J��2����ơA����ƭȬ�3"<<endl;
    enqueue(3);
    cout<<"�b��C�e�ݥ[�J��3����ơA����ƭȬ�5"<<endl;
    enqueue(5);
    cout<<"�b��C�e�ݥ[�J��4����ơA����ƭȬ�7"<<endl;
    enqueue(7);
    cout<<"�b��C�e�ݥ[�J��5����ơA����ƭȬ�9"<<endl;
    enqueue(9);
    cout<<"===================================="<<endl;
    while (1) 
    {
        if (!(front==NULL)) 
        {
            temp=dequeue();
            cout<<"�q��C�e�ݨ̧Ǩ��X��������ƭȬ��G"<<setw(1)<<temp<<endl;
        }
      else
         break;
    }
    cout<<endl;
    return 0;
}
