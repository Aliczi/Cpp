#include <iostream>
#include <memory>


class Wezel{
    public:
    //std::shared_ptr<Wezel> next;
    std::weak_ptr<Wezel> next;
    ~Wezel();
};