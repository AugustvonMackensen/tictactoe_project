#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <iostream>


class Board {
	char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; //틱택토 판 1차원 배열
	int mark; //먼저 둘 말
	int player; // 플레이어 1과 플레이어 2
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
		cout << "	" << board[0] << "	|	" << board[1] << "	|	" << board[2] << endl;
		cout << "________________|_______________|________________" << endl;
		cout << "		|		|		" << endl;
		cout << "	" << board[3] << "	|	" << board[4] << "	|	" << board[5] << endl;
		cout << "________________|_______________|________________" << endl;
		cout << "		|		|		" << endl;
		cout << "	" << board[6] << "	|	" << board[7] << "	|	" << board[8] << endl;
	}
	char resultGame() {
		//결과값 반환
		if (board[0] == board[1] && board[1] == board[2]) {
			if (unit1 == 3) {
				result = unit1;
			}
			else {
				result = unit2;
			}
			return result;
		}
		else if (board[3] == board[4] && board[4] == board[5]) {
			if (unit1 == 3) {
				result = unit1;
			}
			else {
				result = unit2;
			}
			return result;
		}
		else if (board[6] == board[7] && board[7] == board[8]) {
			if (unit1 == 3) {
				result = unit1;
			}
			else {
				result = unit2;
			}
			return result;
		}
		else if (board[0] == board[3] && board[3] == board[6]) {
			if (unit1 == 3) {
				result = unit1;
			}
			else {
				result = unit2;
			}
			return result;
		}
		else if (board[1] == board[4] && board[4] == board[7]) {
			if (unit1 == 3) {
				result = unit1;
			}
			else {
				result = unit2;
			}
			return result;
		}
		else if (board[2] == board[5] && board[5] == board[8]) {
			if (unit1 == 3) {
				result = unit1;
			}
			else {
				result = unit2;
			}
			return result;
		}
		else if (board[0] == board[4] && board[4] == board[8]) {
			if (unit1 == 3) {
				result = unit1;
			}
			else {
				result = unit2;
			}
			return result;
		}
		else if (board[2] == board[4] && board[4] == board[6]) {
			if (unit1 == 3) {
				result = unit1;
			}
			else {
				result = unit2;
			}
			return result;
		}
		else if (board[0] != '1' && board[1] != '2' && board[2] != '3' &&
			board[3] != '4' && board[4] != '5' && board[5] != '6' &&
			board[6] != '7' && board[7] != '8' && board[8] != '9') {
			//어느 쪽도 가로, 세로. 대각선으로 3개의 같은 말을 완성하지 못했을 때
			result = '\0';
			return result;
		}
	}
	void playGame() {
		//플레이어 1이 먼저 시작하도록 함
		player = (player % 2)? 1: 2;
		move = (player == 1) ? unit1 : unit2;
		do {
			display_board();
			cout << player << "의 놓을 위치를 입력하시오 : ";
			cin >> choice;
			if (choice == 1 && board[0] == '1') {
				board[0] = move;
			}
			else if (choice == 2 && board[1] == '2') {
				board[1] = move;
			}
			else if (choice == 3 && board[2] == '3') {
				board[2] = move;
			}
			else if (choice == 4 && board[3] == '4') {
				board[3] = move;
			}
			else if (choice == 5 && board[4] == '5') {
				board[4] = move;
			}
			else if (choice == 6 && board[5] == '6') {
				board[5] = move;
			}
			else if (choice == 7 && board[6] == '7') {
				board[6] = move;
			}
			else if (choice == 8 && board[7] == '8') {
				board[7] = move;
			}
			else if (choice == 9 && board[8] == '9') {
				board[8] = move;
			}
			else {
				//놓을 위치의 숫자를 잘못 입력한 경우(1~9 사이 숫자를 입력하지 않은 경우)
				cout << "잘못 움직이셨습니다." << endl;
				player--;
				cin.ignore(); //입력 버퍼를 비움
				cin.get();
			}
			result = resultGame();
			if (result != 'p') {
				//게임의 승부가 났으면 반복문 빠져나옴.
				break;
			}
			player++;
		} while (true);

		cout << result << endl;
		cin.ignore();
		cin.get();
	}
};


#endif
