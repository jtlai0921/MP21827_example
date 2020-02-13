/*
[�ܽd]:���V��C��@
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
void enqueue(int value) 
{
    QueueByLinkedList node; //�إ߸`�I
    node=new QueueNode;
    node->data=value;
    node->next=NULL;
    //�ˬd�O�_���Ŧ�C
    if (rear==NULL)
        front=node;//�s�إߪ��`�I������1�Ӹ`�I
    else
        rear->next=node;//�N�`�I�[�J���C������
    rear=node;//�N��C�����ݫ��Ы��V�s�[�J���`�I
}
//��kdequeue:��C��ƪ����X
int dequeue(int action)
{
    int value;
    QueueByLinkedList tempNode,startNode;
    //�q�e�ݨ��X���
    if (!(front==NULL) && action==1) 
    {
        if(front==rear) rear=NULL;
        value=front->data;//�N��C��Ʊq�e�ݨ��X
        front=front->next;//�N��C���e�ݫ��Ы��V�U�@��
        return value;
    }
   //�q���ݨ��X���
   else if(!(rear==NULL) && action==2) 
   {
        startNode=front;//���O�U�e�ݪ����Э�
        value=rear->data;//���X�ثe���ݪ����
        //��M�̧��ݸ`�I���e�@�Ӹ`�I
        tempNode=front;
        while (front->next!=rear && front->next!=NULL) 
        { 
            front=front->next;
            tempNode=front;
        }
        front=startNode;//�O���q���ݨ��X��ƫ᪺��C�e�ݫ���
        rear=tempNode;//�O���q���ݨ��X��ƫ᪺��C���ݫ���
        //�U�@��{���O�����C���ȳѤU�̸`�I��,
        //���X��ƫ�K�Nfront��rear���VNULL
        if ((front->next==NULL) || (rear->next==NULL)) 
        { 
            front=NULL;
            rear=NULL;
        }
        return value; 
   }
   else return -1;
}
int main(void)
{
    int temp;
    cout<<"�H�쵲��C�ӹ�@���V��C"<<endl;
    cout<<"===================================="<<endl;
    cout<<"�b���V��C�e�ݥ[�J��1����ơA����ƭȬ�1"<<endl;
    enqueue(1);
    cout<<"�b���V��C�e�ݥ[�J��2����ơA����ƭȬ�3"<<endl;
    enqueue(3);
    cout<<"�b���V��C�e�ݥ[�J��3����ơA����ƭȬ�5"<<endl;
    enqueue(5);
    cout<<"�b���V��C�e�ݥ[�J��4����ơA����ƭȬ�7"<<endl;
    enqueue(7);
    cout<<"�b���V��C�e�ݥ[�J��5����ơA����ƭȬ�9"<<endl;
    enqueue(9);
    cout<<"===================================="<<endl;
    temp=dequeue(1);
    cout<<"�q���V��C�e�ݨ̧Ǩ��X��������ƭȬ��G"<<setw(1)<<temp<<endl;
    temp=dequeue(2);
    cout<<"�q���V��C���ݨ̧Ǩ��X��������ƭȬ��G"<<setw(1)<<temp<<endl;
    temp=dequeue(1);
    cout<<"�q���V��C�e�ݨ̧Ǩ��X��������ƭȬ��G"<<setw(1)<<temp<<endl;
    temp=dequeue(2);
    cout<<"�q���V��C���ݨ̧Ǩ��X��������ƭȬ��G"<<setw(1)<<temp<<endl;
    temp=dequeue(1);
    cout<<"�q���V��C�e�ݨ̧Ǩ��X��������ƭȬ��G"<<setw(1)<<temp<<endl;
    cout<<endl;
    return 0;
}
