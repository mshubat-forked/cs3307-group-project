#include <iostream>
#include <string>
using namespace std;

string dateTrim(string str){
	size_t found = str.find("/");
	if (found == 4 || found == -1) {
		//year is the first 4 characters
		return str.substr(0, 4);
	}else{
		size_t found2 = str.find("/", found+1);
		if (found2 != -1 ) {
			//year is behind months
			return str.substr(found2+1, 4);
		}else{
			//year is the last 4 characters
			return str.substr(found+1, 4);
		}
	} cout << endl;
}
