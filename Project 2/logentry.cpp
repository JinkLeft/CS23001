//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
LogEntry::LogEntry(String s) {
   std::vector<String> vec = s.split(' ');
   if(vec.size() == 10)
   {
		host = vec[0];
		
		std::vector<String> dateTime = vec[3].split(':');
		std::vector<String> dateString = dateTime[0].split('/');
		
		String newDay = dateString[0].substr(1, dateString[0].length() - 1);
		
		date.setday(newDay);
        date.setmonth(dateString[1]);
        date.setyear(dateString[2].toInt());
        
        time.sethour(dateTime[1].toInt());
        time.setminute(dateTime[2].toInt());
        time.setsecond(dateTime[3].toInt());
		
		request = vec[5] + vec[6] + " " + vec[7];
		status = vec[8];
		
		if (vec[9] == '-') {
            number_of_bytes = 0;
        }
		else 
		{
			number_of_bytes = vec[9].toInt();

		}
   }
   else
   {
		host = "";
        date.setday("");
        date.setmonth("");
        date.setyear(0);
        time.sethour(0);
        time.setminute(0);
        time.setsecond(0);
        request = "";
        status = "";
        number_of_bytes = 0; 
   }
	
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::ostream& operator<<(std::ostream& out, const LogEntry& log)
{
	out << "\nHost: " << log.host;

	out << "\nDay: " << log.date.getday();
	out << "\nMonth: " << log.date.getmonth();
	out << "\nYear: " << log.date.getyear();

	out << "\nHour: " << log.time.gethour();
	out << "\nMinute: " << log.time.getminute();
	out << "\nSecond: " << log.time.getsecond();

	out << "\nRequest: " << log.request;
	out << "\nStatus: " << log.status;
	out << "\nBytes: " << log.number_of_bytes << std::endl;

	return out;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
	String tmp;
	
	while (!in.eof())
	{
		char c;
		if(in.get(c))
		{
			if(c != '\n')
			{
				String ca(c);
				tmp += c;
			}
			else
			{
				String reset;
				LogEntry log(tmp);
				result.push_back(log);
				tmp = reset;
			}
		}

	}
	
    return result;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry> & veclogs) {
    for (unsigned int i = 0; i < veclogs.size(); ++i) {
        out << veclogs[i];
    }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>& veclogs) {
	for (unsigned int i = 0; i < veclogs.size(); ++i) {
        out << veclogs[i].gethost() << '\n';
    }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int byte_count(const std::vector<LogEntry> & veclogs) {
	int sum = 0;

	for (unsigned int i = 0; i < veclogs.size(); ++i) {
		sum += veclogs[i].getbyte();
	}

	return sum;
}

