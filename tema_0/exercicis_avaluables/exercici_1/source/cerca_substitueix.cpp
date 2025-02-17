#include "cerca_substitueix.h"
#include <cstring>


bool cercaString(char text[], char subStr[], int &posicio)
{
 int i = posicio; //comença amb la posicio desitjada
bool trobat = false;

int longstr = strlen(str);
int longTEXT = strlen(text);
int j = 0;

while ((!trobat) && (text[i] != '\0')) {

	while (text[i + k] == str[i]) {
		if (i == longstr) {
			trobat = true;
			posicio = i;
		}
		else {
			j++;
		}
	}
}

return trobat; 

}

void substitueixString(char text[], int posicio, char stringOriginal[], char nouString[])
{
//saber les long. de les cadenes: 
int longTEXT = strlen(text);
int longOriginal = strlen(stringOriginal);
int longNOU = strlen(nouString);
int diferencia;

if (longNOU > longOriginal) {

	diferencia = longNOU - longOriginal;

	for (int i = longTEXT; i >= posicio + longOriginal; i--) {
		text[i + diferencia] = text[i];
	}
}

if (longNOU < longOriginal) {

	diferencia = longOriginal - longNOU;
	for (int i = posicio + longOriginal; i <= longTEXT; i++) {
		text[i + diferencia] = text[i];
		//moure a l'esquerra per omplir els espais buits. 
	}
}

for (int i = 0; i < longNOU; i++) {
	text[posicio + i] = nouString[i];
	//posisio + i, posicio indica per on començar, i la i, per anar avançant posicions en el string. 
}
}

int cercaSubstitueix(char text[], char stringOriginal[], char nouString[])
{
 int numsub = 0;
int posicio = 0;

while (cercaString(text, stringOriginal, posicio)) {
	substitueixString(text, posicio, stringOriginal, nouString);
	numsub++;
	posicio = posicio + strlen(nouString);
}
return numsub; 

}
