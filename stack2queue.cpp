#include <iostream>
#include <stdlib.h>
#include <stack>
/*
该文件代码使用2个栈实现队列
created time:2020.08.13
@Author：Jeaten
@E-mail：ljt_IT@163.com
*/
using namespace std;
class Solution{
public:
    void push(int node) {
        stack1.push(node);
        cout<<"入队成功！"<<endl;
    }
    int pop() {
        if(!stack2.empty()){
            stack2.pop();
            cout<<"出队成功！"<<endl;
        }else if(!stack1.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
            stack2.pop();
            cout<<"出队成功！"<<endl;
        }else{
            cout<<"队列为空！"<<endl;
        }
        return 0;
    }
    int print(){
        stack<int> temp;
        int count=1;
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        if(stack2.empty()){
            cout<<"队列为空！"<<endl;
        }else{
            temp=stack2;
            while(!temp.empty()){
                cout<<"队列中的第"<<count<<"个元素为："<<temp.top()<<endl;
                temp.pop();
                count++;
            }
        }
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};
int main(){
    Solution s;
    int choice=888,data;
    while(choice){
        cout<<"+----队列操作系统----+\t\t"<<endl;
        cout<<"|\t1.入队\t     |"<<endl;
        cout<<"|\t2.出队\t     |"<<endl;
        cout<<"|\t3.展示\t     |"<<endl;
        cout<<"|\t0.退出\t     |"<<endl;
        cout<<"+--------------------+\t\t"<<endl;
        cout<<"请出入您的选择：";
        cin>>choice;
        switch (choice){
        case 1:
            cout<<"请输入要入队的数：";
            cin>>data;
            s.push(data);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.print();
            break;
        case 0:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}
