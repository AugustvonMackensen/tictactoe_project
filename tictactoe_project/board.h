#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <iostream>
using namespace std;


class Board {
	char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; //틱택토 판 2차원 배열
	int mark; //먼저 둘 말
	int player =1; // 플레이어, 플레이어 1이 먼저 시작하므로 1로 초기 선언함.
	int choice; // 놓을 위치 선택
	char move; //놓을 위치를 선택하면 선택한 위치에 놓을 말을 담는 문자형 변수
	char unit1, unit2; //플레이어 1과 플레이어 2의 말
	char result = 'p'; //결과 출력. 기본값 p는 게임의 승부가 나기 전 상태를 의미.

public:
	void init() {
		system("cls"); //틱택토 판을 지움.
		cout << "먼저 둘 말을 선택 : (1: X, 2: O) :";
		cin >> mark;
		switch(mark) {
			case 1: 
				//먼저 둘 말이 'X'인 경우
				unit1 = 'X';
				unit2 = 'O';
				break;
			case 2: 
				//먼저 둘 말이 'O'인 경우
				unit1 = 'O';
				unit2 = 'X';
				break;
			default: cout << "잘못 입력하셨습니다." << endl; //오류 메시지 출력
			}
		
	}
	void display_board() {
		//현재 틱택토 판 출력
		cout << "		|		|		" << endl;
		cout << "	" << board[0][0] << "	|	" << board[0][1] << "	|	" << board[0][2] << endl;
		cout << "________________|_______________|________________" << endl;
		cout << "		|		|		" << endl;
		cout << "	" << board[1][0] << "	|	" << board[1][1] << "	|	" << board[1][2] << endl;
		cout << "________________|_______________|________________" << endl;
		cout << "		|		|		" << endl;
		cout << "	" << board[2][0] << "	|	" << board[2][1] << "	|	" << board[2][2] << endl;
	}
	char gameOver() {
		//결과값 반환
		//가로 세로 빙고 여부 체크
		for(int i=0; i<3; i++) {
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
				if (board[i][0] == unit1) {
					result = unit1;
				}
				else {
					result = unit2;
				}
			}

			if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
				if (board[0][i] == unit1) {
					result = unit1;
				}
				else {
					result = unit2;
				}
			}
		}

		//대각선 빙고 체크
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
			if (board[0][0] == unit1) {
				result = unit1;
			}
			else {
				result = unit2;
			}
		}
		else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
			if (board[0][0] == unit1) {
				result = unit1;
			}
			else {
				result = unit2;
			}
		}
		
		else if(board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' && board[1][0] != '4'
			&& board[1][1] != '5' && board[1][2] != '6' && board[2][0] != '7' && board[2][1] != '8'
			&& board[2][2] != '9') {
			result = '\0';
		}
		return result;
	}

	void playGame() {
		//플레이어 1이 먼저 시작하도록 함
		do {
			display_board();
			player = (player % 2) ? 1 : 2;
			cout << player << "의 놓을 위치를 입력하시오 : ";
			cin >> choice;
			move = (player == 1) ? unit1 : unit2;
			playerPosition(move, choice);
			
			result = gameOver();
			if (result != 'p') {
				//게임의 승부가 났으면 반복문 빠져나옴.
				break;
			}
			player++;
		} while (true);
		printResult(result);
	}

	void playerPosition(char &mv, int &ps) {
		//입력받은 위치의 숫자에서 1을 뺀 값을 3으로 나누었을 때에 대한
		//몫은 행, 나머지는 열 인덱스로 처리
		int row = (ps-1) / 3;
		int col = (ps-1) % 3;
		
		if (ps < 1 || ps > 9 || board[row][col] != (ps + '0')) {
			//놓을 위치의 숫자를 잘못 입력한 경우(1~9 사이 숫자를 입력하지 않은 경우)
			//이미 놓여진 위치에 두는 행위 방지
			cout << "잘못 움직이셨습니다." << endl;
			player--;
			cin.ignore(); //입력 버퍼를 비움(undo 기능)
		}
		else {
			board[row][col] = mv;
		}

	}

	void printResult(char &rs) {
		display_board();
		if (rs == unit1) {
			cout << "Player 1이 승리하였습니다." << endl;
		}
		else if (rs == unit2) {
			cout << "Player 2가 승리하였습니다." << endl;
		}
		else if(rs == '\0') {
			cout << "비겼습니다." << endl;
		}
	}
};
#endif