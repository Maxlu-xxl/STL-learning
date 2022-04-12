#include<iostream>
#include<list>
using namespace std;

//初始化
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

//list插入和删除操作
void test02() {
	list<int> mlist;

	mlist.push_back(100);
	mlist.push_front(200);

	//插入
	//insert(pos.elem)  pos位置插入elem元素的拷贝，返回新元素的位置
	//insert(pos,n,elem)  pos位置插入n个elem元素，无返回值
	//insert(pos,beg,end)  pos位置插入[beg,end)区间的元素，无返回值

	mlist.insert(mlist.begin(), 300);
	mlist.insert(mlist.end(), 400);
	mlist.insert(mlist.end(), 200);


	//在第2号位置插入
	list<int>::iterator it = mlist.begin();
	it++;
	it++;
	mlist.insert(it, 500);
	mlist.insert(mlist.end(), 200);


	//删除
	//clear()  移除容器所有的数据
	//erase(beg,end)  删除[beg.end)区间的数据，返回下一个数据的位置
	//erase(pos)   删除pos位置的数据，返回下一个元素的位置
	//remove(elem)  删除容器中*******所有与elem值匹配*******的元素

	//list.pop_back();
	//mlist.pop_front();

	//mlist.erase(mlist.begin(), mlist.end());  //相当于调用mlist.clear()

	mlist.remove(200);
	//打印
	for (list<int>::iterator lit = mlist.begin(); lit != mlist.end(); lit++) {
		cout << *lit << " ";
	}
	cout << endl;

	cout <<"list容器是否为空："<< mlist.empty() << endl;

	//大小
	cout << "list容器大小为："<<mlist.size() << endl;

	//改变list大小
	mlist.resize(10);
	cout << "list容器大小改变后为：" << mlist.size() << endl;
}

//赋值，取值操作
void test03() {
	list<int> mlist;
	mlist.assign(10, 10);
	list<int> mlist2 = mlist;    //重载了=操作

	cout << mlist.front() << endl;
	cout << mlist.back() << endl;

}

//反转，排序操作
void test04() {

	list<int> mlist;  //定义
	//初始化
	for (int i = 0; i < 10; i++)  
		mlist.push_back(i);

	//打印
	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//反转打印
	mlist.reverse();
	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//排序打印
	mlist.sort();  //排序
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

