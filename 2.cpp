/*
This program implements Singly Linked List using C++ which includes the following functions: 
insert(int data)  
insertAt(int pos, int data)  
delete()
deleteAt(int pos)
countItems()
display()
*/
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node()
    {
        data=0;
        next=NULL;
    }
};
class CLL
{
    Node* head;
    Node* tail;
    int size;
    public:
    CLL()
    {
        size=0;
        head=NULL;
        tail=NULL;
    }
   void insert(int n);
   void insertAt(int data, int position);
   void deleten();
   void deleteAt(int pos);
   int countItems();
   void display();
};
//inserts a node at the end of the circle
void CLL::insert(int n)
{
    Node* temp=new Node;
    temp->data=n;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        head->next=head;
        tail=temp;
        tail->next=head;
    }
    else
    {
        tail->next=temp;
        tail=temp;
        tail->next=head;
    }
    size++;
}
/*
   It includes the position at which the insertion happens. Positioning starts with 1.  
   Example: insertAt(1, 3)inserts 3 at the first position. 
	    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.
*/ 
void CLL::insertAt(int position, int num)
{
    if(position>size)
    {
        cout<<"\nNot many elements in the list present !";
    }
    else if(position==0)
    {
        Node* tmp=new Node;
        tmp->data=num;
        tmp->next=head;
        head=tmp;
        size++;
    }
    else if(position==size)
    {
        Node* tmp=new Node;
        tmp->data=num;
        tmp->next=head;
        if(head==NULL) // Steps to perform when the list is empty.
        {
            head=tmp;
        }
        else
        {
            tail->next=tmp;
        }
        tail=tmp;
        size++;
    }
    else
    {
        Node* n=new Node;
	    n->data=num;
	    Node* traverse=head;
        int count=0;
        while(count<position-1)
        {
          traverse=traverse->next;
          count++;
        }
        n->next=traverse->next;
        traverse->next=n;
        size++;
    }
}
//Deletes the element at the end of the list 
   void CLL::deleten()
   {
        Node* traverse = head;   //goes to the 2nd last
	    int count=0;
		while(count<size-2)
		{
			traverse = traverse->next;
			count++;
		}
		tail = traverse;
		traverse->next = head;
		size--;
   }
   //Deletes the element(or node) at the position pos
   void CLL::deleteAt(int pos)
   {
      if(pos>=size)
      {
	      cout<<"\n \nList doesn't have that many elements \n";
	      return;
      }
      int count=0;
      Node* temp, *temp1;
      temp = head  ;
      
      if(head==NULL)   // Steps to perform when the list is empty.
      {
        cout<<"\n \nLinked List Empty !!!";
	      return;
      }
      else if(pos == 0)
      {
        head = head->next;
        delete temp;
        size--;
      }
      else
      {
      while(count!= pos-1)
      {
         temp = temp->next;
         count++;   
      }
      temp1 = temp->next;
      temp->next = temp1->next;
      temp1->next=NULL;
      delete temp1;
      size--;
      }
   }
//Returns the number of items in the linked list. 
   int CLL::countItems()
   {
      //using size variable
	  int s=size;
	   return s; 
   }
//Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 
   void CLL::display()
   {
    if(head==NULL)
      cout << "\n \nNULL \n \nThe List is empty";             // Steps to perform when the list is empty.
    else
    {
      Node *temp = head;
      cout<<"\n \n";
      while(temp->next!=head)
      {
       cout << temp->data;
       cout<<"  -->  ";
       temp = temp->next;
      }
      cout<<temp->data<<" --> NULL \n";
     }
   }
//Main function to implement all the data structures and functions together
int main()
{
    int ch,x;
    char cha;
    int pos;
    CLL S;
    cout<<"\n \nPROGRAM TO USE THE CONCEPT OF LINKED LIST";
    //running a loop that asks continously to the user until "n" is received as an input
    do 
    {
       cout<<"\n1. Insert a node at the end \n2. Insert a node at a position specified \n3. Delete a node at the end ";
       cout<<"\n4. Delete a node at a position specifed \n5. Count the number of items \n6. Display ";
       cout<<"\nPlease enter your choice: ";
       cin>>ch;
       switch(ch)
       {
       case 1:
       {
              cout<<"\nEnter the data: ";
              cin>>x;
              S.insert(x);
              break;
        }
       case 2:
         {     cout<<"\nEnter the data to be inserted ";
              cin>>x;
              cout<<"\nEnter the position to insert the node ";
              cin>>pos;
              S.insertAt(pos,x);
              break;
          }
      case 3:
       {
		 S.deleten();	  
		 break;
       }
       case 4:
           {   cout<<"\nEnter the position of node to be deleted ";
              cin>>pos;
              S.deleteAt(pos);
              break;
	   }
       case 5:
          {
		  int num=0;
		  num=S.countItems();
		  cout<<"\n \nThe number of items in the Linked List is: "<<num;
		  break;
	  }		       
       case 6:
             {
                 S.display();
                 break;
              }
       default:
             { cout<<"\nWrong choice !!!!";
             break;}
    }
    cout<<"Do you want to continue? (y/n)  ";
    cin>>cha;
    }
    while(cha=='y' || cha=='Y');
    return 0;
}
