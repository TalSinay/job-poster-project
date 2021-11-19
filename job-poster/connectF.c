#define _CRT_SECURE_NO_WARNINGS
#include "Database.h"
#include "Manager.h"
#include "Check.h"

int printPostsByCategory();
int printByCategories(Post* postsArray, int size, int category, int innerCategory);

int printPostsByCategory()
{
	int choose = -1;
	int innerChoose = 0;
	int sizeArray = 0;
	Post* postsArray = (Post*) malloc(MAX_POSTS * MAX_MANAGERS * sizeof(Post));
	sizeArray = getAllPosts(&postsArray);
	while (choose != 0)
	{
		printf("Choose search by category:\n1-->Location\n2-->Type (Full time job/Half time job)\n3-->Profession\n0-->Back\n");
		scanf_s("%d", &choose);
		while (choose > 3 || choose < 0)
		{
			printf("Wrong choose,please try again\n");
			scanf_s("%d", &choose);
		}
		switch (choose)
		{
		case 1:
			printf("Choose location:\n1-->North\n2-->Center\n3-->South\n0-->Back\n");
			scanf_s("%d", &innerChoose);
			printByCategories(postsArray, sizeArray, choose, innerChoose);
			break;
		case 2:
			printf("Choose Type:\n1-->Full time job\n2-->Half time job\n0-->Back\n");
			scanf_s("%d", &innerChoose);
			printByCategories(postsArray, sizeArray, choose, innerChoose);
			break;
		case 3:
			printf("Choose proffetion:\n1-->Security\n2-->Engineering\n3-->Medicine\n4-->Restaurants\n5-->Education\n6-->Public transportation\n7-->Factories\n8-->Economics\n0-->Back\n");
			scanf_s("%d", &innerChoose);
			printByCategories(postsArray, sizeArray, choose, innerChoose);
			break;
		default:
			break;
		}
	}
	free(postsArray);
	return 0;
}

int printByCategories(Post* postsArray, int size, int category, int innerCategory)//help function for prev function
{
	for (int i = 0; i < size; i++)
	{
		switch (category)
		{
		case 1:
		{
			if (postsArray[i].Location == innerCategory)
			{
				view_post(postsArray[i]);
			}
		}
		break;
		case 2:
			if (postsArray[i].Type == innerCategory)
			{
				view_post(postsArray[i]);
			}
			break;
		case 3:
			if (postsArray[i].Profession == innerCategory)
			{
				view_post(postsArray[i]);
			}
			break;
		default:
			break;
		}
	}
	return 0;
}

int enterCV(char* CV)//gets char* to enter the data that the user entered
{
	int choose = -1;
	do {
		printf("1-->Enter CV\n 0-->Back\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 0:
			return 0;
		case 1:
			scanf("%s",CV);

		default:
			printf("Wrong number, please try again\n");
			break;
		}
	} while (choose != 0);

}

int editUserProfile(const unsigned int userID)
{
	int choose = -1;
	char temp[MAX_SIZE] = "";
	long tempID = 0;
	int tempAge = 0;
	char temp2[MAX_SIZE] = "";
	int passwordTemp = 0;
	do {
		printf("Choose category to edit:\n1-->User namer\n2-->Full name\n3-->ID\n4-->Age\n5-->Phone number\n6-->Password\n0-->Back");
		scanf_s("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("Enter the new user name please:\n");
			strcpy(temp, "");
			scanf("%s",temp);
			updateUserData(userID, temp, NULL, 0, 0, NULL, NULL);
			break;
		case 2:
			printf("Enter the new full name please:\n");
			strcpy(temp, "");
			scanf("%s", temp);
			if (FullNameCheck(temp) == 0)
				updateUserData(userID, NULL, temp, 0, 0, NULL, NULL);
			else
				printf("Wrong full name\n");
			break;
		case 3:
			printf("Enter the new ID please:\n");
			scanf("%ld",&tempID);
			if (IDcheck(tempID) == 1)
				updateUserData(userID, NULL, NULL, tempID, 0, NULL, NULL);
			else
				printf("Wrong ID number\n");
			break;
		case 4:
			printf("Enter new age please:\n");
			scanf("%d", &tempAge);
			if (AgeCheck(tempAge) == 0)
				updateUserData(userID, NULL, NULL, 0, tempAge, NULL, NULL);
			else
				printf("Wrong age");
			break;
		case 5:
			printf("Enter new phone number please\n");
			strcpy(temp, "");
			scanf("%s", temp);
			if(phoneNumberCheck(temp)==0)
				updateUserData(userID, NULL, NULL, 0, 0, temp, NULL);
			else {
				if (phoneNumberCheck(temp) == 1)
					printf("Length of phone number is not correct");
				if (phoneNumberCheck(temp) == 2)
					printf("Wrong number entered, phone number starts with 05");
			}
			break;
		case 6:
			printf("Enter new password please:");
			strcpy(temp, "");
			scanf("%s", temp);
			printf("Enter new password again please (check)");
			strcpy(temp2, "");
			scanf("%s", temp2);
			if (strcmp(temp, temp2) == 0)
			{
				passwordTemp = PasswordCheck(temp);
				if (passwordTemp == 0)
					updateUserData(userID, NULL, NULL, 0, 0, NULL, temp);
				if (passwordTemp == 1 || passwordTemp == 2)
					printf("Wrong password, the new password is not long enough");
				if (passwordTemp == 3)
					printf("Wrong password, the new password needs to contain at least big and small letter and number");
			}
			else
				printf("Two passwords are not the same");
			break;
		default:
			break;
		}
	} while (choose != 0);
	return 0;
}


int editManagerData(const unsigned int userID)
{
	int choose = -1;
	char temp[MAX_SIZE] = "";
	long tempID = 0;
	int tempAge = 0;
	char temp2[MAX_SIZE] = "";
	int passwordTemp = 0;
	do {
		printf("Choose category to edit:\n1-->User namer\n2-->Full name\n3-->Password\n0-->Back");
		scanf_s("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("Enter the new user name please:\n");
			strcpy(temp, "");
			scanf("%s", temp);
			updateManagerData(userID, temp, NULL, NULL);
			break;
		case 2:
			printf("Enter the new full name please:\n");
			strcpy(temp, "");
			scanf("%s", temp);
			if (FullNameCheck(temp) == 0)
				updateManagerData(userID, NULL, temp, NULL);
			else
				printf("Wrong full name\n");
			break;
		case 3:
			printf("Enter new password please:");
			strcpy(temp, "");
			scanf("%s", temp);
			printf("Enter new password again please (check)");
			strcpy(temp2, "");
			scanf("%s", temp2);
			if (strcmp(temp, temp2) == 0)
			{
				passwordTemp = PasswordCheck(temp);
				if (passwordTemp == 0)
					updateManagerData(userID, NULL, NULL, temp);
				if (passwordTemp == 1 || passwordTemp == 2)
					printf("Wrong password, the new password is not long enough");
				if (passwordTemp == 3)
					printf("Wrong password, the new password needs to contain at least big and small letter and number");
			}
			else
				printf("Two passwords are not the same");
			break;
		default:
			break;
		}
	} while (choose != 0);
}
	