#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int Q;
    cin >> Q;
    stack<string> st;
    string stack;
    for (int i = 0; i < Q; ++i) {
        int n;
        cin >> n;
        if (n == 1) {
            string str;
            cin >> str;
            st.push(stack);
            stack += str;
        } else if (n == 2) {
            int j;
            cin >> j;
            st.push(stack);
            stack.erase(stack.size() - j);
        } else if (n == 3) {
            int k;
            cin >> k;
            cout << stack[k - 1] << "\n";
        } else {
            stack = st.top();
            st.pop();  
        }
    }
    
    return 0;
}
