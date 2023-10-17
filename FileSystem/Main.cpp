#include <iostream>
#include <string>
#include <fstream> //Библиотека, описывающая классы для работы с файловой системой устройства


const char stat_path[] = "stats.txt";

bool statistic(const std::string str) {
	static std::ofstream out;
	out.open(stat_path, std::ios::app);

	if (out.is_open())
	{
		out << str << ' ' << str.size() << '\n';
		out.close();
		return true;
	}
	else
		return false;
}
void print_file() {
	static std::ifstream in;
	in.open(stat_path);

	if (in.is_open()) 
	{
		char sym;
		while (in.get(sym))
			std::cout << sym;
		std::cout << std::endl;
		in.close();
	}
}
bool clear() {
	static std::ofstream out;
	out.open(stat_path);

	if (out.is_open())
	{
		out.close();
		return true;
	}
	return false;
}

int main () {
	system("chcp 1251>null"); //вместо сетлокейл, чтобы вводить на русском языке
	int n;
	std::string path = "file.txt";
	
	//Класс ofstream
	/*std::ofstream out; //Создание объекта для записи даных в файл
	//out.open(path); // Открытие файла с режимом по умолчанию std::ios::out
	out.open(path, std::ios::app); //открытие файла для добавления записей в конец


	if (out.is_open())
	{
		std::cout << "Файл открыт для записи.\n";
		std::string msg;
		std::cout << "Введите строку -> ";
		std::getline(std::cin, msg);
		out << msg << '\n'; //Добавление строки в файл

	}
	else
		std::cout << "Ошибка открытия файла\n";

	out.close();

	//Возможные причины ошибки при открытии файла с помощью ofstream:
	//1. Нет доступа к файлу;
	//2. Некорректный путь к файлу
	//3. Файл открыт другим объектом ил программой. */
	
	//Класс ifstream
	/*std::ifstream in;
	in.open(path);

	if (in.is_open())
	{
		std::cout << "Содержимое файла:\n";
		std::string file;
		// Посимвольное считываение
		//char sym;
		//while (in.get(sym))
		//	file += sym;
		//std::cout << file << std::endl;
		// Пословное считываение
		//while (!in.eof()) 
		//{
		//	std::string str;
		//	in >> str;
		//	file += str + '\n';
		//}
		//std::cout << file << std::endl;
		// Построчное считываение
		std::string str;
		while (std::getline(in, str))
			file += str + '\n';
		std::cout << file << std::endl;
	}
	else
		std::cout << "Ошибка открытия файла.\n";


	in.close();

	//Возможные причины ошибки при открытии файла с помощью ifstream:
	//1. Файла не существует;
	//2. Некорректный путь к файлу;
	//3. Нет доступа к файлу.*/

	//Удаление файла
	/*//remove(path.c_str()); //простой вариант использования функции


	//Правильный вариант использования
	if (remove(path.c_str()) == 0)
		std::cout << "Файл удален.\n";
	else
		std::cout << "Ошибка удаления файла.\n";
	
	//Возможные причины ошибки при удалении:
	//1. Файла не существует;
	//2. Нет доступа к файлу;
	//3. Файл открыт;
	//4. Некорректный путь к файлу;*/


	// Задача 1. Статистика
	std::cout << "Задача 1.\nВведите строку -> ";
	std::string str1;
	std::getline(std::cin, str1);
	if (statistic(str1))
		std::cout << "Запись добавлена в файл.\n\n";
	else
		std::cout << "Ошибка!\n\n";
	
	// Задача 2. Дополнения к задаче 1.


	return 0;
}