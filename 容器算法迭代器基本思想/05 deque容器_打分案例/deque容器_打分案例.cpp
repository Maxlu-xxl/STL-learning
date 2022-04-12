#include<iostream>
#include<deque>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//��ί��ְ�����sort �㷨����
//����5��ѡ�֣��������÷֣� ��10����ί��5��ѡ�ִ��
//�÷ֹ���ȥ����߷֣�ȥ����ͷ֣�ȡ��ƽ��ֵ
//���÷ֶ�5��ѡ�ֽ�������

//����deque��������ɾ��
//�ȴ�ú�����ܣ�������������,�ǿ������гɹ��ģ�ֻ��û����ʾ

//ѡ����
class Player {
public:
	Player(){}
	Player(string name, int score) :mName(name), mScore(score) {}
public:
	string mName;
	int mScore;
};

//����ѡ��,ѡ����Ϣ�Ž�vector������
void Create_Player(vector<Player>& v) {
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		Player p;
		p.mName = "ѡ�֣�";
		p.mName += nameseed[i];
		v.push_back(p);
	}
}

//���
void Set_Score(vector<Player>& v){
    
	//����ѡ�ֽ��д��
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++) {

		//����һ�����ѡ�ַ�����deque
		deque<int> dScore;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;    //�����������
			dScore.push_back(score);
		}

		//�Ը�ѡ�ַ�����������Ĭ�ϴ�С����
		sort(dScore.begin(), dScore.end());

		//ȥ����ͷ֣�ȥ����ͷ�
		dScore.pop_front();
		dScore.pop_back();

		//ȡ��ѡ��ƽ����
		int totalScore = 0;
		for (deque<int>::iterator dit = dScore.begin(); dit != dScore.end(); dit++) {
			totalScore += (*dit);
		}

		int avgScore = totalScore / dScore.size();

		//����ѡ�ֵ�ƽ����д��ѡ�ֵ���Ϣ��
		(*it).mScore = avgScore;
	}
}

//�ƶ���������������ƶ����ǽ�������sortû���Զ�������ֻ�ܶԶ���ķ�����������
bool mycompare(Player &p1,Player &p2) {
	return p1.mScore > p2.mScore;
}

//���ݷ�������Ĭ�ϴ�С������ô�Ӵ�С�أ�����
void Print_Rank(vector<Player>& v) {
	//����,sort(start,end,cmp)cmp���򷽷�
	sort(v.begin(), v.end(),mycompare);
	//��ӡ
	for (vector<Player>::iterator it = v.begin(); it!=v.end(); it++) {
		cout << "ѡ�֣�" << (*it).mName << "�÷֣�" << (*it).mScore << endl;
	}
}

int main()
{
	//����vector����������ѡ����Ϣ
	vector<Player> vPlist;
	Create_Player(vPlist);
	Set_Score(vPlist);
	Print_Rank(vPlist);
	return 0;
}