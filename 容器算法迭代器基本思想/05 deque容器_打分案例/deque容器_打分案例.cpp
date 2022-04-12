#include<iostream>
#include<deque>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//评委打分案例（sort 算法排序）
//创建5个选手（姓名、得分） ，10个评委对5个选手打分
//得分规则：去除最高分，去除最低分，取出平均值
//按得分对5名选手进行排名

//分析deque有序，两端删除
//先搭好函数框架，及主函数调用,是可以运行成功的，只是没有显示

//选手类
class Player {
public:
	Player(){}
	Player(string name, int score) :mName(name), mScore(score) {}
public:
	string mName;
	int mScore;
};

//创建选手,选手信息放进vector容器中
void Create_Player(vector<Player>& v) {
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		Player p;
		p.mName = "选手：";
		p.mName += nameseed[i];
		v.push_back(p);
	}
}

//打分
void Set_Score(vector<Player>& v){
    
	//遍历选手进行打分
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++) {

		//创建一个存放选手分数的deque
		deque<int> dScore;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;    //及格分往上走
			dScore.push_back(score);
		}

		//对该选手分数进行排序，默认从小到大
		sort(dScore.begin(), dScore.end());

		//去掉最低分，去掉最低分
		dScore.pop_front();
		dScore.pop_back();

		//取该选手平均分
		int totalScore = 0;
		for (deque<int>::iterator dit = dScore.begin(); dit != dScore.end(); dit++) {
			totalScore += (*dit);
		}

		int avgScore = totalScore / dScore.size();

		//将该选手的平均分写入选手的信息中
		(*it).mScore = avgScore;
	}
}

//制定排序规则，在这里制定的是降序排序，sort没法对对象排序，只能对对象的分数进行排序
bool mycompare(Player &p1,Player &p2) {
	return p1.mScore > p2.mScore;
}

//根据分数排序，默认从小到大，怎么从大到小呢？？？
void Print_Rank(vector<Player>& v) {
	//排序,sort(start,end,cmp)cmp排序方法
	sort(v.begin(), v.end(),mycompare);
	//打印
	for (vector<Player>::iterator it = v.begin(); it!=v.end(); it++) {
		cout << "选手：" << (*it).mName << "得分：" << (*it).mScore << endl;
	}
}

int main()
{
	//定义vector容器，保存选手信息
	vector<Player> vPlist;
	Create_Player(vPlist);
	Set_Score(vPlist);
	Print_Rank(vPlist);
	return 0;
}