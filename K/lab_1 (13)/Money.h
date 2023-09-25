#pragma once

#include <map>
#include <string>

typedef int Amount;
typedef long long Rubles;
typedef long long Kopecks;;

enum class RubleNominal : int {
	R1,
	R2,
	R5,
	R10,
	R50,
	R100,
	R500,
	R1000,
	R5000,
};

enum class KopeckNominal : int {
	K1,
	K5,
	K10,
	K50,
};

class Money {
	private:
		std::map<RubleNominal, Amount> _rubStore;
		std::map<KopeckNominal, Amount> _kpcStore;

		Rubles _totalRubs = 0;
		Kopecks _totalKopecks = 0;

		void recountKopecks();
		void siftRubles(Rubles& rubs, bool clear = false);
		void siftKopecks(Kopecks& kopecs, bool clear = false);

	public:
		Money();
		Money(Rubles rubs, Kopecks kopecks = 0);

		Rubles GetRubles();
		void SetRubles(Rubles rubs);

		Kopecks GetKopecks();
		void SetKopecks(Kopecks kpcks);

		Money Multiply(Rubles rubs, Kopecks kops);
		Money Division(Rubles rubs, Kopecks kops);

		std::string ToString();

		Money operator+(Money& m) const;
		Money operator-(Money& m) const;
		Money operator/(Money& m) const;
		Money operator*(Money& m) const;

		const Amount& operator[](RubleNominal) const;
		const Amount& operator[](KopeckNominal) const;

		bool operator==(Money& m) const;
		bool operator!=(Money& m) const;
};
