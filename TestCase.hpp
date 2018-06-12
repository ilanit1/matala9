#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class TestCase {

    public:

	string name;
	ostream &os;
	int pass;
	int fail;

    //constructor
	TestCase(string namee, ostream &ost):name(namee), os(ost), pass(0), fail(0){};
	
	//functions
	template <typename T> TestCase& check_equal(T a, T b);
    template <typename T> TestCase& check_different(T a, T b);
    template <typename Function,typename T,typename S> TestCase& check_function(Function f,T a, S b);
    template <typename T> TestCase& check_output(T a,string b);
    void print();

};


template <typename T> TestCase& TestCase::check_equal(T a, T b) {
    
	if (a == b) {
		pass++;
	} 
	else {
	    
		fail++;
		ostringstream s1, s2;
		s1 << a;
		s2 << b;
		os<<name+": Failure in test #" +to_string(pass+fail)+": "+s1.str() + " should equal " + s2.str() + "!"<<endl;
	}
	
	return *this;
}

template <typename T> TestCase& TestCase::check_different(T a, T b) {
    
	if (a != b) {
		pass++;
	} 
	else {
	    
		fail++;
		ostringstream s1, s2;
		s1 << a;
		s2 << b;
	    os<<name+": Failure in test #" +to_string(pass+fail)+": "+ s1.str() + " should equal " + s2.str() + "!"<<endl;
	}
	
	return *this;
}

template <typename Function,typename T,typename S> TestCase& TestCase::check_function(Function f,T a, S b) {
  
   if(f(a)==b)
     pass++;
    
    else{
        
        fail++;
		ostringstream s1, s2;
		s1 << b;
		s2 << f(a);
	    os<<name+": Failure in test #" +to_string(pass+fail)+": "+"Function should return " + s1.str() + " but returned "+ s2.str() + "!"<<endl;

	}

	return *this;
}

template <typename T> TestCase& TestCase::check_output(T a,string b) {

	ostringstream s;
	s << a;
	
	if(s.str()==b)
     	pass++;
	
	else {
	    
	    fail++;
	    os<<name+": Failure in test #" +to_string(pass+fail)+": "+"string value should be " + b + " but is " + s.str()<<endl;
	
	}
	return *this;
}



