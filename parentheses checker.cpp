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
		char pop() {
			
			node *current;
			current = head;
			
			node* previous;
			previous= head;
 
    		while(current->next != NULL) {
    			previous = current;
    			current = current->next;
			}
			char output = current -> data;
			previous->next = NULL;
			tail = previous;
			delete current;
			return output; 
		}
		char top() {
			if(head == NULL){
				return 'f';
			}
    		node *current;
			current = head;
			
			node* previous;
			previous= head;
 
    		while(current->next != NULL) {
    			previous = current;
    			current = current->next;
			}
			return current -> data;
		}
		int empty() 
		{ 
    		return head == NULL; 
		} 
};
bool AreParanthesesBalanced(string exp){
	stack S;
	bool flag = false;
	for(int i = 0; i < exp.length(); i++){
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
			S.push(exp[i]);
			openBrackets++;
		}
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
			closeBrackets++;
			char stat = S.top();
			if(stat == 'f'){
				return false;
				
			}
			if((S.top() == '(' && exp[i] == ')') || (S.top() == '{' && exp[i] == '}') || (S.top() == '[' && exp[i] == ']')){
				if(S.head != S.tail){
					S.pop();			
				}
			}
			else{
				return false;
				
				
			}
		}
	}
	if(S.head == S.tail && openBrackets == closeBrackets){
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
	ifstream mfile ("zahid file.txt");
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
	if(AreParanthesesBalanced(fileData))
		cout<<"Balanced\n";
	else{
		cout<<"Not Balanced\n";
	}
	cout << endl << "bracketCounter :" << bracketCounter << endl;
	
	return 0;
}
