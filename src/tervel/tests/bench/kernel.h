//#include <list>
//#include <stack>
//#include <map>

typedef enum Status
{
	PRESENT,
	ABSENT
}Status; 

typedef struct Item
{
	int key;
	int value;
	//int sum;
	double sum;
	
	//READS needs a separate sum, check linearizability by taking ceiling of sum + sum_reads > 0

	long int numerator;
	long int denominator;	

	double exponent; 

	Status status;
	
	//std::stack<int> promote_items;
	void* promote_items;

	//std::list<Method> demote_methods;
	void* demote_methods;

	//std::map<long int,Method,bool(*)(long int,long int)>::iterator producer;
	void* producer;

	//Failed Consumer
	double sum_f;
	long int numerator_f;
	long int denominator_f;	
	double exponent_f;

	//Reader
	double sum_r;
	long int numerator_r;
	long int denominator_r;	
	double exponent_r;

}Item;