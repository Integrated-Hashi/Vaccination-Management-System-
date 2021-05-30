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
typedef struct Vaccine{
    int vaccine_id;//疫苗编号
    char vaccine_name[10];//疫苗名字
    char company[50];//疫苗生产公司
    int allowed_age[2];//允许接种的年龄
    int times;//需要接种的次数
    int is_used;//是否使用了
}VACCINE;

//接种信息表
typedef struct Thing{
    int thing_id;//事件编号
    char person_name[10];//名字
    char ID_card[20];//身份证 
    int sex;//性别
    int age;//年龄
    char phone[20];//电话
    int vaccine_id; //疫苗编号
    char vaccine_name[10];//疫苗名字
    int time;//接种的次数（第几次）
}THING;

void menu1();
void add_vaccine();
int check_vaccine_num();
void display_vaccine();

void add_vaccinate();
int check_thing_num();
void renew_vaccine(int vaccine_id);

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

    add_vaccine();
    add_vaccinate();

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
            for(i=vaccine_num; i<n+vaccine_num; i++)
            {
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

    char ch;
    FILE *fp=fopen("vaccine.txt","r");
    ch = fgetc(fp);
    if(ch==EOF) 
    {
        printf("\n没有任何疫苗信息!\n\n");
        printf("\n\n按任意键返回上一级菜单!\n");
   	    getch();
        return;
    }
    fclose(fp);

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
    
    printf("\n\n按任意键返回上一级菜单!\n");
   	getch();
}

void add_vaccinate() /*输入添加的接种信息*/
{
    char choice;
    FILE *p1;
    THING newthing;
    system("cls");
    while(1)
      	{

        int n, i;
        int thing_num = check_thing_num();
		
        fflush(stdin); 
    
        printf("请输入身份证号码: ");
        gets(newthing.ID_card);

        //检查表中有无此人
        int flag1 = 0;
        if(thing_num>0)
        {
            THING thing;
            p1=fopen("thing.txt","r");
            while(!feof(p1))
            {
                fscanf(p1,"%d %s %s %d %d %s %d %s %d\n",
                                &thing.thing_id, 
                                thing.person_name, thing.ID_card,
                                &thing.sex, &thing.age, thing.phone,
                                &thing.vaccine_id, thing.vaccine_name,
                                &thing.time);  
                if((strcmp(thing.ID_card, newthing.ID_card))==0)
                {
                    printf("曾接种过，个人信息已存在。\n");
                    newthing = thing;
                    newthing.thing_id = thing_num;
                    flag1 = 1;
                    break;
                }
            }
            fclose(p1);
        }

        if(flag1 == 1)
        {
            //查看接种疫苗的需要接种的次数
            int allowed_num;
            VACCINE vaccine1;
            p1=fopen("vaccine.txt","r");
            while(!feof(p1))
            {
                fscanf(p1,"%d %s %s %d %d %d %d\n",
                                &vaccine1.vaccine_id, 
                                vaccine1.vaccine_name, vaccine1.company,
                                &vaccine1.allowed_age[0], &vaccine1.allowed_age[1],
                                &vaccine1.times, &vaccine1.is_used);  
                if(vaccine1.vaccine_id==newthing.vaccine_id){
                    allowed_num = vaccine1.times;
                    break;
                }
            }
            fclose(p1);

            if(newthing.time>=allowed_num){
                printf("您无需接种，接种次数已足够。\n");
                printf("\n\n按任意键返回上一级菜单!\n");
   	            getch();
                return;
            }
            
            //找到可用的疫苗
            int vaccineID;
            int flag2 = 0;
            VACCINE vaccine2;
            p1=fopen("vaccine.txt","r");
            while(!feof(p1))
            {
                fscanf(p1,"%d %s %s %d %d %d %d\n",
                                &vaccine2.vaccine_id, 
                                vaccine2.vaccine_name, vaccine2.company,
                                &vaccine2.allowed_age[0], &vaccine2.allowed_age[1],
                                &vaccine2.times, &vaccine2.is_used);  
                if((strcmp(newthing.vaccine_name, vaccine2.vaccine_name))==0&&vaccine2.is_used==0)
                {
                    vaccineID = vaccine2.vaccine_id;
                    flag2 = 1;
                    break;
                }
            }
            fclose(p1);

            if(flag2==0){
                printf("抱歉，目前没有合适的疫苗可供接种。\n");
                printf("\n\n按任意键返回上一级菜单!\n");
   	            getch();
                return;
            }

            renew_vaccine(vaccineID);

            p1=fopen("thing.txt","a");
            fprintf(p1,"%d %s %s %d %d %s %d %s %d\n",
                                newthing.thing_id, 
                                newthing.person_name, newthing.ID_card,
                                newthing.sex, newthing.age, newthing.phone,
                                vaccineID, newthing.vaccine_name,
                                newthing.time+1); 
            fclose(p1);

            printf("接种成功！");

        }
        else 
        {
            newthing.thing_id = thing_num;

            printf("请输入姓名: ");
            gets(newthing.person_name);
        
            printf("请输入性别: ");
            scanf("%d",&newthing.sex);
        
            printf("请输入年龄: ");
            scanf("%d",&newthing.age);
            
            fflush(stdin);

            printf("请输入电话: ");
            gets(newthing.phone); 

            //找到可用的疫苗
            int vaccineID;
            int flag2 = 0;
            VACCINE vaccine1;
            p1=fopen("vaccine.txt","r");
            while(!feof(p1))
            {
                fscanf(p1,"%d %s %s %d %d %d %d\n",
                                &vaccine1.vaccine_id, 
                                vaccine1.vaccine_name, vaccine1.company,
                                &vaccine1.allowed_age[0], &vaccine1.allowed_age[1],
                                &vaccine1.times, &vaccine1.is_used);  
                if(newthing.age>=vaccine1.allowed_age[0]&&vaccine1.is_used==0&&newthing.age<=vaccine1.allowed_age[1]){
                    vaccineID = vaccine1.vaccine_id;
                    flag2 = 1;
                    break;
                }
            }
            fclose(p1);

            if(flag2==0){
                printf("抱歉，目前没有合适的疫苗可供接种。\n");
                printf("\n\n按任意键返回上一级菜单!\n");
   	            getch();
                return;
            }

            renew_vaccine(vaccineID);

            p1=fopen("thing.txt","a");
            fprintf(p1,"%d %s %s %d %d %s %d %s %d\n",
                                newthing.thing_id, 
                                newthing.person_name, newthing.ID_card,
                                newthing.sex, newthing.age, newthing.phone,
                                vaccineID, newthing.vaccine_name,
                                newthing.time+1); 
            fclose(p1);

            printf("接种成功！");
        }
        fflush(stdin);
      	printf("\n\n下一位接种？(y/n): ");
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

int check_thing_num(){
    FILE *p1;
    int n;
    THING thing;
    int vaccine_num=0;
    system("cls");
    fflush(stdin);

    char ch;
    FILE *fp=fopen("thing.txt","r");
    ch = fgetc(fp);
    if(ch==EOF) return 0;
    fclose(fp);

    p1=fopen("thing.txt","r");
    while(!feof(p1))
    {
      	fscanf(p1,"%d %s %s %d %d %s %d %s %d\n",
                        &thing.thing_id, 
                        thing.person_name, thing.ID_card,
                        &thing.sex, &thing.age, thing.phone,
                        &thing.vaccine_id, thing.vaccine_name,
                        &thing.time);  
      	vaccine_num++;
    }
    fclose(p1);
    return vaccine_num;
}

void renew_vaccine(int vaccine_id){
    FILE *p1;
    VACCINE vaccine[1000];
    int vaccine_num=0, n;
    p1=fopen("vaccine.txt","r");
    while(!feof(p1))
    {
      	fscanf(p1,"%d %s %s %d %d %d %d\n",
                        &vaccine[vaccine_num].vaccine_id, 
                        vaccine[vaccine_num].vaccine_name, vaccine[vaccine_num].company,
                        &vaccine[vaccine_num].allowed_age[0], &vaccine[vaccine_num].allowed_age[1],
                        &vaccine[vaccine_num].times, &vaccine[vaccine_num].is_used); 
        if(vaccine_id==vaccine[vaccine_num].vaccine_id) {
            vaccine[vaccine_num].is_used=1;
        }
      	vaccine_num++;
    }
    fclose(p1);

    p1=fopen("vaccine.txt","w");
    for(n=0;n<vaccine_num;n++)
        fprintf(p1,"%d %s %s %d %d %d %d\n",
                        vaccine[n].vaccine_id, 
                        vaccine[n].vaccine_name, vaccine[n].company,
                        vaccine[n].allowed_age[0], vaccine[n].allowed_age[1],
                        vaccine[n].times, vaccine[n].is_used); 
    fclose(p1);
    printf("\n修改成功!");
}