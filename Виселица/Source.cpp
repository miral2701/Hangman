//Создайте консольную версию игры «Виселица».
//Правила игры можно посмотреть по этой ссылке.
//Важно:
//■ Слово выбирается компьютером из списка слов.
//■ Список слов находится в файле в зашифрованном виде.
//■ По завершении игры на экран выводится статистика игры :
//• количество времени;
//• количество попыток;
//• искомое слово;
//• буквы игрока.

#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<ctime>
using namespace std;

static string a="             ";//строка в которую будут записываться правильно введенные символы
static string leters = "                                       ";//строка в которую будут записываться асе введенные символы
static int leters_count = 0;//индекс для записи символов 
int try_count = 0;//количество попыток выграша
int error_count = 0;//количество ошибок во время одной партии

//показ игрового поля и всех его вариацый
void drawField1() {
	
	cout << "                   Hangman" << endl;
	cout << "----------------------------------------------------"<<endl;
	cout << "-                                                  -" << endl;
	cout << "-                                                  -" << endl;
	cout << "-           |------------                          -" << endl;
	cout << "-           |/                                     -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-      ___________                                 -" << endl;
	cout << "-                                                  -" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << a << endl;

}
void drawField2() {
	
	cout << "                   Hangman" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "-                                                  -" << endl;
	cout << "-                                                  -" << endl;
	cout << "-           |------------                          -" << endl;
	cout << "-           |/          |                          -" << endl;
	cout << "-           |           |                          -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-      ___________                                 -" << endl;
	cout << "-                                                  -" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << a << endl;
}
void drawField3() {
	
	cout << "                   Hangman" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "-                                                  -" << endl;
	cout << "-                                                  -" << endl;
	cout << "-           |------------                          -" << endl;
	cout << "-           |/          |                          -" << endl;
	cout << "-           |           |                          -" << endl;
	cout << "-           |         (^-^)                        -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-      ___________                                 -" << endl;
	cout << "-                                                  -" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << a << endl;

}
void drawField4() {
	
	cout << "                   Hangman" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "-                                                  -" << endl;
	cout << "-                                                  -" << endl;
	cout << "-           |------------                          -" << endl;
	cout << "-           |/          |                          -" << endl;
	cout << "-           |           |                          -" << endl;
	cout << "-           |         (^-^)                        -" << endl;
	cout << "-           |           |                          -" << endl;
	cout << "-           |           |                          -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-      ___________                                 -" << endl;
	cout << "-                                                  -" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << a << endl;

}
void drawField5() {
	
	cout << "                   Hangman" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "-                                                  -" << endl;
	cout << "-                                                  -" << endl;
	cout << "-           |------------                          -" << endl;
	cout << "-           |/          |                          -" << endl;
	cout << "-           |           |                          -" << endl;
	cout << "-           |         (^-^)                        -" << endl;
	cout << "-           |           |\\                         -" << endl;
	cout << "-           |           | \\                        -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-      ___________                                 -" << endl;
	cout << "-                                                  -" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << a << endl;

}
void drawField6() {
	
	cout << "                   Hangman" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "-                                                  -" << endl;
	cout << "-                                                  -" << endl;
	cout << "-           |------------                          -" << endl;
	cout << "-           |/          |                          -" << endl;
	cout << "-           |           |                          -" << endl;
	cout << "-           |         (^-^)                        -" << endl;
	cout << "-           |          /|\\                         -" << endl;
	cout << "-           |         / | \\                        -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-      ___________                                 -" << endl;
	cout << "-                                                  -" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << a << endl;

}
void drawField7() {
	
	cout << "                   Hangman" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "-                                                  -" << endl;
	cout << "-                                                  -" << endl;
	cout << "-           |------------                          -" << endl;
	cout << "-           |/          |                          -" << endl;
	cout << "-           |           |                          -" << endl;
	cout << "-           |         (^-^)                        -" << endl;
	cout << "-           |          /|\\                         -" << endl;
	cout << "-           |         / | \\                        -" << endl;
	cout << "-           |            \\                         -" << endl;
	cout << "-           |             \\                        -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-      ___________                                 -" << endl;
	cout << "-                                                  -" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << a << endl;

}
void drawField8(string b) {
	
	cout << "                   Hangman" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "-                GAME OVER                         -" << endl;
	cout << "-                                                  -" << endl;
	cout << "-           |------------                          -" << endl;
	cout << "-           |/          |                          -" << endl;
	cout << "-           |           |                          -" << endl;
	cout << "-           |         (^-^)                        -" << endl;
	cout << "-           |          /|\\                         -" << endl;
	cout << "-           |         / | \\                        -" << endl;
	cout << "-           |          / \\                         -" << endl;
	cout << "-           |         /   \\                        -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-           |                                      -" << endl;
	cout << "-      ___________                                 -" << endl;
	cout << "-                                                  -" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "The word was: " << b<<endl;
	cout << "Time you spent: " << clock() / 1000 << " seconds"<<endl;
	cout << "Leters you used: "<<leters<<endl ;

}
void Win() {
	
	cout << "                   Hangman" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "-                   YOU WON!!!                     -" << endl;
	cout << "-                                                  -" << endl;
	cout << "-                                                  -" << endl;
	cout << "-                                                  -" << endl;
	cout << "-                                                  -" << endl;
	cout << "-                 try count: " <<   try_count  << "		         - " << endl;
	cout << "-                 The word was: " << a << "                - " << endl;
	cout << "-                 Time you spent: "<<clock()/1000<<"sec."<<"	   - " << endl;
	cout << "-                 Leters you used: "<<leters<<"          - " << endl;
	cout << "-                                                  -" << endl;
	cout << "-                                                  -" << endl;
	cout << "-                                                  -" << endl;
	cout << "-                                                  -" << endl;
	cout << "-                                                  -" << endl;
	cout << "----------------------------------------------------" << endl;
}


string Random(ifstream& out) {//Возвращает рандомное слово из файла
	
	out.seekg(0, ios::beg);
	int count = 0;
	while (!out.eof()) {
		string b;
		getline(out, b);
		count++;
		
	}
	srand(time(0));
	int number = rand()%count;
	out.seekg(0, ios::beg);
	string b;

	for (int i = 0; i <=number; i++) {
		getline(out, b);
	}
	return b;
}
string GuessWord(string b) {//возвращат строку в которую при правильно угаданном символе будет записан этот символ
	cout << "Enter char->";
	char c;
	cin >> c;
	leters[leters_count] = c;
	leters_count++;
	int index = 0;
	if (b.find(c, index) != 18446744073709551615) {
		while (b.find(c, index) != 18446744073709551615) {
			index = b.find(c, index);
			a[index] = c;

			index++;
		}
	}
	else {
		error_count++;
	}
	return a;
}

int main() {

	ifstream out("Text.txt");
	string b ;
	bool choice = true;

	while (b != a) {
		a = "             ";
		error_count = 0;
		leters = "                                                                                        ";
		leters_count = 0;
		b = Random(out);

		a.erase(b.size());

		if (choice == false) {
			exit(0);
		}

		while (error_count != 8 && b != a) {


			switch (error_count) {
			case 0:
				drawField1();
				GuessWord(b);
				system("cls");
				break;
			case 1:
				drawField2();
				GuessWord(b);
				system("cls");

				break;
			case 2:
				drawField3();
				GuessWord(b);
				system("cls");

				break;
			case 3:
				drawField4();
				GuessWord(b);
				system("cls");

				break;
			case 4:
				drawField5();
				GuessWord(b);
				system("cls");

				break;
			case 5:
				drawField6();
				GuessWord(b);
				system("cls");

				break;
			case 6:
				drawField7();
				GuessWord(b);
				system("cls");

				break;
			case 7:
				drawField8(b);
				cout << "Rematch?1-yes 0-no";
				cin >> choice;
				error_count++;
				system("cls");


				break;
			}
		}

		try_count++;

	}

	Win();
	out.close();
}

