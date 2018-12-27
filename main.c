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
    printf("���������:");
    scanf("%s",word[word_number].idiom);
    getchar();
    printf("����������:");
    scanf("%s",word[word_number].explain);
    getchar();
    FILE *fp = fopen("word.txt","ab");
    fwrite(&word[word_number],sizeof(word),1,fp);
    fclose(fp);
    printf("����¼��ɹ�\n");
}

void show()
{
    load();
    for(int i=0;i<=word_number;i++){
        printf("ID:%d  \t����:%s   \t����:%s\n",i+1,word[i].idiom,word[i].explain);
    }
    system("pause");
}

void reduce_part()
{
    load();
    int temp=0;
    printf("�����ǳ����б�\n");
    show();
    printf("������Ҫɾ���ĵ���id(����-1ȡ��):");
    scanf("%d",&temp);
    if(temp==-1){
        return;
    }else if(temp<=0||temp>word_number){
        printf("�������\n");
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
    printf("��������%d������\n",word_number);
    printf("1)���ӳ���\n");
    printf("2)���ٳ���\n");
    printf("3)���ز˵�\n");
    printf("������:");
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
    printf("�����������������:");
    break;
    }}

void enroll()
{
if(registered_number<=32){
    load();
    int Username_status=0,User_password_status=0;      //״̬Ϊ0ʱ˵��δ���
    char temp[100];
    printf("��ǰ��ע��%d��,���ע��32�ˡ�\n",registered_number);
    while(Username_status!=1){
        printf("�������û���(�벻Ҫ����32���ַ�):");
        scanf("%s",temp);
        getchar();
        if(strlen(temp)<=33){
            strcpy(user[registered_number].name,temp);
            printf("�����û���Ϊ:%s\n",user[registered_number].name);
            Username_status++;
            }
        else
            printf("������������������û���\n");
    }
    while(User_password_status!=1){
        printf("�������û�����(�벻Ҫ����18���ַ�):");
        scanf("%s",temp);
        getchar();
        system("cls");
        if(strlen(temp)<=19){
            strcpy(user[registered_number].password,temp);
            printf("������������ȷ����������:");
            scanf("%s",temp);
            if(strcmp(temp,user[registered_number].password)==0){
            printf("��ȷ����������Ϊ:%s\n",user[registered_number].password);
            printf("�û�%s�Ѿ�ע��ɹ�",user[registered_number].name);
            User_password_status++;
            system("pause");
            system("cls");
            }
        else
            printf("���������������������\n");
    }
    }
    FILE *p=fopen("user.txt","ab");
    fwrite(&user[registered_number],sizeof(user),1,p);
    fclose(p);
    }else
    printf("�������࣬�ݲ�����ע��\n");
}

void putout()
{
    int exit_status=0;
    char temp;
    printf("��ȷ��Ҫ�˳���(Yȷ����Nȡ��)\n");
    while(exit_status!=1){
    printf("������:");
    scanf("%s",&temp);
    if(temp=='Y'||temp=='y'){
        printf("��л��ʹ�ó���ʵ�\n");
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
    printf("�������û���:");
    scanf("%s",temp_name);
    getchar();
    printf("����������:");
    scanf("%s",temp_password);
    getchar();
    for(i=0;i<=registered_number;i++){
        if(strcmp(temp_name,user[i].name)==0&&strcmp(temp_password,user[i].password)==0){
            printf("��ӭ�û�%s��¼ϵͳ\n",user[i].name);
            user_id=i;
            system("pause");
            return;
        }
    }
    printf("�û������������\n");
}

void menu()
{
    int temp=0;
    while(1){
    printf("��ӭ�ο�ʹ�ó���ʵ�\n");
    printf("1)��¼\n");
    printf("2)ע��\n");
    printf("3)�鿴���г���\n");
    printf("4)�������\n");
    printf("5)�˳�����\n");
        printf("������:");
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
        //ռ����
        break;
    case 5:
        putout();
        break;
    default:
        printf("�����������������\n");
        }
    }
}

void menu_user()
{
    int temp=0;
    printf("��ӭ�û�%sʹ�ó���ʵ�\n",user[user_id].name);
    printf("1)�鿴�ղؼ�\n");
    printf("2)����/���ٳ���\n");
    printf("3)�鿴���г���\n");
    printf("4)�������\n");
    printf("5)�˳�����\n");
        printf("������:");
        scanf("%d",&temp);
        switch(temp){
    case 1:
        //ռ����
        break;
    case 2:
        add_word();
        break;
    case 3:
        show();
        break;
    case 4:
        //ռ����
        break;
    case 5:
        putout();
        break;
    default:
        printf("�����������������\n");
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
