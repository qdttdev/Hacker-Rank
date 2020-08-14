#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:

        Node* removeDuplicates(Node *head)
        {
            // Write your code here
            Node *curr = head;

            while(curr->next != NULL)
            {  
                if(curr->data == curr->next->data)
                {
                    // skip/remove curr->next
                    curr->next = curr->next->next;
                }
                else 
                {
                    curr = curr->next;
                }
            }

            return head;
        }

          Node* insert(Node *head,int data)
