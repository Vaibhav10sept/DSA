#include <bits/stdc++.h>
using namespace std;

struct Queue {
    stack<int> input, output;

    void push(int data) { //TIME: 1
        input.push(data);
    }

    int pop() { //TIME: 1 -> amortized
        // shift input to output
        if (output.empty()) {
            while (input.size()) {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty()) return -1;
        int ans = output.top();
        output.pop();
        return ans;
    }

    int front() { //TIME: 1 -> amortized
        // shift input to output
        if (output.empty()) {
            while (input.size()) {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty()) return -1;
        return output.top();
    }

};

// Driver code
int main()
{
    /*
    NOTE: What is meant by amortized complexity?
    Amortized complexity is the total expense per operation, evaluated over a sequence of operations. The idea is to guarantee the total expense of the entire sequence, while permitting individual operations to be much more expensive than the amortized cost.
    TIME: push -> 1
          top and pop -> 1 -> amortized complexity
    VIDEO: https://www.youtube.com/watch?v=3Et9MrMc02A&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=76
    QUESTION: https://takeuforward.org/data-structure/implement-queue-using-stack/
    */
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
    cout << q.pop() << '\n';

    return 0;
}