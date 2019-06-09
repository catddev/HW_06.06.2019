#pragma once
#include"Ticket.h"

class filter2 {
	string prop;
	ticket t;
public:

	filter2(string prop, ticket t) {
		this->prop = prop;
		this->t = t;
	}
	void operator()(ticket t) {
		if (prop == "flight") {
			if (this->t.getFlight() == t.getFlight())
				cout << t;
		}
		else if (prop == "departure") {
			if (this->t.getDeparture() == t.getDeparture())
				cout << t;
		}
		else if (prop == "passenger") {
			if (this->t.getPassenger() == t.getPassenger())
				cout << t;
		}
	}
};