#include <iostream>

using namespace std;

enum constant_set {		//Зададим перечислимое множество
	
	csConstant1 = 5,
	csConstant2 = 4,
	csConstant3 = 3,
	csConstant4 = 2,
	csConstant5 = 1,
	csConstant6 = 0

} c_set;

int main(int argc, char** args) {
	
//Задача на условия:
//Составить программу, принимающую от пользователя целое число.
//Если полученное число больше 5, запросить другое.
//Если вновь введенное число больше 5, но меньше 10, вычесть из него 5.
//В противном случае вычесть введенное число из 5.
//Проверить результат на равенство нулю, нахождение в диапазоне положительных и отрицательных чисел.

	int a;

	cout << "Введите число: ";
	cin >> a;
		
		if (a > 5) {			//Через условия проверяем число соответствию
						//заданным диапазонам
			cout << "Введите другое число: ";
			cin >> a;
		
				if ((a > 5) && (a < 10)) {

					a = a - 5;		//Делаем соответствующие вычисления

				} else if ((a <= 5) || (a >= 10)) {

					a = 5 - a;

				}
				
   		}

		if (a == 0) {			//Оцениваем полученное число

			cout << "a = 0" << endl;
		
		} else {
							
			(a < 0) ? (cout << "a < 0" << endl) : (cout << "a > 0" << endl);
		
		}

//Задача на множественный выбор:
//Составить перечислимое множество из 6 констант со значениями от 5 до 0.
//Получить от пользователя целое знаковое число.
//Проверить полученное число на попадание в первую и вторую половины множества.

	signed int s;
	
	cout << "Введите число: ";
	cin >> s;

		switch(s) {		//Проверка числа  проходит по всем константам до первого оператора break
			
			case csConstant1:
			case csConstant2:
			case csConstant3:
				cout << "Вы попали в первую половину множества" << endl;
				break;
			case csConstant4:
			case csConstant5:
			case csConstant6:
				cout << "Вы попали во вторую половину множества" << endl;
				break;
			default: 
				cout << "Неверный ввод" << endl;
				break;
				
		}	

//Задача на условные циклы:
//Получить от пользователя целое беззнаковое число.
//Проверить полученное число на превышение значения 3.
//Составить цикл с гарантированным выполнением, выводящий на экран полученное число, затем уменьшающий его на 1 без использования операции декремента ‘--’..
	
	unsigned int g;
	
	cout << "Введите число: ";
	cin >> g;
	
		if (g < 3) {
			
			cout << "Неверное число" << endl;

		} else {
					
			do {		//Последовательно выводим числа, не используя оператор --
			
				cout << g << endl;
				g -= 1;

			} while (g);

		}
		
//Задача на счетные циклы:
//Запрограммируйте счетный цикл, использующий переменную-счетчик для вывода значений типа char из заранее составленного массива.
//Для предварительного заполнения объявленного массива используйте счетный цикл с двумя счетчиками, один из которых увеличивается на 1, другой на 3.
	
	int i, j;
	char ar[9];

		for (i = 0, j = 17; i < 9; i++, j += 3) {

			ar[i] = j + '0';	//Превращаем целое число в символ из таблицы ASCII
						//и записываем циклом в массив каждый третий символ
		}
		
		for (i = 0; i < 9; i++) {	//Выводим массив на экран
		
			cout << ar[i] << endl;

		}
		
		//char j = 0x33;	//Вариант с присвоением номера символа
		//ar[i] = j;
		
return 0;
}