#include<iostream>
#include<string>
using namespace std;

//char* 是一个指针，String 是一个类，string封装了char* ,管理这个字符串，是一个char*型的容器
//String封装了很多实用的成员方法
//查找find,拷贝copy,删除delete 替换replace,插入insert
//不用考虑内存释放和越界
//string管理char*所分配的内存，每一次string的复制，取值都由string类负责维护，不用考虑复制越界和取值越界
//string和char*可以相互转换，通过string提供的c_str()方法

//初始化
void test01() {
	string s1;//调用无参构造函数
	string s2(10, 'a');
	string s3("abcdefg");
	string s4(s3);  //拷贝构造
	
	cout << s1 << endl;           //没有显示
	cout << s2 << endl;           //aaaaaaaaaa
	cout << s3 << endl;           //abcdefg
	cout << s4 << endl;            //abcdefg

}

//赋值操作,采用'='赋值
void test02() {
	string s1;
	string s2("apple");
	s1 = "abcdefg";
	cout << s1 << endl;     //abcdefg
	s1 = s2;
	cout << s1 << endl;      //apple
	s1 = 'a';     
	cout << s1 << endl;        //a

	//成员方法assign赋值
	s1.assign("jkl");
	cout << s1 << endl;    //ajkl  为什么是jkl???，因为是赋值操作

}

//取值操作
void test03() {
	string s1 = "abcdefg";

	//重载[]操作符
	for (int i = 0; i < s1.size(); i++) {
		cout << s1[i] << " ";
	}
	cout << endl;

	//成员函数
	for (int i = 0; i < s1.size(); i++) {
		cout << s1.at(i) << " ";
	}
	cout << endl;

	//区别：[]方式访问越界，直接无了
	//at方式，访问越界，抛出异常put_of_range

}

//string插入和删除操作
void test04() {
	string s1("abcdef");
	cout << s1 << endl;
	s1.insert(2, "eee");
	cout << s1 << endl;
	s1.erase(0, 2);    //删除从0开始的两个字符
	cout << s1 << endl;
}

//string查找和替换与比较
void test05() {
	string s1("abbcdecbbf");
	//s.rfind()是逆向查找，正向匹配
	int pos1=s1.find("bb",0);    //查找bb第一次出现的位置，从0开始找
	int pos2 = s1.rfind("bb");    //查找bb最后一次出现的位置，从0开始找
	int pos3 = s1.rfind("c", 5);    //从5开始逆向查找，正相匹配
	//从0开始3个字符替换为aaa
	string s2 = s1.replace(1, 3, "aaa");
	cout << pos1 << endl;
	cout << pos2 << endl;         //pos2=-1
	cout << pos3 << endl;
	cout << s2 << endl;

	//比较，compare函数在>时返回1，<时返回-1，==时返回，比较时区分大小写
	cout<<s1.compare("abbcdecbb")<<endl;

}

void test06() {
	string s1("abc");
	string s2 = s1.operator+=("def");
	cout <<"字符串abc后加上字符串def:"<<s2 << endl;
	string s3 = s1.append("def");
	cout << "字符串abcdef后加上字符串def:" << s3<< endl;
	string s4 = s1.append("defgh", 3);
	cout << "字符串abcdefdef后加上字符串defgh的前3个字符:" << s4 << endl;
	string s5 = s1.append("defgh", 0, 3);
	cout << "字符串abcdefdefdef后加上字符串defgh的从0开始的3个字符:" << s5 << endl;
	string s6 = s1.append(5, 'a');
	cout << "在字符串abcdefdefdefdef后加5个字符a:" << s6 << endl;
}
int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	return 0;
}
