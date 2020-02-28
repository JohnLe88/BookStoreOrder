#include <fstream> 
#include <cstring>
#include "GS1Prefix.h"
using namespace std;
#include <cstdlib>


 bool load(const char* filename, Prefix* prefix) {
     bool rc = false;
     if (filename != NULL) {
         std::ifstream file(filename);
         if (file.is_open()) {
             int no = 0;
             while (file.good()) {  // version 1.2
                 file >> prefix->area[no] >> prefix->pubLow[no]; // version 1.3
                 if (file.good()) {
 					file >> prefix->pubHgh[no]; // version 1.3
                     prefix->pubLen[no] = std::strlen(prefix->pubLow[no]);
                     no++;
                 }
             }
             if (no > 0) {
                 rc = true;
                 prefix->no = no;
             }
         }
     }
     return rc;
 }

bool isRegistered(const Prefix* p, int area){
int i;
bool ischeck=0;

for(i=0;i<p->no;i++){
if(p->area[i] == area){
ischeck=1;
break;
}
}
return ischeck;
}

bool isRegistered(const Prefix* p, int area, const char* publisher){
int i;
int regReturn=0;
for(i=0;i<p->no;i++){
if(area == p->area[i]){
	if((strlen(publisher))==(strlen(p->pubLow[i]))){
		if ((atoi(publisher)) >= (atoi(p->pubLow[i]))) {
		  if ((atoi(publisher)) <= (atoi(p->pubHgh[i]))){
	    	regReturn = true;}
													   }
					 							  }
					  }
					 }
return regReturn;
}

int minNoDigits(const Prefix* p, int area) {
int count=0;
for(int i=0;i<p->no;i++){
if(p->area[i] == area){
count=strlen(p->pubLow[i]);
break;}
}
return count;
}

