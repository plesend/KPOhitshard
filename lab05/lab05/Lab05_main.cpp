#include "Dictionary.h"
int main() {
	using namespace Dictionary;
	setlocale(LC_ALL, "rus");
#if (defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_DELENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) + defined(TEST_DICTIONARY) > 1 )
#error Должно быть определено только одно из тестовых условий

#endif
	try {

#ifdef TEST_CREATE_01 // Если определено TEST_CREATE_01 (первое тестовое условие)
		Instance d1 = Create("Пример для проверки", 5);
#endif

#ifdef TEST_CREATE_02 // Если определено TEST_CREATE_02 (второе тестовое условие)
		Instance d1 = Create("Пример строки", 100000);
#endif

#ifdef TEST_ADDENTRY_03
		Instance test = Create("Test", 0);
		Entry test_entry = { 1, "test_entry1" };
		AddEntry(test, test_entry);
#endif

#ifdef TEST_ADDENTRY_04 // Если определено TEST_ADDENTRY_04 (четвертое тестовое условие)
		Instance test = Create("Test", 2);
		Entry test_entry = { 1, "test_entry1" };
		AddEntry(test, test_entry);
		AddEntry(test, test_entry);
#endif

#ifdef TEST_GETENTRY_05 //GetEntry: не найдена запись
		Instance test = Create("Test", 2);
		Entry test_entry = { 1, "test_entry1" };
		AddEntry(test, test_entry);
		GetEntry(test, 2);
#endif

#ifdef TEST_DELENTRY_06 //DelEntry: не найдена запись
		Instance test = Create("Test", 2);
		Entry test_entry = { 1, "test_entry1" };
		AddEntry(test, test_entry);
		DelEntry(test, 2);
#endif

#ifdef TEST_UPDENTRY_07
		Instance test = Create("Test", 3);
		Entry test_entry = { 1, "test_entry1" }, entry_to_update = { 2, "entry_to_update" };
		AddEntry(test, test_entry);
		UpdEntry(test, 3, entry_to_update);
#endif

#ifdef TEST_UPDENTRY_08
		Instance test = Create("Test", 3);
		Entry test_entry = { 2, "test_entry1" }, entry_to_update = { 2, "entry_to_update" };
		AddEntry(test, test_entry);
		UpdEntry(test, 2, entry_to_update);
#endif

#ifdef TEST_DICTIONARY
		Dictionary::Instance d1 = Dictionary::Create("Преподаватели", 5);
		Dictionary::Entry e1 = { 1, "Гладкий" }, e2 = { 2, "Веялкин" },
			e3 = { 3, "Смелов" }, e4 = { 4, "Урбанович" }, e5 = { 2, "Пацей" };
		Dictionary::AddEntry(d1, e1);
		Dictionary::AddEntry(d1, e2);
		Dictionary::AddEntry(d1, e3);
		Dictionary::AddEntry(d1, e4);
		Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 4);
		Dictionary::DelEntry(d1, 2);
		Dictionary::Entry newentry1 = { 6, "Тугрин" };
		Dictionary::UpdEntry(d1, 3, newentry1);
		Dictionary::Print(d1);
		Dictionary::Instance d2 = Dictionary::Create("Студенты", 5);
		Dictionary::Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" }, s3 = { 3, "Сидоров" };
		Dictionary::AddEntry(d2, s1);
		Dictionary::AddEntry(d2, s2);
		Dictionary::AddEntry(d2, s3);
		Dictionary::Entry newentry3 = { 4, "Николаев" };
		Dictionary::UpdEntry(d2, 3, newentry3);
		Dictionary::Print(d2);
		Dictionary::Delete(d1);
		Dictionary::Delete(d2);
#endif
	}
	catch (char* e) {
		std::cout << e << std::endl;
	};
	system("pause");
	return 0;
}