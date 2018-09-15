#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class node{
public:
	bool endmark;
	node *ar[27];
	node(){
		endmark = false;
		for (int i = 0; i < 27; i++) ar[i] = NULL;
    }
};
node *root;
void Insert(string word){

	int len = word.length();
	node *current =root;
	for (int i = 0; i < len; i++){
		int ascii = word[i] - 'a';
        if (current->ar[ascii] == NULL)
            current->ar[ascii] = new node();
        current= current->ar[ascii];
   }
	current->endmark = true;
}
bool Search(string word){

	int len = word.length();
	node *current = root;
	for (int i = 0; i < len; i++){
		int ascii = word[i] - 'a';
		if (current->ar[ascii] == NULL)
			return false;
		current = current->ar[ascii];
	}
	return current->endmark;
}


void del(node *cur)
{
	for (int i = 0; i<27; i++)
	if (cur->ar[i]){
		del(cur->ar[i]);
      }
    delete(cur);
}

int main(){
	root = new node();

	Insert("algo");
	Insert("also");
	Insert("algeria");
	cout << Search("algo") << endl;
	cout << Search("algeria") << endl;
	cout << Search("al") << endl;
	cout << Search("a") << endl;
	cout << Search("also") << endl;
	del(root); //delete full trie
return 0;
}
