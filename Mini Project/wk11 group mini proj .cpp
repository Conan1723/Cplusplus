#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <random>
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <cmath>
#include <fstream>
#include<ctype.h>



struct Node {
	Node* left, * right;

	int SID,year;
	double grade;
	std::string admType,Major;	
	

	Node() {
		left = right = NULL;
		SID = year = 0;
		grade = 0.0;		
	}

	Node(int stdtn, std::string mj, double g, std::string type, int yy) {
		left = right = NULL;
		SID = stdtn;
		grade = g;
		admType = type;
		year = yy;
		Major = mj;
	}
};

Node* insertBST(Node*root,int stdtn, std::string mj, double g, std::string type, int yy) {
	//stdtn,mj,g,type,yy
	if (root == NULL)return new Node(stdtn,mj,g,type,yy);
	else {
		if (stdtn < root->SID)root->left = insertBST(root->left, stdtn, mj, g, type, yy);
		if (root->SID < stdtn)root->right = insertBST(root->right, stdtn, mj, g, type, yy);
	}
	return root;
}

void deleteTree(Node** root) {
	if ((*root) == NULL) return;

	if ((*root)->left != NULL) deleteTree(&((*root)->left));

	if ((*root)->right != NULL) deleteTree(&((*root)->right));

	*root = NULL;

	delete[](*root);
	free(*root);
}

void printBST(Node* root) {
	if (root != NULL) {
		printBST(root->right);	

		printf("------------------\n");
		printf("SID: %d\n", root->SID);
		std::cout << "Major: " << root->Major << std::endl;
		std::cout << "Grade: " << root->grade << std::endl;
		std::cout << "Adm Type: " << root->admType << std::endl;
		std::cout << "application year: " << root->year << std::endl;
		printf("------------------\n");

		printBST(root->left);
	}	
}

Node* searchSID(Node* root, int num) {
	if (root == NULL)return root;//root is NULL
	Node* ptr = NULL;
	if (root->SID == num)ptr = root;
	else {
		if (num < root->SID)ptr = searchSID(root->left, num);
		if (root->SID < num)ptr = searchSID(root->right, num);
	}
	return ptr;
}

bool deleteMJ(Node* root,int ID) {
	//bool exist = false;
	Node* bye = searchSID(root, ID);
	if (bye != NULL) {
		bye->Major = "null";
		return true;
	}

	return false;
	
}

bool Node_exist(Node* root, int ID) {
	bool exist = false;
	Node* ptr = searchSID(root, ID);
	if (ptr !=NULL)exist = true;//already same ID
	else exist = false;//ID is new
	return exist;
}

void interact(Node*root) {
	//printf("1. search\n2. insert\n3. delete\n4. over\n");
	//goto start;
	
	std::string swear="";	

	Node* idk=NULL;
	
	while (swear != "over") {
		start:printf("\n*****Please input one of the following operations: search, insert, delete, over *****\n");
		std::cin >> swear;
		
		if (swear == "over") {
			printf("Your input is <over>. Bye.\n");
			break;}

		else if (swear == "search") {
			printf("Your input is <search>. What is the student ID\n");			
			int num;
			std::cin >> num;
			idk = searchSID(root, num);
			if (idk != NULL) {
				printf("ID: %d\n", idk->SID);
				std::cout << "Major: " << idk->Major << std::endl;
				std::cout << "Grade: " << idk->grade << std::endl;
				std::cout << "Adm Type: " << idk->admType << std::endl;
				std::cout << "application year: " << idk->year << std::endl;
				//printf("\n");
				printf("\n");
			}
			else printf("This ID does not exist\n");
		}

		else if (swear == "delete") {
			printf("Your input is <delete>. What is the ID you want to delete\n");			
			int num;
			std::cin >> num;
			bool hi = deleteMJ(root, num);
			if (hi == false)printf("wrong ID, nothing to delete!\n");
			else printf("The student with ID %d is deleted\n", num );
		}

		else if (swear == "insert") {
			printf("Your input is <insert>. What is the record\n\n");
			int SID = 0, year = 0;
			double grade = 0.0;
			std::string admType, Major;			
			std::cin >> SID >> Major >> grade >> admType >> year;
			/* 
			major isalpha
			Grade [0.0,100.0]
			*/
			int OK = 1;

			for (int i = 0; i < Major.size(); i++) {
				if (!isalpha(Major[i])) {
					OK *= 0;
					printf("wrong format in Major\n");
					break;
				}
			}

			if (grade < 0.00 || grade>100.00) {
				printf("wrong format in grade\n");
				OK *= 0;
			}
			if (year>2022) {
				printf("wrong format in year\n");
				OK*=0;
			}			
			
			if (OK != 1)goto start;// not ok
			////////////////////////////////////
			if (Node_exist(root, SID) == true)printf("This ID is already used.Invalid input!\n");
			else  root = insertBST(root, SID, Major, grade*1.00, admType, year);
		}		

		else printf("You must choose one of the four operations : search, insert, delete, over\n");
			
	
	}	
		
	// over exist
}

int main() {

	printf("Authors: Pun Wing Hon(56422302) and Chau Chun Yau(56611807)\n");


	std::string filename;

	printf("input file name: ");

	std::cin >> filename;//stduent-record.txt

	Node* BST_record=NULL;

	//input var
	int SID=0, year=0;
	double grade=0.0;
	std::string admType, Major;
	//
	std::fstream reader(filename);
	while (!reader.eof()) {
		reader >> SID;
		reader >> Major;
		reader >> grade;
		reader >> admType;
		reader >> year;
		BST_record = insertBST(BST_record,SID,Major,grade,admType,year);
	}

	reader.close();
	printf("Database indexing fininished\n");
	//printBST(BST_record);
	//printf("\n");

	interact(BST_record);

	//clear
	deleteTree(&BST_record);

	return 0;
}

