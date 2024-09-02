#include "Dictionary.h"

namespace Dictionary {
	Instance Create(const char* name, int size) { // ������� ��� �������� ������ ���������� �������
		if (strlen(name) > DICTNAMEMAXSIZE) {//���� ����� ����� ������ ����������� ������ ��������
			throw(char*)THROW01;
		}
		if (size > DICTMAXSIZE) {//���� � ������� ������ ��� �����
			throw(char*)THROW02;
		}

		Instance inst{};//������ ��������� �������
		strcpy_s(inst.name, name);//����������� ����� � ��������� �������

		inst.maxsize = size;//��������� ���� ������� �������
		inst.size = 0;//������������� ������� ������� ��� 0
		inst.dictionary = new Entry[size];//��������� ������ ��� �������

		return inst;
	}

	void AddEntry(Instance& inst, Entry ed) { // ������� ��� ���������� ������ � �������
		if (inst.size == inst.maxsize) {//���� ������ ������� ������� �� �������
			throw THROW03;
		}
		for (int i = 0; i < inst.maxsize; i++) {
			if (inst.dictionary[i].id == ed.id)//���� ���������� ������������ ��������������
				throw THROW04;
		}
		inst.dictionary[inst.size++] = ed;//���������� ����� ������� � �������
	}

	void DelEntry(Instance& inst, int id) {// ������� ��� �������� ������ �� ������� �� ��������������.
		for (int i = 0; i < inst.size; ++i) {
			if (inst.dictionary[i].id == id) {// �������� ������� ������ � ��������� ID
				for (int j = i; j < inst.size - 1; ++j) {// ����� ������� ����� ���������� ��������
					inst.dictionary[j] = inst.dictionary[j + 1];
				}
				--inst.size;//���������� ������� �������
				return;//����� �� ������� ����� ��������
			}
		}
		throw THROW06;
	}

	void UpdEntry(Instance& inst, int id, Entry new_ed) {// ������� ��� ���������� ������ � �������
		bool find = false;//������� �� ������
		for (int i = 0; i < inst.size; ++i) {

			if (inst.dictionary[i].id == new_ed.id) { //�������� �� ������� �������������
				throw (char*)THROW08;
			}

			if (inst.dictionary[i].id == id) {//���� ������ ������, �� �� �����������
				find = true;
				inst.dictionary[i] = new_ed;
				break;
			}
		}
		if (!find) {
			throw (char*)THROW07;
		}
	}

	Entry GetEntry(Instance inst, int id) { //������� ��� ��������� ������ �� ������� �� ��������������
		for (int i = 0; i < inst.size; ++i) {
			if (inst.dictionary[i].id == id) { // �������� �� ������� �������� ����
				return inst.dictionary[i];
			}
		}
		throw THROW05;
	}

	void Print(Instance d) { // ������� ��� ������ ���� ������� �� �������
		for (int i = 0; i < d.size; ++i) {
			std::cout << d.dictionary[i].id << " " << d.dictionary[i].name << std::endl;
		}
	}

	void Delete(Instance& d) { // ������� ��� ������������ ������ 
		delete[] d.dictionary; // �������� ���������� ������
		d.size = 0; //����� ������� �������
		d.maxsize = 0; // ����� ������������� ������� ������� 
	}
}
