/*
 * julianDay.cpp
 *
 *  Created on: 6 Dec 2022
 *      Author: jole
 *
 *	Class julianDay calculates the Julian Day Number for the given date and time.
 *
 *	This work is largely based on the work of Jean Meeus and his writing in the
 *	publication Astronomical Algorithms ISBN 0-943396-61-1
 *	It can be found here https://isbnsearch.org/isbn/0943396611
 *
 *	The work also includes resources I found here:
 *		- https://www.ladybug.tools/ladybug-web/solar-calculator-noaa/noaa-sandbox-r2.html
 *		- https://gml.noaa.gov/grad/solcalc/main.js
 *		- https://en.wikipedia.org/wiki/Julian_day#Julian_day_number_calculation
 *
 *	****************************************************************************************************
 *	The class is provided as-is without any warranty of any kind. Feel free to modify to your own needs!
 *	****************************************************************************************************
 */


#include "julianDay.h"

#include <math.h>
//#include <stdio.h>
//#include <string>
//#include <iostream>

using namespace std;



//
//	TODO	This can be an inline function...
//
const char*	julianDay::jdnGetDayName(void)
{
	/*
	long	dividend, divisor, quotient;

	dividend = jdnJdnNoon + 1;
	divisor = 7;
	quotient = dividend % divisor;
	*/

	//cout	<< "Dividend: " << setw(25) << setprecision(15) << setfill(' ') << dividend << endl;
	//cout	<< "Divisor: " << setw(25) << setprecision(15) << setfill(' ') << divisor << endl;
	//cout	<< "Quotient: " << setw(25) << setprecision(15) << setfill(' ') << quotient << endl;

	return dayOfTheWeek[long(jdnJdnNoon+1) % (7)];
	//return dayName[quotient];
}



julianDay::julianDay(int year, short month, short day, short hour, short minute, short second, short tz, bool verbose)
{
	//
	//	initialise parameters into the class members
	//
	jdnYear		= year;
	jdnMonth	= month;
	jdnDay		= day;

	jdnHour		= hour;
	jdnMinute	= minute;
	jdnSecond	= second;

	jdnTz		= tz;

	//
	//	This is a fixed value used to calculate Julian century.
	//	See Meeus, Jean Astronomical Algorithms second edition p.163 (25.1)
	//
	jdnJ2000	= 2451545.0;



	//
	// These are to be calculated, so we'll initialise them to NIL
	//
	jdnJulianDay			= 0.;
	jdnJulianCentury		= 0.;
	jdnJulianCenturyNoon	= 0.;
	jdnJdnNoon				= 0.;

	jdnVerbose = verbose;

	jdnFLOATWIDTH		= 25;
	jdnFLOATPRECISION	= 15;


	//
	//	Parsing the date supplied, taking the appropriate action...
	//
	jdnParseDate();

	//
	//	Calculating the JDN for the supplied date
	//
	jdnCalculateJdn();

	//
	//	Calculate the day number of the year
	//
	//int K = jdnIsLeap==true ? 1 : 2;
	//cout << "K = " << K << endl;
	jdnDayOfTheYear = int((275 * jdnMonth) / 9) - ((jdnIsLeap ? 1 : 2) * int((jdnMonth + 9) / 12)) + jdnDay - 30;

	//dayOfWeek = Wednesday;
	//cout << "Day: " << dayOfWeek << endl;



}



julianDay::~julianDay() {
	// Empty destructor
}
