
/*
	BESCOM
					Fixed Charges per month

											2021			2022

	*	for first unit						₹ 85			₹ 100
	*	for every subsequent unit			₹ 95			₹ 110
			from 1KW to 50KW	


					Energy charges per month

								2021			2022

	*	for   0-50  units		₹ 4.10			₹ 4.15
	*	for  51-100 Units		₹ 5.55			₹ 5.60
	*	for 101-200 units		₹ 7.10			₹ 7.15
	*	for abv 200 units		₹ 8.15			₹ 8.20

	*	Fuel Cost Adjustment Charges
	FAC Charges : ₹ 0.74 per unit.

*/


#include <stdio.h>
#include <time.h>


void repeat(char left[], char key, int k){

	for (int i = 0; i < k; i++)
		left[i] = key;
}


int main(){
    
	char left[50] = "", right[50] = "";
	float units, amt, tax, fac;
	float fixedCharge = 100 + 137.5, taxRate = 0.09;


    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);

    int day   = tm.tm_mday,
    	month = tm.tm_mon+1,
    	year  = tm.tm_year+1900;

	repeat(left , '>', 45);
	repeat(right , '<', 45);

	printf("\nENTER NUMBER OF UNITS CONSUMED : ");
	scanf("%f", &units);


	printf("\n%s\n\n", left);
	printf("ELECTRICITY BILL\n");


	printf("%s\n\n", right);

    printf("BILL PERIOD	    %d/%d/%d - %d/%d/%d\n", day, month-1, year, day, month, year);
    printf("RDNG. DATE			 %d/%d/%d\n\n", day, month, year);

    float temp[4] = {0};
	if ( units <= 50) {
		amt = units*4.15;	//Basic Charges
		temp[0] = units;
	}else if ( units > 50 && units <= 100){
		amt = ( units -50)*5.60 + 50*4.15;
		temp[0] = 50;  temp[1] = units -50;
	}else if ( units > 100 && units <= 200){
		amt = ( units -100)*7.15 + 50*5.60 + 50*4.15;
		temp[0] = 50;  temp[1] = 50;  temp[2] = units -100;
	}else if ( units > 200){
		amt = ( units -200)*8.20 + 100*7.15 + 50*5.60 + 50*4.15;
		temp[0] = 50;  temp[1] = 50;  temp[2] = 100;  temp[3] = units -200;
	}

	printf("CONSUMPTION (UNITS)\t\t  %.0f\n", units);

	printf("%s\n\n", left);
	printf("    FIXED  CHARGES (UNIT, RATE, AMT)\n\n");

	printf("1KW\t\t100\t\t  100.00\n");
	printf("1.25KW\t\t110\t\t  137.50\n\n");
	printf("\t\t\t	₹ %.2f\n", fixedCharge);

	printf("%s\n\n", right);
	// printf("FIXED CHARGES		₹ %.2f\n\n", fixedCharge);

	// printf("ENERGY CHARGES		₹ %.2f\n\n", amt);

	printf("    ENERGY CHARGES (UNIT, RATE, AMT)\n\n");


	printf("%.0lf\t\t4.15\t\t  %.2f\n", temp[0], temp[0]*4.15);
	printf("%.0lf\t\t5.60\t\t  %.2f\n", temp[1], temp[1]*5.60);
	printf("%.0lf\t\t7.15\t\t  %.2f\n", temp[2], temp[2]*7.15 );
	printf("%.0lf\t\t8.20\t\t  %.2f\n\n", temp[3], temp[3]*8.20 );
    
	printf("\t\t\t	₹ %.2f\n", amt);
	printf("%s\n\n", right);


	fac = units * 0.74;
	printf("    FAC CHARGES (UNIT, RATE, AMT)\n\n");
	printf("%.0f\t\t0.74\t\t  %.2f\n", units, fac);
	printf("%s\n\n", right);


	tax = amt * taxRate;
	amt += fixedCharge + tax + fac;		//Tax + Meter Charges + FAC


	printf("TAX\t\t\t\t₹ %.2f\n\n", tax);
	printf("BILL AMT\t\t\t₹ %.2f\n\n", amt);
	printf("NET AMT DUE\t\t\t₹ %.0f.00\n\n", amt);

	if (day +14 < 31)
	    printf("DUE DATE\t\t\t%d/%d/%d\n", day +14, month, year);
	else
		printf("DUE DATE\t\t\t%d/%d/%d\n", day -16, month +1, year);

	printf("%s\n\n", left);

	return 0;
}