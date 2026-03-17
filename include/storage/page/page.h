#include <cstdint>
#include <optional>

class Page{
    public: 
    static constexpr uint16_t PAGE_SIZE= 8192;

    struct PageHeader{
        uint16_t slot_count;
        uint16_t free_space;

    };
    
    struct Slot{
        uint16_t  offset;
        uint16_t length;
        uint8_t deleted;
    };

    Page();

};