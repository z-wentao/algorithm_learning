#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include<string>
//线性探测的特化处理，可以处理自定义类型的数据
enum State
{
	EMPTY,
	EXIST,
	DELETE,
};

//处理基本类型
template<class K>
struct DefaultFuncer
{
	size_t operator()(const K& key)
	{
		return key;
	}
};

//处理自定义类型
template<>
struct DefaultFuncer<string>
{
	size_t value = 0;
	size_t operator()(const string& str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			value += str[i];
		}
		return value;
	}	
};


template<class K, template<class>class HashFuncer = DefaultFuncer>
class HashTable
{
public:
	HashTable()
		:_size(0)
		, _capacity(0)
		, _state(NULL)
		, _table(NULL)
	{}

	HashTable(size_t size)
		:_size(0)
		, _capacity(size)
		, _state(new State[size])
		, _table(new K[size])
	{
		for (int i = 0; i < _capacity; i++)//全部状态初始化成EMPTY
		{
			_state[i] = EMPTY;
		}
	}


	//线性探测计算出元素存放位置（假设不哈希冲突）
	int _HashFunc(const K& key)
	{
		HashFuncer<K> hf;
		return hf(key) % _capacity;

		//匿名对象调用operator()
		/*return HashFuncer<K>()(key) % _capacity;*/
	}

	void Swap(HashTable<K> tmp)
	{
		swap(_size, tmp._size);
		swap(_capacity, tmp._capacity);
		swap(_state, tmp._state);
		swap(_table, tmp._table);
	}


	void _CheckCapacity()
	{				
		HashTable<K> tmp(2*_capacity);
		for (int i = 0; i < _capacity; i++)
		{
			tmp.Insert(_table[i]);
		}
		Swap(tmp);
	}
	

	bool Insert(const K& key)
	{
		//静态哈希表
		/*if (_size == _capacity)
		{
			cout<<"HashTable is full!"<<endl;
			return false;
		}*/

		//动态哈希表
		//高效哈希表的载荷因子大概稳定在0.7-0.8较好
		if (10 * _size >= 7 * _capacity)
		{
			_CheckCapacity();
		}

		int index = _HashFunc(key);
	
		while (_state[index] == EXIST)
		{		
			index++;
			if (index == _capacity)
			{
				index = 0;
			}
		}

		_table[index] = key;
		_state[index] = EXIST;
		_size++;
		return true;	
	}


	int Find(const K& key)
	{
		int index = _HashFunc(key);
		while (_state[index] == EXIST || _state[index]== DELETE)
		//while(_state[index] != EMPTY)	//空状态找不到，非空状态找得到
		{
			if (_table[index] == key && _state[index] == EXIST)
			{
				return index;
			}
			++index;
			if (index == _capacity)
			{
				index = 0;
			}
		}
		return -1;	
	}


	bool Remove(const K& key)
	{
		int index = Find(key);
		if (index != -1)
		{
			_state[index] = DELETE;
			--_size;
			return true;
		}
		return false;
	}


	void PrintTable()
	{
		for (int i = 0; i < _capacity; i++)
		{
			if (_state[i] == EXIST )
			{
				cout << i << "(EXIST):" << _table[i] << endl;
			}
			/*我将DELETE状态元素也打印出来，便于观察。
			而Insert处理时，DELETE状态下的位置可以插上新的元素*/
			else if (_state[i] == DELETE)
			{
				cout << i << "(DELETE):" << _table[i] << endl;
			}
			else
			{
				cout << i << "(EMPTY):" << _table[i] << endl;
			}
		}
	}

private:
	size_t _size;//实际存放元素个数
	size_t _capacity;//哈希表长度
	State* _state;
	K* _table;
};


//POD(基本类型)的测试用例
void TestHashTablePOD()
{
	HashTable<int> ht(10);
	ht.Insert(89);
	ht.Insert(18);
	ht.Insert(49);
	ht.Insert(58);
	ht.Insert(9);
	ht.PrintTable();

	int ret = ht.Find(89);
	cout << ret << endl; 

	ht.Remove(89);
	ht.PrintTable();

	ht.Remove(18);
	ht.PrintTable();
}


//自定义类型的测试用例
void TestHashTable()
{
	HashTable<string,DefaultFuncer> ht(10);
	ht.Insert("1");
	ht.Insert("2");
	ht.Insert("3");
	ht.Insert("3");
	ht.PrintTable();

	int ret = ht.Find("3");
	cout << ret << endl;

	ht.Remove("2");
	ht.PrintTable();

	ht.Remove("1");
	ht.PrintTable();
}




int main()
{
	TestHashTable();
	system("pause");
	return 0;
}