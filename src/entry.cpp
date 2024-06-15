#include "entry.h"

class Entry {
public:
    std::string id;
    std::string property_name;
    int completion_year;
    std::string location;
    std::string property_type;
    int rooms;
    int parking;
    int bathroom;
    int size;
    std::string furnishing;
    std::string facilities;
    std::string additional_facilities;

    Entry(const std::string &id, const std::string &property_name, int completion_year,
          const std::string &location, const std::string &property_type, int rooms,
          int parking, int bathroom, int size, const std::string &furnishing,
          const std::string &facilities, const std::string &additional_facilities)
    {
        this->id = id;
        this->property_name = property_name;
        this->completion_year = completion_year;
        this->location = location;
        this->property_type = property_type;
        this->rooms = rooms;
        this->parking = parking;
        this->bathroom = bathroom;
        this->size = size;
        this->furnishing = furnishing;
        this->facilities = facilities;
        this->additional_facilities = additional_facilities;
    }
};
