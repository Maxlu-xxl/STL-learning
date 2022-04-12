#include<iostream>
#include<vector>
using namespace std;


void PrintVector(vector<int> v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//vector��ʼ�����ַ�ʽ

void test01() {
	vector<int> v;   //Ĭ�Ϲ���
	int arr[] = { 10,20,30 };
	//vector(v.begin(),v.end())
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));
	vector<int> v3(v2.begin(),v2.end());
	vector<int> v4(v3);
	vector<int> v5(3, 10);    //���캯����n��elem����������
	PrintVector(v2);
	PrintVector(v3);
	PrintVector(v4);
	PrintVector(v5);

}

//���ø�ֵ����

//vector��С����
void test03() {
	int arr[] = { 100,200,300,400 };
	vector<int> v(arr,arr+sizeof(arr)/sizeof(int));
	cout << "Ԫ�ظ���size:" << v.size() << endl;

	if (v.empty())
		cout << "��" << endl;
	else
		cout << "�ǿ�" << endl;
	PrintVector(v);

	//resize(int num,elem)  ����ָ����������Ϊnum,�䳤�����elem(Ĭ��Ϊ0),������ɾ������Ԫ��
	v.resize(6);
	PrintVector(v);

	cout << "����>=size��" << v.capacity() << endl;

	//reserve(int num) Ԥ��λ�ã����ɷ���,�ܽ�ʡ�ռ䣬�����ڴ濪�ٴ�����ȱ�������Ҫ֪�����ٿռ�Ĵ�С
	v.reserve(100);
	cout << v.capacity() << endl;
}

//�����ɾ����vector��β�˲����ɾ��Ч�ʸߣ�ָ��λ�ò��룬Ч�ʵ�


//����swap�����ռ�
void test04() {
	//vector���Ԫ�أ������Զ�����������ɾ��Ԫ�أ������Զ�����
	vector<int> v;
	for (int i = 0; i < 10000; i++)
		v.push_back(i);
	cout << "size:" << v.size() << endl;
	cout << "������" << v.capacity() << endl;

	v.resize(10); 
	cout << "size:" << v.size() << endl;
	cout << "������" << v.capacity() << endl;

	//�����ռ�
	vector<int>(v).swap(v);
	cout << "�����ռ��" << endl;
	cout << "size:" << v.size() << endl;
	cout << "������" << v.capacity() << endl;

	//����vector<int>(v).swap(v);
	//vector<int>Ϊ�������� (v)��ʾ��vȥ��ʼ������������󣬶�������������v����ʵ��Ԫ�صĸ���ȥ��ʼ�����Լ�
	//Ȼ�������ռ�ָ���ָ�����˽�������������ָ��Ĵ��ڴ�ռ䣬vָ��ʵ�ʿռ䣬��������ᱻ���٣���ռ伴������
}


int main() {
	//test01();
	//test03();
	test04();
	return 0;
}