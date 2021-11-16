#include "Database.h"
#include "Menager.h"


void view_post(Post post) // Helper
{
	printf("Name: %s\n", post.Name);	// ����� �� ������

	printf("Location: ");	// ����� ����� ������
	if (post.location == 1)
		printf("North\n");
	if (post.location == 2)
		printf("Center\n");
	if (post.location == 3)
		printf("South\n");

	printf("Type of job: ");	// ����� ��� ������
	if (post.Type == 1)
		printf("Full-time\n");
	if (post.Type == 2)
		printf("Part-time\n");

	printf("Profession: ");		// ����� ��� ������
	if (post.Profession == 1)
		printf("Security\n");
	if (post.Profession == 2)
		printf("Engineering\n");
	if (post.Profession == 3)
		printf("Medicine\n");
	if (post.Profession == 4)
		printf("Restaurants\n");
	if (post.Profession == 5)
		printf("Education\n");
	if (post.Profession == 6)
		printf("Public transportation\n");
	if (post.Profession == 7)
		printf("Factories\n");
	if (post.Profession == 8)
		printf("Economics\n");
	if (post.Profession == 0)
		printf("Not relevant\n");

	printf("Description:\n%s", post.Description);	// ����� ����� ������
}


void view_posts(Manager manager, Post post) // Requiremrnt 2.4
{
	if (manager.Posts > 0)
	{
		for (int i = 0; i < manager.Posts; i++)
		{
			printf("%d. ", i + 1);	// ����� ���� ������

			printf("Name: %s\n", post.Name);	// ����� �� ������

			printf("Location: ");	// ����� ����� ������
			if (post.location == 1)
				printf("North\n");
			if (post.location == 2)
				printf("Center\n");
			if (post.location == 3)
				printf("South\n");

			printf("Type of job: ");	// ����� ��� ������
			if (post.Type == 1)
				printf("Full-time\n");
			if (post.Type == 2)
				printf("Part-time\n");

			printf("Profession: ");		// ����� ��� ������
			if (post.Profession == 1)
				printf("Security\n");
			if (post.Profession == 2)
				printf("Engineering\n");
			if (post.Profession == 3)
				printf("Medicine\n");
			if (post.Profession == 4)
				printf("Restaurants\n");
			if (post.Profession == 5)
				printf("Education\n");
			if (post.Profession == 6)
				printf("Public transportation\n");
			if (post.Profession == 7)
				printf("Factories\n");
			if (post.Profession == 8)
				printf("Economics\n");
			if (post.Profession == 0)
				printf("Not relevant\n");

			printf("Description:\n%s", post.Description);	// ����� ����� ������
		}
	}
	else printf("No ads exist!\n");
}