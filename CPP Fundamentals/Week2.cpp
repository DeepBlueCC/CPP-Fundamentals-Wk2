#include <iostream>
#include <map>
#include <string>
using namespace std;

class Classy
{
private:

public:
	int foo;
	Classy() { foo = 0; } // In-body initialization.
	Classy(int f) :foo(f) { } // Non-default constructor. Using an initializer.
	int GetFoo() { return foo; }
};

int main()
{
	map<string, int> int_map; // std::map<std::string, int> int_map;
	// First way of adding items. Using insert and make_pair.
	int_map.insert(make_pair("fire", 1)); // std::make_pair
	int_map.insert(make_pair("jump", 2));
	// Second way. Using subscript notation.
	int_map["select"] = 3;
	// Third way. Using emplace. C++11
	int_map.emplace("start", 4);

	// Iterate through map while loop. Using an iterator.
	map<string, int>::iterator it = int_map.begin();
	while (it != int_map.end())
	{
		cout << it->first  // key value.
			<< ':'
			<< it->second // mapped value.
			<< endl;
		it++;
	}
	// Iterate through map standard for loop. Using the iterator.
	for (it = int_map.begin(); it != int_map.end(); it++)
	{
		cout << it->first  // key value.
			<< ':'
			<< it->second // mapped value.
			<< endl;
	}
	// Iterate using for loop. C++11
	for (auto const& i : int_map)
	{
		cout << i.first  // key value.
			<< ':'
			<< i.second // mapped value.
			<< endl;
	}
	int_map.clear(); // Empties the map.
	// To demonstrate some advanced features, let's use objects.
	Classy a(100), b(200);
	map<string, Classy> c_map;
	c_map.insert(make_pair("a", a));
	c_map["b"] = b;
	c_map.emplace("c", Classy(300));
	c_map.insert(make_pair("d", Classy(4500)));
	a.foo = 1000; // You will notice no change to "a" in map.
	for (auto const& i : c_map)
	{
		cout << i.first      // key value.
			<< ':'
			<< i.second.foo // mapped value and property.
			<< endl;
	}
	system("pause");
	return 0;
}