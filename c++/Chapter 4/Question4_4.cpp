#include<iostream>
#include<vector>
#include<list>
#include<iomanip>
using namespace std;

struct node{
    int data;
    node *right, *left;
};

	void printTree(node* p, int indent)
	{
		if (p != NULL) {
			if (p->right) {
				printTree(p->right, indent + 4);
			}
			if (indent) {
				std::cout << std::setw(indent) << ' ';
			}
			if (p->right) std::cout << " /\n" << std::setw(indent) << ' ';
			std::cout << p->data << "\n ";
			if (p->left) {
				std::cout << std::setw(indent) << ' ' << " \\\n";
				printTree(p->left, indent + 4);
			}
		}
	}

void createMinimalBst(node* &root, int arr[], int start, int end){
    if(start>end)
        return;
    if(root==NULL){
        node *ptr = new node;
        int ind = start + (end-start)/2;
        ptr->data = arr[ind];
        ptr->left = NULL;
        ptr->right = NULL;
        root = ptr;
        createMinimalBst(root->left, arr, start, ind-1);
        createMinimalBst(root->right, arr, ind+1, end);
    }
}

void findLevelLinkedLists(vector<list<node*> > &res, node* root){
    list<node*> li;
    li.push_back(root);
    res.push_back(li);
    int depth = 0;
    while(!res[depth].empty()){
        list<node*> l;
        for(auto iter : res[depth] ){
            if(iter->left)
                l.push_back(iter->left);
            if(iter->right)
                l.push_back(iter->right);
        }
        res.push_back(l);
        depth++;
    }
}

void printLevelLinkedLists(vector<list<node*> > res){
    for(auto llist:res){
        for(nnode:llist){
            cout<<nnode->data<<" ";
        }
        cout<<'\n';
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    node* root;
    root = NULL;
    createMinimalBst(root, arr, 0, 8);
    printTree(root, 0);
    vector<list<node*> > res;
    findLevelLinkedLists(res, root);
    printLevelLinkedLists(res);
}
