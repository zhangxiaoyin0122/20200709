#include <iostream>
using namespace std;

template<class T1,class T2>
class pair {
	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;

	pair()
		:first(T1())
		,second(T2())
	{}

	pair(const T1& a,const T2& b)
		:first(a)
		,second(b)
	{}

};


#include <iostream>
#include <string>
using namespace std;
//密码长度
int Length(const string& str) {
	if (str.size() <= 4)
		return 5;
	else if (str.size() > 4 && str.size() < 8)
		return 10;
	else
		return 25;
}
//
bool Letter1(const string& str) {
	for (int i = 0; i < str.size(); ++i) {
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
			return false; // 有字母
		}
	}
	return true; // 没有字母
}
//全小写
bool Letter2(const string& str) {
	for (int i = 0; i < str.size(); ++i) {
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
			if (str[i] >= 'A' && str[i] <= 'Z')
				return false;
		}
	}
	return true;
}
//全大写
bool Letter3(const string& str) {
	for (int i = 0; i < str.size(); ++i) {
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
			if (str[i] >= 'a' && str[i] <= 'z')
				return false;
		}
	}
	return true;
}

//字母
int Letter(const string& str) {
	if (Letter1(str)) {
		return 0;
	}
	else if (Letter2(str) || Letter3(str)) {
		return 10;
	}
	else {
		return 20;
	}
}

//数字
int number(const string& str) {
	int count = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] >= '0' && str[i] <= '9')
			count++;
	}
	if (count == 0)
		return 0;
	else if (count == 1)
		return 10;
	else
		return 20;
}

//符号
int symbol(const string& str) {
	int count = 0;
	for (int i = 0; i < str.size(); ++i) {
		if ((str[i] >= 33 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 64) ||
			(str[i] >= 91 && str[i] <= 96) || (str[i] >= 123 && str[i]) <= 126) {
			count++;
		}
	}
	if (count == 0)
		return 0;
	else if (count == 1)
		return 10;
	else
		return 25;
}

//奖励
int award(const string& str) {
	if (Letter(str) != 0 && number(str) != 0)
		return 2;
	if (Letter(str) != 0 && number(str) != 0 && symbol(str) != 0)
		return 3;
	if (Letter(str) == 20 && number(str) != 0 && symbol(str) != 0)
		return 5;
}

int main() {
	string str;
	while (cin >> str) {
		int ret = Length(str) + Letter(str) + number(str) + symbol(str) + award(str);
		if (ret >= 90)
			cout << "VERY_SECURE" << endl;
		else if (ret >= 80)
			cout << "SECURE" << endl;
		else if (ret >= 70)
			cout << "VERY_STRONG" << endl;
		else if (ret >= 60)
			cout << "STRONG" << endl;
		else if (ret >= 50)
			cout << "AVERAGE" << endl;
		else if (ret >= 25)
			cout << "WEAK" << endl;
		else if (ret >= 0)
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}