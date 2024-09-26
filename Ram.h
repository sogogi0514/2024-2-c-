#ifndef RAM_H   // 헤더 파일 중복 방지 
#define RAM_H

class Ram {   // 클래스 정의
    char mem[100 * 1024];  // 메모리  크기
    int size;  // 크기 저장 변수

public:
    Ram();  // 생성자
    ~Ram();  // 소멸자 
    char read(int address);  // 메모리 주소에서 데이터 읽기 함수 선언
    void write(int address, char value);  // 메모리 주소에 데이터 쓰기 함수 선언
};

#endif  // 헤더 파일 중복 방지
