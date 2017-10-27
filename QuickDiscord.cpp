/*
 * Parker Holt
 * 10/27/2017
 *
 * This program takes a string and converts it to discord emojis.
 */
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <string>
#include <sstream>
using namespace std;

void toClipboard(const string &s);

int main(int argc, char *argv[]){
	if(argc == 1) return -1;
	bool noBadChars = true;
	ostringstream os;
	string returnStr = "";
	for(int i = 1; i < argc; i++){
		for(int j = 0; j < strlen(argv[i]); j++){
			if(argv[i][j] > 96 && argv[i][j] < 123){
				os << ":regional_indicator_" << argv[i][j] << ": ";
			} else {
				os.str("");
				os << "bad char at " << i << " " << j << endl;
				noBadChars = false;
				break;
			}
		}
		if(!noBadChars) break;
		os << "   ";
	}
  toClipboard(os.str());
	return 0;
}

void toClipboard(const string &s){
    OpenClipboard(0);
    EmptyClipboard();
    HGLOBAL hg=GlobalAlloc(GMEM_MOVEABLE,s.size());
    if (!hg){
        CloseClipboard();
        return;
    }
    memcpy(GlobalLock(hg),s.c_str(),s.size());
    GlobalUnlock(hg);
    SetClipboardData(CF_TEXT,hg);
    CloseClipboard();
    GlobalFree(hg);
}
