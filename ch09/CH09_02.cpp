#include <iostream>
#include <cstdlib>
#include <iomanip>
#define ArraySize 10
using namespace std;
class Node//�G���𪺸`�I�ŧi
{
    public:
    int value;//�`�I���
    struct Node *left_Node;//���V���l�𪺫���
    struct Node *right_Node;//���V���k�l�𪺫���
};
typedef class Node TreeNode;//�w�q�s���G����`�I��ƫ��A
typedef TreeNode *BinaryTree;//�w�q�s���G�����쵲��ƫ��A
BinaryTree rootNode;//�G���𪺮ڸ`�I������ 

//�N���w���ȥ[�J��G���𤤾A���`�I
void Add_Node_To_Tree(int value)
{
      BinaryTree currentNode;
      BinaryTree newnode;
      int flag=0;//�ΨӬ����O�_���J�s���`�I
      newnode=(BinaryTree) malloc(sizeof(TreeNode));
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
int main(void)
{
    int tempdata;
    int content[ArraySize];
    int i=0;
    rootNode=(BinaryTree) malloc(sizeof(TreeNode));
    rootNode=NULL;
    cout<<"�гs���J10�����: "<<endl;
    for(i=0;i<ArraySize;i++)
    {
      cout<<"�п�J��"<<setw(1)<<(i+1)<<"�����: ";
      cin>>tempdata;       
      content[i]=tempdata;
    }
    for(i=0;i<ArraySize;i++) 
         Add_Node_To_Tree(content[i]);
    cout<<"�����H�쵲��C���覡�إߤG����";
    cout<<endl;  
	return 0;
}
