#include <iostream>
#include <string>  
#include <ctime>  
#include <cstdlib>  

using namespace std; 

// Player 클래스 정의
class Player {
    int card[3]; 
    string name;
public:
    Player() : Player("플레이어") { } 
    Player(string name) { this->name = name; } 
    string getName() { return name; } 
    bool playGambling(); 
};

// playGambling 메서드 정의
bool Player::playGambling() {
    for (int i = 0; i < 3; i++) {
        card[i] = rand() % 3; 
        cout << "\t" << card[i]; 
    }

    for (int i = 0; i < 2; i++) {
        if (card[i] != card[i + 1]) {
            return false; 
        }
    }
    return true; 
}

// GamblingGame 클래스 정의
class GamblingGame {
    Player player[2]; 
    bool isGameCompleted = false; 
public:
    GamblingGame(); 
    void play(); 
};

// GamblingGame 생성자 정의
GamblingGame::GamblingGame() {
    cout << "*****갬블링 게임을 시작합니다. *****" << endl; 
    string name; 
    cout << "첫번째 선수 이름>>"; 
    cin >> name; 
    player[0] = Player(name); 
    cout << "두번째 선수 이름>>";
    cin >> name; 
    player[1] = Player(name); 
    getchar(); 
}

// play 메서드 정의
void GamblingGame::play() {
    int i = 0; 
    while (!isGameCompleted) {
        cout << player[i % 2].getName() << ":<Enter>"; 
        getchar();
        if (player[i % 2].playGambling()) { 
            isGameCompleted = true; 
            cout << "\t" << player[i % 2].getName() << "님 승리!!" << endl; 
        }
        else {
            cout << "\t아쉽군요!" << endl; 
        }
        i++; 
    }
}

// main 함수
int main() {
    GamblingGame game; 
    game.play(); 

    return 0; 
}
