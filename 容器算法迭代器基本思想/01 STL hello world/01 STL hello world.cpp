#include<iostream>
#include<vector>    //动态数组    可变数组
#include<algorithm>   //算法
using namespace std;


//ctrl+c、ctrl+k     多行注释
//ctrl+c、ctrl+u     取消多行注释

//容器也可以存放自定义数据类型
class Person {
public:
	Person(int age, int id) : age(age), id(id) {}
public:
	int age;
	int id;
};

//容器就像一个数组，容器会提供迭代器，迭代器就如同指针，通过迭代器访问容器中的元素
void test02() {
	vector<Person> v;     //存放自定义Person类型的容器v
	Person p1(10, 20), p2(30, 40), p3(50, 60);     //定义Person类型的三个对象
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	//遍历
	//容器中存放的什么数据类型，（*it)表示的就是该类型的对象，
	//这里（*it)表示Person类对象，所以用.访问该对象的age和id
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it).age << " " << (*it).id << endl;
	}
}



void PrintVector(int v) {
	cout << v << endl;
}

//STL基本语法
void test01() {
	//定义一个容器，并且制定这个容器存放的元素类型是int
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//通过STL提供的for_each算法
	//容器提供的迭代器
	//vector<int>::iterator 迭代器类型
	vector<int>::iterator pBegin = v.begin();    //pBegin为一个迭代器类型的变量，表示v.begin()
	vector<int>::iterator pEnd = v.end();
	//容器中可能存放基本数据类型，也可能存放自定义数据类型
	for_each(pBegin, pEnd, PrintVector);
}

//*********作业，容器存放Person类型的指针，并且用for_each打印 或者 迭代器方式***********
void test03() {
	vector<Person*> v;
	//怎么给Person类型的指针赋值呢？？？？？并且给p1,p2,p3分配内存呢？？
	Person* p1 = new Person(11, 22);
	Person* p2 = new Person(33, 44);
	Person* p3 = new Person(55, 66);
	//error 使用未初始化的内存p1,p2,p3???什么意思
	//p1->age = 11; p1->id = 22;
	//p2->age = 33; p2->id = 44;
	//p3->age = 55; p3->id = 66;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//遍历打印
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