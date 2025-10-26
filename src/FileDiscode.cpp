#include<iostream>
#include<string>
#include<fstream>
#include"head.hpp"
using namespace std;
void FileDiscode(string SourceFile,int key){
	ifstream inFile(SourceFile,ios::in);
	if(!inFile.is_open()){
		cout<<"未成功读取到该文件"<<endl;
	}
	
	string text;
	cin.ignore();
	getline(inFile,text);
	inFile.close();
	
	string textcode=TextDiscode(text,key);
	
	ofstream outFile("DiscodeFile",ios::out);
	outFile<<textcode<<endl;
	outFile.close();
	
	cout<<"已将加密后的资料存放在文件DiscodeFile中"<<endl;
}
