// OBJParser.cpp : Defines the exported functions for the DLL application.
//

#include "OBJParser.h"
#include "Parser.h"
#include "Scanner.h"
#include "Stream.h"
#include <iostream>
#include <fstream>
//#include <thread>

using namespace std;

Data::OBJData* parseData(string fileName, string outFile)
{
	ifstream ifile;
	ifile.open(fileName.c_str());
	ofstream ofile;
	ofile.open(outFile.c_str());
	Stream stream(ifile, ofile);
	Parser parser;
	Scanner scanner(stream,parser);
	Data::OBJData* data = NULL;
	try
	{
		//thread scan = thread(&Scanner::start,&scanner);
		//thread parse = thread(&Parser::parse,&parser);
		//scan.join();
		//parse.join();
		scanner.start();
                parser.parse();
		data = parser.getData();
	}
	catch (Token e)
	{
		stream.output("This token doesn't fit: " + e.output());
	}
	ifile.close();
	ofile.close();
	return data;
}
