#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
    // Write your code here
    private:
    public:    
        vector<char> myStack;
        vector<char> myQueue;

        // STACK METHODS - Last In First Out (LIFO)
        void pushCharacter(char ch) // insert new elem *INTO* the stack @ THE BACK
        {
            myStack.push_back(ch);
        }
        char popCharacter() // delete the elem *OUT OF* the stack @ THE BACK
        {
            char chOut = myStack.back();
            myStack.pop_back();
            return chOut;
        }

        // QUEUE METHODS - First In First Out (FIFO)
        void enqueueCharacter(char ch) // insert new elem *INTO* the queue @ THE BACK
        {
            myQueue.push_back(ch);
        }        

        char dequeueCharacter() // delete the elem *OUT OF* the queue @ THE FRONT
        {
            char chOut = myQueue.front();
            myQueue.erase(myQueue.begin());
            return chOut;
        }
};

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}
