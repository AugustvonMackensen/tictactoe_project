#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <iostream>


class Board {
	char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; //ƽ���� �� 1���� �迭
	int mark; //���� �� ��
	int player; // �÷��̾� 1�� �÷��̾� 2
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
		cout << "	" << board[0] << "	|	" << board[1] << "	|	" << board[2] << endl;
		cout << "________________|_______________|________________" << endl;
		cout << "		|		|		" << endl;
		cout << "	" << board[3] << "	|	" << board[4] << "	|	" << board[5] << endl;
		cout << "________________|_______________|________________" << endl;
		cout << "		|		|		" << endl;
		cout << "	" << board[6] << "	|	" << board[7] << "	|	" << board[8] << endl;
	}
	char resultGame() {
		//����� ��ȯ
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
			//��� �ʵ� ����, ����. �밢������ 3���� ���� ���� �ϼ����� ������ ��
			result = '\0';
			return result;
		}
	}
	void playGame() {
		//�÷��̾� 1�� ���� �����ϵ��� ��
		player = (player % 2)? 1: 2;
		move = (player == 1) ? unit1 : unit2;
		do {
			display_board();
			cout << player << "�� ���� ��ġ�� �Է��Ͻÿ� : ";
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

		cout << result << endl;
		cin.ignore();
		cin.get();
	}
};


#endif
