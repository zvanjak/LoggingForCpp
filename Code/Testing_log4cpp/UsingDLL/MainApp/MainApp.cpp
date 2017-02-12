// MainApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



#include <ostream>
#include <iostream>
#include "../MyAppDll/MathLibrary.h"


#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Priority.hh"
#include "log4cpp/PatternLayout.hh"

using namespace std;

int main()
{
	log4cpp::Category&		_rootLogger = log4cpp::Category::getRoot();

	log4cpp::PatternLayout* layout = new log4cpp::PatternLayout();
	layout->setConversionPattern("%d [%5t] %-6p %c - %m%n");

	log4cpp::Appender *appender2 = new log4cpp::FileAppender("default", "cVF.log");
	appender2->setLayout(layout);
	appender2->setThreshold(log4cpp::Priority::INFO);

	log4cpp::Appender *appender3 = new log4cpp::FileAppender("detailed", "cVF_Detailed.log");
	appender3->setLayout(layout);
	appender3->setThreshold(700);			// hardcode value for DEBUG

	_rootLogger.setPriority(700);
	_rootLogger.addAppender(appender2);
	_rootLogger.addAppender(appender3);

	double a = 7.4;
	int b = 99;

	log4cpp::Category::getRoot().info("Main Add");
	cout << "a + b = " << MathLibrary::Functions::Add(a, b) << endl;

	log4cpp::Category::getRoot().info("Main Mul");
	cout << "a * b = " << MathLibrary::Functions::Multiply(a, b) << endl;

	log4cpp::Category::getRoot().info("Main AddMul");
	cout << "a + (a * b) = " << MathLibrary::Functions::AddMultiply(a, b) << endl;

	return 0;
}