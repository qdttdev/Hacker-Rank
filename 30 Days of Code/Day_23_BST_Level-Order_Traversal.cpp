#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }

        void levelOrder(Node * root)
        {
            // Objective: Since the BST is already implemented, we will traverse through the tree (using curr pointer) from top to bottom, 
            // left to right (Breadth First Search). Using a queue, we will push in the first element (starting with root, then either 
            // left or right leaf) then pop it after outputing, continuing reading the in the next node, from left to right.

            queue <Node*> q;
            Node* curr;

            q.push(root);

            while(!q.empty())
            {
                curr = q.front();
                cout << curr->data << " ";
                q.pop();

                if(curr->left != NULL)
                {
                    q.push(curr->left);
                }
                if(curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
        }

};//End of Solution
