#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
class Node//�G���𪺸`�I�ŧi
{
    public:
        int value;//�`�I���
        class Node *left_Node;//���V���l�𪺫���
        class Node *right_Node;//���V���k�l�𪺫���
};
typedef class Node TreeNode;//�w�q�s���G����`�I��ƫ��A
typedef TreeNode *BinaryTree;//�w�q�s���G�����쵲��ƫ��A
BinaryTree rootNode;//�G���𪺮ڸ`�I������ 
BinaryTree rootNode2;
//�N���w���ȥ[�J��G���𤤾A���`�I
void Add_Node_To_Tree(int value)
{
    BinaryTree currentNode;
    BinaryTree newnode;
    int flag=0;//�ΨӬ����O�_���J�s���`�I
    newnode=(BinaryTree) new TreeNode;
    //�إ߸`�I���e
    newnode->value=value;
    newnode->left_Node=NULL;
    newnode->right_Node=NULL;
    //�p�G���Ū��G����,�K�N�s���`�I�]�w���ڸ`�I
    if(rootNode==NULL)
        rootNode=newnode;
    else 
    {
        currentNode=rootNode;//���w�@�ӫ��Ы��V�ڸ`�I
        while(!flag)
            if (value<currentNode->value) 
            { //�b���l��
                if(currentNode->left_Node==NULL)
                {
                    currentNode->left_Node=newnode;
                    flag=1;
                }
                else
                    currentNode=currentNode->left_Node;
           }
           else
           { //�b�k�l��
                if(currentNode->right_Node==NULL) 
                {
                    currentNode->right_Node=newnode;
                    flag=1;
                }
                else
                    currentNode=currentNode->right_Node;
           }
    }
}
BinaryTree create(char sequence[100],int index,int ArraySize)
{
    BinaryTree tempNode;            
    if ( sequence[index]==0 ||index >= ArraySize )//�@���X�f����
        return NULL;
    else  
	{ 
	    tempNode=(BinaryTree) new TreeNode;
        tempNode->value=(int)sequence[index];
        tempNode->left_Node=NULL;
        tempNode->right_Node=NULL;
        //�إߥ��l��
        tempNode->left_Node = create(sequence, 2*index,ArraySize);
        //�إߥk�l��
        tempNode->right_Node = create(sequence, 2*index+1,ArraySize);
        return tempNode;
    }
}
//preOrder(�e�Ǩ��X)��k���{�����e
void preOrder(BinaryTree node) 
{
    if ( node != NULL ) 
	{
        cout<<setw(1)<<(char)node->value;
        preOrder(node->left_Node);  
        preOrder(node->right_Node); 
    }
}
//inOrder(���Ǩ��X)��k���{�����e
void inOrder(BinaryTree node) 
{
    if ( node != NULL ) {
        inOrder(node->left_Node);  
        cout<<setw(1)<<(char)node->value;
        inOrder(node->right_Node); 
    }
}
//postOrder(��Ǩ��X)��k���{�����e
void postOrder(BinaryTree node) 
{
    if ( node != NULL ) 
	{
        postOrder(node->left_Node);  
        postOrder(node->right_Node); 
        cout<<setw(1)<<(char)node->value;
    }
}
//�P�_�B�⦡�p��B�⪺��k�ŧi���e
int condition(char oprator, int num1, int num2)
{
    switch ( oprator ) {
        case '*': return ( num1 * num2 ); //���k�Ц^��num1 * num2
        case '/': return ( num1 / num2 ); //���k�Ц^��num1 / num2
        case '+': return ( num1 + num2 ); //�[�k�Ц^��num1 + num2
        case '-': return ( num1 - num2 ); //��k�Ц^��num1 - num2
        case '%': return ( num1 % num2 ); //���l�ƪk�Ц^��num1 % num2
    }
    return -1;
}
//�ǤJ�ڸ`�I,�Ψӭp�⦹�G���B��𪺭�
int answer(BinaryTree node) 
{
    int firstnumber = 0;       
    int secondnumber = 0;      
    //���j�I�s���X�f����
    if ( node->left_Node == NULL && node->right_Node == NULL )
        //�N�`�I�����ഫ���ƭȫ�Ǧ^
        return node->value-48;
    else {
        firstnumber = answer(node->left_Node);//�p�⥪�l��B�⦡����
        secondnumber = answer(node->right_Node); //�p��k�l��B�⦡����
        return condition((char)node->value, firstnumber, secondnumber);
    }
}
int main(void)
{
    //�Ĥ@���B�⦡ 
    char information1[] = {' ','+','*','%','6','3','9','5' };
    //�ĤG���B�⦡ 
    char information2[] = {' ','+','+','+','*','%','/','*',
                          '1','2','3','2','6','3','2','2' }; 
    rootNode=(BinaryTree)new TreeNode;                      
    rootNode2=(BinaryTree)new TreeNode;                     
    //create��k�i�H�N�G���𪺰}�C��ܪk�ഫ���쵲��ܪk
    rootNode = create(information1,1,8);
    cout<<"====�G���B���ƭȹB��d�� 1: ===="<<endl;
    cout<<"================================="<<endl;
    cout<<"===�ഫ�����ǹB�⦡===:  ";
    inOrder(rootNode);     
    cout<<endl<<"===�ഫ���e�ǹB�⦡===:  ";
    preOrder(rootNode);    
    cout<<endl<<"===�ഫ����ǹB�⦡===:  ";
    postOrder(rootNode);   
    //�p��G����B�⦡���B�⵲�G
    cout<<endl<<"���G���B���,�g�L�p���ұo�쪺���G��: ";
    cout<<setw(1)<<answer(rootNode);
    //�إ߲ĤG�ʤG���j�M�𪫥�
    rootNode2 = create(information2,1,16);
    cout<<endl;
    cout<<endl;
    cout<<"====�G���B���ƭȹB��d�� 2: ===="<<endl;
    cout<<"================================="<<endl;
    cout<<"===�ഫ�����ǹB�⦡===:  ";
    inOrder(rootNode2);     
    cout<<endl<<"===�ഫ���e�ǹB�⦡===:  ";
    preOrder(rootNode2);    
    cout<<endl<<"===�ഫ����ǹB�⦡===:  ";
    postOrder(rootNode2);   
    //�p��G����B�⦡���B�⵲�G
    cout<<endl<<"���G���B���,�g�L�p���ұo�쪺���G��: ";
    cout<<setw(1)<<answer(rootNode2); 
    cout<<endl;
    delete rootNode;
    delete rootNode2;
	return 0;
}
