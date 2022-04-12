#include<iostream>
#include<stack>
using namespace std;


/***********栈不能遍历，不支持随机存取，即不提供迭代器，只能从栈顶输入输出************/

void test01() {

	//初始化
	stack<int> s1;
	stack<int> s2(s1);   ///用s1初始化s2

	//stack操作
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(100);

	s1.pop();   

	//打印栈容器数据
	//stack大小操作
	//empty();判断堆栈是否为空
	//size();返回堆栈大小

	while (!s1.empty()) {
		cout<<s1.top() <<" ";    //输出栈顶元素
		s1.pop();                 //栈顶元素出栈
	}

	cout << s1.size() << endl;
}


/*******************************作业1  stack容器存放对象指针*****************/

/*******************************作业2  stack容器存放对象*****************/





int main() {
	test01();
	return 0;
}

