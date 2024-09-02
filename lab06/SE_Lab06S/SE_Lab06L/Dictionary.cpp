#include "Dictionary.h"
#include <iostream>
#include <cstring>
using namespace Dictionary;
using namespace std;

Instance Dictionary::Create(const char* name, int size)
{
	Instance NewDict;
	if (strlen(name) > ENTRYNAMEMAXSIZE)
	{
		throw THROW01; //"Create: �������� ������ �������" 
	}
	else
	{
		strcpy_s(NewDict.name, name);
	}
	if (NewDict.maxsize < size)
	{
		throw THROW02; //"Create: �������� ������ ������������ ������� �������"
	}
	else
	{
		NewDict.size = size;
	}

	NewDict.dictionary = new Entry[size]; //��������� ������ ��� ��������� ������� �������
	return NewDict;
}
void Dictionary::addEntry(Instance& inst, Entry ed)
{
	int cnt = inst.cnt;
	if (cnt >= inst.size)
	{
		throw THROW03;   //"AddEntry: ������������ �������"
	}
	else
	{
		inst.dictionary[cnt] = ed;
	}
	for (int i = 0; i < cnt; i++)
	{
		if (inst.dictionary[i].id == ed.id) throw THROW04; //"AddEntry: ������������ ��������������"
	}
	inst.cnt++;
}
void Dictionary::DelEntry(Instance& inst, int id)
{
	bool isFound = false;
	for (int i = 0; i < inst.cnt; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			isFound = true;
			for (int j = i; j < inst.cnt; j++)
			{
				inst.dictionary[j] = inst.dictionary[j + 1];
			}
			inst.cnt--;
			break;
		}
	}
	if (!isFound) throw THROW06; //"DelEntry: �� ������ �������"
}
Entry Dictionary::GetEntry(Instance& inst, int id)
{
	bool isFound = false;
	for (int i = 0; i < inst.cnt; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			cout << inst.dictionary[i].name << endl;
			return inst.dictionary[i];
		}
	}
	if (!isFound) throw THROW05; //"GetEntry: �� ������ �������"
}
void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed)
{
	bool isFound = false;
	for (int i = 0; i < inst.cnt; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			for (int j = i; j < inst.cnt; j++)
			{
				if (new_ed.id == inst.dictionary[j].id) throw THROW08; //"UpdEntry: ������������ ��������������"
			}
			isFound = true;

			inst.dictionary[i].id = new_ed.id;
			strcpy_s(inst.dictionary[i].name, new_ed.name);
			break;
		}
		else if (new_ed.id == inst.dictionary[i].id) throw THROW08; //"UpdEntry: ������������ ��������������"
	}
	if (!isFound)
	{
		throw THROW07; //"UpdEntry: �� ������ �������"
	}
}
void Dictionary::Print(Instance& d)
{

	cout << endl << "--------" << d.name << "--------" << endl;
	for (int i = 0; i < d.cnt; i++)
	{
		cout << "ID = " << d.dictionary[i].id
			<< "\n " << d.dictionary[i].name << endl << endl;
	}
}
void Dictionary::Delete(Instance& inst)
{
	delete[] inst.dictionary;
}