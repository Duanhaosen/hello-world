//��ҵ���������������¿�ܵĴ���ϸ�ڣ������ܱ������еõ���ȷ��� 
#include <iostream>
class Prime {
  public:
  	Prime():number(0) {
	}
  	Prime(int n):number(n) {
	}
	~Prime() {
	}
  	bool isPrime() { 
  	  //2��number-1������ 
  	  return false;
	}
  private:
  	const int number;
}; 
class PrimeSet {
  public:
  	PrimeSet(int size) {
  	  //���ϵĹ���ʲô�� 
  	  N = new Prime*[size];
  	  this->size = size;
  	  index = 0;
	}
	~PrimeSet() {
  	  for (int i = 0; i < index; ++i)  //���ٶ��� 
		delete N[i]; 
	  delete[] N;
	}
	bool add(int n) {
	  if(index == size)  return false;
	  Prime *p = new Prime(n);
	  N[index] = p;
	  index += 1;
	  return true;
	}
	bool isAllPrime() {
	  for(int i = 0; i < index; i++)
	    if (!N[i]->isPrime())
	      return false;
	  return true;
	} 
  private:
  	Prime **N;
	int size, index;
};
class SuperPrime {
  public:
  	SuperPrime():number(0), pset(3) {  //Ϊʲô�����У� 
  	}
  	SuperPrime(int n):number(n), pset(3) {
  	  split();  //�����ǹ������ 
	}
  	~SuperPrime() {
	}
  	bool isSuperPrime() {
  	  //��ôʹ��pset�� 
  	  Prime p(number);
	  if (p.isPrime())
	    return true; 
  	  return false;
	}
  private:
  	const int number;
  	PrimeSet pset;
	void split() {   //�����������ģʽ 
	  // number split into N
	  int temp = number;
	  while(temp > 0) {
	  	int n = temp % 10;
	  	temp /= 10;
	  	pset.add(n);  //��ҵ����������Ϊ���󣿻��Ǻ�/��/ƽ����Ϊ���� 
	  } 
	}
	int sum() {
        int sum;
        for (int i = 0; i <= size; i++) {
            sum += N[i];
        }
	  return sum;
	}
	int multi() {
        int multi;
        for (int i = 0; i <= size; i++) {
            multi += N[i]*N[i];
        }
        return multi;
	  return 0;
	}
	int squareSum() {
        int squareSum;
        for (int i = 0; i <= size; i++) {
            squareSum += N[i]*N[i]*N[i];
        }
        return squareSum;
	  return 0;
	}
};
class SuperPrimeSet {
  public:
  	SuperPrimeSet(int from, int to) {
  	  size = to - from;
  	  for (int i = from; i < to; i++)
  	    set[i-from] = new SuperPrime(i);
	}
  	~SuperPrimeSet() {
  	  for(int i = 0; i < size; i++)
  	    delete set[i];
	}
  	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i]->isSuperPrime())
  	      count += 1;
	  return count; 
	}
  	int sum() {
  	  int sum = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i].isSuperPrime())
  	      sum += set[i];
	  return sum; 
	}
  private:
  	SuperPrime **set;
  	int size, index;
};
int main() {
    Set sp(100, 999);
  SuperPrime sp(100,999);
   std::cout << sp.count << std::endl;
    std::cout << sp.sum << std::endl;
  return 0;
}
