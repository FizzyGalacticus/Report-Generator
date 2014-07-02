#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <algorithm>
using std::sort;

#include <ctime>
using std::time_t;
using std::time;
using std::localtime;

#include <stdlib.h>

#if defined _WIN32 || defined _WIN64 || defined __WINDOWS__
	void openLog() {system("start notepad log.txt");}
#elif defined macintosh || defined Macintosh || defined __APPLE__ && __MACH__
	void openLog() {system("open -t log.txt");}
#elif defined __GNU__ || defined __gnu_linux__ || defined __linux__ || defined linux || defined __linux__
	void openLog() {system("open -t log.txt");}
#endif

/****************GET DATE AND TIME*****************/
tm * getTimeAndDateInfo()
{
	time_t rawtime;
	struct tm * timeinfo;
	
	time (&rawtime);
	timeinfo = localtime(&rawtime);
	
	return timeinfo;
}

const string getDate()
{
	char buffer[80];
	strftime(buffer,80,"%m/%d/%Y",getTimeAndDateInfo());
	
	return string(buffer);
}

const string getTime()
{
	char buffer[80];
	strftime(buffer,80,"%I:%M %p",getTimeAndDateInfo());
	
	return string(buffer);
}

/************CHECK DATE******************/
void writeNewDate(const string & today)
{
	ofstream out;
	
	out.open("lastdate", std::ios::out);
	if(out)
	{
		out << today;
		out.close();
	}
	else cout << "Could not open \"lastdate\" for writing!" << endl;
}

const bool dayHasChanged(const string & today)
{
	ifstream in;
	
	in.open("lastdate", std::ios::in);
	if(in)
	{
		string tempDate;
		getline(in, tempDate);
		in.close();
		
		if(tempDate != today)
		{
			writeNewDate(today);
			return true;
		}
		else return false;
	}
	
	writeNewDate(today);
	return true;
}

/**************CHECKOUT******************/

const string checkout()
{
	string retStr, _input;
	
	cout << "Did you just checkout this system? (Y/N) ";
	getline(cin, _input);
	
	if(_input == "N" || _input == "n") return "";
	
	retStr += "Pulled system from shelf.\n";
	
	return retStr;
}

/*				VIRUS REMOVAL			*/
const string runMalwareScans()
{
	string _malwareBytes, _avast, retStr = "";
	
	cout << "How many objects did you remove with MalwareBytes?" << endl;
	getline(cin, _malwareBytes);
	
	cout << "How many objects did you remove with Avast?" << endl;
	getline(cin, _avast);
	
	if(_malwareBytes != "-1")
		retStr += ("Ran scans with MalwareBytes and removed " + _malwareBytes + " found infected object(s).\n");
	if(_avast != "-1")
		retStr += ("Ran a boot-time scan with Avast and removed " + _avast + " found infected object(s).\n");
	
	return retStr;
}

const string removeBadPrograms()
{
	string _badPrograms = "", temps;
	int tempi;
	vector<string> removedPrograms;
	
	do{
		temps = "";
		cout << "Please enter all programs that you have removed: ";
		getline(cin, temps);
		if(temps.size()) removedPrograms.push_back(temps);
	}while(temps.size());
	
	sort(removedPrograms.begin(), removedPrograms.end());
	
	if(removedPrograms.size())
	{
		_badPrograms += "Removed the following program(s): ";
		for(int i = 0; i < removedPrograms.size(); i++)
		{
			if(i == removedPrograms.size()-1 && removedPrograms.size() != 1) _badPrograms += ("and " + removedPrograms[i] + ".\n");
			else if(removedPrograms.size() == 1) _badPrograms += removedPrograms[0];
			else _badPrograms += removedPrograms[i] + ", ";
		}
	}
	
	return _badPrograms;
}

const string cleanup()
{
	string retStr = "", _input;
	
	cout << "Did you reset IE/Chrome/FireFox/Safari settings? (Y/N) ";
	getline(cin, _input);
	
	if(_input == "Y" || _input == "y") retStr += "Reset all web browser settings to default and disabled all add-on/extensions.\n";
	
	cout << "Did you delete old restore points? (Y/N) ";
	getline(cin, _input);
	
	if(_input == "Y" || _input == "y") retStr += "Deleted old restore points and created a new 'CWI' restore point.\n";
	
	return retStr;
}

const string virusRemoval()
{
	string _input;
	
	cout << "Did you run virus scan + removal? (Y/N) ";
	getline(cin , _input);
	
	if(_input == "N" || _input == "n") return "";
	
	return (cleanup() + removeBadPrograms() + runMalwareScans());
}

/*************SYSTEM FILE CHECKER******************/
const string sfc()
{
	string _sfc, _input;
	
	cout << "Did you run System File Checker? (Y/N) ";
	getline(cin , _input);
	
	if(_input == "N" || _input == "n") return "";
	else{
		cout << "What was the status? ";
		getline(cin, _input);
		
		_sfc = "Ran System File Checker -- ";
		_sfc += _input;
		_sfc += ".\n";
	}
	
	return _sfc;
}

/*************HDD SURFACE SCAN******************/
const string hddScan()
{
	string _hdd, _input;
	
	cout << "Did you run a Hard Drive Surface Scan? (Y/N) ";
	getline(cin , _input);
	
	if(_input == "N" || _input == "n") return "";
	else{
		cout << "What was the status? ";
		getline(cin, _input);
		
		_hdd = "Ran a surface scan on HDD -- ";
		_hdd += _input;
		_hdd += ".\n";
	}
	
	return _hdd;
}

/*****************INSTALLS/UPDATES*****************/

const string installGoodPrograms()
{
	string _goodPrograms = "", temps, _input;
	bool win8 = false, antivirus = false;
	char tempc;
	
	cout << "Did you install/update any core programs? (Y/N) ";
	getline(cin, _input);
	
	if(_input != "N" && _input != "n")
	{
		cout << "Is the machine running Windows 8? (Y/N): ";
		cin >> tempc;
		cin.ignore(80, '\n');
		if(tempc == 'y' || tempc == 'Y') win8 = true;
		
		cout << "Did you install Anti-Virus? (Y/N): ";
		cin >> tempc;
		cin.ignore(80, '\n');
		if(tempc == 'y' || tempc == 'Y') antivirus = true;
		
		_goodPrograms += "Installed/updated the following program(s): ";
		
		if(!win8) _goodPrograms += "Adobe Flash Player, ";
		_goodPrograms += "Adobe Shockwave, Adobe Reader, Java, Microsoft Silverlight, CCleaner";
		if(win8) _goodPrograms += ", Classic Shell";
		
		if(antivirus) _goodPrograms += ", Malwarebytes' Anti-Malware, and Avast! Free Anti-Virus.\n";
		else _goodPrograms += ", and Malwarebytes' Anti-Malware.\n";
	}
	
	cout << "Did you install Windows updates? (Y/N) ";
	getline(cin, _input);
	
	if(_input != "N" && _input != "n") _goodPrograms += "Installed latest Windows updates from Microsoft.\n";
	
	return _goodPrograms;
}

/***************RUN EVERYTHING*********************/
const string runEverything()
{
	string retStr;
	
	retStr += virusRemoval();
	retStr += sfc();
	retStr += hddScan();
	retStr += installGoodPrograms();
	
	return retStr;
}

int main(const int argc, const char * argv[])
{
	ofstream out;
	string _checkout = checkout(), _date = getDate(), _time = getTime();;
	
	out.open("log.txt", std::ios::out);
	if(out)
	{
		if(_checkout.size()) out << "DLD - " << _date << " " << _time << " - " << _checkout;
		else
		{
			if(dayHasChanged(_date) && !_checkout.size()) out << "DLD - " << _date << " ";
			out << _time << " - ";
		}
		out << runEverything();
		out.close();
		cout << "Output has been sent to log.txt!" << endl;
	}
	else cout << "Could not open log.txt for writing!" << endl;
	
	openLog();
	
	return 0;
}