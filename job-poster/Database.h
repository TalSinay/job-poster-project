#ifndef DATABASE
#define DATABASE

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_POSTS 50
#define MAX_MANAGERS 50
#define MAX_DESCRIPTION 255
#define MAX_PASSWORD 20

#define MANAGERS_FILENAME "Managers.bin"
#define USERS_FILENAME "Users.bin"
#define POSTS_FILENAME "Posts.bin"
#define APPLIED_FILENAME "Applied.bin"

typedef struct Users {
	const unsigned int UserID;
	char UserName[MAX_SIZE];
	char FullName[MAX_SIZE];
	long ID;
	int age;
	char PhoneNumber[MAX_SIZE];
	char Password[MAX_PASSWORD];
} User;

typedef struct Managers {
	const unsigned int ManagerID;
	char UserName[MAX_SIZE];
	char FullName[MAX_SIZE];
	int Posts[MAX_POSTS];
	char Password[MAX_PASSWORD];
} Manager;

typedef struct Posts {
	const unsigned int PostID;
	int Location;
	int Type;
	int Profession;
	char Name[MAX_SIZE];
	char Description[MAX_DESCRIPTION];
	int Promoted;
} Post;

typedef struct Applied {
	const unsigned int AppliedId;
	const unsigned int PostID;
	const unsigned int UserID;
	char Description[MAX_DESCRIPTION];
} Apply;

/// <summary>
/// Creates the nessecary files if are missing
///  - you can run it multiple times, nothing will break
/// </summary>
/// <returns>1 - On success | exit on failure</returns>
int initFiles();

/// <summary>
/// Checks if the username exists in the database
/// </summary>
/// <param name="UserName">User's username</param>
/// <returns>0 - If not found | UserID - if found</returns>
int checkUserName(char UserName[MAX_SIZE]);

/// <summary>
/// Checks if the username of the manager exists in the database
/// </summary>
/// <param name="UserName">Manager's username</param>
/// <returns>0 - If not found | ManagerID - if found</returns>
int checkManagerUserName(char UserName[MAX_SIZE]);

/// <summary>
/// Checks if the user has aleardy appied for the application
/// </summary>
/// <param name="PostID">ID of the post the user wants to apply to</param>
/// <param name="UserID">ID of the user</param>
/// <returns>ApplicationID - if found | 0 - Otherwise</returns>
int checkUserApplication(const unsigned int PostID, const unsigned int userID);

/// <summary>
/// Finds the last User ID
/// </summary>
/// <returns>UserID - of the user | 0 - If not found</returns>
int getLastIdUsers();

/// <summary>
/// Finds the last Manager ID
/// </summary>
/// <returns>ManagerID - of the user | 0 - If not found</returns>
int getLastIdManagers();

/// <summary>
/// Finds the last Post ID
/// </summary>
/// <returns>PostID - of the post | 0 - If not found</returns>
int getLastIdPosts();

/// <summary>
/// Finds the last Applied ID
/// </summary>
/// <returns>AppliedID - of the post | 0 - If not found</returns>
int getLastIdApplications();

/// <summary>
/// Register a new user
/// </summary>
/// <param name="UserName">Username</param>
/// <param name="FullName">Full name</param>
/// <param name="ID">User ID (Teudat Zeut)</param>
/// <param name="age">User Age</param>
/// <param name="PhoneNumber">User phone number</param>
/// <returns>UserID - if registration successful | 0 - Otherwise</returns>
int registerUser(char UserName[MAX_SIZE], char FullName[MAX_SIZE], long ID, int age, char PhoneNumber[MAX_SIZE], char Password[MAX_PASSWORD]);

/// <summary>
/// Update user data
/// </summary>
/// <param name="userID">Id of the updated user (Must)</param>
/// <param name="UserName">Optional (pass NULL if not updated)</param>
/// <param name="FullName">Optional (pass NULL if not updated)</param>
/// <param name="ID">Teudat Zeut (ID) Optional (pass 0 if not updated)</param>
/// <param name="age">Optional (pass 0 if not updated)</param>
/// <param name="PhoneNumber">Optional (pass NULL if not updated)</param>
/// <param name="Password">Optional (pass NULL if not updated)</param>
/// <returns>UserID on success | 0 - Otherwise</returns>
int updateUserData(const unsigned int userID, char UserName[MAX_SIZE], char FullName[MAX_SIZE], long ID, int age, char PhoneNumber[MAX_SIZE], char Password[MAX_PASSWORD]);

/// <summary>
/// Register a new manager
/// </summary>
/// <param name="UserName">Username</param>
/// <param name="FullName">Business name/ User Full name</param>
/// <returns>ManagerID - if registration successful | 0 - Otherwise</returns>
int registerManager(char UserName[MAX_SIZE], char FullName[MAX_SIZE], char Password[MAX_PASSWORD]);

/// <summary>
/// Update manager data
/// </summary>
/// <param name="managerID">Optional (pass NULL if not updated)</param>
/// <param name="UserName">Optional (pass NULL if not updated)</param>
/// <param name="FullName">Optional (pass NULL if not updated)</param>
/// <param name="Password">Optional (pass NULL if not updated)</param>
/// <returns>ManagerID - if succeeded | 0 - Otherwise</returns>
int updateManagerData(const unsigned int managerID, char UserName[MAX_SIZE], char FullName[MAX_SIZE], char Password[MAX_PASSWORD]);

/// <summary>
/// Update post data
/// </summary>
/// <param name="postID"></param>
/// <param name="location"></param>
/// <param name="type"></param>
/// <param name="profession"></param>
/// <param name="name"></param>
/// <param name="description"></param>
/// <returns>PostID if succeeded | 0 - Otherwise</returns>
int updatePost(const unsigned int postID, int location, int type, int profession, char name[MAX_SIZE], char description[MAX_DESCRIPTION]);

/// <summary>
/// Register application for user to a post
/// </summary>
/// <param name="PostID">ID of the post the user wants to apply to</param>
/// <param name="UserID">ID of the user</param>
/// <param name="Description">The application contents</param>
/// <returns>ApplicationID if succeeded | 0 otherwise</returns>
int registerApplication(const unsigned int PostID, const unsigned int UserID, char Description[MAX_DESCRIPTION]);

/// <summary>
/// Searches for the user with the given ID and returns the User
/// </summary>
/// <param name="retValue">Pointer to the found user</param>
/// <param name="userID">The user ID to look for</param>
/// <returns>1 - If found | 0 - If not</returns>
int getUserData(User* retValue,const unsigned int userID);

/// <summary>
/// Searches for the manager with the given ID and returnes the Manager
/// </summary>
/// <param name="retValue">Pointer to the found manager</param>
/// <param name="managerID">The manager ID to look for</param>
/// <returns>1 - If found | 0 - If not</returns>
int getManagerData(Manager* retValue, const unsigned int managerID);

/// <summary>
/// Adds new post
/// </summary>
/// <param name="managerID">ID of the manager to add the post to</param>
/// <param name="location">value from 1 to 3 {North, Center, South}</param>
/// <param name="type">value 1 or 2 {Full time, Part time}</param>
/// <param name="profession">value from 1 to 8 {Security, Engineering, Medicine, Restaurants, Education, Public transportation, Factories, Economics}</param>
/// <param name="name">Job tittle</param>
/// <param name="description">Description of the job tittle</param>
/// <returns>1 - If post was added | 0 - If not"</returns>
int addPost(const unsigned int managerID ,int location, int type, int profession, char name[MAX_SIZE], char description[MAX_DESCRIPTION]);

/// <summary>
/// Get all posts from the database and save in the given pointer
/// </summary>
/// <param name="postsArray">The pointer to the posts array</param>
/// <returns>Number of posts in the array.</returns>
int getAllPosts(Post* postsArray[]);

/// <summary>
/// Checks if the userID password matches the one in the database
/// </summary>
/// <param name="userID">User ID</param>
/// <returns>1 - If matches | 0 - Otherwise</returns>
int checkPasswordUser(const unsigned int userID, char password[MAX_PASSWORD]);

/// <summary>
/// Checks if the manaagerID password matches the one in the database
/// </summary>
/// <param name="userID">Manager ID</param>
/// <returns>1 - If matches | 0 - Otherwise</returns>
int checkPasswordManager(const unsigned int managerID, char password[MAX_PASSWORD]);


#endif // !DATABASE
