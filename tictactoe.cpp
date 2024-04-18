#include <iostream>
using namespace std;

void printgrid(char arr[3][3]) {
	system("cls");
	for(int i=0; i<3; i++) {
		if(i == 0) {
			cout << "\n 1   2   3\n";
		}
		for(int j=0; j<3; j++) {
			cout <<" " << arr[i][j];
			if(j<2) {
				cout << " |";
			} else {
				cout << " " << i + 1;
			}
		}
		if (i<2) {
			cout <<"\n_______________\n";
		} else {
			cout << "\n\n\n";
		}
	}
}

string checkwin(char arr[3][3], char sym[2], int tur) {
	for (int i = 0; i <3; i++) {
		if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != '.' && arr[i][1] != '.' && arr[i][2] != '.') {
			if(arr[i][0] == sym[0]) {
				return "Player 1 wins!";
			} else {
				return "Player 2 wins!";
			}
		}
	}

	for (int i = 0; i <3; i++) {
		if(arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != '.' && arr[1][i] != '.' && arr[2][i] != '.') {
			if(arr[0][i] == sym[0]) {
				return "Player 1 wins!";
			} else {
				return "Player 2 wins!";
			}
		}
	}
	if(arr[0][0]==arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != '.') {
		if(arr[0][0] == sym[0]) {
			return "Player 1 wins!";
		} else {
			return "Player 2 wins!";
		}
	}

	if(arr[0][2]==arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != '.') {
		if(arr[0][2] == sym[0]) {
			return "Player 1 wins!";
		} else {
			return "Player 2 wins!";
		}
	}

	if(tur == 9) {
		return "draw";
	} else {
		return "ongoing";
	}
}

void putsymbol(char sym[2], char arr1[3][3], int* tur, string res) {
	int x,y;
	bool z =1;
	for(int i = 0; i<2; i++) {
		while(z) {
			while(z) {
				cout<<"\nFor player " << i+1 << ",enter the row of the placement(1,2,3): ";
				cin >> x;
				if(x > 0 && x<=3) {
					z = 0;
				} else {
					cout << "\nInvalid row number.";
				}
			}
			z=1;
			while(z) {
				cout<<"\nFor player " << i+1 << ",enter the column of the placement(1,2,3): ";
				cin >> y;
				if(y > 0 && y <=3) {
					z = 0;
				} else {
					cout << "\nInvalid column number.";
				}
			}
			z=1;

			if(arr1[x-1][y-1] == '.') {
				arr1[x-1][y-1] = sym[i];
				z = 0;
			} else {
				cout << "\nThat place is already taken!";
			}
		}
		(*tur)++;
		printgrid(arr1);
		res = checkwin(arr1, sym, *tur);
		cout << "\nResult: " << res << "\n";
		if(res == "ongoing") {
			z = 1;
			continue;
		} else {
			break;
		}
	}
}

int main() {
	bool y = 1;
	char grid[3][3];
	char symbol[2];

	while (y) {
		int turn = 0;
		string result = "ongoing";

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				grid[i][j] = '.';
			}
		}

		cout << "\nDo you want to play? (0/1): ";
		cin >> y;

		if (!y) {
			break;
		}

		cout << "\nFor player 1, choose the symbol (0(X)/1(O)): ";
		cin >> symbol[0];
		symbol[0] = (symbol[0] == '1') ? 'O' : 'X';
		symbol[1] = (symbol[0] == 'X') ? 'O' : 'X';

		cout << "\nStarting game: ";
		printgrid(grid);

		while (result == "ongoing") {
			putsymbol(symbol, grid, &turn, result);
			result = checkwin(grid, symbol, turn);
		}

		cout << "\nGame finished. Result: " << result << endl;
	}

	cout << "Thanks for playing!" << endl;
	return 0;
}
