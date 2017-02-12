// MathLibrary.cpp : Defines the exported functions for the DLL application.  
// Compile by using: cl /EHsc /DMATHLIBRARY_EXPORTS /LD MathLibrary.cpp  

#include "stdafx.h"  
#include "MathLibrary.h"  

#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Priority.hh"
#include "log4cpp/PatternLayout.hh"

namespace MathLibrary
{
	double Functions::Add(double a, double b)
	{
		log4cpp::Category::getRoot().info("Dll Add");

		return a + b;
	}

	double Functions::Multiply(double a, double b)
	{
		return a * b;
	}

	double Functions::AddMultiply(double a, double b)
	{
		return a + (a * b);
	}
}