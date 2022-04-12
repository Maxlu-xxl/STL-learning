#include<iostream>
#include<vector>    //��̬����    �ɱ�����
#include<algorithm>   //�㷨
using namespace std;


//ctrl+c��ctrl+k     ����ע��
//ctrl+c��ctrl+u     ȡ������ע��

//����Ҳ���Դ���Զ�����������
class Person {
public:
	Person(int age, int id) : age(age), id(id) {}
public:
	int age;
	int id;
};

//��������һ�����飬�������ṩ������������������ָͬ�룬ͨ�����������������е�Ԫ��
void test02() {
	vector<Person> v;     //����Զ���Person���͵�����v
	Person p1(10, 20), p2(30, 40), p3(50, 60);     //����Person���͵���������
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	//����
	//�����д�ŵ�ʲô�������ͣ���*it)��ʾ�ľ��Ǹ����͵Ķ���
	//���*it)��ʾPerson�����������.���ʸö����age��id
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it).age << " " << (*it).id << endl;
	}
}



void PrintVector(int v) {
	cout << v << endl;
}

//STL�����﷨
void test01() {
	//����һ�������������ƶ����������ŵ�Ԫ��������int
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//ͨ��STL�ṩ��for_each�㷨
	//�����ṩ�ĵ�����
	//vector<int>::iterator ����������
	vector<int>::iterator pBegin = v.begin();    //pBeginΪһ�����������͵ı�������ʾv.begin()
	vector<int>::iterator pEnd = v.end();
	//�����п��ܴ�Ż����������ͣ�Ҳ���ܴ���Զ�����������
	for_each(pBegin, pEnd, PrintVector);
}

//*********��ҵ���������Person���͵�ָ�룬������for_each��ӡ ���� ��������ʽ***********
void test03() {
	vector<Person*> v;
	//��ô��Person���͵�ָ�븳ֵ�أ������������Ҹ�p1,p2,p3�����ڴ��أ���
	Person* p1 = new Person(11, 22);
	Person* p2 = new Person(33, 44);
	Person* p3 = new Person(55, 66);
	//error ʹ��δ��ʼ�����ڴ�p1,p2,p3???ʲô��˼
	//p1->age = 11; p1->id = 22;
	//p2->age = 33; p2->id = 44;
	//p3->age = 55; p3->id = 66;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//������ӡ
	vector<Person*>::iterator pBegin = v.begin();
	vector<Person*>::iterator pEnd = v.end();

	//for_each(pBegin,pEnd,Print)
	for (pBegin; pBegin != pEnd; pBegin++) {
		cout << (*pBegin)->age << " " << (*pBegin)->id << endl;
	}
}


int main() {
	cout << "test01():" << endl;
	test01();
	cout << "test02():" << endl;
	test02();
	cout << "test03():" << endl;
	test03();
	return 0;
}