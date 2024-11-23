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
	cout << "그래픽 에디터입니다. \n";
	while (true) {
		cout << "삽입: 1, 삭제: 2, 모두보기: 3, 종료: 4 >> ";
		cin >> choice;
		if (choice == 1) {
			int choiceShape;
			cout << "선: 1, 원: 2, 사각형: 3 >> ";
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
			cout << "삭제하고자 하는 도형의 인덱스 >> ";
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
	cout << "프로그램을 종료합니다..";
	return 0;
}