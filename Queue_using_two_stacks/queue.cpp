#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    stack<int> st1;
    stack<int> st2;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x == 1) {
            int q;
            cin >> q;
            st2.push(q);
        } else {
           if (st1.empty()) {
               while  (!st2.empty()) {
                   st1.push(st2.top());
                   st2.pop();
               }   
            }    
           if (!st1.empty()) {
               if (x == 2) {
                   st1.pop();
               } else if (x == 3) {
                   cout << st1.top() << endl;
               }
           }  
        }   
    }    
    return 0;
}
