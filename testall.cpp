/**
 * Macc n Cheese - Scanner Tester
 * 9-mar-2016
 * This program is used to test the scanner. It reads in the given source file and outputs the tokens.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <dirent.h>
using namespace std;

#include "mscan.h"

ifstream sourceFile;
ofstream listFile;
Scanner scan;

int called(string argv);

char test[2000][256];// I dont think we ever are 
//going to have even more than 100 test, but 
//I want to play safe

DIR *dir;

struct dirent *ent;

int main() {
	string answer;
	int value = 0,
	 	i = 0;
	if ((dir = opendir ("./tests/")) != NULL) {
	  /* print all the files and directories within directory */
	  while ((ent = readdir (dir)) != NULL) {
		string a = ent->d_name;
		// cout << a << " " << a.length() << endl;
	  	if(a != "." && a != ".." && a.length() > 4 && a.substr( a.length() - 4 ) == ".mnc") {
		    // printf ("%s\n", ent->d_name);
		    strcpy(test[i],"./tests/");
		    strcat(test[i],ent->d_name);
		    i++;
		}
	  }
	  closedir (dir);
	} else {
	  /* could not open directory */
	  perror ("There was no file on the directory");
	  return 3;
	}
	for(int i=0; i < sizeof(test); i++){
		string argv = test[i];
		cout << argv << endl;
		int value = called(argv);
		if(value == 1 || value == 2){
			break;
		///break if there is an error
		}
		//stop and let the user check the file
		//print the name of the file
		cout << "Is " << test[i] << " correct? \n intro no and press enter to stop scanning or answer no \n enter what ever else and press enter to continue" << endl;
		cin >> answer;
		if(answer == "no" || answer == "NO" || answer == "nO" || answer == "No"){
			break;
		}
		cin.clear();
	}
	return value;
}
int called(string argv){
	sourceFile.open(argv);
	if (!sourceFile.is_open()) {
		cout << "File not found.";
		cin.get();
		return 1;
	}

	listFile.open("listFile.lst");
	if (!listFile.is_open()) {
		cout << "Could not open list file.";
		cin.get();
		return 2;
	}

//	cout.width(20);
	cout << "---------- Scanner Tester ----------\n";
	cout << "TOKEN     \t\tTEXT\n";
	while (!sourceFile.eof()) {
		switch(scan.GetNextToken()) {
		case EOF_SYM:
			cout << "EOF_SYM   ";
			break;
		case BOOL_SYM:
			cout << "BOOL_SYM  ";
			break;
		case BREAK_SYM:
			cout << "BREAK_SYM ";
			break;
		case CASE_SYM:
			cout << "CASE_SYM  ";
			break;
		case CHEESE_SYM:
			cout << "CHEESE_SYM";
			break;
		case DECS_SYM:
			cout << "DECS_SYM  ";
			break;
		case DO_SYM:
			cout << "DO_SYM    ";
			break;
		case ELSE_SYM:
			cout << "ELSE_SYM  ";
			break;
		case END_SYM:
			cout << "END_SYM   ";
			break;
		case FALSE_SYM:
			cout << "FALSE_SYM ";
			break;
		case FLOAT_SYM:
			cout << "FLOAT_SYM ";
			break;
		case FOR_SYM:
			cout << "FOR_SYM   ";
			break;
		case HIPHIP_SYM:
			cout << "HIPHIP_SYM";
			break;
		case IF_SYM:
			cout << "IF_SYM    ";
			break;
		case INT_SYM:
			cout << "INT_SYM   ";
			break;
		case LISTEN_SYM:
			cout << "LISTEN_SYM";
			break;
		case OTHERWISE_SYM:
			cout << "OTHERWISE_SYM";
			break;
		case SELECT_SYM:
			cout << "SELECT_SYM";
			break;
		case SHOUT_SYM:
			cout << "SHOUT_SYM ";
			break;
		case THEN_SYM:
			cout << "THEN_SYM  ";
			break;
		case TRUE_SYM:
			cout << "TRUE_SYM  ";
			break;
		case WHILE_SYM:
			cout << "WHILE_SYM ";
			break;
		case LSTAPLE:
			cout << "LSTAPLE   ";
			break;
		case RSTAPLE:
			cout << "RSTAPLE   ";
			break;
		case LBANANA:
			cout << "LBANANA   ";
			break;
		case RBANANA:
			cout << "RBANANA   ";
			break;
		case LMUSTACHE:
			cout << "LMUSTACHE ";
			break;
		case RMUSTACHE:
			cout << "RMUSTACHE ";
			break;
		case COLON:
			cout << "COLON     ";
			break;
		case SEMICOLON:
			cout << "SEMICOLON ";
			break;
		case COMMA:
			cout << "COMMA     ";
			break;
		case ASSIGN_OP:
			cout << "ASSIGN_OP ";
			break;
		case PLUS_OP:
			cout << "PLUS_OP   ";
			break;
		case MINUS_OP:
			cout << "MINUS_OP  ";
			break;
		case MULT_OP:
			cout << "MULT_OP   ";
			break;
		case DIV_OP:
			cout << "DIV_OP    ";
			break;
		case LT_OP:
			cout << "LT_OP     ";
			break;
		case LE_OP:
			cout << "LE_OP     ";
			break;
		case GT_OP:
			cout << "GT_OP     ";
			break;
		case GE_OP:
			cout << "GE_OP     ";
			break;
		case EQ_OP1:
			cout << "EQ_OP1    ";
			break;
		case EQ_OP2:
			cout << "EQ_OP2    ";
			break;
		case NE_OP:
			cout << "NE_OP     ";
			break;
		case ID:
			cout << "ID        ";
			break;
		case BOOL_LIT:
			cout << "BOOL_LIT  ";
			break;
		case INT_LIT:
			cout << "INT_LIT   ";
			break;
		case FLOAT_LIT:
			cout << "FLOAT_LIT ";
			break;
		case CHEESE_LIT:
			cout << "CHEESE_LIT";
			break;
		default:
			break;
		}
		cout << "\t\t" << scan.tokenBuffer << "\n";
	}
	sourceFile.close();
	listFile.close();
	return 0;
}
