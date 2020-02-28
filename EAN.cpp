#include "GS1Prefix.h"
#include <cstring>
using namespace std;
#include <iostream>
#include <cstdlib>

bool isValid(const char* str) {
int isVal=1;
if (str!=NULL){

	if(strlen(str)==13){
		for(int i = 0; str[i]!='\0'; i++){
			if(isdigit(str[i]==0)){
			isVal = 0;}		
										 }
			
	if(isVal==1){
		int cal=0,remain=0;
			for(int i=0; i <=13; i=i+2){
				remain=str[i]-'0';
				cal=cal+remain;}
				

	for(int i=1;i<=12;i=i+2){
		remain=str[i]-'0';
		remain*=3;
		cal=cal+remain;}
				
	if((cal % 10) == 0){
		isVal=1;
		return true;}
	else{
		isVal=0;}
				}
	else{
		isVal=0;}
					  }
	else{
		isVal=0;}
			  }
	else{
		isVal=0;}
return isVal;
}




bool isRegistered(const Prefix* p, const char* str, char area[], char publisher[], char title[]){
bool ischeck = false;
char comparea[6];
char compub[8];
int extra;
char truetitle[8];

for(int i=0;i<5;i++){
	comparea[i]= str[i+3];
	comparea[i+1] = '\0';

	if(isRegistered(p, atoi(comparea))==true){
		ischeck=true;
		strcpy(area,comparea);
		break;
	}
}

if(ischeck!=false){
	ischeck=false;
	int pub=(3+strlen(area));

	for(int i=0;(i+pub)<=12;i++){
		compub[i]=str[i+pub];
		compub[i+1]='\0';

		if(isRegistered(p, atoi(area), compub)==true){
			ischeck = true;
			strcpy(publisher,compub);
			break;}
								}
				  }

if(ischeck !=false){
	int titlepos;
	titlepos=(3 + strlen(area)+ strlen(publisher));

		for(extra=0;(extra+titlepos)<12;extra++){
			truetitle[extra]=str[extra+titlepos];
		}
	truetitle[extra]= '\0';
	strcpy(title,truetitle);
}

return ischeck;




}
