#include<iostream>
#include<string>
using namespace std;

//char* ��һ��ָ�룬String ��һ���࣬string��װ��char* ,��������ַ�������һ��char*�͵�����
//String��װ�˺ܶ�ʵ�õĳ�Ա����
//����find,����copy,ɾ��delete �滻replace,����insert
//���ÿ����ڴ��ͷź�Խ��
//string����char*��������ڴ棬ÿһ��string�ĸ��ƣ�ȡֵ����string�ฺ��ά�������ÿ��Ǹ���Խ���ȡֵԽ��
//string��char*�����໥ת����ͨ��string�ṩ��c_str()����

//��ʼ��
void test01() {
	string s1;//�����޲ι��캯��
	string s2(10, 'a');
	string s3("abcdefg");
	string s4(s3);  //��������
	
	cout << s1 << endl;           //û����ʾ
	cout << s2 << endl;           //aaaaaaaaaa
	cout << s3 << endl;           //abcdefg
	cout << s4 << endl;            //abcdefg

}

//��ֵ����,����'='��ֵ
void test02() {
	string s1;
	string s2("apple");
	s1 = "abcdefg";
	cout << s1 << endl;     //abcdefg
	s1 = s2;
	cout << s1 << endl;      //apple
	s1 = 'a';     
	cout << s1 << endl;        //a

	//��Ա����assign��ֵ
	s1.assign("jkl");
	cout << s1 << endl;    //ajkl  Ϊʲô��jkl???����Ϊ�Ǹ�ֵ����

}

//ȡֵ����
void test03() {
	string s1 = "abcdefg";

	//����[]������
	for (int i = 0; i < s1.size(); i++) {
		cout << s1[i] << " ";
	}
	cout << endl;

	//��Ա����
	for (int i = 0; i < s1.size(); i++) {
		cout << s1.at(i) << " ";
	}
	cout << endl;

	//����[]��ʽ����Խ�磬ֱ������
	//at��ʽ������Խ�磬�׳��쳣put_of_range

}

//string�����ɾ������
void test04() {
	string s1("abcdef");
	cout << s1 << endl;
	s1.insert(2, "eee");
	cout << s1 << endl;
	s1.erase(0, 2);    //ɾ����0��ʼ�������ַ�
	cout << s1 << endl;
}

//string���Һ��滻��Ƚ�
void test05() {
	string s1("abbcdecbbf");
	//s.rfind()��������ң�����ƥ��
	int pos1=s1.find("bb",0);    //����bb��һ�γ��ֵ�λ�ã���0��ʼ��
	int pos2 = s1.rfind("bb");    //����bb���һ�γ��ֵ�λ�ã���0��ʼ��
	int pos3 = s1.rfind("c", 5);    //��5��ʼ������ң�����ƥ��
	//��0��ʼ3���ַ��滻Ϊaaa
	string s2 = s1.replace(1, 3, "aaa");
	cout << pos1 << endl;
	cout << pos2 << endl;         //pos2=-1
	cout << pos3 << endl;
	cout << s2 << endl;

	//�Ƚϣ�compare������>ʱ����1��<ʱ����-1��==ʱ���أ��Ƚ�ʱ���ִ�Сд
	cout<<s1.compare("abbcdecbb")<<endl;

}

void test06() {
	string s1("abc");
	string s2 = s1.operator+=("def");
	cout <<"�ַ���abc������ַ���def:"<<s2 << endl;
	string s3 = s1.append("def");
	cout << "�ַ���abcdef������ַ���def:" << s3<< endl;
	string s4 = s1.append("defgh", 3);
	cout << "�ַ���abcdefdef������ַ���defgh��ǰ3���ַ�:" << s4 << endl;
	string s5 = s1.append("defgh", 0, 3);
	cout << "�ַ���abcdefdefdef������ַ���defgh�Ĵ�0��ʼ��3���ַ�:" << s5 << endl;
	string s6 = s1.append(5, 'a');
	cout << "���ַ���abcdefdefdefdef���5���ַ�a:" << s6 << endl;
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
