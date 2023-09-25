#pragma warning( disable : 4244 )
#include "Money.h"

#include <iostream>

using namespace std;

Money::Money() {
	_totalRubs = 0;
	_totalKopecks = 0;
}

Money::Money(Rubles rubs, Kopecks kopecks) {
	_totalRubs = rubs;
	_totalKopecks = kopecks;

	recountKopecks();
	kopecks = _totalKopecks;
	siftKopecks(kopecks);

	rubs = _totalRubs;
	siftRubles(rubs);
}

void Money::siftRubles(Rubles& rubs, bool clear) {
	int q = 8;
	for (auto r : { 5000, 1000, 500, 100, 50, 10, 5, 2, 1 }) {
		if (clear) _rubStore[RubleNominal(q)] = 0;
		_rubStore[RubleNominal(q--)] += (rubs / r);
		rubs %= r;
	}
}

void Money::siftKopecks(Kopecks& kopecks, bool clear) {
	int q = 3;
	for (auto k : { 50, 10, 5, 1 }) {
		if (clear) _kpcStore[KopeckNominal(q)] = 0;
		_kpcStore[KopeckNominal(q--)] += (kopecks / k);
		kopecks %= k;
	}
}

void Money::recountKopecks() {
	bool isNegative = _totalKopecks < 0;
	if (isNegative) _totalKopecks = -_totalKopecks;

	if (_totalKopecks >= 100) {
		_totalRubs = _totalRubs + (_totalKopecks / 100);

		_totalKopecks %= 100;
		if (isNegative) _totalKopecks = -_totalKopecks;
	}

	if (isNegative) {
		_totalRubs--;
		_totalKopecks = 100 - _totalKopecks;
	}
}

Rubles Money::GetRubles() {
	return _totalRubs;
}

void Money::SetRubles(Rubles rubs) {
	_totalRubs = rubs;
	siftRubles(rubs, true);
}

Rubles Money::GetKopecks() {
	return _totalKopecks;
}

void Money::SetKopecks(Kopecks kpcks) {
	_totalKopecks = kpcks;
	recountKopecks();
	kpcks = _totalKopecks;
	siftKopecks(kpcks, true);
}

Money Money::Multiply(Rubles rubs, Kopecks kops) {
	auto tm = Money(rubs, kops);
	return *this * tm;
}

Money Money::Division(Rubles rubs, Kopecks kops) {
	auto tm = Money(rubs, kops);
	return *this / tm;
}

std::string Money::ToString() {
	return std::to_string(_totalRubs) + "," + ((_totalKopecks <= 9) ? ("0" + std::to_string(_totalKopecks)) : std::to_string(_totalKopecks)) + " rub";
}

const Amount& Money::operator[](RubleNominal rn) const {
	if (_rubStore.find(rn) == _rubStore.end()) return 0;
	return _rubStore.at(rn);
}

const Amount& Money::operator[](KopeckNominal kp) const {
	if (_kpcStore.find(kp) == _kpcStore.end()) return 0;
	return _kpcStore.at(kp);
}

Money Money::operator+(Money& m) const {
	return Money(_totalRubs + m._totalRubs, _totalKopecks + m._totalKopecks);
}

Money Money::operator-(Money& m) const {
	return Money(_totalRubs - m._totalRubs, _totalKopecks - m._totalKopecks);
}

Money Money::operator/(Money& m) const {
	double rm = m._totalRubs + (m._totalKopecks / 100.0);

	if (rm == 0.0) {
		throw new exception("div by zero");
	}

	double r = (_totalRubs + (_totalKopecks / 100.0)) / rm;
	return Money(Rubles(r), (r - Rubles(r)) * 100);
}

Money Money::operator*(Money& m) const {
	return Money(_totalRubs * m._totalRubs + (_totalRubs * _totalKopecks) / 100, (_totalKopecks * m._totalKopecks) / 100 + m._totalRubs * _totalKopecks);
}

bool Money::operator==(Money& m) const {
	return (_totalRubs == m._totalRubs) && (_totalKopecks == m._totalKopecks);
}

bool Money::operator!=(Money& m) const {
	return !((_totalRubs == m._totalRubs) && (_totalKopecks == m._totalKopecks));
}
