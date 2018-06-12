#include "TestCase.hpp"

void TestCase::print(){

	os << name << ": "<< fail << " failed, "<< pass << " passed, "<< pass+fail << " total."<<endl;
}
