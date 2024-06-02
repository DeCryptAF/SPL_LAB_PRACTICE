/*
Problem: Write a C program that takes customer data from the user and prints it.
It will have a First Name, Last Name, Account Number, Balance.
*/
#include <stdio.h>

struct account
{
  //nested struct for name
	struct 
	{
		char firstName[10];
		char lastName[10];
	} names;
	int accountNum;
	double balance;
};

//funtion declaration
void customer_info(struct account *acct);
void print_customer(struct account acct);

int main()
{
	struct account record;
	int n;
	printf("Enter the number of accounts: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("\nACCOUNT :\n");
		customer_info(&record);
		print_customer(record);
	}
	return 0;
}

void customer_info(struct account *acct)
{
	printf("Enter first name: ");
    scanf("%s", acct->names.firstName);
    printf("Enter last name: ");
    scanf("%s", acct->names.lastName);
    printf("Enter account number: ");
    scanf("%d", &acct->accountNum);
    printf("Enter balance: ");
    scanf("%lf", &acct->balance);
}

void print_customer(struct account acct)
{
	printf("\nCustomer Information:\n");
    printf("First Name: %s\n", acct.names.firstName);
    printf("Last Name: %s\n", acct.names.lastName);
    printf("Account Number: %d\n", acct.accountNum);
    printf("Balance: %.2lf\n\n", acct.balance);
}
