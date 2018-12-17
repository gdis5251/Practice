#define _CRT_SECURE_NO_WARNINGS 1

#include "switch.h"

int hexToBin(char *hex, char *bin)
{
	int i_ = 0;
	int j_ = 0;
	int n_ = strlen(hex);

	for (i_ = 0; i_ < n_; i_++)
	{
		switch (hex[i_])
		{
		case '0':
			bin[j_++] = '0';
			bin[j_++] = '0';
			bin[j_++] = '0';
			bin[j_++] = '0';

			break;
		case '1':
			bin[j_++] = '0';
			bin[j_++] = '0';
			bin[j_++] = '0';
			bin[j_++] = '1';

			break;
		case '2':
			bin[j_++] = '0';
			bin[j_++] = '0';
			bin[j_++] = '1';
			bin[j_++] = '0';

			break;
		case '3':
			bin[j_++] = '0';
			bin[j_++] = '0';
			bin[j_++] = '1';
			bin[j_++] = '1';

			break;
		case '4':
			bin[j_++] = '0';
			bin[j_++] = '1';
			bin[j_++] = '0';
			bin[j_++] = '0';

			break;
		case '5':
			bin[j_++] = '0';
			bin[j_++] = '1';
			bin[j_++] = '0';
			bin[j_++] = '1';

			break;
		case '6':
			bin[j_++] = '0';
			bin[j_++] = '1';
			bin[j_++] = '1';
			bin[j_++] = '0';

			break;
		case '7':
			bin[j_++] = '0';
			bin[j_++] = '1';
			bin[j_++] = '1';
			bin[j_++] = '1';

			break;
		case '8':
			bin[j_++] = '1';
			bin[j_++] = '0';
			bin[j_++] = '0';
			bin[j_++] = '0';

			break;
		case '9':
			bin[j_++] = '1';
			bin[j_++] = '0';
			bin[j_++] = '0';
			bin[j_++] = '1';

			break;
		case 'A':
			bin[j_++] = '1';
			bin[j_++] = '0';
			bin[j_++] = '1';
			bin[j_++] = '0';

			break;
		case 'B':
			bin[j_++] = '1';
			bin[j_++] = '0';
			bin[j_++] = '1';
			bin[j_++] = '1';

			break;
		case 'C':
			bin[j_++] = '1';
			bin[j_++] = '1';
			bin[j_++] = '0';
			bin[j_++] = '0';

			break;
		case 'D':
			bin[j_++] = '1';
			bin[j_++] = '1';
			bin[j_++] = '0';
			bin[j_++] = '1';

			break;
		case 'E':
			bin[j_++] = '1';
			bin[j_++] = '1';
			bin[j_++] = '1';
			bin[j_++] = '0';

			break;
		case 'F':
			bin[j_++] = '1';
			bin[j_++] = '1';
			bin[j_++] = '1';
			bin[j_++] = '1';

			break;
		default:
			break;
		}

		
	}

	return strlen(hex) * 4;
}





int binToOct(char *bin, char *oct, int bl)
{
	int i_ = 0;
	int j_ = bl - 1;
	int n_ = 0;

	if (0 == bl % 3)
	{
	
		n_ = bl / 3;
		for (i_ = 0; i_ < n_; i_++)
		{
			oct[i_] = bin[j_] - 48 + (bin[j_ - 1] - 48) * 2 + (bin[j_ - 2] - 48) * 4 + 48;
		}
	}

	else
	{
		n_ = bl / 3 + 1;

		for (i_ = 0; i_ < n_; i_++)
		{

		}
	}
}