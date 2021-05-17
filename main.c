/*
 * @Author: cqupt_chenjunyu 
 * @Date: 2021-05-11 21:33:51 
 * @Last Modified by: cqupt_chenjunyu
 * @Last Modified time: 2021-05-11 21:41:40
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct vaccine{
    long id;
    char company[50];
    int allowed_age[2];
    long user_id;
    int Number_inoculations;
}VACCINE[1000];

typedef struct person{
    long user_id;
    char name[10];
    char ID_card[20]; 
    int sex;
    int age;
    char phone[20];
}volunteer[1000], operator;

int main(){
    
}