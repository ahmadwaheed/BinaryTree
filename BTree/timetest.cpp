//
//  main.cpp
//  MainMethodECS60
//
//  Created by Ahmad Waheed on 1/11/16.
//  Copyright © 2016 Ahmad Waheed. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "CPUTimer.h"
#include "CursorList.h"
#include "LinkedList.h"
#include "QueueAr.h"
#include "StackAr.h"
#include "StackLi.h"
#include "SkipList.h"
vector<CursorNode <int> > cursorSpace(250000);

using namespace std;


int getChoice() 
{
	int c ;
	cin >> c ;
	return c ;
}

void RunList (string filename)
{
	const char* filename2;
	filename2 = filename.c_str();
	List<int> *tmp = new List<int>();
        ListItr<int> itr = tmp->zeroth();
	ifstream inf(filename2);
	string firstLine;		

	getline(cin, firstLine) ;
	
	while (!inf.eof())
	{
		string data ;
		const char* data2;
		cin >> data ;
		if (data[0] == 'i')
		{
			data = data.substr(1);
			data2 = data.c_str();
			int num = atoi(data2);
			tmp -> insert(num,itr) ;			
		}
		else 
		{
			data = data.substr(1);
			data2 = data.c_str() ;
			int num = atoi(data2) ;
			tmp -> remove(num) ;
		}
		
	}
	return ;
}

void RunCursorList (string filename)
{
        const char * filename2;
        filename2 = filename.c_str();
	CursorList<int>* tmp = new CursorList<int>(cursorSpace) ;
	CursorListItr<int> itr = tmp->zeroth();
	ifstream inf(filename2) ;
	string firstLine ;		

	getline(cin, firstLine) ;
	
	while (!inf.eof())
	{
		string data ;
		const char* data2;
		cin >> data ;
		if (data[0] == 'i')
		{
			data = data.substr(1);
			data2 = data.c_str() ;
			int num = atoi(data2);
			tmp->insert(num,itr) ;			
		}
		else 
		{
			data=data.substr(1);
			data2 = data.c_str() ;
			int num = atoi(data2) ;
			tmp->remove(num) ;
		}
	}
	return;
}

void RunStackAr(string filename)
{
 	const char * filename2;
	filename2 =filename.c_str() ;
	 StackAr<int>* tmp = new StackAr<int> ;
	
	ifstream inf(filename2) ;
	string firstLine ;		

	getline(cin, firstLine) ;
	
	while (!inf.eof())
	{
		string data ;
		const char* data2;
		cin >> data ;
		if (data[0] == 'i')
		{
			data = data.substr(1);
			data2 = data.c_str() ;
			int num = atoi(data2);
			tmp->push(num) ;			
		}
		else 
		{
			data=data.substr(1);
			data2 = data.c_str() ;
			int num = atoi(data2) ;
			tmp->pop(num) ;
		}
	}
	return ;
}

void RunStackLi (string filename)
{
   StackLi<int> tmp = new StackLi<int> ;
	ifstream inf(filename) ;
	inf.open ;
	string firstLine ;		

	getline(cin, firstLine) ;
	
	while (!eof())
	{
		string data ;
		cin >> data ;
		if (data[0] == 'i')
		{
			data = data.substr(1);
			data = data.c_str() ;
			int num = atoi(data);
			tmp.insert(num) ;			
		}
		else 
		{
			data=data.substr(1);
			data = data.c_str() ;
			int num = atoi(data) ;
			tmp.delete(num) ;
		}
	}
	return ;
}

void RunQueueAr (string filename)
{
  QueueAr<int> tmp = new QueueAr<int> ;
	ifstream inf(filename) ;
	inf.open ;
	string firstLine ;		

	getline(cin, firstLine) ;
	
	while (!eof())
	{
		string data ;
		cin >> data ;
		if (data[0] == 'i')
		{
			data = data.substr(1);
			data = data.c_str() ;
			int num = atoi(data);
			tmp.insert(num) ;			
		}
		else 
		{
			data=data.substr(1);
			data = data.c_str() ;
			int num = atoi(data) ;
			tmp.delete(num) ;
		}
	}
	return ;
}

void RunSkipList (string filename)
{
   SkipList<int> tmp = new SkipList<int> ;
	ifstream inf(filename) ;
	inf.open ;
	string firstLine ;		

	getline(cin, firstLine) ;
	
	while (!eof())
	{
		string data ;
		cin >> data ;
		if (data[0] == 'i')
		{
			data = data.substr(1);
			data = data.c_str() ;
			int num = atoi(data);
			tmp.insert(num) ;			
		}
		else 
		{
			data=data.substr(1);
			data = data.c_str() ;
			int num = atoi(data) ;
			tmp.delete(num) ;
		}
	}
	return ;
}


int main()
{
    ifstream f;
	string filename;
cout << "Filename >> " ;
getline(cin,filename);
//f.open(filename.c_str()) ;
cout <<  "ADT Menu" << endl << "0. Quit" << endl << "1. LinkedList" << endl << "2. CursorList" << endl << "3. StackAr" << endl << "4. Stackli" << endl << "5. QueueAr" << endl << "6. SkipList" << endl << "Your choice >> " ;

    int choice;
    CPUTimer ct ;	
	do 
	{
		choice = getChoice() ;
		ct.reset() ;
		switch (choice) 
		{
			case 1: RunList(filename); break ;
			case 2: RunCursorList(filename); break ;
			case 3: RunStackAr(filename); break ;
			case 4: RunStackLi(filename); break;
			case 5: RunQueueAr(filename); break;
			case 6: RunSkipList(filename); break;	
		}
		
		cout << "CPU time: " << ct.cur_CPUTime() << endl ;
	} while (choice > 0);
    
    
        
    
       return 0;
}
