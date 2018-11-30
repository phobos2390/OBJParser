// OBJParser.cpp : Defines the exported functions for the DLL application.
//

#include "OBJParser.h"
#include "Parser.h"
#include "Scanner.h"
#include "Stream.h"
#include <iostream>
#include <fstream>

using namespace std;

OBJData parseData(string fileName, string outFile)
{
	ifstream ifile;
	ifile.open(fileName);
	ofstream ofile;
	ofile.open(outFile);
	Stream stream(ifile, ofile);
	Scanner scanner(stream);
	OBJData data;
	try
	{
		scanner.start();
		Parser parser(scanner.getTokens().begin());
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