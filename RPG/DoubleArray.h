#ifndef _DOUBLEARRAY_H_
#define _DOUBLEARRAY_H_


template<typename T>
class DoubleArray
{
private:
	T* array;
	int size;
	int Width, Height;

public:
	DoubleArray(const DoubleArray & doubleArr)
	{
		size = doubleArr.getSize();
		Width = doubleArr.getWidth();
		Height = doubleArr.getHeight();

		if(size > 0)
		{
			array = new T[size];

			for(int i=0; i<size; i++)
				this->array[i] = array[i];
		}
		else
		{
			array = nullptr;
			throw "size must be > 0!";
			//exception
		}
	}

	DoubleArray(int sizeN, int sizeM, T * array = nullptr)
	{
		Width = sizeN;
		Height = sizeM;
		this->size = Width * Height;

		if(size > 0)
			this->array = new T[size];
		else
		{
			this->array = nullptr;
			throw "size must be > 0!";
			//exception
			//return;
		}

		if(array != nullptr)
			for(int i=0; i<size; i++)
				this->array[i] = array[i];
	}

	~DoubleArray()
	{
		if(array != nullptr)
		{
			delete [] array;
			array = nullptr;
		}
	}


	inline int getSize()   {	return size;		}
	inline int getWidth()  {	return Width;		}
	inline int getHeight() {	return Height;		}

	T & getValue(int i, int j)
	{
		if(i < 0 || j < 0 || i >= Width || j >= Height)
		{
			//exception
			//return array[0];
			//throw "kkk";
			return array[0];
		}

		return array[i*Width + j];
	}


};


#endif