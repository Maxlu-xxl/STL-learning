#include<iostream>
#include<queue>
using namespace std;

//队列，只要符合先进先出的结构，就叫队列
//不能进行遍历，不支持随机存取，没有迭代器，仅仅队列和堆栈没有迭代器

//front队头，back队尾，push()入队。pop()出队

void test01() {

	queue<int> q1;  //创建队列

	q1.push(10);
	q1.push(20);
	q1.push(30);
	q1.push(40);

	cout << "队尾元素为：" << q1.back() << endl;

	while (!q1.empty()) {
		cout << q1.front() << " ";
		q1.pop();
	}

	cout << "队的大小为："<<q1.size() << endl;
}

/*********************作业1 queue容器存放对象指针***********************/
/*********************作业2 queue容器存放stack容器***********************/

int main() {
	test01();
	return 0;
}