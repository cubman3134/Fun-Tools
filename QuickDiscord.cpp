#include <iostream>
#include <stdio.h>
//#include <string.h>
#include <string>
//#include <fstream>
using namespace std;

void toClipboard(const string &s);

int main(int argc, char *argv[]){
	if(argc == 1) return -1;
    string returnString = "";
	//stream outfile("discordChat.txt");
	for(int i = 1; i < argc; i++){
		for(int j = 0; j < strlen(argv[i]); j++){
            if(argv[i][j] > 96 && argv[i][j] < 122) ? (returnStr += ":regional_indicator_" + argv[i][j] + ": ") : (returnStr = "Bad char");
            
            //outfile << ":regional_indicator_" << argv[i][j] << ": " : break;//outfile << endl << endl << "BAD_CHAR_LOWERCASE_ONLY" << endl << endl;
		}
        returnStr += "   ";
		//outfile << "   ";
	}
	//outfile << endl;
	//outfile.close();
    toClipboard(returnStr);
    cout << returnStr << endl;
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

