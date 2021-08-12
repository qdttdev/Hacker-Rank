// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem

// Better solution: Use recursion to unstack to output list in reverse
void reversePrint(SinglyLinkedListNode* llist)  // TC: O(n), we recurse the depth of n
{                                               // SC: O(n), n = size of largest recursive stack, in this case the whole list
    // Base case
    if(llist == NULL)
    {
        return;
    }
    
    // Trickle forward
    
    // Recursive case
    reversePrint(llist->next);

    // Trickle backward
    cout << llist->data << endl;
}

// Iterative solution using vector to store, and print from end to front
void reversePrint(SinglyLinkedListNode* llist)  // TC: O(n), n = list size
{                                               // SC: O(n), n = list size (vector created)
    vector<int> vList;        
    SinglyLinkedListNode* curr = llist;
    
    while(curr != nullptr)
    {
        vList.push_back(curr->data);
        curr = curr->next;
    }
    
    for(int i = vList.size()-1; i>= 0; i--)
    {
        cout << vList[i] << endl;
    }
}
