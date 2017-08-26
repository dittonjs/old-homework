#ifndef TERM_H
#define TERM_H
#include <string>
#include <sstream>
#include <iomanip>
using  namespace std;

class Term
{
public:
	long int wt;
	string word;
	Term(string t = "no word", long int w = 0)
	{
		word = t;
		wt = w;
	}
	string toString() {
		stringstream ss;
		ss << "Wt:" << wt << " WORD: " << word;
		return ss.str();
	}
	bool operator<(Term & t2) { return wt < t2.wt; }

};
#endif // !TERM_H
