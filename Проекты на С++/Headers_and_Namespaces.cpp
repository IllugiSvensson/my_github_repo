//HEADER.hpp
//#include <iostream>
//using namespace std;
//int Module(int a, int b);	//прототип функции
//namespace _geek {		//Собственное пространство имен
//void PrintHello() {
//cout << "Hello, world!" << endl; }
//}

#include "HEADER.hpp"

//Задача на файлы-заголовки:
//Объявить в файле-заголовке программы прототип функции, вычисляющей остаток от деления одного целого числа на другое (операция ‘%’)/
//Реализовать объявленную функцию в основном файле программы.
//В основном файле программы создать функцию, выводящую на печать целое число.
//Вызвать функцию печати. В качестве аргумента использовать возвращаемое значение функции определения остатка.
	
int Module(int a, int b) {

	return a % b;		//Возвращаем остаток от деления

}

void PrintModule(int c) {
	
	cout << "Остаток от деления: " << c << endl;

}

//Задача на пространство имен:
//Составить файл-заголовок с пространством имен _geek.
//Определить в составленном файле-заголовке функцию с любой операцией и поместить ее в пространство имен _geek.
//Вызвать полученную функцию из основной программы, используя команду using.

using _geek::PrintHello;	//Используем функцию, определенной в пространстве _geek

int main(int argc, char** args) {
	
	PrintModule(Module(11, 4));	//Подставляем возвращаемое значение в качестве аргумента
	
	PrintHello();
	
return 0;
}