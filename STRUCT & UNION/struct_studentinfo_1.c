/*
Problem: Write a C program to display student info using structrures

Usage:
basic implementation of struct
*/
#include <stdio.h>a
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[100];
    int s1, s2, s3;
    float avg;
    int roll;
    char grade;
};

int main()
{
    struct student student1;
    char name[100];
    
    //Name input
    printf("Enter the name : ");
    scanf("%s", name);
    strcpy(student1.name, name);

    //Roll Number
    printf("Enter the Roll Number : ");
    scanf("%d", &student1.roll);

    //Subject marks info
    printf("Enter marks for PHY, CHEM, MATH : ");
    scanf("%d%d%d", &student1.s1, &student1.s2, &student1.s3);

    // Calculate average:
    student1.avg = (student1.s1 + student1.s2 + student1.s3) / 3.0f;
    
    student1.grade = (student1.avg >= 80) ? 'A' :
                     (student1.avg >= 60) ? 'B' :
                     (student1.avg >= 40) ? 'C' : 'F';

    printf("\nRoll    Name       PHY   CHEM   MATH   Grade     avg\n");
    printf("-------------------------------------------------------\n");
    printf("%d%11s %7d %6d %6d %6c \t%.2f\n", student1.roll, student1.name, student1.s1, student1.s2, student1.s3, student1.grade, student1.avg);
    
    return 0;
}
