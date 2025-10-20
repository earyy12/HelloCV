#ifndef KSCODE_HPP       //防止重复声明
#define KSCODE_HPP

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//文本加密函数
string TextEncode(string text,int key);
//文本解密函数
string TextDiscode(string text,int key);
//文件加密函数
void FileEncode(string SourceFile,int key);
//文件解密函数
void FileDiscode(string SourceFile,int key);

#endif

