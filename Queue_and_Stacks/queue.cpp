#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Solution { 
    public:
        void pushCharacter(char c);
        void enqueueCharacter(char c);
        char popCharacter();
        char dequeueCharacter();
    
    private: 
        stack<char> st;
        queue<char> qu;
};

void Solution::pushCharacter(char c)
{
    st.push(c);
}

void Solution::enqueueCharacter(char c)
{
    qu.push(c);
}

char Solution::popCharacter()
{
    char tmp = st.top();
    st.pop();
    return tmp;
}

char Solution::dequeueCharacter()
{
    char tmp = qu.front();
    qu.pop();
    return tmp;
}

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
