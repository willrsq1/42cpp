#include "Serializer.hpp"

Serializer::Serializer()
{
	CLASS("Constructor", "Serializer");
}

Serializer::~Serializer()
{
	CLASS("Destructor", "Serializer");
}

Serializer::Serializer(const Serializer& other)
{
	CLASS("Constructor by copy", "Serializer");
	if (this == &other)
		return ;
}

Serializer& Serializer::operator= (const Serializer& other)
{
	CLASS("Operand = Constructor", "Serializer");
	if (this == &other)
		return (*this);
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
