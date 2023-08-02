# Lexicographic-anagram-retrieval-system

结构设计：

一个单词交换字母位置，可得另一个单词，如army->mary，成为兄弟单词。提供一个单词，在字典中找到它的兄弟，描述数据结构和查询过程

![image](https://github.com/yunshou79/Lexicographic-anagram-retrieval-system/assets/132857445/7f96c9b0-c2b2-494c-8c67-50cb09f706cd)

功能流程：

1、定义int k;Diction *head,*pl,*p2;FILE*p;

2、开辟新结点plp2=(Diction*)malloc(sizeof(Diction));

3、令 k=0 记录单词个数，head=NULL，如果文件打不开输出提示并返回 head，如果打开成功，读取一个单词给 p1，当 k=1 时，说明是第1个单词 head=p1，p2 指向 p1，以后循环，每读入一个单词给开辟的新结点p1

4、 p2->next=NULL，返回 head，并输出一共有多少单词

数据库设计：

系统采用抽象数据类型线性表，线性表各种定义如下：

（1）抽象数据类型定义

（2）全局变量

（3）存储结构

（4）检索算法

详细设计：

词典变位词检索系统主要实现读入词典、求出变位词并输出合法单词、循环输入单词，详细设计如下：

a)数据库结构定义

 本系统中使用线性表数据结构，结构类型定义如下：
 
定义词典

Typedef char ElemType;

Typedef struct Diction

{

		ElemType word[100]; 
  
		Struct Diction *next;
  
}Diction;


b) 读入词典模块

读入词典模块是words.txt词典文件读入到链式存储结构的顺序表中

c) 求出变位词并输出合法单词模块

求出变位词并输出合法单词模块，先对输入单词进行全排列，每排出一个可能，输出排列，从词典中依次对比看是否为合法单词，如果是存入新建的单链表中然后全部输出合法单词

统计单词字符串的信息，用memset函数将数组空间初始化，m记录字符串长度，n记录字符串中字符种类数，map记录哪几种字符，count记录每种字符有多少个

用stack记录字符的位置，复制字符数组map中第stack[i]个字符给A[i],同时输出字符，直到第一个可能的单词结束。从词典链表中第一个结点存的单词开始，依次查找，直到最后一个，如果是合法单词，则新建结点p2，存入这个单词，直到所有全排列都输出结束后，将存储是合法单词的单链表head带回，在主函数中输出
