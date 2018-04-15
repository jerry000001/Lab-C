#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <time.h> 
using namespace std;
class Organism {
public:
	int HP;
	int MP;
	bool dead()
	{
		if (HP == 0) return true;
		else return false;
	}
	void gethurt(int a)
	{
		if ((HP - a) >= 0) HP = HP - a;
		else HP = 0;
	}
};
class Summoner : public Organism {
public:
	int ATK; // Max ATK
	int rATK;
	void Create(int hp, int mp, int atk)
	{
		HP = hp;
		MP = mp;
		ATK = atk;
	}
	void random()
	{
		rATK = rand() % ATK + 1;
	}
};
class Monster : public Organism {
public:
	int ATK; // Max ATK
	int rATK;
	void Create(int hp, int mp, int atk)
	{
		HP = hp;
		MP = mp;
		ATK = atk;
	}
	void random()
	{
		rATK = rand() % ATK + 1;
	}
};
int main() {
	srand(time(NULL));
	Summoner s;
	s.Create(20, 5, 3);
	Monster m;
	m.Create(10, 5, 4);
	cout << "Create Summoner (" << s.HP << ", " << s.MP << ", " << s.ATK << ")" << endl;
	cout << "Create Monster  (" << m.HP << ", " << m.MP << ", " << m.ATK << ")" << endl;
	int round = 1;
	while (!s.dead() && !m.dead())
	{
		cout << "#" << round << endl;
		s.random();
		if (s.dead() == false)
		{
			m.gethurt(s.rATK);
			cout << "Summoner hurt Monster  " << s.rATK << "HP" << endl;
		}
		else cout << "Summoner Died." << endl;
		m.random();
		if (m.dead() == false)
		{
			s.gethurt(m.rATK);
			cout << "Monster  hurt Summoner " << m.rATK << "HP" << endl;
		}
		else cout << "Monster Died." << endl;
		cout << "Summoner HP is " << s.HP << endl;
		cout << "Monster  HP is " << m.HP << endl << endl;
		round++;
	}
	cout << "===END===" << endl;
	system("pause");
}