#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMax' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

vector<int> getMax(vector<string> operations) {
    stack<int> st;
    stack<int> tmp;
    vector<int> max;
    string s;
    int temp;
    
    for (int i = 0; i < operations.size(); ++i) {    
        switch (operations[i][0]) {
        case '1':
            s = operations[i].substr(2, ((operations[i].size()) - 1));
            temp = stoi(s);
            st.push(temp);
            
            if (tmp.empty()) {
                tmp.push(temp);
            } else if (tmp.top() <= temp) {
                tmp.push(temp);
            }
            break;
            
        case '2':
            if (!(st.empty() && tmp.empty())) {
                if (st.top() == tmp.top()) {
                    st.pop();
                    tmp.pop();
                } else {
                    st.pop();
                }
            }
            break;
            
        case '3':
            if (!(tmp.empty())) {
                max.push_back(tmp.top());
            }
            break;
        }
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> ops(n);

    for (int i = 0; i < n; i++) {
        string ops_item;
        getline(cin, ops_item);

        ops[i] = ops_item;
    }

    vector<int> res = getMax(ops);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
