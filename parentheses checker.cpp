#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class node{
	public:
		char data;
		node* next;
};
class stack{
	public:
		node *head, *tail;
	public:
		stack(){
			head = NULL;
			tail = NULL;
		}
		void push(char value){
			node *temp = new node;
			temp -> data = value;
			temp -> next = NULL;
			if(head == NULL){
				head = temp;
				tail = temp;
			}
			else{
				tail -> next = temp;
				tail = temp;
			}
			
		}
		void printList(){
			node *temp = new node;
			temp = head;
			while(temp != NULL){
				cout << temp -> data << "\t";
				temp = temp -> next;
			}
		}
		char pop() {
			
    		node *current;
			current = head;
			
			node* previous;
			previous= head;
 
    		while(current->next != NULL) {
    			previous = current;
    			current = current->next;	
			}
			previous->next = NULL;
			tail = previous;
			return current -> data;
			delete current;
		}
};


bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')'){
		cout<<"y()S";
		return true;
	}
	else if(opening == '{' && closing == '}'){
		cout<<"y{}S";
		return true;
	}
	else if(opening == '[' && closing == ']'){
		cout<<"y[]S";
		return true;
	}
	else{
		return false;
	}
}
bool bracketChaker(string exp)
{
	stack S;
	bool flag;
	for(int i = 0; i < exp.length(); i++)
	{
		
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			{
				S.push(exp[i]);
				flag = false;
				
			}
		else if( exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{	
			if(!ArePair(S.pop(),exp[i])){			
				flag = false;
			}
			else{
				S.pop();
				flag = true;
			}
		}
	}
	if(flag && S.head -> next == NULL){
		return true;
	}
	else{
		return false;
	}
}

int main()
{
	string fileData;
	
	//reading file
	string line;
	ifstream mfile ("program.txt");
	if (mfile.is_open())
	{
		while ( getline (mfile,line, '\0') )
    	{
    	  fileData = line;
    	  cout<<endl<<endl<<fileData<<endl<<endl<<endl;
    	}
		mfile.close();
	}
	else cout << "Unable to open file";
	if(bracketChaker(fileData))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
	return 0;
}
