#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void interpret(std::string input)
{
	unsigned char tape[30000] = {0};
	unsigned char *ptr = tape;

	for (int i = 0; i <= input.length(); i++) {
		char c = input[i];
		if(c == '+') {
			++*ptr;
		} else if (c == '-') {
			--*ptr;
		} else if (c == '>') {
			++ptr;
		} else if (c == '<') {
			--ptr;
		} else if (c == '.') {
			std::putchar(*ptr);
		} else if (c == ',') {
			*ptr=getchar();
		} else if (c == '[') {
			if(*ptr == 0)
			{
				while (c != ']') {
					i++;
					c = input[i];
				}
				i--;
			}
		} else if (c == ']') {
			if(*ptr != 0)
			{
				while (c != '[') {
					i--;
					c = input[i];
				}
				i--;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	std::ifstream inputFile;
	inputFile.open(argv[1]);
	std::string input((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>()));

	interpret(input);
	return 0;
}
