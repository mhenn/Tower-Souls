#pragma once
#include <iostream>
#include "windows.h"
namespace Utils {
	static void multEndl(int i) {
		while (i-- > 0)
			std::cout << std::endl;
	}

	static void printIt(int centre, std::string text) {

		int t = centre + (text.size() / 2);
		char *cText = &text[0u];
		std::printf("%*s\n", t, cText);
	}

	static void printWithBreaks(int rowBreak, int centre, std::string text) {
		std::string tmp = text;
		while (rowBreak >= 0) {
			std::string out = tmp.substr(0, rowBreak);
			tmp = tmp.substr(rowBreak +1);
			if (out.size() > 0) {
				printIt(centre, out);
			}
			else
				std::cout << std::endl;
			rowBreak = tmp.find("\n");
		}
		printIt(centre, tmp);
	}


	static int getScreenWidth() {
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		return csbi.srWindow.Right - csbi.srWindow.Left + 1;
	}

	static void printCentered(std::string text) {		
		int screenWidth = getScreenWidth();
		int centre = screenWidth / 2;
		bool doIt = true;
		std::string output;
		std::string tmp = text;
		while (doIt) {
			if (tmp.size() > 100) {
				int end = tmp.find(" ", 100);
				output = tmp.substr(0, end);
				tmp = tmp.substr(end);
				int rowBreak = output.find("\n");
				if (rowBreak >= 0)
					printWithBreaks(rowBreak, centre, output);				
				else {					
					printIt(centre, output);
				}
			}
			else {
				char *cText = &tmp[0u];
				std::printf("%*s\n", (centre + (tmp.size() / 2)), cText);
				doIt = false;
			}
		}
	}

	static void printSingleCentered(std::string text) {
		int screenWidth = getScreenWidth();
		int center = screenWidth / 2;
		char *cText = &text[0u];
		std::printf("%*s\n", (center + text.size()), cText);
	}
}