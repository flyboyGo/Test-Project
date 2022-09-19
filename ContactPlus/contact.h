#define _CRT_SECURE_NO_WARNINGS 1
#define DEFAULT_SIZE 3

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <malloc.h>
#include <errno.h>

//#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 50

//定义枚举选项
enum Option
{
    EXIT, //0
    ADD,  //1
    DEL,  //2
    SEARCH,//..
    MODIFY,
    SHOW,
    SORT,
    SAVE//7
};

//用户详细信息组组成
struct PeoInfo
{
    char name[MAX_NAME];
    int  age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};

//通讯录类型
struct Contact
{
    struct PeoInfo* data;//改造
    int size; //个数
    int capacity;//容量
};

//申明函数

//初始化函数声明
void InitContact(struct Contact* pc);

//添加函数声明
void AddContact(struct Contact* pc);

//查找函数声明
void SearchContact(const struct Contact* pc);

//修改函数声明
void ModifyContact(const struct Contact* pc);

//排序函数声明
void SortContact(struct Contact* pc);

//打印函数声明
void ShowContact(const struct Contact* pc);

//删除函数声明
void DelContact(struct Contact* pc);

//销毁函数的声明
void DestoryContact(struct Contact* pc);

//保存函数的声明
void SaveContact(struct Contact* pc);

//加载文件中的信息到通讯录中函数声明
void LoadContact(struct Contact* pc);