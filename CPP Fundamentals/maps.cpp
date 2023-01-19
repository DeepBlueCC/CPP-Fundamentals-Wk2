#include <iostream>
#include <vector>

#include <map>
#include <unordered_map>

struct CityRecord
{
	std::string Name;
	uint64_t Population;	// unsigned interger 64bit
	double Latitude, Longitude;
};

int mmain()
{
	
	std::vector<CityRecord> cities;

	cities.push_back({ "London", 5000000, 2.4, 9.5 });
	cities.push_back({ "Warsaw", 6000000, 2.4, 9.5 });
	cities.push_back({ "New York", 7000000, 2.4, 9.5 });
	cities.push_back({ "Paris", 8000000, 2.4, 9.5 });

	// Slow way to find how many people live in New York using Vectors
	for (const auto& city : cities)
	{
		if (city.Name == "New York")
		{
			// Display the population once found
			std::cout << "New York's population: " << city.Population << std::endl;	
			break;
		}
	}

	/* Note: Following would work, but crazy to use the CityRecord struct as a hash
	* 
	* std::unordered_map<CityRecord, uint32_5> numMap;
	* 
	* numMap[CityRecord{ "London", 5000000, 2.4, 9.5 }] = 1000;
	*/
		
	std::unordered_map<std::string, CityRecord> cityMap;	// Can change to std::map 

	cityMap["London"] = CityRecord{ "London", 5000000, 2.4, 9.5 };
	cityMap["Warsaw"] = CityRecord{ "Warsaw", 6000000, 2.4, 9.5 };
	cityMap["New York"] = CityRecord{ "New York", 7000000, 2.4, 9.5 };
	cityMap["Paris"] = CityRecord{ "Paris", 8000000, 2.4, 9.5 };

	CityRecord& nyData = cityMap["New York"];	// String is hashable, it's basic data type. Not complex
	std::cout << "New York's population: " << nyData.Population << std::endl;

	// If "New York" is not found, it inserts into unordered_map and gives back 
	// a reference of the newly inserted record of New York!!!!
	// Therefore, it can be used to insert a new record if hash is not found
	CityRecord& hkData = cityMap["Hong Kong"];
	hkData.Name = "Hong Kong";
	hkData.Population = 4000000;
	hkData.Latitude = 2.4;
	hkData.Longitude = 9.5;
	std::cout << "Hong Kong's population: " << hkData.Population << std::endl;

	// You can also use .at to find record, but if not found it will return error
	// Therefore check first before using .at. Will not insert record.
	if (cityMap.find("Hong Kong") != cityMap.end())
	{
		const CityRecord& atData = cityMap.at("Hong Kong");
		std::cout << "Hong Kong's population: " << atData.Population << std::endl;
	}



	return 0;
}
