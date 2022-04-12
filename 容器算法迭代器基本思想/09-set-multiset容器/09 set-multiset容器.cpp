#include<iostream>
#include<set>
using namespace std;

//set/multiset都是set这一个头文件

/**set/multiset的特性是所有元素会根据元素的值自动进行**排序****
set是以RB-tree(红黑树，平衡二叉树的一种）为底层机制，其查找效率非常好。
set容器中不允许重复元素，multiset允许重复元素***/

//仅仅有insert()操作
//不能通过迭代器修改元素的值，但是可以删除该元素，再插入新元素


//set容器初始化
void test01() {
	//仅仅有insert()操作
	set<int> s1;           //默认从小->大排序
	s1.insert(7);
	s1.insert(1);
	s1.insert(5);
	s1.insert(2);
	s1.insert(9);

	//打印，不是顺序遍历，是先序遍历/中序遍历/后序遍历
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//赋值   
	set<int> s2;
	s2 = s1;

	//插入、删除
	s1.erase(s1.begin());
	s1.erase(7);
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//如何改变默认排序

}

//查找
void test02() {
	set<int> s1;
	s1.insert(7);
	s1.insert(1);
	s1.insert(5);
	s1.insert(2);
	s1.insert(9);
	
	//查找键key是否存在，存在返回改键迭代器，不存在返回map.end()
	//????????map.end()是什么
	set<int>::iterator ret1=s1.find(2);
	if (ret1 == s1.end()) {
		cout << "没有找到" << endl;
	}
	else
		cout << "找到了ret:" << *ret1 << endl;


	//lower_bound(keyelem)返回第一个key>=keyelem元素的迭代器
	//upper_bound(keyelem)返回第一个key>keyelem元素的迭代器
	//equal_range(keyelem)返回容器中key与keyelem元素相等的上下限的两个迭代器

	set<int>::iterator ret2 = s1.lower_bound(5);
	cout << "lowret:"<<*ret2 << endl;    //找出第一个>=5的元素

	set<int>::iterator ret3 = s1.upper_bound(5);
	cout <<"upper:"<< *ret3 << endl;     //找出第一个>5的元素

	//找到lower和upper的值
	pair<set<int>::iterator, set<int>::iterator> myret = s1.equal_range(5);

	if (myret.first == s1.end()) {
		cout << "没有找到";
	}
	else
		cout << "找到了myret:"<<*myret.first << endl;

	if (myret.second == s1.end()) {
		cout << "没有找到";
	}
	else
		cout << "找到了myret:" << *myret.second << endl;

}

int main() {
	//test01();
	test02();
	return 0;
}

