#pragma once

template <typename T>
class IRepository {
public:
    virtual void Insert(const T& item) = 0;

    virtual T* GetById(int id) = 0;
    
    virtual bool Update(int id, T& updatedItem) = 0;
    
    virtual bool Delete(int id) = 0;
    
    virtual void DisplayAll() const = 0;

    virtual ~IRepository() = default;
};
