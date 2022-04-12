#include<iostream>
#include<list>
using namespace std;

//��ʼ��
void test01() {
	list<int> mlist1;
	list<int> mlist2(10, 10);
	list<int> mlist3(mlist2);
	list<int> mlist4(mlist2.begin(), mlist2.end());


	for (list<int>::iterator it = mlist4.begin(); it != mlist4.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//list�����ɾ������
void test02() {
	list<int> mlist;

	mlist.push_back(100);
	mlist.push_front(200);

	//����
	//insert(pos.elem)  posλ�ò���elemԪ�صĿ�����������Ԫ�ص�λ��
	//insert(pos,n,elem)  posλ�ò���n��elemԪ�أ��޷���ֵ
	//insert(pos,beg,end)  posλ�ò���[beg,end)�����Ԫ�أ��޷���ֵ

	mlist.insert(mlist.begin(), 300);
	mlist.insert(mlist.end(), 400);
	mlist.insert(mlist.end(), 200);


	//�ڵ�2��λ�ò���
	list<int>::iterator it = mlist.begin();
	it++;
	it++;
	mlist.insert(it, 500);
	mlist.insert(mlist.end(), 200);


	//ɾ��
	//clear()  �Ƴ��������е�����
	//erase(beg,end)  ɾ��[beg.end)��������ݣ�������һ�����ݵ�λ��
	//erase(pos)   ɾ��posλ�õ����ݣ�������һ��Ԫ�ص�λ��
	//remove(elem)  ɾ��������*******������elemֵƥ��*******��Ԫ��

	//list.pop_back();
	//mlist.pop_front();

	//mlist.erase(mlist.begin(), mlist.end());  //�൱�ڵ���mlist.clear()

	mlist.remove(200);
	//��ӡ
	for (list<int>::iterator lit = mlist.begin(); lit != mlist.end(); lit++) {
		cout << *lit << " ";
	}
	cout << endl;

	cout <<"list�����Ƿ�Ϊ�գ�"<< mlist.empty() << endl;

	//��С
	cout << "list������СΪ��"<<mlist.size() << endl;

	//�ı�list��С
	mlist.resize(10);
	cout << "list������С�ı��Ϊ��" << mlist.size() << endl;
}

//��ֵ��ȡֵ����
void test03() {
	list<int> mlist;
	mlist.assign(10, 10);
	list<int> mlist2 = mlist;    //������=����

	cout << mlist.front() << endl;
	cout << mlist.back() << endl;

}

//��ת���������
void test04() {

	list<int> mlist;  //����
	//��ʼ��
	for (int i = 0; i < 10; i++)  
		mlist.push_back(i);

	//��ӡ
	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//��ת��ӡ
	mlist.reverse();
	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//�����ӡ
	mlist.sort();  //����
	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	//test01();
	//test02();
	test04();
	return 0;
}

