#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;
struct Student {
	string name;
	string id;
	int score;
};
int main() {
	vector<struct Student> svector;
	int input;
	string name, id;
	int score;
	cout << "=== Add(0) / Delete(1) / Show(2) ===" << endl;
	cout << "Function you want : ";
	cin >> input;
	bool flag = true;
	while (flag) {
		if (input == 0) {
			cin >> name >> id >> score;
			struct Student newStudent;
			newStudent.name = name;
			newStudent.id = id;
			newStudent.score = score;
			svector.push_back(newStudent);
		}
		else if (input == 1) {
			if (svector.size() == 0) cout << "none" << endl;
			else
			{
				cout << "Which do you want to delete :";
				cin >> input;
				if (input - 1 > svector.size()) cout << "error" << endl;
				else svector.erase(svector.begin() + input - 1);
			}
		}
		else if (input == 2) {
			for (int i = 0; i<svector.size(); i++)
				cout << svector[i].name << " " << svector[i].id << " " << svector[i].score << endl;
		}
		else flag = false;
		cout << "Function you want : ";
		cin >> input;
	}
	system("PAUSE");
}