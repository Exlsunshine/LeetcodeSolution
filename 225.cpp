#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if (!q2.empty())
            q2.push(x);
        else
            q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (q2.empty())
        {
            while (!q1.empty())
            {
                int element = q1.front();
                q1.pop();

                if (q1.empty())
                    break;
                else
                    q2.push(element);
            }
        }
        else
        {
            while (!q2.empty())
            {
                int element = q2.front();
                q2.pop();

                if (q2.empty())
                    break;
                else
                    q1.push(element);
            }
        }
    }

    // Get the top element.
    int top() {
        int element;
        if (q2.empty())
        {
            while (!q1.empty())
            {
                element = q1.front();
                q1.pop();
                q2.push(element);
            }
        }
        else
        {
            while (!q2.empty())
            {
                element = q2.front();
                q2.pop();
                q1.push(element);
            }
        }

        return element;
    }

    // Return whether the stack is empty.
    bool empty() {
        return (q1.empty() && q2.empty());
    }
private:
    queue<int> q1, q2;
};

int main(int argc, char const *argv[])
{
    queue<int> q;
    q.push(1);
    q.push(2);

    cout << q.front();
    q.pop();
    cout << q.front();
    q.pop();

    Stack s;
    s.push(1);
    s.push(2);

    cout << s.top();
    s.pop();
    cout << s.top();
    s.pop();


    return 0;
}







