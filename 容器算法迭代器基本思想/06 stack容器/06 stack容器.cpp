#include<iostream>
#include<stack>
using namespace std;


/***********ջ���ܱ�������֧�������ȡ�������ṩ��������ֻ�ܴ�ջ���������************/

void test01() {

	//��ʼ��
	stack<int> s1;
	stack<int> s2(s1);   ///��s1��ʼ��s2

	//stack����
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(100);

	s1.pop();   

	//��ӡջ��������
	//stack��С����
	//empty();�ж϶�ջ�Ƿ�Ϊ��
	//size();���ض�ջ��С

	while (!s1.empty()) {
		cout<<s1.top() <<" ";    //���ջ��Ԫ��
		s1.pop();                 //ջ��Ԫ�س�ջ
	}

	cout << s1.size() << endl;
}


/*******************************��ҵ1  stack������Ŷ���ָ��*****************/

/*******************************��ҵ2  stack������Ŷ���*****************/





int main() {
	test01();
	return 0;
}

