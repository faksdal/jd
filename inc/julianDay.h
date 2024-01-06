/*
 *
 *	julianDay.h
 *	created 6 Dec 2022 by jole
 *
 *	References:
 *		https://isbnsearch.org/isbn/0943396611
 *		https://observablehq.com/@danleesmith/meeus-solar-position-calculations
 *
 *	The following is taken from Jean Meeus' Astronomical algorithms second edition
 *	published by Willmann-Bell, Inc. in 1998.
 *
 *	Algorithms used in this software can be found in ch. 7, p.59 onwards.
 *
 *
 *
 *
 *	Constructor parameters:
 * 		jdnYear:	the year as an integer, i.e. 2022 or -1
 * 		jdnMonth:	the month as a short, 1 = January, 2 = February and so forth
 * 		jdnDay:		the day of the month
 *		jdnHour:	the hour of the day, 0-23, local time
 *		jdnMinute:	the minute of the hour 0-59, local time
 *		jdnSecond:	the second of the minute, 0-59, local time
 *		jdnTz:		the timezone
 *		jdnVerbose:	if true, prints out extra info during calculation
 *
 *
 *
 *	****************************************************************************************************
 *	The class is provided as-is without any warranty of any kind. Feel free to modify to your own needs!
 *	****************************************************************************************************
 *
 *
 *
*/

#ifndef __julianDay_h__
#define __julianDay_h__

#include <math.h>
#include <iomanip>
#include <iostream>


using namespace std;



class julianDay {


			//	True for dates in the Gregorian calendar, false otherwise
	bool	jdnGregorianDate;

			//	Some dates in our history doesn't exist; 5th - 14th of October 1582 were skipped during the
			//	transition from the Julian to the Gregorian Calendar.
			//	True for any other date
	bool	jdnValidDate;

			//	Set this to true if you want the calculation process to be verbose
	bool	jdnVerbose;

			//	True for leap years
	bool	jdnIsLeap;

			//	These holds values for the date to be converted into Julian Day Number (JDN)
	short	jdnDay, jdnMonth, jdnHour, jdnMinute, jdnSecond, jdnTz;

			//	Precision formatters for terminal printing
	short	jdnFLOATWIDTH, jdnFLOATPRECISION;

	short	jdnDayOfTheYear;

			//	Value of the year being converted to JDN
	int		jdnYear;

			//	These are the calculated values for JD and the Julian Century (JC)
			//	I also keep the JD and JC for noon, to be used for calculating
			//	the day of the week, sunrise an sunset
	long double	jdnJulianDay, jdnJulianCentury, jdnJdnNoon, jdnJulianCenturyNoon, jdnJ2000, jdnJulianMillennia, jdnJulianMillenniaNoon;

	//enum Days {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
	//Days	dayOfWeek;
	const char	*dayOfTheWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };


	void	jdnParseDate(void);
	void	jdnCalculateJdn(void);



public:

	julianDay(int year, short month, short day, short hour, short minute, short second, short tz, bool verbose);
	virtual ~julianDay();


	//
	// inline public functions providing data member values
	//
	int			jdnGetJdnYear(void)					{ return jdnYear; }
	int			jdnGetDayOfTheYear(void)			{ return jdnDayOfTheYear; }
	short		jdnGetJdnMonth(void)				{ return jdnMonth; }
	short		jdnGetJdnDay(void)					{ return jdnDay; }
	short		jdnGetJdnHour(void)					{ return jdnHour; }
	short		jdnGetJdnMinute(void)				{ return jdnMinute; }
	short		jdnGetJdnSecond(void)				{ return jdnSecond; }
	short		jdnGetJdnTz(void)					{ return jdnTz; }
	long double	jdnGetJdnJulianDay(void)			{ return jdnJulianDay; }
	long double	jdnGetJdnNoon(void)					{ return jdnJdnNoon; }
	long double	jdnGetJdnJulianCentury(void)		{ return jdnJulianCentury; }
	long double	jdnGetJdnJulianCenturyNoon(void)	{ return jdnJulianCenturyNoon; }
	long double	jdnGetJdnJulianMillenia(void)		{ return jdnJulianMillennia; }
	long double	jdnGetJdnJulianMilleniaNoon(void)	{ return jdnJulianMillenniaNoon; }

	bool		jdnGetIsLeap(void)					{ return jdnIsLeap; }


	const char*	jdnGetDayName(void);

	/*
	void	jdnSetJdnJulianCentury(double _jdnJulianCentury) {jdnJulianCentury = _jdnJulianCentury;}
	void	jdnSetJdnJulianCenturyNoon(double _jdnJulianCenturyNoon){jdnJulianCenturyNoon =_jdnJulianCenturyNoon;}

	//
	//	print-to-screen routines
	//
	void jdnPrintOutput(void);
	*/

};	//	class julianDay{}



#endif	//	__julianDay_h__
