#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp 
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 

////////////////////////////////////////////////////////////
class Date { 
public:
            Date() {};
			void setday(String s) { day = s; };				//Day Setter
			void setmonth(String s) { month = s; };			//Month Setter
			void setyear(int s) { year = s; };				//Year Setter
			String getday() const { return day; };			//Day Getter
			String getmonth() const { return month; };		//Month Getter
			int getyear() const { return year; };			//Year Getter
private:
    String  day, month;
    int     year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
            Time() {};
			void sethour(int i) { hour = i; };				//Hour Setter
			void setminute(int i) { minute = i; };			//Minute Setter
			void setsecond(int i) { second = i; };			//Second Setter
			int gethour() const { return hour; };			//Hour Getter
			int getminute() const { return minute; };		//Minute Getter
			int getsecond() const { return second; };		//Second Getter
  private:
    int     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
public:
            LogEntry() {};
            LogEntry(String);
			String gethost() const { return host;};
			int getbyte() const { return number_of_bytes;};
	friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);

#endif

