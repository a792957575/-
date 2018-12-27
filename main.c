#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Word
{
    char idiom[9];
    char explain[201];
};

int registered_number=0,user_id=404,word_number=0;

struct User
{
    char name[33];
    char password[19];
};

struct User user[32];

struct Word word[512];

void load(){
    registered_number = 0;
    FILE *f = fopen("user.txt","rb");
    while(1){
        int n = fread(&user[registered_number],sizeof(user),1,f);
        if(n==0)
            break;
        registered_number++;
    }
    fclose(f);
    word_number=0;
    FILE *fp = fopen("word.txt","rb");
    while(1){
        int i = fread(&word[word_number],sizeof(word),1,f);
        if(i==0)
            break;
        word_number++;
    }
    fclose(fp);
}

void add_part()
{
    load();
    printf("请输入成语:");
    scanf("%s",word[word_number].idiom);
    getchar();
    printf("请输入释义:");
    scanf("%s",word[word_number].explain);
    getchar();
    FILE *fp = fopen("word.txt","ab");
    fwrite(&word[word_number],sizeof(word),1,fp);
    fclose(fp);
    printf("成语录入成功\n");
}

void show()
{
    load();
    for(int i=0;i<=word_number;i++){
        printf("ID:%d  \t成语:%s   \t释义:%s\n",i+1,word[i].idiom,word[i].explain);
    }
    system("pause");
}

void reduce_part()
{
    load();
    int temp=0;
    printf("以下是成语列表；\n");
    show();
    printf("请输入要删除的单词id(输入-1取消):");
    scanf("%d",&temp);
    if(temp==-1){
        return;
    }else if(temp<=0||temp>word_number){
        printf("输入错误\n");
        return;
    }
    struct Word temp_word;
    for(;temp<word_number;temp++){
        temp_word=word[temp];
        word[temp-1]=temp_word;
    }
    word_number--;
    FILE *fp = fopen("word.txt","wb");
    fwrite(&word[0],sizeof(word),1,fp);
    fclose(fp);
    FILE *f = fopen("word.txt","ab");
    for(int temp1=1;temp1<word_number;temp1++){
        fwrite(&word[temp1],sizeof(word),1,f);
    }
    fclose(f);
}

void add_word()
{
    load();
    int temp;
    printf("现在已有%d个成语\n",word_number);
    printf("1)增加成语\n");
    printf("2)减少成语\n");
    printf("3)返回菜单\n");
    printf("请输入:");
    scanf("%d",&temp);
    switch(temp){
case 1:
    add_part();
    break;
case 2:
    reduce_part();
    break;
case 3:
    return;
    break;
default:
    printf("输入错误，请重新输入:");
    break;
    }}

void enroll()
{
if(registered_number<=32){
    load();
    int Username_status=0,User_password_status=0;      //状态为0时说明未完成
    char temp[100];
    printf("当前已注册%d人,最多注册32人。\n",registered_number);
    while(Username_status!=1){
        printf("请输入用户名(请不要超过32个字符):");
        scanf("%s",temp);
        getchar();
        if(strlen(temp)<=33){
            strcpy(user[registered_number].name,temp);
            printf("您的用户名为:%s\n",user[registered_number].name);
            Username_status++;
            }
        else
            printf("输入错误，请重新输入用户名\n");
    }
    while(User_password_status!=1){
        printf("请输入用户密码(请不要超过18个字符):");
        scanf("%s",temp);
        getchar();
        system("cls");
        if(strlen(temp)<=19){
            strcpy(user[registered_number].password,temp);
            printf("请重新输入以确认您的密码:");
            scanf("%s",temp);
            if(strcmp(temp,user[registered_number].password)==0){
            printf("已确认您的密码为:%s\n",user[registered_number].password);
            printf("用户%s已经注册成功",user[registered_number].name);
            User_password_status++;
            system("pause");
            system("cls");
            }
        else
            printf("输入错误，请重新输入密码\n");
    }
    }
    FILE *p=fopen("user.txt","ab");
    fwrite(&user[registered_number],sizeof(user),1,p);
    fclose(p);
    }else
    printf("人数过多，暂不开放注册\n");
}

void putout()
{
    int exit_status=0;
    char temp;
    printf("您确认要退出吗？(Y确定，N取消)\n");
    while(exit_status!=1){
    printf("请输入:");
    scanf("%s",&temp);
    if(temp=='Y'||temp=='y'){
        printf("感谢您使用成语词典\n");
        system("pause");
        exit(0);
    }else if(temp=='N'||temp=='n'){
        system("cls");
        exit_status++;
    }}
}

void login()
{
    load();
    char temp_name[40],temp_password[40];
    int i;
    printf("请输入用户名:");
    scanf("%s",temp_name);
    getchar();
    printf("请输入密码:");
    scanf("%s",temp_password);
    getchar();
    for(i=0;i<=registered_number;i++){
        if(strcmp(temp_name,user[i].name)==0&&strcmp(temp_password,user[i].password)==0){
            printf("欢迎用户%s登录系统\n",user[i].name);
            user_id=i;
            system("pause");
            return;
        }
    }
    printf("用户名或密码错误\n");
}

void menu()
{
    int temp=0;
    while(1){
    printf("欢迎游客使用成语词典\n");
    printf("1)登录\n");
    printf("2)注册\n");
    printf("3)查看所有成语\n");
    printf("4)成语查找\n");
    printf("5)退出程序\n");
        printf("请输入:");
        scanf("%d",&temp);
        switch(temp){
    case 1:
        login();
        if(user_id!=404){
            return;
        }
        break;
    case 2:
        enroll();
        break;
    case 3:
        show();
        break;
    case 4:
        //占个坑
        break;
    case 5:
        putout();
        break;
    default:
        printf("输入错误，请重新输入\n");
        }
    }
}

void menu_user()
{
    int temp=0;
    printf("欢迎用户%s使用成语词典\n",user[user_id].name);
    printf("1)查看收藏夹\n");
    printf("2)增加/减少成语\n");
    printf("3)查看所有成语\n");
    printf("4)成语查找\n");
    printf("5)退出程序\n");
        printf("请输入:");
        scanf("%d",&temp);
        switch(temp){
    case 1:
        //占个坑
        break;
    case 2:
        add_word();
        break;
    case 3:
        show();
        break;
    case 4:
        //占个坑
        break;
    case 5:
        putout();
        break;
    default:
        printf("输入错误，请重新输入\n");
}
}

int main()
{
    while(1){
        if(user_id==404)
            menu();
        else
            menu_user();
    }
    return 0;
}
