// R_D.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<random> 
#include<strstream>
#include<Windows.h>

int name_number(std::string name);

int main()
{
	std::string Name_buf; //���ڿ��� �޴� string ������ �����Ѵ�.
	std::cout << "�̸��� ������ �����ּ���." << std::endl;
	std::cout << "ex)�̸� �̸� �̸�" << std::endl;

	std::getline(std::cin, Name_buf);   //���ڿ��� �Է¹޴´�.

	int Names_num=name_number(Name_buf)+1; 
	//���� ���ڿ��� ������ Names_num�� �ֽ��ϴ�. 
	//���� ���ڿ��� ������ ��ü������ ������ ���մϴ�.
	std::string *Names_arr = new std::string[Names_num]; 
	//string ��ü�� �����մϴ�.
	int index = 0;
	//index�� ������ �����մϴ�. index�� ��ü�� ������ ���� �����Ͽ����ϴ�.
	std::istrstream Instream(Name_buf.c_str()); //Instream������ name_buf�� ����ȯ�Ͽ� ���� �ִ´�.
		 
	std::string name;
	

	while (std::getline(Instream, name, ' ')) 
	{		//��Ʈ����Ʈ������ ������ �����ϰ� name�� �Ѵܾ ���ڿ��� �ִ´�.
			Names_arr[index]=name; //������ ��ü�� �������� �̸����� �ִ´�.
			index++; 
			if (index == Names_num )
				break;
	}
	std::uniform_int_distribution<int> dist(10, 100);
	//10~100������ ���� �������� ������ �����Ѵ�.
	std::random_device gen; //���� ���� ����
	unsigned int RD = dist(gen); 
	//int�� ���� RD�� 10~100�� �������� ����� ���� �ִ´�. 
	index = 0;
	for (int Rdindex = 0; Rdindex < RD; Rdindex++)
	{ //
		system("cls"); //ȭ���� �����
		std::cout << Names_arr[index] << std::endl;//�̸��� ����Ѵ�.
		Sleep(500); //0.5�ʵڿ� index���� ���� ��Ų��.
		index++;
		if (index ==Names_num )  //��ü�� ���ڿ� index���� ������� �ʱ�ȭ��Ų��.
			index = 0;
	}
	
	delete[] Names_arr;
    return 0;
}

int name_number(std::string name)
{
	// eraly objects- 8th edition Page531 Example 8-12
	char ch;
	int vowelCount = 0;//���ڿ� ī��Ʈ ��������
	for (int pos = 0; pos < name.length(); pos++)
	{
		ch = name[pos];//ù��° ���ں��� ���� ���ڱ��� ch������ �ϳ��� �ִ´�.
		switch (ch)
		{
		case ' ': vowelCount++; //(' ')�� ������� vowelCount���� ���� 1�� ����
		}
	}
	return vowelCount; //vowelCount�� ���� �����Ѵ�.
}