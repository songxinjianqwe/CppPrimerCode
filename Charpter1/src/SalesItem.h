#ifndef SALESITEM_H  
#define SALESITEM_H  
#include <iostream>  
#include <string>  

class SalesItem {
public:
	SalesItem(const std::string &book) :
			isbn(book), units_sold(0), revenue(0.0) {
	}
	SalesItem(std::istream &is) {
		is >> *this;
	}
	friend std::istream& operator >>(std::istream &, SalesItem &);
	friend std::ostream& operator<<(std::ostream &, const SalesItem &);
public:
	SalesItem & operator+=(const SalesItem&);
public:
	double avg_price() const;
	bool same_isbn(const SalesItem &rhs) const {
		return isbn == rhs.isbn;
	}
	SalesItem() :
			units_sold(0), revenue(0.0) {
	}
public:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};

using std::istream;
using std::ostream;
SalesItem operator+(const SalesItem &, const SalesItem &);
inline bool operator==(const SalesItem &lhs, const SalesItem &rhs) {
	return lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue
			&& lhs.same_isbn(rhs);
}
inline bool operator!=(const SalesItem &lhs, const SalesItem &rhs) {
	return !(lhs == rhs);
}

inline SalesItem & SalesItem::operator +=(const SalesItem &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
inline SalesItem operator+(const SalesItem &lhs, const SalesItem &rhs) {
	SalesItem ret(lhs);
	ret += rhs;
	return ret;
}
inline istream& operator >>(istream &in, SalesItem &s) {
	double price;
	in >> s.isbn >> s.units_sold >> price;
	if (in)
		s.revenue = s.units_sold * price;
	else
		s = SalesItem();
	return in;
}
inline ostream& operator<<(ostream &out, const SalesItem &s) {
	out << s.isbn << "\t" << s.units_sold << "\t" << s.revenue << "\t"
			<< s.avg_price();
	return out;
}
inline double SalesItem::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
#endif
