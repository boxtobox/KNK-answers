// readline.h
#pragma once
/***************************************************************
  read_line: Skips leading whilte-space characters, then
             reads the remainder of the input line and
			 stores it in str. Truncates the line if its
			 length exceeds n. Returns the number of
			 characters stored.
***************************************************************/
int read_line(char str[], int n);
