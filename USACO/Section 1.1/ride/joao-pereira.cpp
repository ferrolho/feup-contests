/*
 ID: pereira1
 PROG: ride
 LANG: C++11
 */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {

	FILE* ifile = fopen("ride.in", "r");

	char comet[8], group[8];

	fscanf(ifile, "%s", comet);
	fscanf(ifile, "%s", group);

	fclose(ifile);

	int cometResult = comet[0] - 64, groupResult = group[0] - 64;

	for (unsigned int i = 1; i < strlen(comet); i++)
		cometResult *= (comet[i] - 64);

	for (unsigned int i = 1; i < strlen(group); i++)
		groupResult *= (group[i] - 64);

	FILE* ofile = fopen("ride.out", "w");

	if ((cometResult % 47) == (groupResult % 47))
		fprintf(ofile, "GO\n");
	else
		fprintf(ofile, "STAY\n");

	fclose(ofile);

	return 0;
}
