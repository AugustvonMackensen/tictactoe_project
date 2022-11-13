#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <iostream>
using namespace std;


class Board {
	char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; //ƽ���� �� 2���� �迭
	int mark; //���� �� ��
	int player =1; // �÷��̾�, �÷��̾� 1�� ���� �����ϹǷ� 1�� �ʱ� ������.
	int choice; // ���� ��ġ ����
	char move; //���� ��ġ�� �����ϸ� ������ ��ġ�� ���� ���� ��� ������ ����
	char unit1, unit2; //�÷��̾� 1�� �÷��̾� 2�� ��
	char result = 'p'; //��� ���. �⺻�� p�� ������ �ºΰ� ���� �� ���¸� �ǹ�.

public:
	void init() {
		system("cls"); //ƽ���� ���� ����.
		cout << "���� �� ���� ���� : (1: X, 2: O) :";
		cin >> mark;
		switch(mark) {
			case 1: 
				//���� �� ���� 'X'�� ���
				unit1 = 'X';
				unit2 = 'O';
				break;
			case 2: 
				//���� �� ���� 'O'�� ���
				unit1 = 'O';
				unit2 = 'X';
				break;
			default: cout << "�߸� �Է��ϼ̽��ϴ�." << endl; //���� �޽��� ���
			}
		
	}
	void display_board() {
		//���� ƽ���� �� ���
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
		//����� ��ȯ
		//���� ���� ���� ���� üũ
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

		//�밢�� ���� üũ
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
		//�÷��̾� 1�� ���� �����ϵ��� ��
		do {
			display_board();
			player = (player % 2) ? 1 : 2;
			cout << player << "�� ���� ��ġ�� �Է��Ͻÿ� : ";
			cin >> choice;
			move = (player == 1) ? unit1 : unit2;
			playerPosition(move, choice);
			
			result = gameOver();
			if (result != 'p') {
				//������ �ºΰ� ������ �ݺ��� ��������.
				break;
			}
			player++;
		} while (true);
		printResult(result);
	}

	void playerPosition(char &mv, int &ps) {
		//�Է¹��� ��ġ�� ���ڿ��� 1�� �� ���� 3���� �������� ���� ����
		//���� ��, �������� �� �ε����� ó��
		int row = (ps-1) / 3;
		int col = (ps-1) % 3;
		
		if (ps < 1 || ps > 9 || board[row][col] != (ps + '0')) {
			//���� ��ġ�� ���ڸ� �߸� �Է��� ���(1~9 ���� ���ڸ� �Է����� ���� ���)
			//�̹� ������ ��ġ�� �δ� ���� ����
			cout << "�߸� �����̼̽��ϴ�." << endl;
			player--;
			cin.ignore(); //�Է� ���۸� ���(undo ���)
		}
		else {
			board[row][col] = mv;
		}

	}

	void printResult(char &rs) {
		display_board();
		if (rs == unit1) {
			cout << "Player 1�� �¸��Ͽ����ϴ�." << endl;
		}
		else if (rs == unit2) {
			cout << "Player 2�� �¸��Ͽ����ϴ�." << endl;
		}
		else if(rs == '\0') {
			cout << "�����ϴ�." << endl;
		}
	}
};
#endif