#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <iostream>
using namespace std;


class Board {
	char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; //ƽ���� �� 1���� �迭
	int mark; //���� �� ��
	int player =1; // �÷��̾� 1 ���� �����ϵ��� ��
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
	char resultGame() {
		//����� ��ȯ
		int check1 = 0, check2 = 0; //���� ĭ�� ���� ������ 1 �����Ͽ� ������ ����.
		//���� ���� ���� ���� üũ
		for(int i=0; i<3; i++) {

			for (int j = 0; j < 2; j++) {
				if (board[i][j] == board[i][j + 1]) {
					if (board[i][j] == unit1) {
						check1++;
					}
					else {
						check2++;
					}
				}
				else if (board[j][i] == board[j + 1][i]) {
					if (board[i][j] == unit1) {
						check1++;
					}
					else {
						check2++;
					}
				}
			}
		}

		//�밢�� ���� üũ
		for (int k=0; k<2; k++) {
			if (board[k][k] == board[k + 1][k + 1]) {
				if (board[k][k] == unit1) {
					check1++;
				}
				else {
					check2++;
				}
			}
			else {
				for (int m = 2; m > 0; m--) {
					if (board[k][m] == board[k + 1][m - 1]) {
						if (board[k][m] == unit1) {
							check1++;
						}
						else {
							check2++;
						}
					}
				}
			}
		}

		//
		if (check1 == 2) {
			result = unit1;
		}
		else if (check2 == 2) {
			result = unit2;
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
			if (choice == 1 && board[0][0] == '1') {
				board[0][0] = move;
			}
			else if (choice == 2 && board[0][1] == '2') {
				board[0][1] = move;
			}
			else if (choice == 3 && board[0][2] == '3') {
				board[0][2] = move;
			}
			else if (choice == 4 && board[1][0] == '4') {
				board[1][0] = move;
			}
			else if (choice == 5 && board[1][1] == '5') {
				board[1][1] = move;
			}
			else if (choice == 6 && board[1][2] == '6') {
				board[1][2] = move;
			}
			else if (choice == 7 && board[2][0] == '7') {
				board[2][0] = move;
			}
			else if (choice == 8 && board[2][1] == '8') {
				board[2][1] = move;
			}
			else if (choice == 9 && board[2][2] == '9') {
				board[2][2] = move;
			}
			else {
				//���� ��ġ�� ���ڸ� �߸� �Է��� ���(1~9 ���� ���ڸ� �Է����� ���� ���)
				cout << "�߸� �����̼̽��ϴ�." << endl;
				player--;
				cin.ignore(); //�Է� ���۸� ���
				cin.get();
			}
			result = resultGame();
			if (result != 'p') {
				//������ �ºΰ� ������ �ݺ��� ��������.
				break;
			}
			player++;
		} while (true);

		display_board();
		cout << result << endl;
		cin.ignore();
		cin.get();
	}
};
#endif