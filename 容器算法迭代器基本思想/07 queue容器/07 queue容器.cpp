#include<iostream>
#include<queue>
using namespace std;

//���У�ֻҪ�����Ƚ��ȳ��Ľṹ���ͽж���
//���ܽ��б�������֧�������ȡ��û�е��������������кͶ�ջû�е�����

//front��ͷ��back��β��push()��ӡ�pop()����

void test01() {

	queue<int> q1;  //��������

	q1.push(10);
	q1.push(20);
	q1.push(30);
	q1.push(40);

	cout << "��βԪ��Ϊ��" << q1.back() << endl;

	while (!q1.empty()) {
		cout << q1.front() << " ";
		q1.pop();
	}

	cout << "�ӵĴ�СΪ��"<<q1.size() << endl;
}

/*********************��ҵ1 queue������Ŷ���ָ��***********************/
/*********************��ҵ2 queue�������stack����***********************/

int main() {
	test01();
	return 0;
}