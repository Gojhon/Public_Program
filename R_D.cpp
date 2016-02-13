// R_D.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<random> 
#include<strstream>
#include<Windows.h>

void gotoXY(int x, int y);
int name_number(std::string name);

int main()
{
	std::string Name_buf; //문자열을 받는 string 변수를 생성한다.
	std::cout << "이름을 나열해 적어주세요." << std::endl;
	std::cout << "ex)이름 이름 이름" << std::endl;

	std::getline(std::cin, Name_buf);   //문자열을 입력받는다.

	int Names_num=name_number(Name_buf)+1; 
	//공백 문자열의 갯수를 Names_num에 넣습니다. 
	//공백 문자열의 갯수는 객체생성의 갯수를 정합니다.
	std::string *Names_arr = new std::string[Names_num]; 
	//string 객체를 생성합니다.
	int index = 0;
	//index를 변수를 생성합니다. index는 객체의 순서를 위해 생성하였습니다.
	std::istrstream Instream(Name_buf.c_str()); //Instream변수에 name_buf를 형변환하여 값을 넣는다.
		 
	std::string name;
	

	while (std::getline(Instream, name, ' ')) 
	{		//스트링스트림에서 공백을 제외하고 name에 한단어씩 문자열을 넣는다.
			Names_arr[index]=name; //각각의 객체에 나누어진 이름명을 넣는다.
			index++; 
			if (index == Names_num )
				break;
	}
	std::uniform_int_distribution<int> dist(20, 50);
	//10~100사이의 값이 랜덤으로 값으로 지정한다.
	std::random_device gen; //랜덤 변수 생성
	unsigned int RD = dist(gen); 
	//int형 변수 RD에 10~100의 랜덤으로 추출된 값을 넣는다. 
	index = 0;
	int sleep = 0;
	for (int Rdindex = 0; Rdindex < RD; Rdindex++)
	{ //
		system("cls"); //화면을 지운다
		gotoXY(75,25);
		std::cout << Names_arr[index] << std::endl;//이름을 출력한다.
		Sleep(sleep); //0.5초뒤에 index값을 증가 시킨다.
		index++;
		sleep += 20;
		if (index ==Names_num )  //객체의 숫자와 index값이 같을경우 초기화시킨다.
			index = 0;
	}
	
	delete[] Names_arr;

	system("pause");
    return 0;
}

void gotoXY(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


int name_number(std::string name)
{
	// eraly objects- 8th edition Page531 Example 8-12
	char ch;
	int vowelCount = 0;//문자열 카운트 변수생성
	for (int pos = 0; pos < name.length(); pos++)
	{
		ch = name[pos];//첫번째 문자부터 끝의 문자까지 ch변수에 하나씩 넣는다.
		switch (ch)
		{
		case ' ': vowelCount++; //(' ')를 만날경우 vowelCount변수 값이 1씩 증가
		}
	}
	return vowelCount; //vowelCount의 값을 리턴한다.
}