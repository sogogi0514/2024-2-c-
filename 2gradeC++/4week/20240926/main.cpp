#include "Ram.h" 
#include <iostream> 

int main() {
    Ram ram;  // Ram 객체 생성
    ram.write(100, 20);  // 100번지 20
    ram.write(101, 30);  // 101번지 30
    char res = ram.read(100) + ram.read(101);  // 100번지 + 101번지
    ram.write(102, res);  // 102번지 결과저장
    std::cout << "102 번지의 값 = " << (int)ram.read(102) << std::endl;  // 102번지 출력
}