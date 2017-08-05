#include "Proportion.h"

//Constructors
Proportion::Proportion() :max_(1), current_(max_) {}
Proportion::Proportion(double currentValue, double MaxValue) : current_(currentValue), max_(MaxValue) {}

//Mutators/Setters
void Proportion::Max(double newValue)
{
	//Enfornces the proportion by not allowing
	//the max_ to be les than current_.
	if(newValue >= current_)
	{
		max_ = newValue;
	}
}

void Proportion::Current(double newValue)
{
	//Enforces the proportion by not allowing
	//the current_ to be greater than
	//max_ or Less than 0.
	current_ = EnforceProportion(newValue);
}

void Proportion::Set(double currentValue, double MaxValue)
{
	//Since max_ must always be GREATHER THEN current_
	//and current_ must always be LESSER OR EQUAL to max_;
	//setMax(float newValue) must be called before
	//setCurrent(float newValue).

	Max(MaxValue);
	Current(currentValue);
}

//Utility function which is used to enforce the rules of the Proportion
//objects (See Proportion.h). This is accomplished by calling this function
//anytime an attempt is mode to modify current_.(See Operator OverLoads)
//
//The return value is used set/mutate current_.
double Proportion::EnforceProportion(double  newValue)
{
	if(newValue > max_)	//Rule 1
	{
		//Enforce Rule 1.1
		return max_;
	}
	else if(newValue < 0) //Rule 2
	{
		//Enforce Rule 2.1
		return 0.0f;
	}
	else //No Rules Have Been Broken
	{
		return newValue;
	}
}

//Operator Overloads

//Pre-Increment Operator Overload(e.g. ++i)
Proportion& Proportion::operator++()
{
	//If current_ is LESS THAN the max_
	if(current_ < max_)
	{
		++current_;
	}

	return *this;	//Otherwise do nothing
}

//Post-Increment Operator Overload(e.g. i++)
Proportion Proportion::operator++(int)
{
	Proportion oldState(current_, max_);

	//If current_ is LESS THAN the max_
	if(current_ < max_)
	{
		++current_;
	}

	return oldState;  //Otherwise do nothing
}

//Pre-Decrement Operator Overload(e.g. i--)
Proportion& Proportion::operator--()
{
	Proportion oldState(current_, max_);
	//If our number is LESS THAN OR EQUAL to max_
	// AND current_ is GREATER THAN -1.
	if(current_ <= max_ && current_ > 0)
	{
		--current_;
	}

	//Otherwise do nothing
	return oldState;
}

//Pre-Decrement Operator Overload(e.g. i--)
Proportion Proportion::operator--(int)
{
	Proportion oldState(current_, max_);

	//If our number is LESS THAN OR EQUAL to max_
	// AND current_ is GREATER THAN -1.
	if(current_ <= max_ && current_ > 0)
	{
		--current_;
	}

	//Otherwise do nothing
	return oldState;
}

//Compound Addition Assignment Operator Overload | (Proportion += Integer)
Proportion& Proportion::operator+=(const int newValue)
{
	const double finalNewValue = (current_ + static_cast<double>(newValue));
	current_ = EnforceProportion(finalNewValue);

	return *this;	//Return a reference to this object
}

//Compound Addition Assignment Operator Overload | (Proportion += Integer)
Proportion& Proportion::operator+=(const float newValue)
{
	const double finalNewValue = (current_ + newValue);
	current_ = EnforceProportion(finalNewValue);

	return *this;	//Return a reference to this object
}

//Compound Addition Assignment Operator Overload | (Proportion += Proportion)
Proportion& Proportion::operator+=(const Proportion& newValue)
{
	const double finalNewValue = (current_ + newValue.Current());
	current_ = EnforceProportion(finalNewValue);

	return *this;	//Return a reference to this object
}

Proportion& Proportion::operator+=(const double otherValue)
{
	const double finalNewValue = (current_ + otherValue);
	current_ = EnforceProportion(finalNewValue);

	return *this;
}

//Compound Subtraction Assignment Operator Overload | (Proportion -= Integer)
Proportion& Proportion::operator-=(const int newValue)
{
	const double finalNewValue = (current_ - static_cast<double>(newValue));
	current_ = EnforceProportion(finalNewValue);

	return *this;	//Return a reference to this object
}

//Compound Subtraction Assignment Operator Overload | (Proportion -= Integer)
Proportion& Proportion::operator-=(const float newValue)
{
	const double finalNewValue = (current_ - newValue);
	current_ = EnforceProportion(finalNewValue);

	return *this;	//Return a reference to this object
}

//Compound Subtraction Assignment Operator Overload | (Proportion -= Integer)
Proportion& Proportion::operator-=(const Proportion& newValue)
{
	const double finalNewValue = (current_ - newValue.Current());
	current_ = EnforceProportion(finalNewValue);

	return *this;	//Return a reference to this object
}

Proportion& Proportion::operator-=(const double otherValue)
{
	const double finalNewValue = (current_ - otherValue);
	current_ = EnforceProportion(finalNewValue);

	return *this;
}


//Compound Multiplication Assignment Operator Overload | (Proportion *= Integer)
Proportion& Proportion::operator*=(const int newValue)
{
	const double finalNewValue = (current_ * static_cast<double>(newValue));
	current_ = EnforceProportion(finalNewValue);

	return *this;	//Return a reference to this object
}

//Compound Multiplication Assignment Operator Overload | (Proportion *= Integer)
Proportion& Proportion::operator*=(const float newValue)
{
	const double finalNewValue = (current_ * newValue);
	current_ = EnforceProportion(finalNewValue);

	return *this;	//Return a reference to this object
}

//Compound Multiplication Assignment Operator Overload | (Proportion *= Integer)
Proportion& Proportion::operator*=(const Proportion& newValue)
{
	const double finalNewValue = (current_ * newValue.Current());
	current_ = EnforceProportion(finalNewValue);

	return *this;	//Return a reference to this object
}

Proportion& Proportion::operator*=(const double otherValue)
{
	const double finalNewValue = (current_ * otherValue);
	current_ = EnforceProportion(finalNewValue);

	return *this;
}


//Compound Divisin Assignment Operator Overload | (Proportion /= Integer)
Proportion& Proportion::operator/=(const int newValue)
{
	const double finalNewValue = (current_ / static_cast<double>(newValue));
	current_ = EnforceProportion(finalNewValue);

	return *this; //Return a reference to this object
}

//Compound Division Assignment Operator Overload | [Proportion += Integer]
Proportion& Proportion::operator/=(const float newValue)
{
	const double finalNewValue = (current_ / newValue);
	current_ = EnforceProportion(finalNewValue);

	return *this; //Return a reference to this object
}

//Compound Division Assignment Operator Overload | [Proportion += Proportion]
Proportion& Proportion::operator/=(const Proportion& newValue)
{
	const double finalNewValue = (current_ / newValue.Current());
	current_ = EnforceProportion(finalNewValue);

	return *this; //Return a reference to this object
}

Proportion& Proportion::operator/=(const double otherValue)
{
	const double finalNewValue = (current_ / otherValue);
	current_ = EnforceProportion(finalNewValue);

	return *this;
}


// Binary Addition Operator Overloads | [Proportion + int || float || Proportion]
// 
//The below overloads utilizes the implementation for compound addition [+=]
//to accomplish the addition operation.
const Proportion Proportion::operator+(const int otherValue) const
{
	return Proportion(*this)+= otherValue;
}

const Proportion Proportion::operator+(const float otherValue) const
{
	return Proportion(*this)+= otherValue;
}

const Proportion Proportion::operator+(const Proportion &otherValue) const
{
	return Proportion(*this) += otherValue.Current();
}

const Proportion Proportion::operator+(const double otherValue) const
{
	return Proportion(*this) += otherValue;
}
//Subtraction Operator Overloads | [Proportion - int || float || Proportion]
// 
//The below overloads utilizes the implementation for compound subtraction [-=]
//to accomplish the subtraction operation.
const Proportion Proportion::operator-(const int otherValue) const
{
	return Proportion(*this) -= otherValue;
}

const Proportion Proportion::operator-(const float otherValue) const
{
	return Proportion(*this)-= otherValue;
}

const Proportion Proportion::operator-(const Proportion &otherValue) const
{
	return Proportion(*this) -= otherValue.Current();
}

const Proportion Proportion::operator-(const double otherValue) const
{
	return Proportion(*this) -= otherValue;
}

// Multiplication Operator Overloads | [Proportion * int || float || Proportion]
//
//The below overloads utilizes the implementation for compound multiplication [*=]
//to accomplish the multiplication operation
const Proportion Proportion::operator*(const int otherValue) const
{
	return Proportion(*this)*=otherValue;
}
const Proportion Proportion::operator*(const float otherValue) const
{
	return Proportion(*this)*=otherValue;
}
const Proportion Proportion::operator*(const Proportion &otherValue) const
{
	return Proportion(*this)*=otherValue.Current();
}

const Proportion Proportion::operator*(const double otherValue) const
{
	return Proportion(*this) *= otherValue;
}

//Division Operator Overloads | [Proportion / int || float || Proportion]
//
//The below overloads utilize the implementations for compound division [/=]
//to accomplish the division operation
const Proportion Proportion::operator/(const int otherValue) const
{
	return Proportion(*this)/=otherValue;
}
const Proportion Proportion::operator/(const float otherValue) const
{
	return Proportion(*this)/=otherValue;
}
const Proportion Proportion::operator/(const Proportion &otherValue) const
{
	return Proportion(*this)/=otherValue.Current();
}

const Proportion Proportion::operator/(const double otherValue) const
{
	return Proportion(*this) /= otherValue;
}

//Relational Comparison/Equality Operator Overload
bool Proportion::operator==(const Proportion &valueToCompare) const
{
	if(current_ == valueToCompare.Current())
	{
		return true;
	}

	return false;
}

//Relational NOT EQUAL TO Operator Overload | [Proportion != Proportion]
bool Proportion::operator!=(const Proportion &valueToCompare) const
{
	//If the values are EQUAL this will return FALSe,
	//If they are NOT EQUAL it will return TRUE
	return !(*this == valueToCompare);
}

// operator>
//Returns TRUE if current_ of the left hand is 
// GREATER THAN current_ of the Righ hand operand. Otherwise
// it returns FALSE;
bool Proportion::operator>(const Proportion &valueToCompare) const
{
	return(this->current_ > valueToCompare.Current());
}

//operator<
//Returns TRUE if current_ of the left hand operand is 
//LESS THAN current_ of the Right hand operand. Otherwise
//it returs FALSE;
bool Proportion::operator<(const Proportion &valueToCompare) const
{
	return (this->current_ < valueToCompare.Current());
}


//operator>=
//Returns TRUE if current_ of the left hand operand is 
//GREATER THAN OR EQUAL TO current_ of the Right hand operand. 
//Otherwise it returs FALSE; 
bool Proportion::operator>=(const Proportion &valueToCompare) const
{
	return (this->current_ >= valueToCompare.Current());
}

//operator<=
//Returns TRUE if current_ of the left hand operand is 
//LESS THAN OR EQUAL TO current_ of the Right hand operand. 
//Otherwise it returs FALSE; 
bool Proportion::operator<=(const Proportion &valueToCompare) const
{
	return (this->current_ <= valueToCompare.Current());
}

//Output Stream Operator Overload
//This is a NOT a member function/operator of Proportion but rather
//a friend function/operator.
ostream& operator<<( ostream &output, const Proportion &P )
{
	//Output: [ current_/max_ ] | [ 100/100 ]]
	output << "[" << (float)P.Current() << "/" << P.Max() << "]";
	return output;
}

