/*
 * @Author: cqupt_chenjunyu 
 * @Date: 2021-05-11 21:33:51 
 * @Last Modified by: cqupt_chenjunyu
 * @Last Modified time: 2021-05-11 21:41:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

//疫苗表
typedef struct vaccine{
    int vaccine_id;//疫苗编号
    char vaccine_name[10];//疫苗名字
    char company[50];//疫苗生产公司
    int allowed_age[2];//允许接种的年龄
    int times;//需要接种的次数
    int is_used;//是否使用了
}VACCINE;

//受试者表
typedef struct person{
    int user_id;//编号
    char person_name[10];//名字
    char ID_card[20];//身份证 
    int sex;//性别
    int age;//年龄
    char phone[20];//电话
}PERSON;

//接种信息表
typedef struct thing{
    int id;//事件编号
    int user_id;//用户编号
    char vaccine_id; //疫苗编号
    int time;//接种的次数（第几次）
}THING;

void menu1();
void add_vaccine();
int check_vaccine_num();
void display_vaccine();

int main(){
    int flag1=1,flag2=1,flag3=1;/* flag是判断条件,flag为 1 时为真，为 0 时为假 */
	char choice1,choice2,choice3;
	FILE *p1,*p2,*p3;
	
    system("疫苗管理系统--by陈俊谕");
    
    if((p1=fopen("vaccine.txt","r"))==NULL)/*p1是疫苗信息文件指针*/ 
    {
      	p1=fopen("vaccine.txt","w");
      	fclose(p1);
    }

	if((p2=fopen("person.txt","r"))==NULL)/*p2是个人信息文件指针*/ 
	{
		p2=fopen("person.txt","w");
		fclose(p2);
	}
	if( (p3=fopen("thing.txt","r"))==NULL)/*p3是接种信息文件指针*/ 
	{
		p3=fopen("thing.txt","w");
		fclose(p3);
	}

    display_vaccine();

}

void menu1()
{
	system("color E9");
	printf("\n\n");
	printf("\t\t\t *=======================================*\n");
	printf("\t\t\t|  * - Vaccination-Management-System - *  |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [1]   添加疫苗                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [2]   疫苗接种                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [3]   查看接种人信息               | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [4]   查看疫苗信息                 | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t| |  [5]   退出系统                     | |\n");
	printf("\t\t\t| *                                     * |\n");
	printf("\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
	printf("\t\t\t *=======================================*\n");
}

void add_vaccine() /*输入添加的疫苗信息*/
{
    char choice;
    FILE *p1;
    VACCINE newvaccine;
    system("cls");
    while(1)
      	{

        int n, i;
        int vaccine_num = check_vaccine_num();
		
        fflush(stdin); 
        printf("请输入疫苗名称: ");
        gets(newvaccine.vaccine_name);
    
        printf("请输入疫苗生产公司: ");
        gets(newvaccine.company);
    
        printf("请输入允许接种的最低年龄: ");
        scanf("%d",&newvaccine.allowed_age[0]);
        
        printf("请输入允许接种的最高年龄: ");
        scanf("%d",&newvaccine.allowed_age[1]); 

        printf("请输入需要接种的次数: ");
        scanf("%d",&newvaccine.times); 
    
        printf("请输入疫苗入库数量: ");
        scanf("%d",&n); 

		fflush(stdin);
      	printf("是否保存该疫苗信息(y/n): ");
      	choice=getch();
		while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    choice=getch();
      	printf("%c",choice);
     	if(choice=='Y'||choice=='y')
        {
        	p1=fopen("vaccine.txt","a");
            for(i=vaccine_num; i<n+vaccine_num; i++){
                fprintf(p1,"%d %s %s %d %d %d %d\n",
                        i,newvaccine.vaccine_name,newvaccine.company,
                        newvaccine.allowed_age[0], newvaccine.allowed_age[1],
                        newvaccine.times, 0);    
            }
	        
	        fclose(p1);
        	printf("\n疫苗信息已添加到vaccine.txt文件中!\n");
       	}
        else
        {
       		printf("\n疫苗信息未保存!\n");
        }
      	printf("\n\n是否继续添加其他疫苗(y/n): ");
        choice=getch();
        while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
      	    choice=getch();
      	printf("%c",choice);
      	printf("\n");
     	if(choice=='Y'||choice=='y')
        	continue;
      	else
       	 	break;
      }
}

int check_vaccine_num(){
    FILE *p1;
    int n;
    VACCINE newvaccine;
    int vaccine_num=0;
    system("cls");
    fflush(stdin);

    char ch;
    FILE *fp=fopen("vaccine.txt","r");
    ch = fgetc(fp);
    if(ch==EOF) return 0;
    fclose(fp);

    p1=fopen("vaccine.txt","r");
    while(!feof(p1))
    {
      	fscanf(p1,"%d %s %s %d %d %d %d\n",
                        &newvaccine.vaccine_id, 
                        newvaccine.vaccine_name, newvaccine.company,
                        &newvaccine.allowed_age[0], &newvaccine.allowed_age[1],
                        &newvaccine.times, &newvaccine.is_used);  
      	vaccine_num++;
    }
    fclose(p1);
    return vaccine_num;
}

void display_vaccine()/*显示全部疫苗信息*/
{
    FILE *p1;
    int n;
    VACCINE newvaccine[1000];
    int vaccine_num=0;
    system("cls");
    fflush(stdin);
    p1=fopen("vaccine.txt","r");
    while(!feof(p1))
    {
      	fscanf(p1,"%d %s %s %d %d %d %d\n",
                        &newvaccine[vaccine_num].vaccine_id, 
                        newvaccine[vaccine_num].vaccine_name, newvaccine[vaccine_num].company,
                        &newvaccine[vaccine_num].allowed_age[0], &newvaccine[vaccine_num].allowed_age[1],
                        &newvaccine[vaccine_num].times, &newvaccine[vaccine_num].is_used);  
      	vaccine_num++;
    }
    fclose(p1);
    printf("当前系统内有%d条疫苗记录\n\n",vaccine_num);
    if(vaccine_num==0)
    {
      	printf("\n没有任何疫苗信息!\n\n");
    }
    else
    {
      	n=0;
      	printf("|---------------------------------疫苗信息----------------------------------|\n");
      	printf("|编号  疫苗名      公司      允许接种年龄     需要接种的次数   是否使用了   |\n");
      	printf("|                                                                           |\n");
      	while(n<vaccine_num)
        {
        	printf("|%-6d%-12s%-10s%-8d~%-16d%-14d%-8d|\n",
                    newvaccine[n].vaccine_id, 
                    newvaccine[n].vaccine_name, newvaccine[n].company,
                    newvaccine[n].allowed_age[0], newvaccine[n].allowed_age[1],
                    newvaccine[n].times, newvaccine[n].is_used);
        	n++;
        }
      }
    printf("\n\n按任意键返回上一级菜单!\n");
   	getch();
}