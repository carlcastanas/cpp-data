#include<iostream>
using namespace std;

class node{
	public:
		node *next;
		int value;
};

class linklist{
	node *head;
	node *tail;
	public:
		linklist(){					// constructor
			head=NULL;
			tail=NULL;
		}
		void insert(int data){		// insert value in linklist
			node *ptr=new node;
			ptr->value=data;
			ptr->next=NULL;
			if(head==NULL){
				head=ptr;
				tail=ptr;
			}
			else{
				tail->next=ptr;
				tail=ptr;
			}
		}
		void search(int dat){
			node *ptr;
			int counter=1;
			ptr=head;
			while(ptr!=NULL){
				if(ptr->value==dat){
					cout<<"The searched value is found at node "<<counter<<endl;
				}
				else{
					counter++;
				}
				
				ptr=ptr->next;
			}
		}
		void del(char val){
			node *prev,*forward;
			prev=head;
			forward=head->next;
			if(prev->value==val){
				head=forward;
				delete(prev);
			}
			else{
				while(forward->value!=val){
					prev=prev->next;
					forward=forward->next;
				}
			
				if(forward->next==NULL){
					prev->next=NULL;
					delete(forward);
				}
				else{
					prev->next=forward->next;
					delete(forward);
				}
			}
		}
		void display(){
			node *ptr;
			ptr=head;
			while(ptr!=NULL){
				cout<<ptr->value<<endl;
				ptr=ptr->next;
			}
		}
		bool edit(char d,char v){
			node *ptr;
			ptr=head;
			while(ptr!=NULL){
				if(ptr->value==d){
					ptr->value=v;
					return true;
				}
				ptr=ptr->next;
			}
			return false;
		}
		
		void sort(){
			node *i,*j;
			for(i=head;i!=NULL;i=i->next){
				for(j=i->next;j!=NULL;j=j->next){
			
					if(i->value>j->value){
						swap(i->value,j->value);
					}
				}
		}
	}
};

//good

int main(){
	int data,i=0,x,input,insertvalue,deletevalue,editvalue,searchvalue,toedit;
	linklist ll;
	while(true){
	
	cout<<"following are Functions \n 1.Insert \n2.search \n3.edit \n4.delete \n5.display"<<endl;
	cin>>input;
	switch(input){
		case 1:{
			cout<<"Enter the value to insert"<<endl;
			cin>>insertvalue;
			ll.insert(insertvalue);
			ll.sort();
			cout<<"value has been inserted"<<endl;
			break;
		}
		case 2:{
			cout<<"Enter the value to search"<<endl;
			cin>>searchvalue;
			ll.search(searchvalue);
			break;
		}
		case 3:{
			cout<<"enter the value to edit"<<endl;
			cin>>editvalue;
			cout<<"enter the value to enter"<<endl;
			cin>>toedit;
			x=ll.edit(editvalue,toedit);
			ll.sort();
				if(x==1){
					cout<<"value has been edited "<<endl;
				}
				else{
					cout<<"given value is not found "<<endl;
				}
			break;
		}
		case 4:{
			cout<<"enter the value to delete"<<endl;
			cin>>deletevalue;
			ll.del(deletevalue);
			cout<<"value has been deleted"<<endl;
			break;
		}
		case 5:{
			ll.display();
			break;
		}
		default:{
			cout<<"wrong input"<<endl;
			break;
		}
		
	} 
	}
	return 0;
}
