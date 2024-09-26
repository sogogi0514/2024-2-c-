#include "Ram.h"  // ��� ����
#include <iostream>  

Ram::Ram() : size(100 * 1024) {  // ��-�� �ʱ�ȭ
    std::fill_n(mem, size, 0);  // mem �迭 �ʱ�ȭ
}

char Ram::read(int address) {  //������ �б�
    return mem[address];  // �޸� �� ��ȯ
}

void Ram::write(int address, char value) {  // ������ ����
    mem[address] = value;  // ���� ����
}

Ram::~Ram() {  // �Ҹ���
    std::cout << "�޸� ����" << std::endl;  // "�޸� ����" �޽��� ���
}