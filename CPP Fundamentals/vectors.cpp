#include <iostream>
#include <vector>

struct Vertex
{
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
} 

void print(const std::vector<Vertex>& vertices)
{
	for (const Vertex& v : vertices)			// To avoid copying, reference: for (Vertex& v: vertices)
		std::cout << v << std::endl;
}

int main()
{
	std::vector<Vertex> vertices;
	vertices.push_back({ 1,2,3 }); // Enters values into vector, and pushes it longer
	vertices.push_back({ 4,5,6 });

	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;

	vertices.erase(vertices.begin() + 1);	// Removes begin+1 = second element

	print(vertices);

	vertices.clear();	// Clear memory block

	std::cin.get();
	return 0;
}