#pragma once

#include <ostream>

using std::ostream;

// Proportion Object
//
//	The proportion object is designed to manage a single proportion (Define Proportion: A Part,
//	share, or number consider in comparative relation to a whole.) The 'whole' in this context
//	is max_ and the 'the share' is current_.
//
//	Proportion Rules:
//		1. current_ cannot be the greater then max_.
//			1.1 IF ( current_ + X ) > max_ THEN current_ = max_.
//		
//		2. current_ cannot be less then 0.
//			2.1 IF ( current_ - X) < 0 THEN current_ = 0;
//
//		3. max_ cannot be less then current.

class Proportion
{
private:
	double max_;
	double current_;
	double EnforceProportion(double newValue);

public:
	//Ctors
	Proportion();
	Proportion(double currentValue, double MaxValue);

	//Accessors / Inspectors / Getters
	double Max() const { return max_; }
	double Current() const { return current_; }

	//Mutators / Setters
	void Max(double);
	void Current(double);
	void Set(double currentValue, double MaxValue);

	// Operator Overloads
	// Addition
	const Proportion operator+(const int otherValue) const;
	const Proportion operator+(const float otherValue) const;
	const Proportion operator+(const Proportion &otherValue) const;
	const Proportion operator+(const double otherValue) const;
	// Subtraction
	const Proportion operator-(const int otherValue) const;
	const Proportion operator-(const float otherValue) const;
	const Proportion operator-(const Proportion &otherValue) const;
	const Proportion operator-(const double otherValue) const;
	// Multiplication
	const Proportion operator*(const int otherValue) const;
	const Proportion operator*(const float otherValue) const;
	const Proportion operator*(const Proportion &otherValue) const;
	const Proportion operator*(const double otherValue) const;
	// Division
	const Proportion operator/(const int otherValue) const;
	const Proportion operator/(const float otherValue) const;
	const Proportion operator/(const Proportion &otherValue) const;
	const Proportion operator/(const double otherValue) const;
// (Pre & Post) Increment & Decrement Operators
	Proportion operator++(int);
	Proportion& operator++();
	Proportion operator--(int);
	Proportion& operator--();

// Compound Addition Assignment
	Proportion& operator+=(const int otherValue);
	Proportion& operator+=(const float otherValue);
	Proportion& operator+=(const Proportion &otherValue);
	Proportion& operator+=(const double otherValue);
// Compound Subtraction Assignment
	Proportion& operator-=(const int otherValue);
	Proportion& operator-=(const float otherValue);
	Proportion& operator-=(const Proportion &otherValue);
	Proportion& operator-=(const double otherValue);
// Compound Multiplication Assignment
	Proportion& operator*=(const int otherValue);
	Proportion& operator*=(const float otherValue);
	Proportion& operator*=(const Proportion &otherValue);
	Proportion& operator*=(const double otherValue);
// Compound Division Assignment
	Proportion& operator/=(const int otherValue);
	Proportion& operator/=(const float otherValue);
	Proportion& operator/=(const Proportion &otherValue);
	Proportion& operator/=(const double otherValue);
// Relational Operators: EQUAL TO, NOT EQUAL TO, GREATER THAN, LESS THAN, GREATER THAN OR EQUAL TO & LESS THAN OR EQUAL TO
	bool operator==(const Proportion &valueToCompare) const;
	bool operator!=(const Proportion &valueToCompare) const;
	bool operator>(const Proportion &valueToCompare) const;
	bool operator<(const Proportion &valueToCompare) const;
	bool operator>=(const Proportion &valueToCompare) const;
	bool operator<=(const Proportion &valueToCompare) const;
//	Output Stream Operator
	friend ostream& operator<<(ostream &output, const Proportion &P);

};