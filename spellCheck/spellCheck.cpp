/*
Program: spellCheck.cpp
Author:  Paola Socorro
Project:   Project 3
Date:    May 15, 2014
*/

#include <iostream>
#include<string>
#include <iomanip> 

using namespace std;

char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int letterCount[26]={ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };
char text[1000];
//converts text to lowercase.
char lowercaseCon(char input [1000])
{
	for (int i=0; i<strlen(input);i++)
	{
		//x=input[i]; //testing for loop
		if(input[i]>='A' && input[i]<='Z')
		{
		 //cout<<input[i]<<endl; //char before conversion
		 input[i]=input[i]+'a'-'A';
		 //cout<<input[i]<<endl; //char after conversion
		}
		//cout<<x<<endl;  // print single charactervalue.
	}
	
	return input[1000];
}
//Counting the occurrence of letters in the text.
void count (char input [1000])
{
	for (int i=0; i<strlen(alphabet);i++)
	{
		for(int j=0; j<strlen(text); j++)
		{
			if(text[j]==alphabet[i])
				letterCount[i]++;
		}
	}
/*
	cout<<alphabet<<endl;
	for(int k=0; k<26;k++)
	{
		cout<<letterCount[k]<<',';
	}
	*/
}

void characterCount()
{
	int charCount=0;
	for(int j=0; j<strlen(text); j++)
	{
		charCount++;
	}
	cout<<'\n';
	cout<<"Character Count: "<<charCount<<endl;
}
void report ()
{
	int per=0;
	cout<<"/"<<setw(7)<<"Count"<<setw(3)<<"%"<<endl;
	cout<<'\n';
	for (int i=0; i<strlen(alphabet);i++)
	{
		if(letterCount[i]<0)
			per==1;
			//per = (letterCount[i]/charCount)*100;
		else
			per==0;
		cout<<alphabet[i]<<setw(5)<<letterCount[i]<<setw(5)<<per<<endl;
	}
}
void max()
{
	int length=sizeof letterCount/ sizeof letterCount[0];
	int max=letterCount[0];
	int sMax=letterCount[1];
	int temp;
	int pos;
	for(int i=1; i<length;i++)
	{
		
		if(letterCount[i]>max)
		{
			max=letterCount[i];
			pos=i;
		}
		
	}
	cout<<'\n';
	cout<<"Most frequent letter is: "<<alphabet[pos]<<" at "<<max<<" counts.";
}
void main()
{
	//int c;
	cout<<"Enter a sentence with a mix of lower and uppercase to convert: "<<endl;
	cin.getline(text,1000,'\n');

	text[1000]=lowercaseCon(text);
	count(text);
	max();
	cout<<'\n';
	characterCount();
	cout<<'\n';
	cout<<'\n';
	report();

	//cout<<"All in lowercase: "<<text<<endl;



}