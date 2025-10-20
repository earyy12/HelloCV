#include<iostream>
#include<string>
#include"head.hpp"
using namespace std;
string TextEncode(string text,int key){
	
	string textcode="";
	for(int i=0;i<text.size();i++){
		char a=text[i];
		if(a>='A'&&a<='Z'){
			a=((a-'A')+key)%26+'A';
		}
		else if(a>='a'&&a<='z'){
			a=((a-'a')+key)%26+'a';
		}
		textcode +=a;
	}
	return textcode;
}
