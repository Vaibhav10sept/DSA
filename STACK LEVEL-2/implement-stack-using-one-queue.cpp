#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    queue<int> q;

    void push(int data) {
        q.push(data);
        int size = q.size();
        //WV recommended, think, CS

        while (size != 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
    }

    int pop() {
        //I DID IT MYSELF
        if (q.empty()) {
            cout << "empty" << endl;
            return -1;
        }

        int ans = q.front();
        q.pop();
        return ans;
    }
};

// Driver code
int main()
{
    /*
    VIDEO: https://www.youtube.com/watch?v=jDZQKzEtbYQ&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=75
    QUESTION: https://takeuforward.org/data-structure/implement-stack-using-single-queue/
    */
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;

}