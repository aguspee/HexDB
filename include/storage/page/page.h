#include <cstdint>
#include <optional>

class Page
{

  
public:
    static constexpr uint16_t PAGE_SIZE = 8192;

    struct PageHeader
    {
        uint16_t slot_count;
        uint16_t free_space;
    };

    struct Slot
    {
        uint16_t offset;
        uint16_t length;
        uint8_t deleted;
    };

    Page();
    void initialize();
    PageHeader getHeader();
    void setHeader(PageHeader &header);
    Slot getSlot(uint16_t slotIndex);
    void setSlot(uint16_t slotIndex, Slot &slot); // posicion, slot
    uint16_t getFreeSpace();
    std::optional<uint16_t> insertRow(const char* rowData, uint16_t length);// devuelve template si falla nada, si sirve index
    bool deleteRow(uint16_t slotIndex);
    
    const char* rawData() const; //solo lecutra
    char* rawData();//se puede modificar
private:
char data[PAGE_SIZE];  

};