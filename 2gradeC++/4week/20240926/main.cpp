#include "Ram.h" 
#include <iostream> 

int main() {
    Ram ram;  // Ram ��ü ����
    ram.write(100, 20);  // 100���� 20
    ram.write(101, 30);  // 101���� 30
    char res = ram.read(100) + ram.read(101);  // 100���� + 101����
    ram.write(102, res);  // 102���� �������
    std::cout << "102 ������ �� = " << (int)ram.read(102) << std::endl;  // 102���� ���
}