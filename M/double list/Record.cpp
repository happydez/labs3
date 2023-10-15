#include "Record.h"

#include <iostream>

using std::string;

Record::Record() {
	this->Catalog = this->Name = this->Extension = "";
	this->Day = this->Month = this->Year = 0;
	this->Size = 0;
}

Record::Record(string ctg, string name, string ext, int d, int m, int y, long s) {
	this->Catalog = ctg;
	this->Name = name;
	this->Extension = ext;
	this->Day = d;
	this->Month = m;
	this->Year = y;
	this->Size = s;
}

string Record::FullName() const {
	return "../" + this->Catalog + "/" + this->Name + "." + this->Extension;
}

 std::ostream& operator<<(std::ostream& out, const Record& r) {
	 out << r.FullName() << " | " << r.Year << "." << ((r.Month < 10) ? "0" : "") << r.Month << "." << ((r.Day < 10) ? "0" : "") << r.Day << " | " << r.Size << " байт";
	 return out;
 }
