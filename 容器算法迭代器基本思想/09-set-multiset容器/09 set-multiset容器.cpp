#include<iostream>
#include<set>
using namespace std;

//set/multiset����set��һ��ͷ�ļ�

/**set/multiset������������Ԫ�ػ����Ԫ�ص�ֵ�Զ�����**����****
set����RB-tree(�������ƽ���������һ�֣�Ϊ�ײ���ƣ������Ч�ʷǳ��á�
set�����в������ظ�Ԫ�أ�multiset�����ظ�Ԫ��***/

//������insert()����
//����ͨ���������޸�Ԫ�ص�ֵ�����ǿ���ɾ����Ԫ�أ��ٲ�����Ԫ��


//set������ʼ��
void test01() {
	//������insert()����
	set<int> s1;           //Ĭ�ϴ�С->������
	s1.insert(7);
	s1.insert(1);
	s1.insert(5);
	s1.insert(2);
	s1.insert(9);

	//��ӡ������˳����������������/�������/�������
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//��ֵ   
	set<int> s2;
	s2 = s1;

	//���롢ɾ��
	s1.erase(s1.begin());
	s1.erase(7);
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//��θı�Ĭ������

}

//����
void test02() {
	set<int> s1;
	s1.insert(7);
	s1.insert(1);
	s1.insert(5);
	s1.insert(2);
	s1.insert(9);
	
	//���Ҽ�key�Ƿ���ڣ����ڷ��ظļ��������������ڷ���map.end()
	//????????map.end()��ʲô
	set<int>::iterator ret1=s1.find(2);
	if (ret1 == s1.end()) {
		cout << "û���ҵ�" << endl;
	}
	else
		cout << "�ҵ���ret:" << *ret1 << endl;


	//lower_bound(keyelem)���ص�һ��key>=keyelemԪ�صĵ�����
	//upper_bound(keyelem)���ص�һ��key>keyelemԪ�صĵ�����
	//equal_range(keyelem)����������key��keyelemԪ����ȵ������޵�����������

	set<int>::iterator ret2 = s1.lower_bound(5);
	cout << "lowret:"<<*ret2 << endl;    //�ҳ���һ��>=5��Ԫ��

	set<int>::iterator ret3 = s1.upper_bound(5);
	cout <<"upper:"<< *ret3 << endl;     //�ҳ���һ��>5��Ԫ��

	//�ҵ�lower��upper��ֵ
	pair<set<int>::iterator, set<int>::iterator> myret = s1.equal_range(5);

	if (myret.first == s1.end()) {
		cout << "û���ҵ�";
	}
	else
		cout << "�ҵ���myret:"<<*myret.first << endl;

	if (myret.second == s1.end()) {
		cout << "û���ҵ�";
	}
	else
		cout << "�ҵ���myret:" << *myret.second << endl;

}

int main() {
	//test01();
	test02();
	return 0;
}

