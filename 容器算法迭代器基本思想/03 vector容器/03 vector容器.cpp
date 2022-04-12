#include<iostream>
#include<vector>
using namespace std;


void PrintVector(vector<int> v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//vector初始化四种方式

void test01() {
	vector<int> v;   //默认构造
	int arr[] = { 10,20,30 };
	//vector(v.begin(),v.end())
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));
	vector<int> v3(v2.begin(),v2.end());
	vector<int> v4(v3);
	vector<int> v5(3, 10);    //构造函数将n个elem拷贝给本身
	PrintVector(v2);
	PrintVector(v3);
	PrintVector(v4);
	PrintVector(v5);

}

//常用赋值操作

//vector大小操作
void test03() {
	int arr[] = { 100,200,300,400 };
	vector<int> v(arr,arr+sizeof(arr)/sizeof(int));
	cout << "元素个数size:" << v.size() << endl;

	if (v.empty())
		cout << "空" << endl;
	else
		cout << "非空" << endl;
	PrintVector(v);

	//resize(int num,elem)  重新指定容器长度为num,变长则填充elem(默认为0),缩短则删除多余元素
	v.resize(6);
	PrintVector(v);

	cout << "容量>=size：" << v.capacity() << endl;

	//reserve(int num) 预留位置，不可访问,能节省空间，减少内存开辟次数，缺点就是需要知道开辟空间的大小
	v.reserve(100);
	cout << v.capacity() << endl;
}

//插入和删除，vector在尾端插入和删除效率高，指定位置插入，效率低


//巧用swap缩减空间
void test04() {
	//vector添加元素，他会自动增长，但是删除元素，不会自动减少
	vector<int> v;
	for (int i = 0; i < 10000; i++)
		v.push_back(i);
	cout << "size:" << v.size() << endl;
	cout << "容量：" << v.capacity() << endl;

	v.resize(10); 
	cout << "size:" << v.size() << endl;
	cout << "容量：" << v.capacity() << endl;

	//收缩空间
	vector<int>(v).swap(v);
	cout << "收缩空间后：" << endl;
	cout << "size:" << v.size() << endl;
	cout << "容量：" << v.capacity() << endl;

	//解释vector<int>(v).swap(v);
	//vector<int>为匿名对象 (v)表示用v去初始化这个匿名对象，而匿名对象会根据v里面实际元素的个数去初始化它自己
	//然后两个空间指针的指向发生了交换，匿名对象指向的大内存空间，v指向实际空间，匿名对象会被销毁，大空间即被销毁
}


int main() {
	//test01();
	//test03();
	test04();
	return 0;
}