//
// Created by Stephanie Agbim on 11/03/2022.
//

#pragma once
template<typename S>
class battleArr {
private:
    unsigned maximum;
    unsigned prevMaximum;
    unsigned noOfN;
    S **arr;

    void max(); //expand
    void initialise(unsigned from);

public: //functions to overload operators
    battleArr(unsigned size = 4);

    battleArr(const battleArr &obj);

    ~battleArr();

    S& operator[](const unsigned index);

    void operator=(const battleArr &obj);

    unsigned inMaximum();

    unsigned size();

    void push(const S element);

    void rid(const unsigned index, bool desc = false);
};

/*template<typename S>
battleArr<S>::battleArr(unsigned index )
{}*/
template<typename S>
battleArr<S>::battleArr(unsigned size) {
    this->prevMaximum = size;
    this->maximum = size;
    this->noOfN = 0; //NUMBER OF elements
    this->arr = new S*[this->maximum];
    this->initialise(0);
}

template<typename S>
battleArr<S>::battleArr(const battleArr& obj)
{
    this->prevMaximum = obj.prevMaximum;
    this->maximum = obj.maximum;
    this->noOfN = obj.noOfN;
    this->arr = new S*[this->maximum];

    for (size_t i = 0; i< this->noOfN; i++)
    {
        this->arr[i] = new S(*obj.arr[i]);
    }
    this->initialise(0);

}
template<typename S>
battleArr<S>::~battleArr<S>() {
    for (size_t i = 0; i < this->noOfN; i++)
    {
        delete this->arr[i];
    }
    delete[]arr;

}
template<typename S>
S& battleArr<S>::operator[](const unsigned int index) {
    if (index < 0 || index >= this->noOfN)
        throw "Please try again";
    return *this->arr[index];

}

template<typename S>
void battleArr<S>::operator= (const battleArr& obj)
{
    for (size_t i = 0; i < this->noOfN; i++)
    {
        delete this->arr[i];
    }
    delete[] arr;

    this->prevMaximum = obj.prevMaximum;
    this->maximum = obj.maximum;
    this->noOfN = obj.noOfN;

    this->arr = new S*[this->maximum];

    for (size_t i = 0; i < this->noOfN; i++)
    {
        this->arr[i] = new S(*obj.arr[i]);
    }

    this->initialise(0);
}

template<typename S>
void battleArr<S>::max()
{
    this->maximum *= 2;

    S* *temporary = new S*[this->maximum];

    for (size_t i = 0; i < this->noOfN; i++)
    //for (size_t i = 0; i < this->maximum; i++)
    {
        temporary[i] = this->arr[i];
    }

    delete[]arr;

    this->arr = temporary;

    this->initialise(this->noOfN);
}

template<typename S>
void battleArr<S>::initialise(unsigned from)
{
    for (size_t i = from; i < this->maximum; i++)
    {
        this->arr[i] = nullptr;
    }
}

template<typename S>
unsigned battleArr<S>::inMaximum()
{
    return this->maximum;
}

template<typename S>
unsigned battleArr<S>::size()
{
    return this->noOfN;
}

template<typename S>
void battleArr<S>::push(const S element)
{
    if (this->noOfN >= this->maximum)
        this->max();

    this->arr[this->noOfN++] = new S(element);
}

template<typename S>
void battleArr<S>::rid(const unsigned index, bool desc)
{
    if (index < 0 || index >= this->noOfN)
        throw "ERROR, REMOVE.";

    if (desc)
    {
        delete this->arr[index];

        for (size_t i = 0; i < this->noOfN-1; i++)
        {
            this->arr[i] = this->arr[i + 1];
        }

        this->arr[--this->noOfN] = nullptr;
    }
    else
    {
        delete this->arr[index];

        this->arr[index] = this->arr[this->noOfN - 1];

        this->arr[--this->noOfN] = nullptr;
    }
}


