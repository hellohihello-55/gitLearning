#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int num,char* a[])
{
    FILE *fp;
        fp=fopen(a[2],"r");
        if(!strcmp(a[1],"-w")) countw(a[2]);
        else if(!strcmp(a[1],"-c")) countc(a[2]);
    return 0;
}
int countc(char *file) //�����ļ����ַ���
{   FILE *f;
    int charnum = 0;
    f = fopen(file, "r");
    char a;
    while (!feof(f)) {
        a=fgetc(f);
    if (a == ' '||a == '\n'||a == '\t' ||(a >= 'a'&&a <= 'z')||(a>='A'&&a<='Z')){
        charnum++;
    }
    }
    fclose(f);
    printf("�ַ���:%d" ,charnum);
}
int countw(char *file)//�����ļ��ʵ���Ŀ
{   FILE *f;
    int wordnum=0;
    int flag=0;
    f=fopen(file,"r");
    char ch;
        while(!feof(f)) {
        ch=fgetc(f);
        if(ch==' '||ch==','){ flag=1; continue;}
        else if (flag) {
            wordnum++; flag=0;
            }
    }
    fclose(f);
    if(flag==1)printf("������:%d ",wordnum);
    else

    printf("������:%d ",wordnum+1);
    return 0;
}
