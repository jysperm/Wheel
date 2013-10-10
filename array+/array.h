#ifndef H_JYDS_ARRAY_PLUS
#define H_JYDS_ARRAY_PLUS

template<class T> class Array
{
public:
    Array(int length);
    Array(int length, const T defaultValue);
    Array(const Array &other);
    ~Array();
    Array<T>& operator = (const Array<T> &other);

    T& at(int offset);
    T& operator [] (int offset);
    T& frist();
    T& last();
    T* raw();

    int size() const;

private:
    T* data;
    int length;
};

template<class T> Array<T>::Array(int length)
{
    data = new T[length];
    this->length = length;
}

template<class T> Array<T>::Array(int length, const T defaultValue)
{
    data = new T[length];
    this->length = length;
    for(int *p = data; p != &data[length]; p++)
        *p = defaultValue;
}

template<class T> Array<T>::Array(const Array &other)
{
    length = other.length;
    data = new T[length];

    for(int i = 0; i < length; i++)
        data[i] = other.data[i];
}

template<class T> Array<T>::~Array()
{
    delete data;
}

template<class T> Array<T>& Array<T>::operator = (const Array& other)
{
    if(&other == this)
        return *this;

    delete data;

    length = other.length;
    data = new T[length];

    for(int i = 0; i < length; i++)
        data[i] = other.data[i];
}


template<class T> T& Array<T>::at(int offset)
{
    return data[offset];
}

template<class T> T& Array<T>::operator [] (int offset)
{
    return data[offset];
}

template<class T> T& Array<T>::frist()
{
    return data[0];
}

template<class T> T& Array<T>::last()
{
    return data[length - 1];
}

template<class T> T* Array<T>::raw()
{
    return data;
}

template<class T> int Array<T>::size() const
{
    return length;
}

#endif // H_JYDS_ARRAY_PLUS
