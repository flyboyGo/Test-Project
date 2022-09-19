#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//菜单
void menu()
{
    printf("*******************************\n");
    printf("******1、add     2、del********\n");
    printf("******3、search  4、modify*****\n");
    printf("******5、show    6、sort*******\n");
    printf("******7、save    0、exit*******\n");
    printf("*******************************\n");
}

int main(void) {
    int input = 0;
    //创建通讯录
    struct Contact con;//con就是通讯录,里面包含capacity容量、size个数、data指针
    //初始化通讯录
    InitContact(&con);
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:
            AddContact(&con);
            break;
        case DEL:
            DelContact(&con);
            break;
        case SEARCH:
            SearchContact(&con);
            break;
        case MODIFY:
            ModifyContact(&con);
            break;
        case SHOW:
            ShowContact(&con);
            break;
        case SORT:
            SortContact(&con);
            break;
        case EXIT:
            SaveContact(&con);
            //销毁通讯录--释放动态开辟的内存
            DestoryContact(&con);
            printf("推出通讯录!\n");
            break;
        case SAVE:
            SaveContact(&con);
            printf("保存成功!\n");
            break;
        default:
            printf("输入错误!\n");
            break;
        }
    } while (input);

    return 0;
}
