#include <iostream>
class BaseItem {
public:
    virtual void useItem() = 0;
    virtual int getRes() = 0;
    virtual ~BaseItem() = default;
};

class HPBasedItem : public BaseItem {
protected:
    std::string name;
    int hprestore;
public:
    HPBasedItem(std::string name, int hprestore) : name(name), hprestore(hprestore) {}
    ~HPBasedItem(){}
    void useItem() override {

    }
    int getRes() override{
        return hprestore;
    }
};









