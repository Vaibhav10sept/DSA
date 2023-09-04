#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    queue<int> q1, q2;

    void push(int data) {
        //I DID IT MYSELF
        q1.push(data);
    }

    int pop() {
        //I DID IT MYSELF
        if (q1.empty()) {
            cout << "empty" << endl;
            return -1;
        }

        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        //now, q1 has one element left
        int ans = q1.front();
        q1.pop();

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        return ans;
    }
};

// Driver code
int main()
{
    //I DID IT MYSELF
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