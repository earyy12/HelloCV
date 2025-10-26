#include<iostream>
#include<string>
#include"head.hpp"
using namespace std;
string TextDiscode(string text,int key){
	
	string textdiscode="";
	for(int i=0;i<text.size();i++){
		char a=text[i];
		if(a>='A'&&a<='Z'){
			a=((a-'A')-key+26)%26+'A';
		}
		else if(a>='a'&&a<='z'){
			a=((a-'a')-key+26)%26+'a';
		}
		textdiscode +=a;
	}
	return textdiscode;
}
