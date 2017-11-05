#ifndef CUSTOMDICTIONARRY
#define CUSTOMDICTIONARRY

//define zone------------------------------------------------------------------
#include <vector>
#include <exception>
#include <iterator>
#include <utility>
#include <algorithm>
#include <iostream>
//type zone--------------------------------------------------------------------


using namespace std;

template<typename ValueType>
class DictIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
	template<typename Key, typename Value>
	friend class dictionary;


private:
	DictIterator(ValueType* p)
	{
		this->p  = p;
	}



public:
	

	DictIterator(const DictIterator &it)
	{
		this->p = it.p;
	}



	bool operator!=(DictIterator const& other) const
	{
		return p != other.p;
	}



	bool operator==(DictIterator const& other) const
	{
		return p == other.p;
	}



	typename DictIterator::reference operator*() const
	{
		return *p;
	}



	DictIterator& operator++()
	{
		++p;
		return *this;
	}



private:
	ValueType* p;



};





template<class Key, class Value>
class dictionary
{

    //private zone--------------------------------------------------------------
private:
 
    //fields-------------------------------------------------------------------
    vector<pair<Key,Value>> _base;
    
    size_t _memoryStep; 


    //methods------------------------------------------------------------------
    bool _isntKeyExists(Key key)
    {  
       return this->find(key) == this->end(); 
    }



    void _add(pair<Key,Value> newPair)
    {
		if (_base.size() == _base.capacity())
			_base.reserve(_base.capacity() + _memoryStep);
            
		_base.push_back(newPair);      
    }



    size_t _find_num(Key key)
    {
        for (int i = 0; i< _base.size(); ++i)
        {
            if (_base[i].first == key)
            {
                return i;
            }
        }
        return this-> size();
    }
    


    //public zone--------------------------------------------------------------
public:
    
    //type zone----------------------------------------------------------------
	typedef DictIterator<pair<Key, Value>> iterator;

	typedef DictIterator<const pair<Key, Value>> const_iterator;
    
    
    
    //set/get zone-------------------------------------------------------------
    
    size_t capacity()
    {
        return _base.capacity();
    }




    size_t size()
    {
        return _base.size();
    }



    iterator begin()
    {
        return iterator(_base.data());
    }



    iterator end()
    {
        return iterator(_base.data() + (int)_base.size());
    }



    iterator cbegin()
    {
        return const_iterator(_base.data());
    }



    iterator cend()
    {

        return const_iterator( _base.data() +(int) _base.size());
    }


    //methods zone-------------------------------------------------------------
    void add(pair<Key,Value> newPair)
    {
        if (_isntKeyExists(newPair.first))
            _add(newPair);
        else
            throw "The key already exists"; 
    }



    void add(Key key, Value value)
    {
		auto pair = make_pair(key, value);
        add(pair);
    }



    iterator find (Key key)
    {
        for (auto i = begin(); i!=end(); ++i)
        {
            if ((*i).first == key)
            {  // cout << "find return " << (*i).first << ' ' << (*i).second << endl; 
                return i;
            }
        }
       // cout << "find return end()" << endl;
        return this->end();
    }



    void remove(Key key)
    {
        _base.erase(_base.begin() + _find_num(key));
    } 



     Value operator [] (Key key)
    {
        return *(this->find(key)).second;
    }



    void printlnInConsole()
    {
        for (int i = 0; i <_base.size(); i++ )
        {
            cout << _base[i]. first << ":" << _base[i].second << endl;
        }
    }


    //constructors zone--------------------------------------------------------
    dictionary(size_t capacity = 10, size_t memoryStep = 10)
    {
        _base = vector<pair<Key,Value>>(0);
        _memoryStep = memoryStep;
        _base.reserve(memoryStep);

    }

};





#endif
