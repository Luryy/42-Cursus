#include <stdint.h>
#include <iostream>
#include <Data.hpp>

uintptr_t serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data *data = new Data();
    uintptr_t serialized;
	Data *deserializeData;

    std::cout << "Data address: " << data << std::endl
              << "Data atribute: " << data->getI() << std::endl;

    serialized = serialize(data);
    std::cout << "Serialize Value: " << serialized << std::endl;

    deserializeData = deserialize(serialized);
    std::cout << "Deserialized data address: " << deserializeData << std::endl
              << "Deserialized data atribute: " << deserializeData->getI() << std::endl;
    delete data;
    return (0);
}
