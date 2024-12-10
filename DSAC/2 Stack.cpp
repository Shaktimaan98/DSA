#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

class stack {
    node *top;
public:
    stack() {
        top = NULL;
    }

    int isEmpty() {
        if (top == NULL)
            return 1;
        else
            return 0;
    }

    void push(int x) {
        node *p;
        p = new node;
        p->data = x;
        p->next = top;
        top = p;
    }

    int pop() {
        int x;
        node *temp;
        if (top == NULL) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        x = top->data;
        temp = top;
        top = top->next;
        delete temp;
        return x;
    }

    int topdataa() {
        return top->data;
    }

    void display() {
        node *temp;
        temp = top;
        cout << "Stack is: ";
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
};

class post {
public:
    void inftopof(char inf[], char pof[], int k) {
        stack s;
        int i, j = 0;
        for (i = 0; inf[i] != '\0'; i++) {
            int x = inf[i];
            if (isalnum(x)) {
                pof[j++] = x;
            } else if (x == '(') {
                s.push(x);
            } else if (x == ')') {
                while ((x = s.pop()) != '(') {
                    pof[j++] = x;
                }
            } else {
                if (k == 1) {
                    while (!s.isEmpty() && icp(x) <= isp(s.topdataa())) {
                        pof[j++] = s.pop();
                    }
                    s.push(x);
                } else if (k == 2) {
                    while (!s.isEmpty() && icp(x) < isp(s.topdataa())) {
                        pof[j++] = s.pop();
                    }
                    s.push(x);
                }
            }
        }
        while (!s.isEmpty()) {
            pof[j++] = s.pop();
        }
        pof[j] = '\0';
    }

    int icp(char x) {
        switch (x) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
            return 4;
        }
        return 5;
    }

    int isp(char x) {
        if (x == '(')
            return 0;
        else if (x == '+' || x == '-')
            return 1;
        else if (x == '*' || x == '/' || x == '%')
            return 2;
        else if (x == '^')
            return 3;
        return 4;
    }

    void strrev(char inf[]) {
        int i = 0, j;
        j = strlen(inf) - 1;
        char temp;
        while (i < j) {
            temp = inf[i];
            inf[i] = inf[j];
            inf[j] = temp;
            i++;
            j--;
        }
    }

    void inftopre(char inf[], char pre[]) {
        strrev(inf);

        for (int i = 0; inf[i] != '\0'; i++) {
            if (inf[i] == '(')
                inf[i] = ')';
            else if (inf[i] == ')')
                inf[i] = '(';
        }
        inftopof(inf, pre, 2);
        strrev(pre);
    }

    float eval(char x, float x1, float x2) {
        switch (x) {
        case '+': return x1 + x2;
        case '-': return x1 - x2;
        case '*': return x1 * x2;
        case '/': return x1 / x2;
        case '%': return (int)x1 % (int)x2;
        case '^': return pow(x1, x2);
        }
        return -1;
    }

    float posteval(char post[]) {
        float x, x1, x2, val;
        stack s;
        for (int i = 0; post[i] != '\0'; i++) {
            x = post[i];
            if (isalpha(x)) {
                cout << "Enter the value of " << x << ": ";
                cin >> val;
                s.push(val);
            } else if (isdigit(x)) {
                s.push(x - '0');
            } else {
                x2 = s.pop();
                x1 = s.pop();
                val = eval(x, x1, x2);
                s.push(val);
            }
        }
        val = s.pop();
        return val;
    }

    float preeval(char pre[]) {
        float x, x1, x2, val;
        stack s;
        for (int i = strlen(pre) - 1; i >= 0; i--) {
            x = pre[i];
            if (isalpha(x)) {
                cout << "Enter the value of " << x << ": ";
                cin >> val;
                s.push(val);
            } else if (isdigit(x)) {
                s.push(x - '0');
            } else {
                x1 = s.pop();
                x2 = s.pop();
                val = eval(x, x1, x2);
                s.push(val);
            }
        }
        val = s.pop();
        return val;
    }
};

int main() {
    stack s;
    post p;
    int ch;
    char a[20], b[20], c[20], d[20];
    float f;
    while (1) {
        cout << "\n**********MENU**********\n";
        cout << "\n1.Infix to Postfix conversion\n2.Infix to Prefix conversion\n3.Evaluate Postfix Expression\n4.Evaluate Prefix Expression\n5.Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter the infix expression: ";
            cin >> a;
            p.inftopof(a, b, 1);
            cout << "Postfix expression is: " << b << endl;
            break;
        case 2:
            cout << "Enter the infix expression: ";
            cin >> a;
            p.inftopre(a, c);
            cout << "Prefix expression is: " << c << endl;
            break;
        case 3:
            cout << "Enter the postfix expression: ";
            cin >> a;
            f = p.posteval(a);
            cout << "Value of expression is: " << f << endl;
            break;
        case 4:
            cout << "Enter the prefix expression: ";
            cin >> a;
            f = p.preeval(a);
            cout << "Value of expression is: " << f << endl;
            break;
        case 5:
            exit(0);
        }
    }
}

