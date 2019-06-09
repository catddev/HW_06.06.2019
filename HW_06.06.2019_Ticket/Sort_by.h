#pragma once
#include"Ticket.h"

class SortBy2 {
	string prop;
public:
	SortBy2(string prop) {
		this->prop = prop;
	}
	bool operator()(ticket t1, ticket t2) {
		if (prop == "flight")
			return (t1.getFlight() < t2.getFlight());
		else if (prop == "departure")
			return (t1.getDeparture() < t2.getDeparture());
		else if (prop == "passenger")
			return(t1.getPassenger() < t2.getPassenger());
	}
};