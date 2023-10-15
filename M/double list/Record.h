#pragma once

#include <string>
#include <ostream>

using std::string;

class Record {
	public:
		string Catalog;
		string Name;
		string Extension;
		int Day;
		int Month;
		int Year;
		long Size;

		Record();
		Record(string ctg, string name, string ext, int d, int m, int y, long s);

		string FullName() const;

		friend std::ostream& operator<<(std::ostream& out, const Record& r);
};

