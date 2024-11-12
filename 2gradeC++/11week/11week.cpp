#include <iostream>
using namespace std;

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	Shape* add(Shape* p) {
		this->next = p;
		return p;
	}
	void paint() {
		draw();
	}
	Shape* getNext() { return next; }
};

class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};

class Circle : public Shape {
protected:
	virtual void draw() {
		cout << "Circle" << endl;
	}
};

class Rect : public Shape {
protected:
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};

class UI {
public:
	static int getMenu() {
		int key;
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
		cin >> key;
		return key;
	}
	static int input_shape() {
		int key;
		cout << "��:1, ��:2, �簢��:3 >> ";
		cin >> key;
		return key;
	}
	static int del_index() {
		int key;
		cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
		cin >> key;
		return key;
	}
};

class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
public:
	GraphicEditor() { pStart = pLast = NULL; }
	void insertItem(int type) {
		Shape* p = NULL;
		switch (type) {
		case 1:
			p = new Line();
			break;
		case 2:
			p = new Circle();
			break;
		case 3:
			p = new Rect();
			break;
		default:
			break;
		}
		if (pStart == NULL) {
			pStart = p;
			pLast = p;
			return;
		}
		pLast->add(p);
		pLast = pLast->getNext();
	}
	void deleteItem(int index) {
		Shape* pre = NULL;
		Shape* tmp = pStart;
		if (pStart == NULL) {
			cout << "������ �����ϴ�!" << endl;
			return;
		}
		if (index == 0) {
			pStart = tmp->getNext();
			delete tmp;
			return;
		}
		for (int i = 0; tmp != NULL && i < index; i++) {
			pre = tmp;
			tmp = tmp->getNext();
		}
		if (tmp == NULL) {
			cout << "��ȿ���� ���� �ε����Դϴ�!" << endl;
			return;
		}
		pre->add(tmp->getNext());
		delete tmp;
	}

	void show() {
		Shape* tmp = pStart;
		int i = 0;
		while (tmp != NULL) {
			cout << i++ << ": ";
			tmp->paint();
			tmp = tmp->getNext();
		}
	}
	void run() {
		cout << "�׷��� �������Դϴ�." << endl;
		int menu, index, type;
		while (true) {
			menu = UI::getMenu();
			switch (menu) {
			case 1:
				type = UI::input_shape();
				insertItem(type);
				break;
			case 2:
				index = UI::del_index();
				deleteItem(index);
				break;
			case 3:
				show();
				break;
			default:
				return;
			}
		}
	}
};

int main() {
	GraphicEditor graphicEditor;
	graphicEditor.run();

	return 0;
}