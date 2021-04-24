#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


struct date 
{
	int day;
	int month;
	int year;
};

struct time 
{
	int hour;
	int minutes;
};

class Date_time
{
  private:
	int day = 1;
	int month = 1;
	int year = 0;
	int hour = 0;
	int minute = 0;

	void add_day ()
	{
		int max_date = 31;
		int months_with_30[] = { 4, 6, 9, 11 };

        for ( int i = 0; i < 4; i = i + 1 )
            if ( month == months_with_30[ i ] )
                max_date = 30;

       if ( month == 2 )
        {
            if (year % 4 == 0)
                max_date = 29;
            else
                max_date = 28;
        }

        if ( day == max_date )
        {
            day = 1;

            if ( month == 12 )
            {
                month = 1;
                year = year + 1;
            }
            else
                month = month + 1;
        }
        else
            day = day + 1;
	}

	void substract_day ()
	{
        if ( day == 1 && month == 1 && year == 0 )
            return;

       int previous_month;

        if ( month == 1 )
            previous_month = 12;
        else
            previous_month = month - 1;

        int max_date = 31;
        int months_with_30[] = { 4, 6, 9, 11 };

        for ( int i = 0; i < 4; i = i + 1 )
            if ( previous_month == months_with_30[ i ] )
                max_date = 30;

        if ( previous_month == 2 )
        {
            if (year % 4 == 0)
                max_date = 29;
            else
                max_date = 28;
        }

        if ( day == 1 )
        {
            day = max_date;

            if ( month == 1 )
            {
                month = 12;
                year = year - 1;
            }
            else
                month = month - 1;
        }
        else
            day = day - 1;
	}

	void add_minute ()
	{
		if ( minute == 59 )
        {
            minute = 0;

            if ( hour == 23 )
			{
                hour = 0;
				add_day();
			}
            else
                hour = hour + 1;
        }
        else
            minute = minute + 1;
	}

	void substract_minute ()
	{
		if ( minute == 0 )
        {
            minute = 59;

            if ( hour == 0 )
			{
                hour = 23;
				substract_day();
			}
            else
                hour = hour - 1;
        }
        else
            minute = minute - 1;
	}

	void add_hour ()
	{
		if ( hour == 23 )
		{
			hour = 0;
			add_day();
		}
		else
			hour = hour + 1;
	}

	void substract_hour ()
	{
		if ( hour == 0 )
		{
			hour = 23;
			substract_day();
		}
		else
			hour = hour - 1;
	}

	string date_int_to_string (int a)
	{
		if ( a == 0 )
			return "00";

		string result = "";

		while ( a != 0 )
		{
			result = result + (char) (a % 10 + 48);
			a = a / 10;
		}

		int size = result.length();

		string inverted = "";

		for ( int i=size-1; i>=0; i=i-1 )
			inverted = inverted + result[i];

		if ( size == 1 )
			inverted = '0' + inverted;

		return inverted;
	}

	int date_string_to_int ( string a )
	{
		if ( a.length() == 1 )
			return a[0] - 48;

		int size = a.length();

		int iter = 0;
		bool is_neg = false;
		if ( a[0] == '-' )
		{
			is_neg = true;
			iter = 1;
		}

		int num_int = 0;

		for ( int i=iter; i<size; i=i+1 )
			num_int = num_int * 10 + ( a[i] - 48 );

		if ( is_neg )
			num_int = -num_int;

		return num_int;
	}

	void move_date_time ( string text, string words[], char sep )
	{
		text = text + sep;

		int size = text.length();

		int words_iter = 0;

		for ( int i=0; i<size; i=i+1 )
			if ( text[i] == sep )
			{
				words_iter = words_iter + 1;
				words[ words_iter ] = "";
			}
			else
				words[ words_iter ] = words[ words_iter ] + text[i];
	}

  public:

	void set_year ( int years ) { if( year < 0 ) return; year = years; }
	void set_month ( int months ) { if( months <= 0 or months > 12 ) return; month = months; }
	void set_day ( int days ) 
	{
		int max_day = 31;
		if ( month == 4 or month == 6 or month == 9 or month == 11 )
			max_day = 30;
		if ( month == 2 )
		{
			if ( year % 4 == 0 )
				max_day == 29;
			else
				max_day == 28;
		}

		if ( days < 0 or days > max_day )
			return;

		day = days;
	}
	void set_hour ( int hours ) { if( hours < 0 or hours >= 24 ) return; hour = hours; }
	void set_minute ( int minutes ) { if ( minutes < 0 or minutes >= 60 ) return; minute = minutes; }

	void set_date ( int days, int months, int years )
	{
		set_day ( days );
		set_month ( months );
		set_year ( years );
	}

	void set_date_time ( int days, int months, int years, int hours, int minutes )
	{
		set_day ( days );
		set_month ( months );
		set_year ( years );
		set_hour ( hours );
		set_minute ( minutes );
	}

	void set_time ( int hours, int minutes )
	{
		set_hour ( hours );
		set_minute ( minutes );
	}

	void set_date_time ( string date_time )
	{
		string date_times[ 5 ];
		string date[ 5 ];
		string time[ 5 ];

		move_date_time( date_time, date_times, ' ' );
		move_date_time( date_times[0], date, '/' );
		move_date_time( date_times[1], time, ':' );

		set_day ( date_string_to_int( date[0] ) );
		set_month ( date_string_to_int( date[1] ) );
		set_year ( date_string_to_int( date[2] ) );
		set_hour ( date_string_to_int( time[0] ) );
		set_minute ( date_string_to_int( time[1] ) );
	}

	void set_date_time ( Date_time d )
	{
		year = d.year;
		month = d.month;
		day = d.day;
		hour = d.hour;
		minute = d.minute;
	}

	bool equals ( Date_time d )
	{
		if ( year == d.year && 
		month == d.month && 
		day == d.day && 
		hour == d.hour && 
		minute == d.minute )
			return 1;
		return 0;
	}

	Date_time ()
	{
		
	}

	Date_time ( int days, int months, int years )
	{
		set_date( days, months, years );
	}

	Date_time ( int days, int months, int years, int hours, int minutes )
	{
		set_date_time( days, months, years, hours, minutes );
	}

	Date_time ( int hours, int minutes )
	{
		set_time( hours, minutes );
	}

	Date_time ( string date_time )
	{
		set_date_time( date_time );
	}

	int get_year () { return year; }
	int get_month () { return month; }
	int get_day () { return day; }
	int get_hour () { return hour; }
	int get_minute () { return minute; }


	void add_days ( int days )
	{
		if ( days > 0 )
			for ( int i = 0; i < days; i = i + 1 )
				add_day();
		if ( days < 0 )
			for ( int i = 0; i < -days; i = i + 1 )
				substract_day();
	}

	void add_weeks ( int weeks )
	{
		add_days( weeks * 7 );
	}
	
	void add_hours ( int hours )
	{
		if ( hours > 0 )
			for ( int i = 0; i < hours; i = i + 1 )
				add_hour();
		if ( hours < 0 )
			for ( int i = 0; i < -hours; i = i + 1 )
				substract_hour();
	}
	
	void add_minutes ( int minutes )
	{
		if ( minutes > 0 )
			for ( int i = 0; i < minutes; i = i + 1 )
				add_minute();
		if ( minutes < 0 )
			for ( int i = 0; i < -minutes; i = i + 1 )
				substract_minute();
	}

	string get_weekday ()
	{
		string weekdays[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	}

	int compare ( Date_time d1, Date_time d2 )
	{
		if ( d1.year > d2.year )
			return 1;
		if ( d1.year < d2.year )
			return -1;

		if ( d1.month > d2.month )
			return 1;
		if ( d1.month < d2.month )
			return -1;

		if ( d1.day > d2.day )
			return 1;
		if ( d1.day < d2.day )
			return -1;

		if ( d1.hour > d2.hour )
			return 1;
		if ( d1.hour < d2.hour )
			return -1;

		if ( d1.minute > d2.minute )
			return 1;
		if ( d1.minute < d2.minute )
			return -1;

		return 0;
	}

	int minutes_between ( Date_time d1, Date_time d2 )
	{
		Date_time swap;
		swap.set_date_time( d1 );

		if ( compare( d1, d2 ) == -1 )
		{
			d1.set_date_time( d2 );
			d2.set_date_time( swap );
			swap.set_date_time( d1 );
		}

		int minutes = 0;
		while ( ! swap.equals( d2 ) )
		{
			swap.add_minutes( -1 );
			minutes = minutes + 1;
		}

		return minutes;
	}
	
	void info ()
	{
		string result = "";

		result = result + date_int_to_string( day );

		result = result + '/';

		result = result + date_int_to_string( month );

		result = result + '/';

		if ( year < 10 )
			result = result + "000";

		if ( year < 100 and year >= 10 )
			result = result + "00";

		if ( year < 1000 and year >= 100 )
			result = result + "0";

		result = result + date_int_to_string( year );

		result = result + ' ';

		result = result + date_int_to_string( hour );

		result = result + ':';

		result = result + date_int_to_string( minute );

		cout << result << '\n';
	}
};






int main ()
{
//	cout << "date ";

	Date_time date_time_1 = Date_time( 5, 11, 2010, 23, 56 );
	Date_time date_time_2 = Date_time( "5/11/2010 23:56" );
	date_time_1.info();
	date_time_1.add_minutes( 7 );
	date_time_1.info();
	date_time_1.add_minutes( -60 );
	date_time_1.info();
	date_time_1.add_days( 35 );
	date_time_1.info();
	date_time_1.add_days( -35 );
	date_time_1.info();
	cout << date_time_1.compare( date_time_1, date_time_2 ) << '\n';
	cout << date_time_1.minutes_between( date_time_1, date_time_2 ) << '\n';

	return 0;
}
