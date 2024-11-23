#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Shape {
protected:
	virtual void draw() = 0;
public:
	void paint() { draw(); }
};

class Circle : public Shape {
protected:
	void draw() { cout << "Circle" << endl; }
};

class Rect : public Shape {
protected:
	void draw() { cout << "Rectangle" << endl; }
};

class Line : public Shape {
protected:
	void draw() { cout << "Line" << endl; }
};

int main() {
	int choice, index;
	string name;
	vector<Shape*> v;
	cout << "�׷��� �������Դϴ�. \n";
	while (true) {
		cout << "����: 1, ����: 2, ��κ���: 3, ����: 4 >> ";
		cin >> choice;
		if (choice == 1) {
			int choiceShape;
			cout << "��: 1, ��: 2, �簢��: 3 >> ";
			cin >> choiceShape;
			if (choiceShape == 1) {
				v.push_back(new Line);
			}
			else if (choiceShape == 2) {
				v.push_back(new Circle);
			}
			else if (choiceShape == 3) {
				v.push_back(new Rect);
			}
		}
		else if (choice == 2) {
			vector<Shape*>::iterator it;
			it = v.begin();
			cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
			cin >> index;
			for (int i = 0; i < index; i++) {
				it++;
			}
			it = v.erase(it);
		}
		else if (choice == 3) {
			for (int i = 0; i < size(v); i++) {
				cout << i << " : ";
				v[i]->paint();
			}
		}
		else if (choice == 4) {
			break;
		}
	}
	cout << "���α׷��� �����մϴ�..";
	return 0;
}