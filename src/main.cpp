#include<iostream>
#include<string>
#include"head.hpp"
using namespace std;

int main(){
	
	while(true){
		cout<<"加密和解密工具为凯撒密码"<<endl;
		cout<<"请选择：1.文本加密 2.文本解密 3.文件加密 4.文件解密 5.退出"<<endl;
		int choice;
		cin>>choice;
		
		int key;
		string text,source;
		
		switch(choice){
			case 5:
				return 0;
			case 1:
				cout<<"请输入要加密的文本："<<endl;
				cin.ignore();
				getline(cin,text);
				cout<<"请输入数字密钥："<<endl;
				cin>>key;
				cout<<"加密后的文本为："<<TextEncode(text,key)<<endl;
				break;
			case 2:
				cout<<"请输入要解密的文本："<<endl;
				cin.ignore();
				getline(cin,text);
				cout<<"请输入数字密钥："<<endl;
				cin>>key;
				cout<<"解密后的文本为："<<TextDiscode(text,key)<<endl;
				break;	
			case 3:
				cout<<"请输入要加密的文件的路径："<<endl;
				cin.ignore();
				getline(cin,source);
				cout<<"请输入数字密钥："<<endl;
				cin>>key;
				FileEncode(source,key);
				break;
			case 4:
				cout<<"请输入要解密的文件的路径："<<endl;
				cin.ignore();
				getline(cin,source);
				cout<<"请输入数字密钥："<<endl;
				cin>>key;
				FileDiscode(source,key);
				break;	
			default:
				cout<<"无效选项，请重新输入"<<endl;		
		
		
		}
	}
	return 0;
}
