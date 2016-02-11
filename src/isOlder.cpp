/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int wrongDate(char *dob,int *day, int *month, int *year)
{
	if (dob[10] != '\0') return 1;
	for (int i = 0; i < 10; i++)
	{
		if (dob[i] == '\0') return 1;
		if (!(('0' <= dob[i] && dob[i] <= '9') || dob[i] == '-'))return 1;
	}
	 *day = (int)((dob[0] - '0') * 10 + (dob[1] - '0'));
	 *month = (int)((dob[3] - '0') * 10 + (dob[4] - '0'));
	 *year = (int)((dob[6] - '0') * 1000 + (dob[7] - '0') * 100 + (dob[8] - '0') * 10 + (dob[9] - '0'));
	 if (*month > 12||*day > 31)return 1;
	 if ((*month == 4) || (*month == 6) || (*month == 9) || (*month == 11)){ if (*day > 30) return 1; }
	 if (*month == 2)
	 {
		 if ((*year) % 4 == 0 && (!(((*year % 100) == 0) ^ ((*year % 400) == 0)))){ if (*day > 29) return 1; }
		 else { if ((*day) > 28) return 1; }
	 }
	 return 0;
}
int isOlder(char *dob1, char *dob2) {
	int day1 = 0, month1 = 0, year1 = 0, day2 = 0, month2 = 0, year2 = 0;
	if (wrongDate(dob1, &day1, &month1, &year1) || wrongDate(dob2, &day2, &month2, &year2))return -1;
	if (year1 < year2)return 1;
	else if (year1 > year2) return 2;
	else {
		if (month1 < month2)return 1;
		else if (month1 > month2) return 2;
		else {

			if (day1 < day2)return 1;
			else if (day1 > day2) return 2;
			else return 0;
		}

	}
}