#ifndef RAM_H   // ��� ���� �ߺ� ���� 
#define RAM_H

class Ram {   // Ŭ���� ����
    char mem[100 * 1024];  // �޸�  ũ��
    int size;  // ũ�� ���� ����

public:
    Ram();  // ������
    ~Ram();  // �Ҹ��� 
    char read(int address);  // �޸� �ּҿ��� ������ �б� �Լ� ����
    void write(int address, char value);  // �޸� �ּҿ� ������ ���� �Լ� ����
};

#endif  // ��� ���� �ߺ� ����
