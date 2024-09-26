#include "Ram.h"  // 헤더 포함
#include <iostream>  

Ram::Ram() : size(100 * 1024) {  // 생-사 초기화
    std::fill_n(mem, size, 0);  // mem 배열 초기화
}

char Ram::read(int address) {  //데이터 읽기
    return mem[address];  // 메모리 값 반환
}

void Ram::write(int address, char value) {  // 데이터 쓰기
    mem[address] = value;  // 값을 저장
}

Ram::~Ram() {  // 소멸자
    std::cout << "메모리 제거" << std::endl;  // "메모리 제거" 메시지 출력
}