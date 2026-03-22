#include "storage/page/page.h"
#include <cstring>
#include <stdexcept>


Page :: Page(){
    initialize();
}
void Page:: initialize(){
    std:: memset(data, 0, PAGE_SIZE);
    PageHeader header{};
    header.slot_count= 0;
    header.free_space=PAGE_SIZE;
    setHeader(header);

}

Page::PageHeader Page::getHeader(){
    PageHeader header{};
    std:: memcpy(&header, data, sizeof(PageHeader));
    return header;
}


void Page::setHeader(PageHeader& header){
    std:: memcpy(data, &header, sizeof(PageHeader));
}

Page::Slot Page::getSlot(uint16_t slotIndex){
    PageHeader header= getHeader();
    if(slotIndex > header.slot_count){
        throw std::out_of_range("Invalid slot index");

    }
    Slot slot{};
    std::size_t offset= sizeof(PageHeader)+slotIndex * sizeof(slot);
    std:: memcpy(&slot, data+ offset, sizeof(slot) );
}