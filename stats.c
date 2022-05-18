#include "stats.h"
#include <stdio.h>
#include "math.h"

/*global variables*/
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

 Stats compute_statistics(const float* numberset, int setlength)
 {
	 Stats s;
	 s.average = 0;
	 s.min = numberset[0];
	 s.max = numberset[0];
	 int i;
	 int sum = 0;

	 if(setlength == 0)
	 {
		 s.average = NAN;
		 s.max = NAN;
		 s.min = NAN;
	 }
	 else
	 {
		 for(i = 0; i < setlength; i++ )
		 {
			 sum = sum + numberset[i];

			 //to find minimum number
			 if (numberset[i] < s.min )
			 {
				 s.min = numberset[i];
			 }

			 //to find maximum number
			 if(numberset[i] > s.max)
			 {
				 s.max = numberset[i];
			 }
		 }

		 //to find average of given numbers
		 s.average = sum / setlength;
	 }
	 return s;
}

 void check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats computedStats)
 {
	 int alertersCount;

	      if (computedStats.max > maxThreshold)
	     {
	         for(alertersCount = 0; alertersCount < 2; alertersCount++)
	         {
	             alerters[alertersCount]();
	         }
	     }
 }




