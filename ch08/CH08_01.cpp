#include <iostream>
#include <iomanip>
#define MAXSTACK 100 //�w�q�̤j���|�e�q
using namespace std;
int stack[MAXSTACK];//���|���}�C�ŧi
int top=-1;//���|������
//�P�_�O�_���Ű��|
int isEmpty() 
{
    if(top==-1) return 1;
    else return 0;
}
//�N���w����Ʀs�J���|
int push(int data)
{
    if(top>=MAXSTACK)
    {
        cout<<"���|�w��,�L�k�A�[�J"<<endl;
        return 0; 
    }
    else
    {
        stack[++top]=data; //�N��Ʀs�J���|
        return 1;
    }
}
//�q���|���X���
int pop()
{
    if(isEmpty()) //�P�_���|�O�_����,�p�G�O�h�Ǧ^-1
        return -1;
    else
        return stack[top--]; //�N��ƨ��X��,�A�N���|���Щ��U��
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
